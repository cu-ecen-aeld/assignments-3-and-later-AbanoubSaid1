#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>


int main(int argc, char *argv[]){
  int open_error;
  
  openlog(NULL,0,LOG_USER);
  if(argc != 3){
   syslog(LOG_ERR, "Invalid Arguments, Please Input 2 Arguments, path to the file you want to write AND the text to write\n");
   return 1;
  }
  
  char *path=argv[1];
  char *text=argv[2];
  
  open_res=open(path, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
  
  if(open_res == -1){
   syslog(LOG_ERR, "error opening file %s %s\n", path, strerror( errno ));
   return 1;
   }
   
  ssize_t write_res = write(open_res, text, strlen(text));
  if(write_res == -1){
    syslog(LOG_ERR, "fail to write file %s %s\n", text, strerror( errno ));
    return 1;
    }
   
   syslog(LOG_DEBUG, "Writing %s to %s\n", text, path);
   close(open_res);
   
   return 0;
   }