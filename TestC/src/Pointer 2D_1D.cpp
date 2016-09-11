#include <stdio.h>

int main22()
{
  int a = 4, b = 7;
  int *pointer ;
  int Array[2][3] = {//  1 2 3
                        {0,1,2},//row 1
                        {3,4,5} //row 2      
                    };
  pointer = (int*)Array ; // con tro 1D tro toi mang 2D nen phai ep kieu
//pointer = (int*)Array  <=> pointer = (int*)Array[0] ;
  a = pointer[2]; // <=> Array[1][2]
  printf("values are: a = %d, b = %d\n", a, b);
  getchar();
  return 0;
}
