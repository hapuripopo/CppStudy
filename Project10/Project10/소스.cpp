#include <iostream>

using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0)
		: xpos(x), ypos(y)
	{ }
	Point(const Point& ref)
	{
		xpos = ref.xpos;
		ypos = ref.ypos;
	}
	void ShowPosition() const
	{
		cout << "[" << xpos << "," << ypos << "]" << endl;
	}

	Point operator+(const Point& ref) const
	{
		Point result(xpos + ref.xpos, ypos + ref.ypos);
		return result;
	}

	Point operator-(const Point& ref) const
	{
		Point result (xpos - ref.xpos, ypos - ref.ypos);
		return result;
	}

	Point& operator+=(const Point& ref)
	{
		xpos += ref.xpos;
		ypos += ref.ypos;
		return *this;
	}

	Point& operator-=(const Point& ref)
	{
		xpos -= ref.xpos;
		ypos -= ref.ypos;
		return *this;
	}

	bool operator==(const Point& ref) const
	{
		if (xpos == ref.xpos && ypos == ref.ypos)
			return true;
		else
			return false;
	}

	bool operator!=(const Point& ref) const
	{
		if (*this == ref)
			return false;
		else
			return true;
	}

	Point& operator++()
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}

	Point& operator--()
	{
		xpos -= 1;
		ypos -= 1;
		return *this;
	}

	Point& operator-()
	{
		xpos = -xpos;
		ypos = -ypos;
		return *this;
	}

	friend Point operator~(const Point& ref);
	friend ostream& operator<<(ostream&, const Point&);
	friend istream& operator>>(istream&, Point&);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << "[" << pos.xpos << "," << pos.ypos << "]" << endl;
	return os;
}

istream& operator>>(istream& is, Point& pos)
{
	is >> pos.xpos >> pos.ypos;
	return is;
}

Point operator~(const Point& ref)
{
	Point pos(ref.ypos, ref.xpos);
	return pos;
}

int main(void)
{
	Point pos1;
	cout << "x, y 좌표 순으로 입력:";
	cin >> pos1;
	cout << pos1;

	Point pos2;
	cout << "x, y 좌표 순으로 입력:";
	cin >> pos2;
	cout << pos2;

	return 0;
}
