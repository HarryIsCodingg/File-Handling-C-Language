#include <stdio.h>
#include <dirent.h>
#include "traversal.h"
#include "report.h"

int main(int argc, char **argv)
{

  printf("\nTarget String: %s\n", (argv[1]));
  DIR *directory = opendir(".");

  traverseFiles(".", argv[1]);

  printf("\nSearch begins in currrent folder: %s\n\n", (directory->dd_name));
  printReport();
}
