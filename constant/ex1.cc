#include <iostream>
using namespace std;


class Point {
	double x_, y_;
public:
	Point (double x, double y) {
		x_ = x;
		y_ = y;
	}

	double get_x() const {
		return x_;
	}
	double get_y () const {
		return y_;	
	}

	void set_x(double x) {
		x_ = x;
	}


	void print() const {
		cout << '(' << x_ << ',' << y_ << ')' << endl;
	}
};	



int main() {

	Point p1(1, 2);
	const Point origin(0, 0);	

	p1.print();
	origin.print();
	origin.get_x();

	//origin.set_x(1.0);

	p1.set_x(42.42);
	p1.print();

	return 0;
}


























