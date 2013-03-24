/*
 * main.cpp
 *
 *  Created on: 02-Apr-2012
 *      Author: vipul
 */

#include <stdlib.h> // NULL
#include <stdio.h>
#include <dirent.h>

int main()
{
  const char* path = "/home/vipul//tmp/";//argc <= 1 ? "." : argv[1];

  DIR* d = opendir(path);
  if (d == NULL) return -1;

  for(struct dirent *de = NULL; (de = readdir(d)) != NULL; )
    printf("%s/%s\n", path, de->d_name);

  closedir(d);
  printf("done");
  return 0;
}

