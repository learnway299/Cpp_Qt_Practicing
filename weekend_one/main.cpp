#include "Market.h"
#include<iostream>
using namespace std;

int main() {
	SupermarketManager* manager = new SupermarketManager();
	manager->menu();
	delete manager;
	return 0;
}