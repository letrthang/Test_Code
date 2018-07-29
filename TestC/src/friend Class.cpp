// friend class
#include <iostream.h>
int gDouble = 2;  //global variant

class CSquare;
class CRectangle {
    int width, height;
  public:
    int area (void)
      {return (width * height*gDouble);}
    void convert (CSquare a);
};
class CSquare {
  private:
    int side;
  public:
    void set_side (int a)
      {side=a;}
    friend class CRectangle;
};
void CRectangle::convert (CSquare a) {
  width = a.side;
  height = a.side;
}

int main10 () {
  CSquare sqr;
  CRectangle rect;
  sqr.set_side(4);
  rect.convert(sqr);
  cout << rect.area();
  getchar();
  return 0;
}

