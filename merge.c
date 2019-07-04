#include <stdio.h>
#include <stdlib.h>
void mergesort(char *a, int start1, int end1, int start2, int end2, int size);
void sorting(char *a, int begin, int end, int size);

int main(void)
{
  char sortme[] = {1, 3, 4, 5, 22, 88, 2, 8, 13}; 
  char *p = NULL;
  int size = sizeof(sortme);
  int i = 0;
  printf("size: %d\n", size);
  //mergesort(a, 0, 0, 1, 1, 2);
  sorting(sortme, 0, size-1, size);
  for(i=0; i<size; i++)
  {
    printf("%d ", sortme[i]);
  }
  printf("\n");
  return 0;
}
void sorting(char *a, int begin, int end, int size)
{
  if(begin == end)
  {
    return;
  }
  sorting(a, begin, (begin+end)/2, size);
  sorting(a, (begin+end)/2+1, end, size);
  mergesort(a, begin, (begin+end)/2, (begin+end)/2+1, end, size);

}
//merge two sorted "arrays"
// input: one real array with indexes denoting end and start of the two subarrays
void mergesort(char *a, int start1, int end1, int start2, int end2, int size)
{
  char *b = (char *)malloc(size);
  int i = start1;
  int j = start2;
  int k = start1;
  
  while(i<=end1 && j<=end2)
  { 
    if(a[i] < a[j])
    {
      b[k] = a[i++]; 
    }     
    else
    {
      b[k] = a[j++];
    } 
    k++; 
  }
  if(i>end1)
  {
    while(j<=end2)
    {
      b[k++] = a[j++];
    }
  }
  else if(j>end2)
  {
    while(i<=end1)
    {
      b[k++] = a[i++];
    }
  }
  
  for(i=start1; i<end2+1; i++)
  {
    a[i] = b[i];
  }
  free(b); 
}
