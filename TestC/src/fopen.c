/*
When a program opens a file, the operating system returns a corresponding file 
descriptor that the program refers to in order to process the file. A file 
descriptor is a low positive integer. The first three file descriptors (0,1, and 2,)
are associated with the standard input (stdin), the standard output (stdout), 
and the standard error (stderr), respectively. Thus, the function scanf() uses 
stdin and the function printf() uses stdout. You can override the default setting 
and re-direct the process's I/O to different files by using different file descriptors.
Ex:
#include <cstdio>
fprintf(stdout, "writing to stdout"); //write to stdout instead of a physical file
 
*/

#define cach_1  0
#define cach_2  1

#if cach_1
#include <stdio.h>
int main_ ()
{
  FILE * pFile;
  pFile = fopen ("myfile.txt","w"); // tra ve handaller cua file 
  fprintf(stdout, "This is an apple.\n" );// hien thi tren man hinh
  if (pFile!=NULL)
  {
    fprintf(pFile, "This is an apple.\n" );//ghi vao file
    fseek ( pFile ,30,SEEK_SET );   // di chuyen con tro file toi 
                                    // vi tri thu 20, tinh tu dau file
    fputs ( "Mac PC ", pFile );
  }
  getchar();
  return 0;
}

#else // cach 2

/* fwrite(): write buffer */
#include <stdio.h>

int main8 ()
{
  FILE * pFile;
  char buffer[] = { 'x' , 'y' , 'z' };
  pFile = fopen ( "myfile.bin" , "wb" );
  fwrite (buffer , 1 , sizeof(buffer) , pFile );
  fclose (pFile);
  return 0;
}
#endif
