// constructors and derivated classes
#include <iostream.h>
class mother {
  public:
    mother () //constructor mac dinh chay khi lop thua ke khoi tao
      { cout << "mother: no parameters\n"; }
    mother (int a) //constructor qua tai, ko tu dong chay khi lop thua ke khoi tao
      { cout << "mother: int parameter\n"; }
};
class daughter : public mother {
  public:
    daughter (int a)
      { cout << "daughter: int parameter\n\n"; }
};
class son : public mother {
  public:
    son (int a) : mother (a) //ko chay constructor default, ma chay constructor duoc chi dinh
      { cout << "son: int parameter\n\n"; }
};
int main4 () {
  daughter cynthia (1); // chay constructor mac dinh va constructor qua tai
  son daniel(1);// chay constructor duoc chi dinh va constructor qua tai
  //getchar();
  return 0;
}
