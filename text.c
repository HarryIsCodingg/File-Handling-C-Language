
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include "report.h"

void openFileAndModify(char textFile[], char targetString[])
{

  FILE *fileForReading, *fileForWriting;
  char read[100];
  char *upperCase;
  char readingFileName[256], writingFileName[256];
  int counter = 0;
  strcpy(readingFileName, textFile);
  strcat(readingFileName, ".txt");
  strcpy(writingFileName, textFile);
  strcat(writingFileName, "temp.txt");

  fileForReading = fopen(readingFileName, "r");

  fileForWriting = fopen(writingFileName, "w+");

  if (fileForReading == NULL || fileForWriting == NULL)
  {
    printf("Can't open file.");
  }

  upperCase = strupr(targetString);

  while (!feof(fileForReading))
  {

    fscanf(fileForReading, "%s", read);

    if (strcasecmp(read, targetString) == 0)
    {
      strcpy(read, upperCase);
      counter++;
    }
    else
    {
      char *pointer1, *pointer2, *pointer3;
      int i = 0, j = 0;

      pointer1 = read;
      pointer2 = strlwr(targetString);

      for (i = 0; i < strlen(read); i++)
      {
        if (*pointer1 == *pointer2)
        {
          pointer3 = pointer1;
          for (j = 0; j < strlen(targetString); j++)
          {
            if (*pointer3 == *pointer2)
            {
              pointer3++;
              pointer2++;
            }
            else
            {
              break;
            }
          }
          pointer2 = targetString;
          if (j == strlen(targetString))
          {
            int index = i;
            while (index < i + strlen(targetString))
            {
              read[index] = toupper(read[index]);
              index++;
            }
          }
        }
        pointer1++;
      }
      strupr(targetString);
    }

    fprintf(fileForWriting, "%s ", read);
  }
  addFileName(textFile, counter);
  counter = 0;

  fclose(fileForReading);
  fclose(fileForWriting);
  remove(strcat(textFile, ".txt"));
  rename(writingFileName, readingFileName);
}
