#include <iostream>
using namespace std;

class Point {
	double x_, y_;
	static unsigned long count_;
	static unsigned long live_;
public:
	Point(double x=0.0, double y=0.0)
	: x_(x), y_(y)
	{
		count_++;
		live_++;
	}
	
	~Point() {
		live_--;
	}
	
	static unsigned long get_count() {
		return count_;
	}
	static unsigned long get_live() {
		return live_;
	}

};

unsigned long Point::count_ = 0;
unsigned long Point::live_ = 0;

int main() {
	cout << "count= " << Point::get_count() << endl;
	cout << "live= " << Point::get_live() << endl;
	Point p1, p2;

	cout << "count= " << Point::get_count() << endl;
	cout << "live= " << Point::get_live() << endl;

	{
		Point p1, p2;
		cout << "count= " << Point::get_count() << endl;
		cout << "live= " << Point::get_live() << endl;
	}

	cout << "count= " << Point::get_count() << endl;
	cout << "live= " << Point::get_live() << endl;

	return 0;
}
