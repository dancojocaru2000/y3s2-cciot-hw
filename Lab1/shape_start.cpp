#include <iostream>
#include <math.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

using namespace std;

enum BOOL { FALSE, TRUE };

class GeneralShape
{
    public:
        GeneralShape(){};
        ~GeneralShape(){};
        virtual long GetArea() = 0;
        virtual long GetPerim()= 0;
        virtual void Draw() = 0;
};

void GeneralShape::Draw()
{
    cout << "drawing mechanism!" << endl;
}

class Circle : public GeneralShape
{
    public:
        Circle(int radius):itsRadius(radius){}
        ~Circle(){}

    private:
        int itsRadius;
        int itsCircumference;
};

class Rectangle : public GeneralShape
{
    public:
        Rectangle(int len, int width):
        itsLength(len), itsWidth(width){}
        ~Rectangle(){}
        virtual int GetLength() { return itsLength; }
        virtual int GetWidth() { return itsWidth; }

    private:
        int itsWidth;
        int itsLength;
};

class Square : public Rectangle
{
    public:
        Square(int len);
        Square(int len, int width);
        ~Square(){}
        long GetPerim() {return 4 * GetLength();}
};

Square::Square(int len):
Rectangle(len,len)
{}

Square::Square(int len, int width):
Rectangle(len,width)
{
 if (GetLength() != GetWidth())
  cout << "Error, not a square... a Rectangle??\n";
}

int main()
{
 int choice;
 BOOL quit = FALSE;
 GeneralShape *sp;

    while (1)
    {
        cout << "(1)Circle (2)Rectangle (3)Square (0)Quit: ";
        cin >> choice;

        switch (choice)
        {
            default: quit = TRUE;
            break;
        }

    if (quit) break;

    cout << endl;
    }

 return 0;
}
