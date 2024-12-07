#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <stdio.h>
#ifdef _WIN32
#include <io.h>
#else
#include <unistd.h>
#endif
bool is_support_ansi_color(FILE *file) {
#ifdef _WIN32
  if (_isatty(_fileno(file)) == 0)
    return false;
#else
  if (isatty(fileno(file)) == 0)
    return false;
#endif
  const char *no_color_env = getenv("NO_COLOR");
  if (no_color_env != NULL && no_color_env[0] != '\0')
    return false;
  const char *term_env = getenv("TERM");
  size_t term_len = 0;
  if (term_env)
    term_len = strlen(term_env);
  if ((term_env && term_len < 5) ||
      (term_env && term_len >= 5 &&
       strcmp(term_env + term_len - 5, "color") != 0))
    return false;
#ifdef _WIN32
  DWORD console_mode;
  if (GetConsoleMode((HANDLE)_get_osfhandle(_fileno(file)), &console_mode) &&
      (ENABLE_VIRTUAL_TERMINAL_PROCESSING & console_mode) !=
          ENABLE_VIRTUAL_TERMINAL_PROCESSING &&
      SetConsoleMode((HANDLE)_get_osfhandle(_fileno(file)),
                     console_mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING) ==
          FALSE)
    return false;
#endif
  return true;
}
/*
#include <stdio.h>
int main() { printf("%d\n", is_support_ansi_color(stdout)); }
*/
