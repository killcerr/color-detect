#ifndef COLOR_DETECT_H
#define COLOR_DETECT_H
#include <stdio.h>
#include <stdbool.h>
#ifdef __cplusplus
extern "C"
#endif
// FILE *file must be a valid C file
// If file is NULL, will check stdout
bool is_support_ansi_color(FILE *file);
#endif
