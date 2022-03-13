#include <iostream>
#include <math.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

using namespace std;

enum BOOL { FALSE, TRUE };

class GeneralShape {
    public:
        GeneralShape(){};
        ~GeneralShape(){};
        virtual long GetArea() = 0;
        virtual long GetPerim()= 0;
        virtual void Draw() = 0;
};

void GeneralShape::Draw() {
    cout << "drawing mechanism!" << endl;
}

class Circle : public GeneralShape {
    public:
        Circle(int radius):itsRadius(radius), itsCircumference(2*M_PI*radius){}
        ~Circle(){}
        virtual long GetArea();
        virtual long GetPerim();
        virtual void Draw();

    private:
        int itsRadius;
        int itsCircumference;
};

long Circle::GetArea() {
    return M_PI * itsRadius * itsRadius;
}

long Circle::GetPerim() {
    return itsCircumference;
}

void Circle::Draw() {
    cout << "Drawing circle with r=" << itsRadius << ", area=" << GetArea() << ", perim=" << GetPerim() << endl;
}

class Rectangle : public GeneralShape {
    public:
        Rectangle(int len, int width):
        itsLength(len), itsWidth(width){}
        ~Rectangle(){}
        virtual int GetLength() { return itsLength; }
        virtual int GetWidth() { return itsWidth; }
        virtual long GetArea();
        virtual long GetPerim();
        virtual void Draw();

    private:
        int itsWidth;
        int itsLength;
};

long Rectangle::GetArea() {
    return itsLength * itsWidth;
}

long Rectangle::GetPerim() {
    return (itsLength + itsWidth) * 2;
}

void Rectangle::Draw() {
    cout << "Drawing rectangle with W=" << itsWidth << ", H=" << itsLength << ", area=" << GetArea() << ", perim=" << GetPerim() << endl;
}

class Square : public Rectangle {
    public:
        Square(int len);
        Square(int len, int width);
        ~Square(){}
        long GetPerim() {return 4 * GetLength();}
        virtual void Draw();
};

Square::Square(int len): Rectangle(len,len) {}

Square::Square(int len, int width): Rectangle(len,width) {
    if (GetLength() != GetWidth()) {
        cout << "Error, not a square... a Rectangle??\n";
    }
}

void Square::Draw() {
    cout << "Drawing square with L=" << GetLength() << ", area=" << GetArea() << ", perim=" << GetPerim() << endl;
}

void shapeMenu(GeneralShape& shape) {
    bool stop {false};
    int choice {};
    while (1) {
        cout << "(1)Draw (2)Get Perimeter (3)Get Area (0)Back: ";
        cin >> choice;
        switch (choice) {
            case 1:
                shape.Draw();
                break;
            case 2:
                cout << shape.GetPerim() << endl;
                break;
            case 3:
                cout << shape.GetArea() << endl;
                break;
            default:
                stop = true;
        }
        if (stop) break;
        cout << endl;
    }
}

void circleMenu() {
    int radius;
    cout << "Radius? ";
    cin >> radius;
    Circle c {radius};
    shapeMenu(c);
}

void rectMenu() {
    int width, height;
    cout << "Width? ";
    cin >> width;
    cout << "Height? ";
    cin >> height;
    Rectangle r {height, width};
    shapeMenu(r);
}

void squareMenu() {
    int length;
    cout << "Side Length? ";
    cin >> length;
    Square s {length};
    shapeMenu(s);
}

int main() {
    int choice;
    BOOL quit = FALSE;
    GeneralShape *sp;
    while (1) {
        cout << "(1)Circle (2)Rectangle (3)Square (0)Quit: ";
        cin >> choice;
        switch (choice) {
            case 1:
                circleMenu();
                break;
            case 2:
                rectMenu();
                break;
            case 3:
                squareMenu();
                break;
            default: quit = TRUE;
            break;
        }
        if (quit) break;
        cout << endl;
    }
    return 0;
}
