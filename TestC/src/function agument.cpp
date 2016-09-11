#include <iostream.h>

int * pointer ;
void address(int var)
{
    pointer = &var;
    
    }

int main12()
{
    int x = 9 ;
   //cout << &x << endl ;
   address(x);
   //cout << pointer << endl; 
   cout << *pointer ;
   getchar();
   return 0;
      
      }
