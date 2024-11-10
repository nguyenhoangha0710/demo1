#pragma once

#include<iostream>
#include"khoa.h"
#include"ChinhQui.h"
#include<vector>


// manage thi gom nhieu khoa

class manage {
private:
	string name;
	vector<Khoa>khoa;
public: 
	manage() {
		this->name = "";
	}
	manage(string name) {
		this->name = name;
	}
	void input(); 
	void print();
	void inputSV();
	void inputFaculty();
	void printSVFaculty(const string& name);
};

void manage::inputFaculty() {
	cin.ignore();
	cout << "\nNhap thong tin khoa ban muon them\n"; 
	Khoa x;
	x.input(); 
	for (int i = 0; i < this->khoa.size(); i++) {
		if (this->khoa[i].getName() == x.getName()) {
			cout << "\nKhoa da co trong danh sach\n";
			return;
		}
	}
	this->khoa.push_back(x); 
	cout << "\nDA THEM THANH CONG\n\n";
}

void manage::printSVFaculty(const string& name) {
	string tmp = name;
	chuanhoa(tmp);
	if (this->khoa.size() == 0) {
		cout << "Chua co khoa duoc thanh lap!\n";
	}
	else {
		for (int i = 0; i < this->khoa.size(); i++) {
			if (this->khoa[i].getName() == tmp) {
				this->khoa[i].print();
				return;
			}
		}
		cout << "\nKhong tim thay khoa trong danh sach\n";
	}
}

void manage::inputSV() {
	int degree; 
	cout << "Nhap he dao tao cua sinh vien ban muon them:[1: chinh qui / 2: Van Bang 2] \n";
	cout << "Nhap: "; 
	cin >> degree;
	sinhvien* data=nullptr;
	while (degree <= 0 || degree > 2) {
		cout << "Loi! Vui long nhap lai\n"; 
		cout << "Nhap: "; 
		cin >> degree;
	}
	if (degree == 1) {
		data = new SVchinhQui();
	}
	if (degree == 2) {
		data = new VB2(); 
	}
	cout << "\nNhap thong tin sinh vien ban muon them\n";
	data->input(); 
	if (this->khoa.size() == 0) {
		cout << "Chua co khoa duoc thanh lap!\n";
	}
	else {
		cout << "\nDANH SACH KHOA\n";
		for (int i = 0; i < this->khoa.size(); i++) {
			cout << i+1 << " : ";
			cout << this->khoa[i].getName()<<endl;
		}
		int choice; 
		cout << "nhap khoa ban muon them: ";
		cin >> choice; 
		while (choice <= 0 || choice > this->khoa.size()) {
			cout << "Loi! Vui long nhap lai!\n";
			cout << "nhap khoa ban muon them: ";
			cin >> choice; 
		}
		data->changeFaculty(this->khoa[choice-1].getName());
		if (degree == 1) {
			this->khoa[choice - 1].push(*dynamic_cast<SVchinhQui*>(data));
		}
		else if(degree==2){
			this->khoa[choice - 1].push(*dynamic_cast<VB2*>(data));
		}
	}
	delete data;
}

void manage::print() {
	cout << this->name<<endl; 
	if (this->khoa.size() == 0) {
		cout << "\nChua co khoa duoc thanh lap!\n\n"; 
	}
	else {
		cout << "\n        DANH SACH KHOA\n"; 
		cout << "******************************************\n";
		for (int i = 0; i < this->khoa.size(); i++) {
			this->khoa[i].printBasic();
			cout << "-----------------------------------------\n";
		}
	}
	cout << endl;
}

void manage::input() {
	cout << "Nhap ten phan mem quan ly: "; 
	getline(cin, this->name); 
	cout << "Nhap so luong khoa: "; 
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin.ignore();
		Khoa x;
		x.input();
		this->khoa.push_back(x);
		cout << "DA THEM THANH CONG\n\n"; 
	}
}