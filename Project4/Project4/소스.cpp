#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;

public:
	Point(int x, int y) //좌표 생성자
	{
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const //좌표 출력
	{
		cout << "[" << xpos << ',' << ypos << "]" << endl;
	}
};

class Circle
{
private:
	Point* point;
	int r;

public:
	Circle(int x, int y, int r) //원의 생성자
	{
		point = new Point(x, y);
		this->r = r;
	}
	void ShowCircleInfo() const //원의 정보 출력
	{
		cout << "radius: " << r << endl;
		point->ShowPointInfo();
	}
};

class Ring
{
private:
	Circle* cir1;
	Circle* cir2;

public:
	Ring(int x1, int y1, int r1, int x2, int y2, int r2) //ring의 생성자
	{
		cir1 = new Circle(x1, y1, r1);
		cir2 = new Circle(x2, y2, r2);
	}
	void ShowRingInfo() const //ring의 정보 출력
	{
		cout << "Inner Circle Info" << endl;
		cir1->ShowCircleInfo();
		cout << "Outter Circle Info" << endl;
		cir2->ShowCircleInfo();
	}
};

//int main(void)
//{
//	Ring* ring = new Ring(1, 1, 4, 2, 2, 9);
//	ring->ShowRingInfo();
//	return 0;
//}