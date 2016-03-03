 ///
 /// @file    friend1.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-03 03:20:43
 ///
#include <math.h> 
#include <iostream>

using std::endl;
using std::cout;

class Point; //类的前向声明

class Line{
	public:
		float len(const Point &lhs,const Point &rhs);
};

class Point{
	/*将一个类的成员函数声明为另一个类的友元函数*/
	friend float Line::len(const Point &lhs,const Point &rhs);
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

float Line::len(const Point &lhs,const Point &rhs){
	return sqrt((lhs._x - rhs._x)*(lhs._x - rhs._x) + (lhs._y - rhs._y)*(lhs._y - rhs._y));
}

void Point::print(){
	cout<<"("<<_x<<" , "<<_y<<")"<<endl;
}

int main(void){
	Line line;
	Point p1(2,2);
	Point p2(4,4);
	p1.print();
	p2.print();
	float length = line.len(p1,p2);
	cout<<"the length from p1 to p2: "<<length<<endl;
	return 0;
}
