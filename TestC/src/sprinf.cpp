#include <stdio.h>

int main26 ()
{
  char buffer [50];
  int n, a=5, b=3;
  //bo tat ca nhung gi có trong " " vào buffer
  n=sprintf (buffer, "%d plus %d is %d", a, b, a+b);
  printf ("[%s] is a %d char long string\n",buffer,n);
  getchar();
  return 0;
}
