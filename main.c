#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "app.h"

int main(int argc, char* argv[]) {
  if (run_all_tests() != 0) exit(1);
  
  main_menu();

  return 0;
}


