#include <iostream>
#include <cstdlib>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
    friend ostream& operator<<(ostream& os, const Point& pos);
    friend ostream& operator<<(ostream& os, const Point* pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}

ostream& operator<<(ostream& os, const Point* pos)
{
    os << '[' << pos->xpos << ", " << pos->ypos << ']' << endl;
    return os;
}

typedef Point* POINT_PTR;

class BoundCheckIntArray
{
private:
    int* arr;
    int arrlen;

    BoundCheckIntArray(const BoundCheckIntArray& arr) { }
    BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) { }

public:
    BoundCheckIntArray(int len) : arrlen(len)
    {
        arr = new int[len];
    }

    int& operator[] (int idx)
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }

    int& operator[] (int idx) const
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }

    int GetArrLen() const { return arrlen; }
    ~BoundCheckIntArray() { delete[]arr; }
};

typedef BoundCheckIntArray* BoundCheckIntArrayPtr; //배열을 가리키는 포인터

class BoundCheck2dIntArray
{
private:
    BoundCheckIntArray** arr;
    int arrlen;

    BoundCheck2dIntArray(const BoundCheck2dIntArray& arr) {}
    BoundCheck2dIntArray& operator=(const BoundCheck2dIntArray& arr) { }
public:
    BoundCheck2dIntArray(int col, int row)
        :arrlen(col)
    {
        arr = new BoundCheckIntArrayPtr[col]; //동적할당
        for (int i = 0; i < col; i++)         //열마다 행 생성
            arr[i] = new BoundCheckIntArray(row);
    }

    BoundCheckIntArray& operator[](int idx)
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return *(arr[idx]);
    }

    ~BoundCheck2dIntArray()
    {
        for (int i = 0; i < arrlen; i++)
            delete arr[i];
        delete[]arr;
    }
};

int main(void)
{
    BoundCheck2dIntArray arr2d(3, 4);

    for (int n = 0; n < 3; n++) {
        for (int m = 0; m < 4; m++) {
            arr2d[n][m] = n + m;
        }
    }

    for (int n = 0; n < 3; n++) {
        for (int m = 0; m < 4; m++) {
            cout << arr2d[n][m] << ' ';
        }
        cout << endl;
    }

    return 0;
}