// off_process.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
#include "off_process.h"
#include <iostream>
using namespace std;

int main()
{
	off_process* tmp = new off_process();
	string filepath;
	int flg, flg_x;
	std::cout << "�����ļ�����·��" << std::endl;
	std::cin >> filepath;
	//filepath = "C:/Users/asus/Desktop/kingsoft/code/cpp_students/tasks/lesson2/models/m4.off";
	tmp->read_off_file(filepath);
	tmp->show_off_basis();
	while (true)
	{
		std::cout << "����1���ݶ������� 2��������ѯ��Ƭ��������" << std::endl;
		std::cin >> flg;
		if (flg == 1) {
			std::cout << "���붥������,����ֵ���ó�����ֵ" << std::endl;
			std::cin >> flg_x;
			tmp->find_by_vertex(flg_x);
		}
		else {
			if (flg == 2) {
				std::cout << "����������,����ֵ���ó�����ֵ" << std::endl;
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