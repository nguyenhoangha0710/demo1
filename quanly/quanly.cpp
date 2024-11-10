#include<iostream>
#include<math.h>
#include<sstream>
#include<cctype>
#include<algorithm>
#include"khoa.h"
#include"quanly.h"
using namespace std;

string chuanhoa(string& name); 
void menu();

int main() {
	manage quanli;
	quanli.input();
	while (true) {
		system("cls");
		int program; 
		menu(); 
		cout << "Nhap chuong trinh ban  muon thuc hien: "; 
		cin >> program; 
		switch (program) {
		case 1: {
			quanli.print();
			break;
		}
		case 2: {
			string findFaculty; 
			cin.ignore();
			cout << "Nhap ten khoa ban muon xem thong tin: "; 
			getline(cin, findFaculty);
			quanli.printSVFaculty(findFaculty);
			break;
		}
		case 3: {
			quanli.inputSV();
			break;
		}
		case 4: {
			quanli.inputFaculty();
			break;
		}
		}
		int stop;
		cout << endl;
		cout << "Nhap 1 de tiep tuc\n"; 
		cout << "Nhap 0 de dung lai\n"; 
		cout << "Nhap: "; 
		cin >> stop;
		if (stop != 1) {
			system("cls");
			cout << "                   goobye!!!!\n";
			break;
		}
	}
}