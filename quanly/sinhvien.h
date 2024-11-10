#pragma once
#include<string>
using namespace std;

class sinhvien {
public: 
	virtual void input()  = 0;
	virtual void print() const =0;
	virtual void changeFaculty(const string& faculty)=0;
	virtual double GPA() = 0;
};