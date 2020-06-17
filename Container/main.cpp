// Container.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

//typedef float currency;
using currency_t = double;

class Runner
{
public:
	Runner() : name{}, time{ 0 } {}
	Runner(const string& name, float time) : name{ name }, time{ time } {}

	float GetTime() const { return time; }

	friend bool operator < (const Runner& runner1, const Runner& runner2)
	{
		return (runner1.GetTime() < runner2.time);
	}

	friend ostream& operator << (ostream& stream, Runner runner)
	{
		stream << runner.name << " " << runner.time << endl;
		return stream;
	}

	friend bool operator == (const Runner& runner, const string& name)
	{
		return (runner.name == name);
	}

	friend bool operator == (const Runner& runner, float time)
	{
		return (runner.time == time);
	}

protected:
	string name;
	float time;
};

int main()
{
	currency_t dollars = 4.5;
	auto i = true;

	int n[] = { 1, 2, 3 ,4, 5 };
	cout << n << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << &n[i] << " " << n[i] << endl;
	}

	array<float, 5> numbers = { 3.4f, 1.7f, 23.4f, 6.7f, 12.8f };
	cout << numbers.size() << endl;
	cout << numbers[2] << endl;
	cout << numbers.at(0) << endl;
	cout << numbers.front() << endl;

	for (size_t i = 0; i < numbers.size(); i++)
	{
		cout << numbers.at(i) << " ";
	}
	cout << endl;

	list<string> strings = { "Hello", "my", "name", "is", "Raymond" };
	auto iter = strings.begin();
	strings.insert(iter, "Students!");
	strings.push_back("Maple");
	for (string str : strings)
	{
		cout << str << " ";
	}
	cout << endl;
	
	vector<int> nv = { 5, 12, 6, 43, 23 };
	auto iiter = find(nv.begin(), nv.end(), 6);
	iiter = nv.erase(iiter);
	cout << *iiter << endl;

	for (auto iter = nv.begin(); iter != nv.end(); iter++)
	{
		//if (*iter == 6) {}
		cout << *iter << " ";
	}
	cout << endl;

	//reverse(nv.begin(), nv.end());
	sort(nv.begin(), nv.end()); // <
	for (int i : nv)
	{
		cout << i << " ";
	}
	cout << endl;
	// iterator(* -> value)

	vector<Runner> runners = { {"felix", 5.6f}, {"bolt", 4.8f}, {"johnson", 5.2f} };
	sort(runners.begin(), runners.end()); // <
	auto riter = find(runners.begin(), runners.end(), 5.6f); // ==
	cout << *riter << endl;
	for (Runner runner : runners)
	{
		cout << runner;
	}
}

