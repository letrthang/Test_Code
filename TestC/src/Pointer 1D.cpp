#include <stdio.h>

int main21()
{
  int a = 4, b = 7, c =0, d= 0;
  char *pointer ;           // tao ra 1 ô nho co kich thuoc 4 byte (mac dinh cua Win)
  typedef char (*ArrPointer)[3]; //kieu du lieu ArrPointer la mot con tro tro toi mang co 3 phan tu kieu char
  ArrPointer Arpp ; 
	char Array[3] = {0,1,2}; // tao ra 3 ô nho, moi ô là 4 byte
  printf("Address: &pointer: %d, &Array: %d, &Array[0]: %d\n"
														,&pointer,&Array,&Array[0]);
  printf("=> Array khong duoc cap phat vung nho rieng nhu la mot con tro that su.\n");
	pointer = Array ;
  a = pointer[2];
  b = Array[2]; // ==> a == b
  Arpp = (ArrPointer)Array ;
  c = (int)*(Arpp+1) ;// tang theo kich thuoc cua data mà nó tro toi (3 byte).
  										//dau * trong *(Arpp+1) ko phai lay noi dung, ma la lay d/c cua phan 
											// tu tiep theo(phan tu o day là mang Array nen tang len 3 byte)
	d = (int)*(*(Arpp+0)+1); //do mang có kieu char nen so 1 tuong ung voi tang d/c lên 1 byte.
  printf("Pointer 1D values : a = %d, b = %d,c = %d,d = %d, size pointer %d, size Array %d\n"
																, a, b, c, d, sizeof(pointer),sizeof(Array));
  getchar();
  return 0;
}
