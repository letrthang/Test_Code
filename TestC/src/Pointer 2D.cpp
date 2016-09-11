#include <stdio.h>
//-------------------------cach 1---------------
#define cach_1  0
#define cach_2  0
#define cach_3  1
//----------------------------------------------
#if cach_1
int main24()
{
  int a = 4, b = 7;
  int (*pointer)[3] ; // pointer la con tro mang,tuc gia tri gan cho pointer phai la d/c cua mot mang
  int Array[2][3] = {//  1 2 3
                        {0,1,2},//row 1
                        {3,4,5} //row 2      
                    };
  pointer = Array ;  // mang 2 chieu tuong duong voi mot con tro mang, vi ten cua mang tuong duong
                    // voi mot con tro, ten mang 2 chieu tuong duong voi mot con tro tro toi mang 1 chieu
								    // t/hop này, Array tro toi mang 1D co 3 phan tu int
	a = pointer[0][2];
  printf("values: a = %d, b = %d, size pointer = %d\n", a, b,sizeof(pointer));
  getchar();
  return 0;
}
#endif
//----------------------Cach 2------------------------
#if  cach_2
//----------------------------------------------------
int main24()
{
  char a = 4, b = 7;
  char **pointer ;  // pointer tro toi kieu int, *pointer tro toi kieu char.Tuy vay,ko he ton tai bien 
	                  //nao la *pointer ca, day chi la cach noi hinh thuc,trong bo nho chi co bien pointer.
	char Array[3][3] = {//  1 2 3
                        {0,1,2},//row 1
                        {3,4,5},//row 2 
                        {6,7,8},//row 3   
                    };
  pointer = (char**)Array ;//ve syntax thi pointer va Array khac kieu, nen phai ep kieu.
  a = (char)pointer[1]; // pointer tang moi lan 4 byte, vi pointer tro toi kieu du lieu 
                        // 4 byte (int), con *pointer thi tro toi kieu du lieu 1 byte (char).
                        // De y la: (char)pointer[1] <=> (char)(*(pointer+1))
  printf("Pointer 2D: a = %d,b = %d,&Array = %d,&Array[0] = %d, &Array[1] = %d,&Array[1][0]=%d\n",
                                           a, b,Array,&Array[0],&Array[1],&Array[1][0]);
  getchar();
  return 0;
}
#endif
//------------------------ cach 3 ------------------
#if cach_3
//--------------------------------------------------
int main24()
{
  int a = 4, b = 7,c = 0;
  int **pointer ; // khai bao the nay thi cung van tao ra 1 ô nho co 4 byte chua Pointer
                   // boi vi **pointer là 1 con tro tro toi 1 con tro khac, cho nen Pointer
                   //luon la 4 byte
  int Array[2][3] = {//  1 2 3
                        {37814064,1,2},//row 1
                        {3,4,5} 			 //row 2, 37814064 = &Array      
                    };
  pointer = (int**)Array ;//con tro hoat dong theo cau truc data mà nó duoc khai bao chu ko 
  												//hoat dong theo cau truc data mà nó tro toi. 
  a = pointer[0][1]; //  <=> *(*(pointer+0)+1); chu y: (pointer +1)=> pointer tang 4 byte.  
  // neu viet la: a = pointer[0][1]; ==> van dung syntax,
  // nhung ket qua ko nhu y muon, tuc la: pointer[0][1] != Array[0][1]
	
	b = (int)(*(Array+1) ) ;//Array ko phai la mot con tro that su. Nhung complier van doi xu voi nó nhu là mot
  												//con tro dac biet(là con tro mang,o vd này thì Array tro toi mang co 3 phan tu int).   
  												//Vì là con tro dac biet nen ko co o nho nào duoc cap rieng cho Array nhu doi voi mot 
													//con tro that su.De y: Ten cua mang 1 chieu duoc complier xem nhu la mot con tro tro 
													//toi mot kieu du lieu xác dinh nào do (int, float, struct,..). Ten cua mang nhieu chieu 
													//duoc complier doi xu nhu là 1 con tro tro toi mang (mang o day có the là 1D hay nhieu chieu). 
													   
  c = (int)*(*(Array+1)+1); // <=> Array[1][1] ; chu y: pointer[1][1] != Array[1][1] .
														//(Array+1): Array se tang theo kích thuoc cua kieu data ma nó tro toi,(t/h này là 12 byte).
	printf("2D Pointer values: a = %d, b = %d, c = %d, Array = %d\n", a, b,c,Array);
  getchar();
  return 0;
}
//Khi ta nói tên cua mang 2 chieu tuong duong voi mot con tro mang, thì chu "tuong duong" o day có ý nghia là các thao tác 
//(manipulation) xu lí doi voi tên cua mang duoc complier thuc hien giong nhu là thuc hien tren mot con tro mang that su. 
//Diem khác biet là o cho, voi con tro mang that su thì luon ton tai 4 byte ô nho duoc cap phát cho nó.Còn voi ten mang thi 
//ko có 4 byte ô nho rieng biet nào duoc cap phát cho nó. Tên cua mang là d/c dau tien cua vùng nho duoc cap phát cho mang do.

//neu muon khai báo mot con tro mang 2 chieu thi khai báo: int (*pointer)[2][3]; pointer tro toi mang 2 chieu kieu array[2][3].
//vd: int array[1][2][3] ;  int (*pointer)[2][3] = array ; khi do: *(*(*pointer))) = array[0][0][0].

#endif
/*
				
		|=====================
50	| 00 | 00 | 00 | 100 |  char ** ppi = 100 ; --> ppi luon chiem 4 byte trong bo nho
		|=====================



		======================
		|  									 |
		|=====================
100	| 00 | 00 | 00 | 200 |  <==== (* ppi)==> se tro toi ô nho co d/c 100 va lay gia tri cua 4 byte 
		|=====================									 lien tiep la: 100,..,103. Tuc complier se hieu la phai 
104	|										 |									lay gia tri o 4 ô nho lien tiep 100,..,103. Lay 4 byte 
		|................... |									la vi d/c 100 dong vai tro nhu mot con tro (tro toi d/c 300). 
		|									 	 |									 Vi la con tro nen duoc cap phat 4 byte.
		|										 |
		|										 |
		|										 |
		|										 |
		|=====================
200 |		300							 | <==== *(* ppi) ==> truong hop nay, complier se tinh (* ppi)
		|=====================									(la 200) roi tro toi ô nho có d/c 200 va 
		|										 |									lay gia tri o d/c nay (la 300).
		|=====================

* Chu y: ko he ton tai mot bien nao la *ppi hay **ppi, tuc ko co ô nho nao duoc cap phat  
*					truoc cho *ppi hay **ppi. * hay ** chi la nhung toan tu de báo cho complier 
*					biet can phai lam gi.
*/
