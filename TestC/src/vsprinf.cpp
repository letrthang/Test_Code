#include <stdarg.h>
#include <stdio.h>

void vout(char *string, char *fmt, ...);
char fmt1 [] = "%s  %s  %s %s\n";
 
int main34(void)
{
   char string[100];
 
   vout(string, fmt1, "Sat", "Sun", "Mon","Fri");
   printf("The string is:  %s\n", string);
   getchar();
}
 
void vout(char *string, char *fmt, ...)
{
   va_list arg_ptr;
 
   va_start(arg_ptr, fmt);
   vsprintf(string, fmt, arg_ptr);
   va_end(arg_ptr);
}
