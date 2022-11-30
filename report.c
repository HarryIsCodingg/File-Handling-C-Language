#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int countIndex = 0;
int totalNumberOfFiles = 0;

struct Data
{
  char fileName[256];
  int counter;
};

struct Data files[15];

int comparefunction(const void *a, const void *b)
{
  int x = ((struct Data *)a)->counter;
  int y = ((struct Data *)b)->counter;
  return (y - x);
}

void printReport()
{
  printf("** Search Report **\n");
  printf("\nUpdates\t\t\t\t File Name\n");
  struct Data *ptr = files;
  qsort((void *)files, sizeof(files) / sizeof(files[0]), sizeof(files[0]), comparefunction);
  while (totalNumberOfFiles < countIndex)
  {
    printf(" %d\t\t\t\t %s \n", ptr->counter, ptr->fileName);
    ptr++;
    totalNumberOfFiles++;
  }
}

void addFileName(char fileName[], int counter)
{
  struct Data file;
  file.counter = counter;
  strcpy(file.fileName, fileName);
  files[countIndex] = file;
  countIndex++;
}
