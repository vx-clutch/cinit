#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void err(int eval, const char *fmt, ...) {
  va_list args;
  fprintf(stderr, "cinit: ");

  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);

  fprintf(stderr, ": %s\n", strerror(errno));
  exit(eval);
}

void errx(int eval, const char *fmt, ...) {
  va_list args;
  fprintf(stderr, "cinit: ");

  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);

  fprintf(stderr, "\n");
  exit(eval);
}
