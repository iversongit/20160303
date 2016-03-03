 ///
 /// @file    friend1.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-03 03:20:43
 ///
#include <math.h> 
#include <iostream>

using std::endl;
using std::cout;

class Point{
	friend float len(const Point &lhs,const Point &rhs);
	public:
		Point(int,int);
		~Point();
		void print();
	private:
		int _x;
		int _y;
};

Point::Point(int x,int y)
:_x(x)
,_y(y)
{
	cout<<"Point(int,int)"<<endl;
}

Point::~Point(){
	cout<<"~Point()"<<endl;
}

float len(const Point &lhs,const Point &rhs){
	return sqrt((lhs._x - rhs._x)*(lhs._x - rhs._x) + (lhs._y - rhs._y)*(lhs._y - rhs._y));
}

void Point::print(){
	cout<<"("<<_x<<" , "<<_y<<")"<<endl;
}

int main(void){
	Point p1(2,2);
	Point p2(4,4);
	p1.print();
	p2.print();
	float length = len(p1,p2);
	cout<<"the length from p1 to p2: "<<length<<endl;
	return 0;
}
