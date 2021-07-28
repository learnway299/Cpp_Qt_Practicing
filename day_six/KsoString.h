#pragma once
#include <iostream> 
#include <vector>
using namespace std;

template<class T>
struct ListNode
{
	T m_tElement;          // 数据域
	ListNode<T>* m_pNext;  // 链域
	// 构造函数
	ListNode() {}
	ListNode(const T& theElement) { this->m_tElement = theElement; }
	ListNode(const T& theElement, ListNode<T>* theNext)
	{
		this->m_tElement = theElement;
		this->m_pNext = theNext;
	}
};

template<class T>
class KsoString
{
public:
	// 构造函数与析构函数
	KsoString() {
		m_pFirstNode = NULL;
		m_iLength = 0;
	}

	KsoString(const KsoString<T>& theList) {
		m_iLength = theList.m_iLength;
		// 判断源链表是否为空链表
		if (m_iLength == 0)
		{
			m_pFirstNode = NULL;
			return;
		}

		ListNode<T>* otherNode = theList.m_pFirstNode;
		m_pFirstNode = new ListNode<T>(otherNode->m_tElement);
		ListNode<T>* thisNode = m_pFirstNode;
		otherNode = otherNode->m_pNext;

		while (otherNode != NULL)
		{
			// 当源链表后续还有节点时，复制链表剩下的其他节点
			thisNode->m_pNext = new ListNode<T>(otherNode->m_tElement);
			thisNode = thisNode->m_pNext;
			otherNode = otherNode->m_pNext;
		}
		thisNode->m_pNext = NULL;
	}

	~KsoString() {
		while (m_pFirstNode != NULL)
		{
			ListNode<T>* tempNode = m_pFirstNode;
			delete m_pFirstNode;
			m_pFirstNode = tempNode;
		}
	}

	// 类方法 
	bool empty() const { return m_iLength == 0; }
	int size() const { return m_iLength; }
	int indexOf(const T& theElement) const;
	T get(int theIndex) const;
	void insert(int theIndex, const T& theElement);
	void delete_node(int theIndex);
	void update(int theIndex, const T& theElement);
	void output();
	T operator[](int i);

private:
	void checkIndex(int theIndex);  // 确认是否索引值是否合法
	int m_iLength;              // 链表的长度
	ListNode<T>* m_pFirstNode;  // 链表的头节点
};