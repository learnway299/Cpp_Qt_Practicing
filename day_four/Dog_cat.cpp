// Dog_cat.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include < vector> 
#include <iostream>
using namespace std;


class Animal
{
public:
	Animal() {
		std::cout << "Animal" << std::endl;
	}

	virtual void speak() = 0;
};

class Dog :public Animal {
public:
	Dog() { std::cout << "Dog" << std::endl; }

	virtual void speak() {
		std::cout << "wang" << std::endl;
	};

	void swim() {
		std::cout << "swim" << std::endl;
	}
};

class Cat :public Animal {
public:
	Cat() { std::cout << "Cat" << std::endl; }
	virtual void speak() {
		std::cout << "miao" << std::endl;
	};
};

int main()
{
	int n;
	vector<Animal*> vects;
	std::cout << "输入整数n\n";
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		vects.push_back(new Dog);
		vects.push_back(new Cat);
	}
	for (auto v : vects) {
		v->speak();
		if (Dog* dog = dynamic_cast<Dog*> (v)) {
			dog->swim();
		}
		delete v;
		vects.pop_back();
	}
}