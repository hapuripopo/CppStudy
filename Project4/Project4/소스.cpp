#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;

public:
	Point(int x, int y) //��ǥ ������
	{
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const //��ǥ ���
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
	Circle(int x, int y, int r) //���� ������
	{
		point = new Point(x, y);
		this->r = r;
	}
	void ShowCircleInfo() const //���� ���� ���
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
	Ring(int x1, int y1, int r1, int x2, int y2, int r2) //ring�� ������
	{
		cir1 = new Circle(x1, y1, r1);
		cir2 = new Circle(x2, y2, r2);
	}
	void ShowRingInfo() const //ring�� ���� ���
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