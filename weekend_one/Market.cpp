#include "Market.h"
#include<iostream>
using namespace std;

void Commodity::output_product() {
	std::cout << "[" << name << "($" << price << "),剩余" << stock << "] ";
};

void Commodity::delete_cmmodity(int n) {
	stock = n;
};


void  Commodity::change_cmmodity() {
	int flg;
	std::cout << "请输入你需要修改的类型1商品名称 2编号 3价格 4数量" << std::endl;
	switch (flg) {
	case 1:
		std::cin >> name;
		break;
	case 2:
		std::cin >> ID;
		break;
	case 3:
		std::cin >> price;
		break;
	case 4:
		std::cin >> stock;
		break;
	default:
		std::cout << "错误输入" << endl;
		break;
	}
};

string Commodity::get_describe()
{
	return describe;
}

int Commodity::get_price()
{
	return price;
}

int Commodity::get_id()
{
	return ID;
}

string Commodity::get_name()
{
	return name;
}

int operator>(const Drink& r, const Drink& l)
{
	if (r.get_price() > l.get_price())
		return 1;
	else
		return 0;
}

int operator>(const Daily& r, const Daily& l)
{
	if (r.get_price() > l.get_price())
		return 1;
	else
		return 0;
}

int operator>(const Fruit& r, const Fruit& l)
{
	if (r.get_price() > l.get_price())
		return 1;
	else
		return 0;
}

int operator>(const Vegetable& r, const Vegetable& l)
{
	if (r.get_price() > l.get_price())
		return 1;
	else
		return 0;
}

int operator>(const Snack& r, const Snack& l)
{
	if (r.get_price() > l.get_price())
		return 1;
	else
		return 0;
}


void SupermarketManager::menu() {
	int flg;
	std::cout << "1、新增商品信息" << std::endl;
	std::cout << "2、删除商品信息 " << std::endl;
	std::cout << " 3、修改商品信息（ps：例如按Id修改价格、描述等）" << std::endl;
	std::cout << "4、商品信息检索" << std::endl;
	std::cout << "5、商品按价格排序输出" << std::endl;
	std::cout << "6、输出价格前五的商品" << std::endl;
	std::cout << "0、退出" << std::endl;
	std::cout << "请选择功能(0 - 6)：" << std::endl;
	std::cin >> flg;
	switch (flg) {
	case 1:
		add_product();
		break;
	case 2:
		delete_product();
		break;
	case 3:
		change_product();
		break;
	case 4:
		void get_by_type();
		break;
	case 5:
		sort_prodtuct_by_price();
		break;
	case 6:
		out_top_product(5);
	case 0:
		exit(1);
		break;
	default:
		std::cout << "错误输入" << endl;
		break;
	}
}

void SupermarketManager::add_product() {
	int flg;
	string n;
	int i;
	int p;
	int s;
	string d;
	std::cout << "请选择添加商品类型 1饮料 2日用品 3水果 4蔬菜 5零食：" << std::endl;
	std::cin >> flg;
	switch (flg) {
	case 1:
		d = "drinks";
		break;
	case 2:
		d = "Daily necessities";
		break;
	case 3:
		d = "fruits";
		break;
	case 4:
		d = "vegetables";
		break;
	case 5:
		d = "snacks";
		break;
	default:
		std::cout << "错误输入" << endl;
		break;
	}
	std::cout << "请输入添加的商品名称(string) 编号(int) 价格(int) 添加数量(int)" << endl;
	std::cin >> n >> i >> p >> s;
	switch (flg) {
	case 1:
		drink.push_back(Drink(n, i, p, s, d));
		std::cout << "商品添加成功" << std::endl;
		break;
	case 2:
		daily.push_back(Daily(n, i, p, s, d));
		std::cout << "商品添加成功" << std::endl;
		break;
	case 3:
		fruit.push_back(Fruit(n, i, p, s, d));
		std::cout << "商品添加成功" << std::endl;
		break;
	case 4:
		vegetable.push_back(Vegetable(n, i, p, s, d));
		std::cout << "商品添加成功" << std::endl;
		break;
	case 5:
		snack.push_back(Snack(n, i, p, s, d));
		std::cout << "商品添加成功" << std::endl;
		break;
	default:
		std::cout << "错误输入" << endl;
		std::cout << "商品添加失败" << std::endl;
		break;
	}

};

