#include <stdio.h>
#include <stdlib.h>

int main()
{
  #define SIZE 10
  
  FILE *fp;
  int count = 0;

  int * m_entries = (int*) malloc(sizeof(int) * SIZE*SIZE);
  int ** m = (int**) malloc(sizeof(int*) * SIZE);

  for ( size_t ix = 0, jx = 0; ix < SIZE; ++ix, jx+=SIZE )
    m[ix] = m_entries + jx;

  fp = fopen("matrix.txt", "w");  
  
  for ( size_t ix = 0; ix < SIZE; ++ix ){
    for ( size_t jx = 0; jx < SIZE; ++jx ){
      m[ix][jx] = ++count;
      fprintf(fp, "%4d ", m[ix][jx]);
    }
    fprintf(fp,"\n");
  }

  fclose(fp);
  
  free(m);
  m = NULL; // will cause an error to be generated if the pointer is erroneous utilized after the memory has been de-allocated.
  //free(m_entries);
  //m_entries = NULL;
}
