#include<iostream>
#include<math.h>
#include<sstream>
#include<cctype>
#include<algorithm>

using namespace std;
string chuanhoa(string& name) {
	stringstream ss(name);
	string word, result;
	while (ss >> word) {
		word[0] = toupper(word[0]);
		for (int i = 1; i < word.size(); i++) {
			word[i] = tolower(word[i]);
		}
		result = result + word;
		result += " ";
	}
	result.pop_back();
	name = result;
	return result;
}
void menu() {
	cout << "\n------------MENU-------------\n";
	cout << "1. Xuat danh sach cac khoa\n";
	cout << "2. Tim khoa va xem thong tin cua sinh vien khoa\n";
	cout << "3. Them sinh vien vao server\n";
	cout << "4. Them khoa vao server\n";
}