void SupermarketManager::delete_product() {
	string name;
	int n;
	bool flg = false;
	std::cout << "请输入待删除商品的名称、数量" << std::endl;
	std::cin >> name >> n;
	if (!flg) {
		if (drink.size() > 0) {
			for (auto d : drink) {
				if (d.get_name().compare("drinks")) {
					d.output_product();
					d.delete_cmmodity(n);
					std::cout << "商品删除成功" << std::endl;
					flg = true;
				}
			}
		}

		if (daily.size() > 0) {
			for (auto d : daily) {
				if (d.get_name().compare("dailys")) {
					d.output_product();
					d.delete_cmmodity(n);
					//d.output_product();
					std::cout << "商品删除成功" << std::endl;
					flg = true;
				}
			}
		}

		if (fruit.size() > 0) {
			for (auto d : fruit) {
				if (d.get_name().compare("fruits")) {
					d.output_product();
					d.delete_cmmodity(n);
					//d.output_product();
					std::cout << "商品删除成功" << std::endl;
					flg = true;
				}
			}
		}

		if (vegetable.size() > 0) {
			for (auto d : vegetable) {
				if (d.get_name().compare("vegetables")) {
					d.output_product();
					d.delete_cmmodity(n);
					//d.output_product();
					std::cout << "商品删除成功" << std::endl;
					flg = true;
				}
			}
		}

		if (snack.size() > 0) {
			for (auto d : snack) {
				if (d.get_name().compare("drinks")) {
					d.output_product();
					d.delete_cmmodity(n);
					//d.output_product();
					std::cout << "商品删除成功" << std::endl;
					flg = true;
				}
			}
		}
	}
};

void SupermarketManager::change_product() {
	int num;
	bool flg = false;
	std::cout << "请输入待更改商品的编号" << std::endl;
	std::cin >> num;
	if (!flg) {
		if (drink.size() > 0) {
			for (auto d : drink) {
				if (d.get_id() == num) {
					d.output_product();
					d.change_cmmodity();
					d.output_product();
					flg = true;
				}
			}
		}

		if (daily.size() > 0) {
			for (auto d : daily) {
				if (d.get_id() == num) {
					d.output_product();
					d.change_cmmodity();
					d.output_product();
					flg = true;
				}
			}
		}

		if (fruit.size() > 0) {
			for (auto d : fruit) {
				if (d.get_id() == num) {
					d.output_product();
					d.change_cmmodity();
					d.output_product();
					flg = true;
				}
			}
		}

		if (vegetable.size() > 0) {
			for (auto d : vegetable) {
				if (d.get_id() == num) {
					d.output_product();
					d.change_cmmodity();
					d.output_product();
					flg = true;
				}
			}
		}

		if (snack.size() > 0) {
			for (auto d : snack) {
				if (d.get_id() == num) {
					d.output_product();
					d.change_cmmodity();
					d.output_product();
					flg = true;
				}
			}
		}
	}
};
void SupermarketManager::get_by_type() {};
void SupermarketManager::sort_prodtuct_by_price() {};
void SupermarketManager::out_top_product(int) {};


template <typename T>
T& SupermarketManager::operator[](string flg) {
	if ((flg.compare("drinks")) == 0)
		return drink;
	if ((flg.compare("dailys")) == 0)
		return daily;
	if ((flg.compare("fruits")) == 0)
		return fruit;
	if ((flg.compare("vegetables")) == 0)
		return vegetable;
	if ((flg.compare("drinks")) == 0)
		return snack;
};

