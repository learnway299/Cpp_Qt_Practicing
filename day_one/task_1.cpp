#include <iostream>
using namespace std;

/*假设存在一个m*n的栅格，编写函数计算从左下角（坐标：0, 0）走右上角（坐标：m, n）的路径有多少种。
只能沿栅格线走，且不能反向走，既只能向上或向右走。*/

int solution(int x, int y, int m, int n) {
	int tmp;
	//到达最右/上 只有一个走法 
	if (x == m || y == n) {
		tmp = 1;
	}
	else {
		//可以走上、右两种 
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
		std::cout << "路径有：" << solution(0, 0, m, n) << "种" << std::endl;
	}
	return 0;
}
