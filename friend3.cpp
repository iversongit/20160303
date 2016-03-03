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

	friend class Line;  //将一个类作为另一个类的友元
	public:
		Point(int,int);
		~Point();
		void print();
	private:
		int _x;
		int _y;
};

class Line{
	public:
		float len(const Point &lhs,const Point &rhs);
		void setPoint(Point &p,int x,int y);
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

float Line::len(const Point &lhs,const Point &rhs){
	return sqrt((lhs._x - rhs._x)*(lhs._x - rhs._x) + (lhs._y - rhs._y)*(lhs._y - rhs._y));
}

void Line::setPoint(Point &p,int x,int y){
	p._x = x;
	p._y = y;
}
void Point::print(){
	cout<<"("<<_x<<" , "<<_y<<")"<<endl;
}

int main(void){
	Point p1(2,2);
	Point p2(4,4);
	p1.print();
	p2.print();
	Line line;
	float length = line.len(p1,p2);
	cout<<"the length from p1 to p2: "<<length<<endl;
	line.setPoint(p1,8,8);
	p1.print();
	return 0;
}
