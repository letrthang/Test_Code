/*
This sample code redirects the output that would normally go to the standard 
output to a file called myfile.txt, that after this program is executed contains:
This sentence is redirected to a file.
*/

/* freopen example: redirecting stdout */
#include <stdio.h>

int main9 ()
{
  freopen ("myfile2.txt","w",stdout);
  printf ("This sentence is redirected to a file.");
  fclose (stdout);
  return 0;
}
