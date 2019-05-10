// creat by parth
// date : 10 may 2019



#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 4444 //change port number if u want to change

int main()
{
  struct sockaddr_in addr;
  int fd;

  fd = socket(AF_INET, SOCK_STREAM, 0);
  if(fd == -1)
  {
      printf("Error opening socket\n");
      return -1;
  }

  addr.sin_port = htons(PORT);
  addr.sin_addr.s_addr = 0;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_family = AF_INET;

  if(bind(fd, (struct sockaddr *)&addr,sizeof(struct sockaddr_in) ) == -1)
  {
      printf("Error binding socket\n");
      return -1;
  }

  printf("Successfully bound to port %u\n", PORT);
}