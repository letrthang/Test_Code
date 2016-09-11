#include <iostream>
#include <vector>
#include <iomanip>

class Matrix 
{
    std::vector<int> data;
    unsigned n;

  public:
      Matrix(unsigned n, unsigned m):n(n),data(n*m,0){
      }

      int &element(unsigned row, unsigned col)
      {
          return data[row*n+col];
      }

      class Nested 
      {
          Matrix &Ob;
          unsigned row;
        public :

          Nested(Matrix &Ob, unsigned row):Ob(Ob),row(row){
          }

          int &operator [] (unsigned col)
          {
              return Ob.element(row,col);
          }
      };

    Nested operator[](unsigned row)
    {
        return Nested(*this,row);
    }
};

int main18()
{
    Matrix M(3,4);
    for(int y = -3; y < 4; y++)
    {
        for( int x = -3; x < 3; ++x)
            M[y][x]=x*y;
    }
    for(int y = -3; y < 4; y++)
    {
        for(int x = -3; x < 3; x++)
            std::cout << M[y][x] << std::setw(4);
        std::cout << std::endl << std::endl;
    }
    //getchar();
    return 0;
}
