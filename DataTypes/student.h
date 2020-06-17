#pragma once
#include <string>

class Student
{
public:
	Student()
	{
		name = "invalid";
		age = 0;
		gpa = 0.0f;
	}

	Student(std::string name_, int age_ = 20, float gpa_ = 4.0f)
	{
		name = name_;
		age = age_;
		gpa = gpa_;
	}

	void SetAge(int age_) { age = age_; }
	int GetAge() { return age; }

	std::string GetName() { return name; }
	void SetName(const std::string& name_) { name = name_; }

	//student.SetName()
	// main.cpp
	//student.SetName(std::string name("Cody"));

	void Write();
	void Read();

public:
	std::string name;
	int age;
	float gpa;
};
