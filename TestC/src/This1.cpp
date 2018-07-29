// this
#include <iostream.h>

class CDummy {
  public:
    int isitme (CDummy &param);
};

int CDummy::isitme (CDummy &param)
{
  if (&param == this) return 1;
  else return 0;
}

int main31 () {
  CDummy a;
  CDummy* b = &a;
  if ( b->isitme(a) )
    cout << "yes, &a is b";
  getchar();
  return 0;
}

