 ///
 /// @file    complex.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-03 04:03:39
 ///
 
#include <iostream>

/*运算符重载问题（以复数运算为例）*/
using std::endl;
using std::cout;

class Complex{
	public:
		Complex(int ireal,int imag);
		~Complex();
		/*以成员函数进行重载*/
		Complex operator +(const Complex &rhs);
		Complex & operator +=(const Complex &rhs);
		void print();
		int _ireal;
		int _imag;
};

Complex::Complex(int ireal,int imag)
:_ireal(ireal)
,_imag(imag)
{
	cout<<"Complex(int,int)"<<endl;
}

Complex::~Complex(){
	cout<<"~Complex()"<<endl;
}

#if 0
/*以全局/自由函数进行重载*/
Complex operator +(const Complex &lhs,const Complex &rhs){
	Complex cmp(lhs._ireal + rhs._ireal,lhs._imag + rhs._imag);
	return cmp;
}
#endif

Complex	Complex::operator +(const Complex &rhs){
	Complex cmp(this->_ireal + rhs._ireal,this->_imag + rhs._imag);
	return cmp;
}

Complex & Complex::operator +=(const Complex &rhs){
	this->_ireal += rhs._ireal;
	this->_imag += rhs._imag;
	return *this;
}

void Complex::print(){
	cout<<_ireal;
	if(_imag > 0){
		cout<<" + "<<_imag<<"i"<<endl;
	}else if(_imag == 0){
		cout<<endl;
	}else{
		cout<<" - "<<-1*_imag<<"i"<<endl;
	}
}

#if 0
/*内置数据类型的运算符不可重载*/
int operator +(int a,int b){
	return a * b;
}
#endif

int main(void){
	Complex c1(5,5);
	Complex c2(2,2);
	Complex c3(1,-4);
	c1.print();
	c2.print();
	c3.print();
	Complex c4 = c1 + c2;
	Complex c5 = c2 + c3;
	c4.print();
	c5.print();
	cout<<"-------------------------"<<endl;
	c4 += c1;
	c4.print();
	return 0;
}
