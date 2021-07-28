#include "KsoString.h"
#include <iostream> 
#include <vector>
using namespace std;

// 返回指定元素的索引值
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

// 返回指定索引的元素
template<class T>
T KsoString<T>::get(int theIndex) const
{
	checkIndex(theIndex);
	ListNode<T>* currNode = m_pFirstNode;
	// 找到索引值对应的元素
	for (int i = 0; i < theIndex; ++i)
		currNode = currNode->m_pNext;
	// 返回元素的值
	return currNode->m_tElement;
}

// 在指定位置插入元素
template<class T>
void KsoString<T>::insert(int theIndex, const T& theElement)
{
	// 判断索引值是否合法
	checkIndex(theIndex);
	if (theIndex == 0)
	{
		m_pFirstNode = new ListNode<T>(theElement, m_pFirstNode);
	}
	if (theIndex > 0)
	{
		ListNode<T>* currNode = m_pFirstNode;
		// 因为要在指定位置插入元素, 因此去找指定位置的前一个元素
		for (int i = 0; i < theIndex - 1; ++i)
			currNode = currNode->m_pNext;
		ListNode<T>* newNode = new ListNode<T>(theElement, currNode->m_pNext);
	}
	++m_iLength;
}

// 修改指定位置元素的值
template<class T>
void KsoString<T>::update(int theIndex, const T& theElement)
{
	// 判断索引值是否合法
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

// 检查索引值是否合法
template<class T>
void KsoString<T>::checkIndex(int theIndex)
{
	if (theIndex < 0 || theIndex >= m_iLength - 1)
		std::cout << "Error Index Value" << std::endl;
}

// 删除指定位置的元素
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