#include <stdio.h>
#include <stdlib.h>

int main()
{
  #define SIZE 10
  
  FILE *fp;
  int count = 0;

  int * m_entries = (int*) malloc(sizeof(int) * SIZE*SIZE);
  int ** m = (int**) malloc(sizeof(int*) * SIZE);

  // Duplicate of 'm' to test reading:
  int * m_read_entries = (int*) malloc(sizeof(int) * SIZE*SIZE);
  int ** m_read = (int**) malloc(sizeof(int*) * SIZE);

  for ( size_t ix = 0, jx = 0; ix < SIZE; ++ix, jx+=SIZE ){
    m[ix] = m_entries + jx;
    m_read[ix] = m_read_entries + jx;
  }
  // --------------- Writing to file --------------
  fp = fopen("matrix.txt", "w");  
  
  for ( size_t ix = 0; ix < SIZE; ++ix ){
    for ( size_t jx = 0; jx < SIZE; ++jx ){
      m[ix][jx] = ++count;
      fprintf(fp, "%4d", m[ix][jx]);
    }
    fprintf(fp,"\n");
  }

  fclose(fp);

  // --------------- Reading from file --------------
  printf("Matrix has been written to the file. Reopeining for reading...\n");

  fp = fopen("matrix.txt", "r"); 

  printf("The read values are (non-matching with the original matrix will be reported):\n");
  for ( size_t ix = 0; ix < SIZE; ++ix ){
    for ( size_t jx = 0; jx < SIZE; ++jx ){
      fscanf(fp, "%d", &m_read[ix][jx]);
      printf("%4d", m_read[ix][jx]);
      
      // Check that 2 matrices are the same:
      if (m[ix][jx] != m_read[ix][jx]){
        printf("Element [%d, %d] is not the same!\n", ix, jx);
      }  
    }
    printf("\n");
  }
  
  fclose(fp); 

  free(m);
  m = NULL; // will cause an error to be generated if the pointer is erroneous utilized after the memory has been de-allocated.
  free(m_entries);
  m_entries = NULL;

  free(m_read);
  m_read = NULL;
  free(m_read_entries);
  m_entries = NULL;
    
}
