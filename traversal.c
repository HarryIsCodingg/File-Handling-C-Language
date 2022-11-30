
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "text.h"

char *innerPath;

int isDir(const char *fileName)
{
  struct stat path;

  stat(fileName, &path);

  return S_ISREG(path.st_mode);
}

void traverseFiles(const char *directoryName, char targetString[])
{

  DIR *directory = opendir(directoryName);

  if (directory == NULL)
  {
    return;
  }

  struct dirent *elements;
  elements = readdir(directory);
  while (elements != NULL)
  {

    if ((isDir(elements->d_name) == 0) && strcmp(elements->d_name, ".") != 0 && strcmp(elements->d_name, "..") != 0)
    {
      char path[200] = {0};
      strcat(path, directoryName);
      strcat(path, "\\");
      strcat(path, elements->d_name);
      traverseFiles(path, targetString);
    }

    char *token = strtok(elements->d_name, ".");

    while (token != NULL)
    {

      if (strcmp(token, "txt") == 0)
      {
        char path[200];
        char *pathName = getcwd(path, 200);
        strcat(pathName, "\\");
        strcat(pathName, directoryName);
        strcat(pathName, "\\");
        strcat(pathName, elements->d_name);
        openFileAndModify(pathName, targetString);
      }
      token = strtok(NULL, ".");
    }
    elements = readdir(directory);
  }
  closedir(directory);
  return;
}
