#include <dirent.h> 
#include <stdio.h> 
#include <string.h>

static int d_size = 0;

void get_dir_size(char * path)
{
  DIR * d = opendir(path);                          // open the path
  if(d==NULL) return;                               // if was not able, return
  struct dirent * dir;                              // for the directory entries

  while ((dir = readdir(d)) != NULL)                // if we were able to read somehting from the directory
    {
      if(dir-> d_type != DT_DIR)                    // if the type is not directory just print it with blue color
        printf("%s\n", dir->d_name);
      else {
        if(dir -> d_type == DT_DIR && strcmp(dir->d_name,".")!=0 && strcmp(dir->d_name,"..")!=0 ) {
            printf("%s\n", dir->d_name); 
            char d_path[255]; 
            sprintf(d_path, "%s/%s", path, dir->d_name);
            get_dir_size(d_path);               // recall with the new path
        }
      }
    }

    closedir(d); // finally close the directory
}

int main(int argc, char **argv)
{
  get_dir_size(".");
  return(0);
}
