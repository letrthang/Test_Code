// pointers to structures
#include <iostream.h>

struct time_str {
	unsigned char day[2];//ko giong voi mang, voi struct, kich thuoc cua stuct (l� so byte
	unsigned char month;//cap ph�t cho struct) c� the khong bang tong k�ch thuoc cua c�c th�nh
	unsigned int year; //vi�n cua struct do.
	unsigned char century;
};
int main25() {
	time_str time;
	time_str * ptime;
	ptime = &time;

	time.day[0] = 0x00;
	time.day[1] = 0x00;
	time.month = 0x00;
	time.year = 0x00;
	time.century = 0x02;

	printf("sizeof *ptime: %d, (*ptime).century: %d \n", sizeof(*ptime),
			(*ptime).century);
	printf("*ptime: %d\n", *ptime);//ban th�n (*ptime) l� ko c� � nghia, tuc se cho ket qua ngau nhien.

	return 0;
}

