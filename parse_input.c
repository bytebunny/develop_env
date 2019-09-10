#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
  int a, b;
  char *ptr;
  
  for ( size_t ix = 1; ix < argc; ++ix ){ // starts with 1 because 0 is the program name.
    ptr = strchr( argv[ix], 'a');
    if (ptr) a = ptr[1] - '0';
    else{
      ptr = strchr( argv[ix], 'b');
      b = ptr[1] - '0';
    }
  }
  printf("A is %d and B is %d\n", a, b);

  return(0);
}
