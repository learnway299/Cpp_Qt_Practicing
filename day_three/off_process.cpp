#include <string> 
#include <fstream>
#include <iostream>
using namespace std;
#include "off_process.h"

void off_process::read_off_file(string filepath)
{
	string flg;
	int i, j, k = 0;
	int s;
	ifstream fin;
	fin.open(filepath, ios::in);
	while (fin.fail())
	{
		cout << "Fail to open the off file!" << endl;
		exit(1);
	}
	//读取第一行判别是否为off file
	fin >> flg;
	if (strcmp("OFF", flg.c_str()) == 0) {
		cout << "The file isn't  a  off file!" << endl;
		exit(1);
	}

	do
	{
	} while (fin.get() != '\n');
	fin >> vertex_num >> surface_num >> other_num;

	for (i = 0; i < vertex_num; i++)
	{
		for (j = 0; j < 3; j++)
		{
			fin >> vertex[i][j];
		}
	}
	for (i = 0; i < surface_num; i++)
	{
		fin >> s;
		//	cout << s << endl;
		for (j = 0; j < 3; j++)
		{
			fin >> surface[i][j];
		}
	}
}

void off_process::show_off_basis()
{
	int vertex_num;
	std::cout << "此off文件有" << this->vertex_num << "个顶点" << this->surface_num << "个面片" << std::endl;
}

void off_process::find_by_vertex(int vert_x)
{
	std::cout << "点坐标为;" << std::endl;
	std::cout << this->vertex[vert_x][0] << " " << this->vertex[vert_x][1] << " " << this->vertex[vert_x][2] << std::endl;
}

void off_process::find_by_surface(int vert_y)
{
	int flg = this->surface[vert_y][0];
	std::cout << "本面有" << flg << "个点，坐标为;" << std::endl;
	for (int i = 0; i < flg; i++)
		this->find_by_vertex(surface[vert_y][i]);
}