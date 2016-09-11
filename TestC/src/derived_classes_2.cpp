// derived classes
/*
ex: class Dericed: protected Base {...}
Protected inheritance:
          
-------------------------------------------------------------------------------------------------          
Base access specifier |	Derived access specifier |	Derived class access? |	Outside access?(Other calsses)
-------------------------------------------------------------------------------------------------
Public 	              |  Protected 	             |   Yes 	              |  No
-------------------------------------------------------------------------------------------------
Private 	          |  Private 	             |   No 	              |  No
-------------------------------------------------------------------------------------------------
Protected 	          |  Protected 	             |   Yes 	              |  No
-------------------------------------------------------------------------------------------------
*/

#include <iostream.h>

class CRectangle; // su dung truoc trong class CPlygon
class CTriangle;  // su dung truoc trong class CPlygon

class CPolygon {     
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b;};
      // ko the truy xuat "set_values" tu ben ngoai lop, nen can
      // dung mot ham friend la "set_to_value" de truy xuat set_values
       friend void set_to_value(int a, int b, CRectangle &c, CTriangle &d);     
  };
  
  
class CRectangle: protected CPolygon {//muc do bao ve toi thieu la protected, tuc
  public:                             //ben ngoai nhin vao cac thanh vien inherited
    int area (void)                   //cua CRectangle, se thay muc do bao ve toi 
      { return (width * height); }    //thieu la protected hoac private.
  };
class CTriangle: protected CPolygon {
  public:
    int area (void)
      { return (width * height / 2); }
  };

void set_to_value (int a, int b, CRectangle &c, CTriangle &d)
     {      
      c.set_values(a,b);
      d.set_values(a,b);
      cout << c.width <<endl;
      cout << c.height <<endl;
      cout << d.width <<endl;
      cout << d.height <<endl;
      }
  
int main7 () {
  
  CRectangle rect;
  CTriangle trgl;
  set_to_value(4,5,rect,trgl);
  //rect.set_values (4,5);
  //trgl.set_values (4,5);
  cout << rect.area() << endl;
  cout << trgl.area() << endl;
  getchar();
  return 0;
}
