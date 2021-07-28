#pragma once
#include <cstdlib>
#include <string> 
#include <iostream>
using namespace std;

class off_process
{

private:
	//存储顶点数、面片数
	int vertex_num;
	int surface_num;
	int other_num;
	//存储最多73000点、面
	float vertex[73000][3];
	int  surface[73000][3];

public:
	//导入指定文件
	void read_off_file(string input);
	//输出模型基本信息（顶点数、面片数）
	void show_off_basis();
	//根据顶点索引查询顶点坐标
	void find_by_vertex(int vert_x);
	//根据面索引查询面片定点坐标
	void find_by_surface(int vert_y);
};