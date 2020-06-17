// Features.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

// template function
template<typename T>
T sqr(T v)
{
	return v * v;
}

// template class
template<typename T>
class Number
{
public:
	Number() {}
	Number(T number) { this->number = number; }

	void Set(T number) { this->number = number; }
	T Get() { return number; }

protected:
	T number;	
};

template<typename T>
class Point
{
public:
	Point() {}
	Point(T x, T y) : x(x), y(y) {}

	friend Point operator + (Point p1, Point p2)
	{
		Point point;
		point.x = p1.x + p2.x;
		point.y = p1.y + p2.y;

		return point;
	}

	Point operator + (T v)
	{
		Point point;
		point.x = x + v;
		point.y = y + v;

		return point;
	}

	friend ostream& operator << (ostream& stream, Point point)
	{
		cout << point.x << " " << point.y << endl;

		return stream;
	}

protected:
	T x;
	T y;
};

int main()
{
	Point<float> point1(3.4f, 7.5f);
	Point<float> point2(6.1f, 5.2f);
	
	Point<float> point3 = point1 + point2;
	cout << point3 << endl;

	Number<float> n(5.7f);
	cout << n.Get() << endl;

	cout << sqr<int>(5) << endl;
	cout << sqr<float>(6.5f) << endl;
	cout << sqr<double>(7.8) << endl;

	int na[4] = { 1, 2, 3, 4 };
	//na[5] = 3;
	// [int, int, int, int, ???, ??? = 3]

	vector<int> numbers = { 5, 6, 7 };
	numbers.push_back(9);

	for (size_t i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;

	for (int i : numbers)
	{
		cout << i << " ";
	}
	cout << endl;

	for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++)
	{
		if (*iter == 6)
		{
			iter = numbers.erase(iter);
		}
		cout << *iter << " ";
	}
	cout << endl;

	for (int i : numbers)
	{
		cout << i << " ";
	}
	cout << endl;
}

