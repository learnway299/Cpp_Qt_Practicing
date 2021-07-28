#include <iostream>
using namespace std;

/*�������һ��m*n��դ�񣬱�д������������½ǣ����꣺0, 0�������Ͻǣ����꣺m, n����·���ж����֡�
ֻ����դ�����ߣ��Ҳ��ܷ����ߣ���ֻ�����ϻ������ߡ�*/

int solution(int x, int y, int m, int n) {
	int tmp;
	//��������/�� ֻ��һ���߷� 
	if (x == m || y == n) {
		tmp = 1;
	}
	else {
		//�������ϡ������� 
		tmp = solution(x + 1, y, m, n) + solution(x, y + 1, m, n);
	}
	return tmp;
}


int main()
{
	int n, m;
	while (1)
	{
		std::cout << "counting: input n and m" << std::endl;
		std::cin >> n >> m;
		std::cout << "·���У�" << solution(0, 0, m, n) << "��" << std::endl;
	}
	return 0;
}
