#pragma once


#include<iostream>
#include<string>
#include<math.h>
#include"sinhvien.h"

using namespace std; 

string chuanhoa(string &name);

class SVchinhQui :public sinhvien{
private:
	string id;
	string name; 
	float avrg; 
	float thesis;
	string faculty;
public:
	SVchinhQui() {
		this->id = ""; 
		this->name = ""; 
		this->avrg = 0;
		this->thesis = 0;
		this->faculty = ""; 
	}
	void input() override;
	void print() const override;
	void changeFaculty(const string &faculty) override;
	double GPA() override; 
	friend string chuanhoa(string &name);
};

double SVchinhQui::GPA() {
	return this->avrg * 0.8 + this->thesis * 0.2;
}

void SVchinhQui::changeFaculty(const string& faculty) {
	this->faculty = faculty;
}

void SVchinhQui::print() const{
	cout << "\nMSSV             : " << this->id;
	cout << "\nHo va ten        : " << name;
	cout << "\nDiem trung binh  : " << avrg;
	cout << "\nDiem khoa luan   : " << thesis;
	cout << "\nKhoa             : " << faculty;
	cout << "\n-------------------------------------------\n";
}

void SVchinhQui::input() {
	cout << "nhap ma so sinh vien: "; 
	cin >> id;
	cin.ignore(); 
	cout << "Nhap ten sinh vien: ";
	getline(cin, name); 
	chuanhoa(name);
	cout << "Nhap diem trung binh: "; 
	cin >> avrg; 
	cout << "Nhap diem khoa luan: "; 
	cin >> thesis; 
}

