#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "app.h"

int main(int argc, char* argv[]) {
  if (argv[1])
    if (strcmp(argv[1], "-test") != 0) {
      printf("\n\nINVALID ARGUMENT: '%s' \ntry '-test' for test mode\n\n",
             argv[1]);
      exit(1);
    }

  if (run_all_tests(argv[1])) exit(1);

  main_menu();

  return 0;
}
