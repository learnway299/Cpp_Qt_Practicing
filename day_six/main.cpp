#include "KsoString.h"
#include "KsoString.cpp"
#include <iostream> 
#include <vector>
using namespace std;

int main() {
	KsoString<wchar_t>* str1 = new KsoString<wchar_t>();
	wchar_t element;
	/*KsoString<char>* str1 = new KsoString<char>();
	char element;*/
	int flg;
	int index;
	while (1) {
		std::cout << "当前元素个数：" << str1->size() << endl;;
		std::cout << "请输入选项 1插入字符 2删除字符 3更改字符 4查看元素个数 5拷贝构造 6 按下标查找 其他：退出" << endl;
		std::cin >> flg;
		switch (flg) {
		case 1:
		{
			std::cout << "请输入插入的下标与字符" << endl;
			//std::cin >> index>> element;
			std::wcin >> index >> element;
			str1->insert(index, element); }
		break;
		case 2:
		{
			std::cout << "请输入删除的下标" << endl;
			std::cin >> index;
			str1->delete_node(index); }
		break;
		case 3: {
			std::cout << "请输入更改的下标与字符" << endl;
			//std::cin >> index >> element;
			std::wcin >> index >> element;
			str1->update(index, element); }
			  break;
		case 4:
			std::cout << str1->size() << endl;
			break;
		case 5:
		{
			//KsoString<char>* str2 = new KsoString<char>(*str1);
			KsoString<wchar_t>* str2 = new KsoString<wchar_t>(*str1);
			std::cout << "str1:" << endl;
			str1->output();
			std::cout << "\nstr2:" << endl;
			str2->output();
			delete str2;
		}
		break;
		case 6: {
			std::cout << "请输入查询的下标" << endl;
			std::cin >> index;
			std::wcout << "str1[" << index << "] : " << (&str1[index]) << endl; }
			  break;
		default:
			//	exit(1);
			break;
		}
	}
	delete str1;
	return 0;
}