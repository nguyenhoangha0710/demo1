#pragma once

#include<iostream>
#include<math.h>
#include<string>
#include"ChinhQui.h"
#include<vector>
#include"VanBang2.h"

using namespace std;

// khoa co ten, nam thanh lap va danh sach cac sinh vien thuoc khoa do


string chuanhoa(string& name);

class Khoa {
private:
	string nameFaculty;
	int year;
	vector<SVchinhQui>SVCQ;
	vector<VB2>SVVB2;
public:
	Khoa() {
		this->nameFaculty = ""; 
		this->year = 0;
	}
	void input(); 
	void print();
	void printBasic();
	string getName();
	friend string chuanhoa(string& name);
	void push(const SVchinhQui &data);
	void push(const VB2& data);
};

void Khoa::push(const VB2& data) {
	this->SVVB2.push_back(data);
}

void Khoa::push(const SVchinhQui &data) {
	this->SVCQ.push_back(data);
}

string Khoa::getName() {
	return this->nameFaculty;
}

void Khoa::printBasic() {
	cout << "Khoa             : " << this->nameFaculty << endl;
	cout << "Nam thanh lap    : " << this->year << endl;
}

void Khoa::print() {
	if (this->SVCQ.size() == 0&&this->SVVB2.size()==0) {
		cout << "Khoa " << this->nameFaculty << " chua co sinh vien!\n";
	}
	else {
		cout << "Khoa             : " << this->nameFaculty << endl;
		cout << "Nam thanh lap    : " << this->year << endl;
		if (this->SVCQ.size() == 0) {
			cout << "Khoa khong co sinh vien chinh qui\n"; 
		}
		else {
			cout << "\n      DANH SACH SINH VIEN CHINH QUI\n";
			cout << "***************************************************\n";
			for (int i = 0; i < this->SVCQ.size(); i++) {
				this->SVCQ[i].print();
			} 
		}
		if (this->SVVB2.size() == 0) {
			cout << "Khoa khong co sinh vien Van Bang 2\n";
		}
		else {
			cout << "\n       DANH SACH SINH VIEN VAN BANG 2\n";
			cout << "***************************************************\n";
			for (int i = 0; i < this->SVVB2.size(); i++) {
				this->SVVB2[i].print();
			}
		}
	}
	cout << endl;
}

void Khoa::input() {
	cout << "Nhap ten khoa: ";
	getline(cin, this->nameFaculty);
	cout << "Nhap nam thanh lap: ";
	chuanhoa(this->nameFaculty);
	cin >> this->year;
	int n;
	cout << "\nNhap so luong sinh vien chinh qui: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		SVchinhQui x;
		x.input();
		x.changeFaculty(this->nameFaculty);
		this->SVCQ.push_back(x);
		cout << "DA THEM THANH CONG\n";
	}
	cout << "\nNhap so luong sinh vien Van Bang 2: "; 
	cin >> n;
	for (int i = 0; i < n; i++) {
		VB2 x; 
		x.input(); 
		x.changeFaculty(this->nameFaculty); 
		this->SVVB2.push_back(x);
		cout << "DA THEM THANH CONG\n";
	}
}