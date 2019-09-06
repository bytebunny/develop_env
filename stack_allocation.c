#include <stdio.h>

#include <stdlib.h>
#include <limits.h>
#include <float.h>


int main()
{
  #define SIZE 10000000

  int as[SIZE]; // If global scope (in preamble), static memory will be used instead of stack.
  for ( size_t ix = 0; ix < SIZE; ++ix )
    as[ix] = 0;
  
  printf("%d\n", as[0]);
  printf("Storage size of int: %d\n", sizeof(int));
}
