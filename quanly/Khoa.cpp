#include<iostream>
#include<math.h>
#include<string>
using namespace std;

class Khoa {
private:
	string name;
	int year;
public: 
	Khoa() {
		this->name = "";
		this->year = 0;
	}
	void input() {
		getline(cin, this -> name);
		cin >> this->year;
	}
	void print() {
		cout << "Khoa: " << this->name << endl;
		cout << "Nam thanh lap: " << this->year << endl;
	}
};