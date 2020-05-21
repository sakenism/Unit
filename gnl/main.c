#include "get_next_line.h"

int main () {

  char** line = (char**)(malloc(sizeof(char*) * 11111));
  for (int i = 0; i < 11111; i++) {
    // *line = (char*)(malloc())
  }
  int fd = open("a.txt", O_RDONLY);
  printf("%s", get_next_line(fd));
  printf("%s", get_next_line(fd));
  printf("%s", get_next_line(fd));
  
  close(fd);
}