#include <stdio.h>
#include <stdlib.h>

int main()
{
  #define SIZE 10000000

  int * as = (int*) malloc(sizeof(int) * SIZE);
  for ( size_t ix = 0; ix < SIZE; ++ix )
    as[ix] = 0;
  
  printf("%d\n", as[0]);
  
  free(as);
  as = NULL; // will cause an error to be generated if the pointer is erroneous utilized after the memory has been de-allocated.
}
