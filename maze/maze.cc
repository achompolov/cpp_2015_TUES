#include <iostream>
#include <vector>
using namespace std;

enum Dir {
	LEFT = 1, //0001
	RIGHT = 1 << 1, //0010
	UP = 1 << 2, //0100
	DOWN = 1 << 3, //1000
};

class Cell {
	friend class Board;
	int row_;
	int col_;
	bool visited_;
	unsigned int walls_;

public:
	Cell(int row=-1, int col=-1) 
	: row_(row), col_(col), visited_(false),
	  walls_(LEFT | RIGHT | UP | DOWN)
	{} 

	bool visited() const {
		return visited_;
	}

	bool has_wall(Dir dir) const {
		return walls_ & dir;
	}

	void drill(Dir dir) {
		// 0010
		// ~
		//1111
		//&
		//1101		
		walls_ &= ~dir;
	}	

	void draw(int step=20) const {
		cout << col_*step << " " << row_*step << " " << " moveto" << endl;
		cout << step << " " << 0 << " " << (has_wall(DOWN)?"rlineto":"rmoveto") << endl;
		cout << 0 << " " << step << " " << (has_wall(RIGHT)?"rlineto":"rmoveto") << endl;
		cout << -step << " " << 0 << " " << (has_wall(UP)?"rlineto":"rmoveto") << endl;
		cout << 0 << -step << " " << (has_wall(LEFT)?"rlineto":"rmoveto") << endl;
	}


};

class Board {
	friend class Cell;
	int rows_;
	int cols_;
	vector<Cell> cells_;

public:
	Board(int rows, int cols)
	: rows_(rows), cols_(cols) 
	{
		for(int i=0; i<rows_; ++i) {
			for(int j=0; j<cols_; ++j) {
				cells_.push_back(Cell(i, j));
			}
		}
	}

	Cell& at(int i, int j) {
		int index = i*cols_ + j;
		return cells_[index];	
	}

	const Cell& at(int i, int j) const {
		int index = i*cols_ + j;
		return cells_[index];
	}

	void draw() const {
		cout << "newpath" << endl;
		for (vector<Cell>::const_iterator it = cells_.begin(); it!=cells_.end(); ++it) {
			(*it).draw();
		}
	}

};


int main() {
	
	/*
		Cell c1(1,1);
		cout << c1.visited() << endl;
		cout << c1.has_wall(UP) << endl;
		cout << c1.has_wall(LEFT) << endl;
		c1.drill(LEFT);
		cout << c1.has_wall(UP) << endl;
		cout << c1.has_wall(LEFT) << endl;
	*/

	Board b(5,5);
	b.draw();


	return 0;
}











