// off_process.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "off_process.h"
#include <iostream>
using namespace std;

int main()
{
	off_process* tmp = new off_process();
	string filepath;
	int flg, flg_x;
	std::cout << "输入文件绝对路径" << std::endl;
	std::cin >> filepath;
	//filepath = "C:/Users/asus/Desktop/kingsoft/code/cpp_students/tasks/lesson2/models/m4.off";
	tmp->read_off_file(filepath);
	tmp->show_off_basis();
	while (true)
	{
		std::cout << "输入1根据顶点索引 2面索引查询面片定点坐标" << std::endl;
		std::cin >> flg;
		if (flg == 1) {
			std::cout << "输入顶点索引,输入值不得超过阈值" << std::endl;
			std::cin >> flg_x;
			tmp->find_by_vertex(flg_x);
		}
		else {
			if (flg == 2) {
				std::cout << "输入面索引,输入值不得超过阈值" << std::endl;
				std::cin >> flg_x;
				tmp->find_by_surface(flg_x);
			}
			else {
				std::cout << "innorect input" << std::endl;
				return 0;
			}
		}
	}
	delete tmp;
	return 0;
}