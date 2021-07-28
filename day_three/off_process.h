#pragma once
#include <cstdlib>
#include <string> 
#include <iostream>
using namespace std;

class off_process
{

private:
	//�洢����������Ƭ��
	int vertex_num;
	int surface_num;
	int other_num;
	//�洢���73000�㡢��
	float vertex[73000][3];
	int  surface[73000][3];

public:
	//����ָ���ļ�
	void read_off_file(string input);
	//���ģ�ͻ�����Ϣ������������Ƭ����
	void show_off_basis();
	//���ݶ���������ѯ��������
	void find_by_vertex(int vert_x);
	//������������ѯ��Ƭ��������
	void find_by_surface(int vert_y);
};