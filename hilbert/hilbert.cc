#include <iostream>

using namespace std;

void b(int , int);
void c(int , int);
void d(int , int);


void a(int i, int h) {
	if (i <= 0) {
		return;
	}
	d(i-1, h/2);
	cout << '-' << h << ' ' << 0 << ' ' << "rlineto" << endl;
	a(-1, h/2);
	cout << 0 << ' ' << '-' << h << ' ' << "rlineto" << endl;
	a(-1, h/2);
	cout << h << ' ' << 0 << ' ' << "rlineto" << endl;
	b(-1, h/2); 
}

void b(int i, int h) {
	if (i <= 0) {
		return;
	}
	c(i-1, h/2);
	cout << 0 << ' ' << h << ' ' << "rlineto" << endl;
	b(i-1, h/2);
	cout << h << ' ' << 0 << ' ' << "rlineto" << endl;
	b(i-1, h/2);
	cout << 0 << ' ' << '-' << h << ' ' << "rlineto" << endl;
	a(i-1, h/2);
}

void c(int i, int h) {
	if (i <= 0) {
		return;
	}
	b(i-1, h/2);
	cout << h << ' ' << 0 << ' ' << "rlineto" << endl;
	c(-1, h/2);
	cout << 0 << ' ' << h << ' ' << "rlineto" << endl;
	c(-1, h/2);
	cout << '-' << h << ' ' << 0 << ' ' << "rlineto" << endl;
	d(-1, h/2); 
}

void d(int i, int h) {
	if (i <= 0) {
		return;
	}
	a(i-1, h/2);
	cout << 0 << ' ' << '-' << h << ' ' << "rlineto" << endl;
	d(-1, h/2);
	cout << '-' << h << ' ' << 0 << ' ' << "rlineto" << endl;
	d(-1, h/2);
	cout << 0 << ' ' << h << ' ' << "rlineto" << endl;
	c(-1, h/2); 
}


int main() {

	cout << "newpath" << endl;
	// cout << "520 520 moveto" << endl;
	cout << "10 10 moveto" << endl;
	a(11, 128);
	b(2, 128);
	c(5, 128);
	d(9, 128);
	cout << "stroke" << endl;
	cout << "showpage" << endl;

	return 0;
}
