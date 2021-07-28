#include "KsoString.h"
#include <iostream> 
#include <vector>
using namespace std;

// ����ָ��Ԫ�ص�����ֵ
template<class T>
int KsoString<T>::indexOf(const T& theElement) const
{
	ListNode<T>* currNode = m_pFirstNode;
	int index = 0;
	while (currNode != NULL && currNode->m_tElement != theElement)
	{
		currNode = currNode->m_pNext;
		++index;
	}
	if (currNode == NULL)
	{
		return -1;
	}
	if (currNode != NULL)
		return index;
}

// ����ָ��������Ԫ��
template<class T>
T KsoString<T>::get(int theIndex) const
{
	checkIndex(theIndex);
	ListNode<T>* currNode = m_pFirstNode;
	// �ҵ�����ֵ��Ӧ��Ԫ��
	for (int i = 0; i < theIndex; ++i)
		currNode = currNode->m_pNext;
	// ����Ԫ�ص�ֵ
	return currNode->m_tElement;
}

// ��ָ��λ�ò���Ԫ��
template<class T>
void KsoString<T>::insert(int theIndex, const T& theElement)
{
	// �ж�����ֵ�Ƿ�Ϸ�
	checkIndex(theIndex);
	if (theIndex == 0)
	{
		m_pFirstNode = new ListNode<T>(theElement, m_pFirstNode);
	}
	if (theIndex > 0)
	{
		ListNode<T>* currNode = m_pFirstNode;
		// ��ΪҪ��ָ��λ�ò���Ԫ��, ���ȥ��ָ��λ�õ�ǰһ��Ԫ��
		for (int i = 0; i < theIndex - 1; ++i)
			currNode = currNode->m_pNext;
		ListNode<T>* newNode = new ListNode<T>(theElement, currNode->m_pNext);
	}
	++m_iLength;
}

// �޸�ָ��λ��Ԫ�ص�ֵ
template<class T>
void KsoString<T>::update(int theIndex, const T& theElement)
{
	// �ж�����ֵ�Ƿ�Ϸ�
	checkIndex(theIndex);
	// 
	if (theIndex == 0)
	{
		m_pFirstNode->m_tElement = theElement;
		return;
	}

	ListNode<T>* currNode = m_pFirstNode;
	for (int i = 0; i < theIndex; ++i)
		currNode = currNode->m_pNext;
	currNode->m_tElement = theElement;
}

template<class T>
void KsoString<T>::output()
{
	while (m_pFirstNode != NULL) {
		std::cout << m_pFirstNode->m_tElement;
		m_pFirstNode = m_pFirstNode->m_pNext;
	}
}

template<class T>
T KsoString<T>::operator[](int theIndex)
{
	return get(theIndex);
}

// �������ֵ�Ƿ�Ϸ�
template<class T>
void KsoString<T>::checkIndex(int theIndex)
{
	if (theIndex < 0 || theIndex >= m_iLength - 1)
		std::cout << "Error Index Value" << std::endl;
}

// ɾ��ָ��λ�õ�Ԫ��
template<class T>
void KsoString<T>::delete_node(int theIndex)
{
	checkIndex(theIndex);
	ListNode<T>* targetNode = NULL;
	if (theIndex == 0)
	{
		targetNode = m_pFirstNode;
		m_pFirstNode = m_pFirstNode->m_pNext;
	}
	if (theIndex > 0)
	{
		ListNode<T>* prevNode = m_pFirstNode;
		for (int i = 0; i < theIndex - 1; ++i)
			prevNode = prevNode->m_pNext;
		targetNode = prevNode->m_pNext;
		prevNode->m_pNext = targetNode->m_pNext;
	}
	delete targetNode;
	--m_iLength;
}