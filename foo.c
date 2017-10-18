#include <dirent.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char longFormat = 0;

void parseOptions(int argc, char *argv[])
{
  int opt;

  while ((opt = getopt(argc, argv, "l")) != -1) {
    switch (opt) {
      case 'l':
        longFormat = 1;
        break;
      default:
        longFormat = 0;
    }
  }
}

void processEntry(char *entryName)
{
  struct stat   entryStat;
  char         *folderDelimiter;

  if (stat(entryName, &entryStat) == -1) {
    perror("stat");
    exit(EXIT_FAILURE);
  }

  folderDelimiter = ((entryStat.st_mode & S_IFMT) == S_IFDIR) ? "/" : "";

  if(longFormat)
    printf("%lld %s%s\n", (long long) entryStat.st_size, 
                          entryName, 
                          folderDelimiter);
  else
    printf("%s%s\n", entryName, 
                     folderDelimiter);
}

int main(int argc, char *argv[])
{
  DIR           *dirStream;
  struct dirent *dirEntry;

  parseOptions(argc, argv);

  if((dirStream = opendir(".")) == NULL)
  {
    perror("opendir");
    exit(EXIT_FAILURE);
  }

  while ((dirEntry = readdir(dirStream)) != NULL)
    processEntry(dirEntry->d_name);

  closedir(dirStream);

  return(0);
}
