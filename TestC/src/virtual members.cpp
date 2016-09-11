// virtual members
#include <iostream.h>
class CPolygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
    virtual int area (void) =0;
    void printarea ()
      { cout << this->area() << endl; }
  };
class CRectangle: public CPolygon {
  public:
    int area (void)
      { return (width * height); }
  };
class CTriangle: public CPolygon {
  public:
    int area (void)
      { return (width * height / 2); }
  };
int main33 () {
  CRectangle rect;
  CTriangle trgl;
  CPolygon * ppoly1 = &rect;
  CPolygon * ppoly2 = &trgl;
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  ppoly1->printarea();
  ppoly2->printarea();
  getchar();
  return 0;
}
