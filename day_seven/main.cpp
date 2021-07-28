#include "Smart_ptr.h"
#include <iostream>
using namespace std;

class A {
private:
	int a1;
public:
	A() :a1(0) {};
	A(int x) :a1(x) {};
	int fun() const {
		return a1;
	};
};

int main()
{
	//T = int
	// Test Constructor and Assignment Operator Overloaded
	Smart_ptr<int> p1(new int(0));
	p1 = p1;
	std::cout << "bool(p1): " << bool(p1) << endl;
	//std::cout << "*p1: " << *(p1) << endl;
	std::cout << "p1.get(): " << p1.get() << endl;
	std::cout << "&p1: " << &p1 << endl;
	std::cout << "*p1: " << *p1 << endl;
	std::cout << " use_count: " << p1.use_count_() << endl;
	// Test Copy Constructor
	Smart_ptr<int> p2(p1);
	std::cout << "bool(p2): " << bool(p2) << endl;
	std::cout << "p2.get(): " << p2.get() << endl;
	std::cout << " use_count: " << p1.use_count_() << endl;
	// Test Assignment Operator Overloaded
	Smart_ptr<int> p3(new int(1));
	//Smart_ptr<char> p3(new char(1));
	p3 = p1;
	std::cout << "p3 is empty?: " << p3.isempty() << endl;
	std::cout << "bool(p3): " << bool(p3) << endl;
	std::cout << "p3.get(): " << p3.get() << endl;
	std::cout << "*p3: " << *p3 << endl;
	std::cout << " use_count: " << p3.use_count_() << endl;
	//T = a
	Smart_ptr<A> p4(new A(9));
	std::cout << "p4->fun(): " << p4->fun() << endl;
	std::cout << "&p4: " << &p4 << endl;
	std::cout << " use_count: " << p4.use_count_() << endl;
	return 0;
}