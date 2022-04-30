#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << "[" << xpos << "," << ypos << "]" << endl;
	}
	void operator=(Point& ref)
	{
		xpos = ref.xpos;
		ypos = ref.ypos;
	}
};

template <class T>
class SmartPtr
{
private:
	T* ptr;
public:
	SmartPtr(T* _ptr)
		:ptr(_ptr)
	{ }
	Point& operator*() const { return *ptr; }
	Point* operator->() const { return ptr; }
	~SmartPtr() { delete ptr; }
};

int main()
{
	SmartPtr<Point> sptr1(new Point(1, 2));
	SmartPtr<Point> sptr2(new Point(3, 4));
	sptr1->ShowPosition();
	sptr2->ShowPosition();

	return 0;
}