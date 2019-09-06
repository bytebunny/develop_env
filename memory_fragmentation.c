#include <stdio.h>
#include <stdlib.h>

int main()
{
  #define SIZE 10

  int ** as = (int**) malloc(sizeof(int*) * SIZE);

  for ( size_t ix = 0; ix < SIZE; ++ix )
    as[ix] = (int*) malloc(sizeof(int) * SIZE);
  
  for ( size_t ix = 0; ix < SIZE; ++ix )
    for ( size_t jx = 0; jx < SIZE; ++jx )
      as[ix][jx] = 0;

  printf("%d\n", as[0][0]);

  for ( size_t ix = 0; ix < SIZE; ++ix )
    free(as[ix]);

  free(as);
  as = NULL; // will cause an error to be generated if the pointer is erroneous utilized after the memory has been de-allocated.
}
