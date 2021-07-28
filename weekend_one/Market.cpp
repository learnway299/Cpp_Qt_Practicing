#include "Market.h"
#include<iostream>
using namespace std;

void Commodity::output_product() {
	std::cout << "[" << name << "($" << price << "),ʣ��" << stock << "] ";
};

void Commodity::delete_cmmodity(int n) {
	stock = n;
};


void  Commodity::change_cmmodity() {
	int flg;
	std::cout << "����������Ҫ�޸ĵ�����1��Ʒ���� 2��� 3�۸� 4����" << std::endl;
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
		std::cout << "��������" << endl;
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
	std::cout << "1��������Ʒ��Ϣ" << std::endl;
	std::cout << "2��ɾ����Ʒ��Ϣ " << std::endl;
	std::cout << " 3���޸���Ʒ��Ϣ��ps�����簴Id�޸ļ۸������ȣ�" << std::endl;
	std::cout << "4����Ʒ��Ϣ����" << std::endl;
	std::cout << "5����Ʒ���۸��������" << std::endl;
	std::cout << "6������۸�ǰ�����Ʒ" << std::endl;
	std::cout << "0���˳�" << std::endl;
	std::cout << "��ѡ����(0 - 6)��" << std::endl;
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
		std::cout << "��������" << endl;
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
	std::cout << "��ѡ�������Ʒ���� 1���� 2����Ʒ 3ˮ�� 4�߲� 5��ʳ��" << std::endl;
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
		std::cout << "��������" << endl;
		break;
	}
	std::cout << "��������ӵ���Ʒ����(string) ���(int) �۸�(int) �������(int)" << endl;
	std::cin >> n >> i >> p >> s;
	switch (flg) {
	case 1:
		drink.push_back(Drink(n, i, p, s, d));
		std::cout << "��Ʒ��ӳɹ�" << std::endl;
		break;
	case 2:
		daily.push_back(Daily(n, i, p, s, d));
		std::cout << "��Ʒ��ӳɹ�" << std::endl;
		break;
	case 3:
		fruit.push_back(Fruit(n, i, p, s, d));
		std::cout << "��Ʒ��ӳɹ�" << std::endl;
		break;
	case 4:
		vegetable.push_back(Vegetable(n, i, p, s, d));
		std::cout << "��Ʒ��ӳɹ�" << std::endl;
		break;
	case 5:
		snack.push_back(Snack(n, i, p, s, d));
		std::cout << "��Ʒ��ӳɹ�" << std::endl;
		break;
	default:
		std::cout << "��������" << endl;
		std::cout << "��Ʒ���ʧ��" << std::endl;
		break;
	}

};

void SupermarketManager::delete_product() {
	string name;
	int n;
	bool flg = false;
	std::cout << "�������ɾ����Ʒ�����ơ�����" << std::endl;
	std::cin >> name >> n;
	if (!flg) {
		if (drink.size() > 0) {
			for (auto d : drink) {
				if (d.get_name().compare("drinks")) {
					d.output_product();
					d.delete_cmmodity(n);
					std::cout << "��Ʒɾ���ɹ�" << std::endl;
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
					std::cout << "��Ʒɾ���ɹ�" << std::endl;
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
					std::cout << "��Ʒɾ���ɹ�" << std::endl;
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
					std::cout << "��Ʒɾ���ɹ�" << std::endl;
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
					std::cout << "��Ʒɾ���ɹ�" << std::endl;
					flg = true;
				}
			}
		}
	}
};

void SupermarketManager::change_product() {
	int num;
	bool flg = false;
	std::cout << "�������������Ʒ�ı��" << std::endl;
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

