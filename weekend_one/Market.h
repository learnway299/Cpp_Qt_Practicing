#pragma once
#include<vector>
#include <string> 
using namespace std;

class SupermarketManager
{
public:
	SupermarketManager() {}
	void menu();;
	void add_product() {};
	void delete_product() {};
	void change_product() {};
	void get_by_type() {};
	void sort_prodtuct_by_price() {};
	void out_top_product(int) {};

	template <typename T>
	T& operator[](string) {};


private:
	std::vector<Drink> drink;
	std::vector<Daily> daily;
	std::vector<Fruit> fruit;
	std::vector<Vegetable> vegetable;
	std::vector<Snack> snack;
};

class Commodity {
protected:
	string name;
	int ID;
	int price;
	int stock;
	string describe;
public:
	Commodity() :name(""), ID(0), price(0), stock(0), describe("") {}
	Commodity(string n, int i, int p, int s, string d) :name(n), ID(i), price(p), stock(s), describe(d) {}
	void output_product() {};
	virtual string get_describe();
	virtual int get_price();
	virtual int get_id();
	virtual string get_name();
	void  change_cmmodity() {};
	void delete_cmmodity(int) {};
};

class Drink : public Commodity {

public:
	Drink() {
		name = ""; ID = 0; price = 0;
		stock = 0; describe = "drinks";
	}
	Drink(string n, int i, int p, int s, string d = "drinks") {
		name = n; ID = i; price = p;
		stock = s; describe = d;
	}

	string get_describe()const;
	int get_price()const;
	friend int operator >(const Drink&, const Drink&);
};

class Daily : public Commodity {
public:
	Daily() {
		name = ""; ID = 0; price = 0;
		stock = 0; describe = "Daily necessities";
	}

	Daily(string n, int i, int p, int s, string d = "Daily necessities") {
		name = n; ID = i; price = p;
		stock = s; describe = d;
	}

	string get_describe()const;
	int get_price()const;
	friend int operator >(const Daily&, const Daily&);
};

class Fruit : public Commodity {
public:
	Fruit() {
		name = ""; ID = 0; price = 0;
		stock = 0; describe = "fruits";
	}

	Fruit(string n, int i, int p, int s, string d = "fruits") {
		name = n; ID = i; price = p;
		stock = s; describe = d;
	}

	string get_describe()const;
	int get_price()const;
	friend int operator >(const Fruit&, const Fruit&);
};

class Vegetable : public Commodity {
public:
	Vegetable() {
		name = ""; ID = 0; price = 0;
		stock = 0; describe = "vegetables";
	}

	Vegetable(string n, int i, int p, int s, string d = "vegetables") {
		name = n; ID = i; price = p;
		stock = s; describe = d;
	}

	string get_describe()const;
	int get_price()const;
	friend int operator >(const Vegetable&, const Vegetable&);
};

class Snack : public Commodity {
public:
	Snack() {
		name = ""; ID = 0; price = 0;
		stock = 0; describe = "snacks";
	}

	Snack(string n, int i, int p, int s, string d = "snacks") {
		name = n; ID = i; price = p;
		stock = s; describe = d;
	}

	string get_describe()const;
	int get_price()const;
	friend int operator >(const Snack&, const Snack&);
};

