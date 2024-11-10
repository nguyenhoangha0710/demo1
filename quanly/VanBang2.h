#pragma once



#include<iostream>
#include<string>
#include<math.h>
#include"sinhvien.h"

using namespace std; 

string chuanhoa(string& name); 

class VB2 : public sinhvien{
private:
	string id;
	string name;
	float avrg;
	float theory;
	float practise;
	string faculty;
public: 
	VB2() {
		this->id = ""; 
		this->name = "";
		this->avrg = 0; 
		this->theory = 0;
		this->practise = 0;
		this->faculty = "";
	}
	void input() override;
	void print() const override;
	void changeFaculty(const string& faculty) override; 
	double GPA() override;
	friend string chuanhoa(string& name);
};

double VB2::GPA() {
	return this->avrg * 0.4 + this->theory * 0.3 + this->practise * 0.3;
}

void VB2::changeFaculty(const string& faculty) {
	this->faculty = faculty;
}


void VB2::print() const{
	cout << "\nMSSV             : " << this->id;
	cout << "\nHo va ten        : " << name;
	cout << "\nDiem trung binh  : " << avrg;
	cout << "\nDiem ly thuyet   : " << theory;
	cout << "\nDiem thuc hanh   : " << practise;
	cout << "\nKhoa             : " << faculty;
	cout << "\n-------------------------------------------\n";
}

void VB2::input(){
	cout << "nhap ma so sinh vien: ";
	cin >> id;
	cin.ignore();
	cout << "Nhap ten sinh vien: ";
	getline(cin, name);
	chuanhoa(name);
	cout << "Nhap diem trung binh: ";
	cin >> avrg;
	cout << "Nhap diem ly thuyet: ";
	cin >> theory;
	cout << "Nhap diem thuc hanh: "; 
	cin >> practise;
}