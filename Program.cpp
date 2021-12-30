#include <iostream>
#include <vector>
#include <conio.h>

#define Content_Length 1024

using namespace std;

struct Data {
	int id;
	char content[Content_Length] = { 0 };
};

class Hash_ {
public:
	vector<Data> data;

	Hash_() {
		Data a;
		a.id = 0;
		for (int i = 0; i < 1024; i++) {
			a.content[i] = 0;
		}
		data.push_back(a);
	}

	void add_Hash(string a) {
		Data* data_ = new Data;
		Hashing(*data_, a);
		delete data_;
	}

	void show_all() {
		vector<Data>::iterator it;
		for (it = data.begin() + 1; it != data.end(); it++) {
			cout << "ID : " << it->id << " ���� : " << it->content << endl;
		}
	}

private:
	void Hashing(Data a, const string b) {
		int* c = new int;
		*c = 0;
		for (int i = 0; i < b.length(); i++) {
			*c += b[i];
			a.content[i] = b[i];
		}
		a.id = *c;
		delete c;
		vector<Data>::iterator it;
		Data d = { 0 };
		Data e = { 0 };
		bool hashbigger = false;
		for (it = data.begin() + 1; it != data.end(); it++) { // ������� �ֱ�
			if (a.id < it->id) {
				if (hashbigger == false || a.id == it->id) {
					d = *it;
					*it = a;
					hashbigger = true;
				}
				else {
					e = *it;
					*it = d;
					d = e;
				}
			}
		}
		if (hashbigger != true) data.push_back(a);
		else data.push_back(e);
		return;
	}
};

int main() {
	Hash_ A;
	while (true) {
		cout << "�ֱ� : 1, ���� : 2 ";
		int* a = new int;
		cin >> *a;
		if (*a == 1 && !cin.fail()) {
			system("cls");
			cout << "���� ���� : ";
			string b;
			cin >> b;
			system("cls");
			A.add_Hash(b);
			cin.clear();
			cin.ignore(256, '\n');
			b = { 0 };
			delete a;
		}
		else if(*a == 2 && !cin.fail()) {
			system("cls");
			delete a;
			cin.clear();
			cin.ignore(256, '\n');
			A.show_all();
			cout << "Ű���� �Է� �� ���ư���";
			char c;
			c = _getch();
			system("cls");
		}
		else {
			cout << "�� �� �Է��ϼ̽��ϴ�.";
			break;
		}
	}
}