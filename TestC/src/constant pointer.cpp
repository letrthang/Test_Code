#include <stdio.h>

int main3()
{
  int a = 4, b = 7;
  int const  *pointer1,*pointer2 ; 
  pointer1 = &a ;
  pointer2 = &b ;
  a++ ; //OK
  //*pointer1 = 8 ; sai, pointer1 la con tro hang nen ko the thay doi gia tri
  printf("values are: a == %d, b == %d, a == %d\n", *pointer1, *pointer2, a);
  getchar();
  return 0;
}

