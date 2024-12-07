# usage
```c
bool is_support_ansi_color(FILE *file);
```
## file:
must be a valid C file or NULL
## Return Value:
if the file handle support ansi color, this function will return true.
# example
```c
#include "color-detect.h"
int main()
{
        printf("%d",is_support_ansi_color(stdout));
}
```
