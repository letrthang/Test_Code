// static members in classes
#include <iostream.h>
class CDummy {
  public:
    static int n;
    CDummy () { n++; };
    ~CDummy () { n--; };
};
int CDummy::n=0;
int main27 () {
  CDummy a;
  CDummy b[5];
  CDummy * c = new CDummy;
  cout << a.n << endl;
  delete c;
  cout << CDummy::n << endl;
  getchar();
  return 0;
}
