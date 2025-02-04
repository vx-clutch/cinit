#ifndef __linux__
#
"Just linux vro"
#endif

#include "err.h"
#include <stdio.h>

int confirm(const char *prompt);

struct {
  char *PROGRAM;
  int CD;
  int CLANG;
  int DOC;
  int GIT;
  int MAN;
  int README;
  int VLIBC;
} config;

int main(int argc, char **argv) {
  if (argc < 2)
    errx(1, "Not enough arguments, expected 1, found %d", argc - 1);
  config.PROGRAM = argv[1];
  if (confirm("Add README.md"))
    config.README = 1;
  if (confirm("Init git repo"))
    config.GIT = 1;
  if (confirm("Add .clang-format"))
    config.CLANG = 1;
  if (confirm("Add man page"))
    config.MAN = 1;
  if (confirm("Add DOCS directory"))
    config.DOC = 1;
  if (confirm("Add VLIBC"))
    config.VLIBC = 1;
  if (confirm("cd into directory"))
    config.CD = 1;
  return 0;
}

int confirm(const char *prompt) {
  printf("%s [Y/n] ", prompt);
  int ch = getchar();

  if (ch == 'y' || ch == 'Y' || ch == '\n')
    return 1;
  return 0;
}
