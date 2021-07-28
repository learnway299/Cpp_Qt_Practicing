#pragma once
#include <iostream> 
#include <vector>
using namespace std;

template<class T>
struct ListNode
{
	T m_tElement;          // ������
	ListNode<T>* m_pNext;  // ����
	// ���캯��
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
	// ���캯������������
	KsoString() {
		m_pFirstNode = NULL;
		m_iLength = 0;
	}

	KsoString(const KsoString<T>& theList) {
		m_iLength = theList.m_iLength;
		// �ж�Դ�����Ƿ�Ϊ������
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
			// ��Դ����������нڵ�ʱ����������ʣ�µ������ڵ�
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

	// �෽�� 
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
	void checkIndex(int theIndex);  // ȷ���Ƿ�����ֵ�Ƿ�Ϸ�
	int m_iLength;              // ����ĳ���
	ListNode<T>* m_pFirstNode;  // �����ͷ�ڵ�
};