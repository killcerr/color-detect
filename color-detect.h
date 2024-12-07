#ifndef COLOR_DETECT_H
#define COLOR_DETECT_H
#include <stdio.h>
#include <stdbool.h>
#ifdef __cplusplus
extern "C"
#endif
bool is_support_ansi_color(FILE *file);
#endif
