#pragma once

#include<iostream>

using namespace std;

template <class T>
struct TNode {
	T val;
	TNode<T> *pNext;
};

template <class T>
class TList {
protected:
	TNode<T> *pFirst;
	TNode<T> *pPrev;
	TNode<T> *pCurr;
	TNode<T> *pLast;
	TNode<T> *pStop;
	int size;
	int pos;
public:
	TList();
	~TList();

	int getSize() { return size; }
	int getPos() { return pos; }
	void setPos(const int _pos);

	virtual void insFirst(const T& elem);
	virtual void insLast(const T& elem);
	virtual void insCurrent(const T& elem);

	void Reset() {
		pCurr = pFirst;
		pos = 0;
		pPrev = pStop;
	}
	void GoNext() {
		pPrev = pCurr;
		pCurr = pCurr->pNext;
		pos++;
	}
	bool IsEnd() {
		return (pCurr == pStop);
	}

	void DelFirst();
	void DelCurrent();
	void DelLast();

	TNode<T> *GetCurr();
	TNode<T> *GetPrev();
	TNode<T> *GetFirst();
	TNode<T> *GetLast();

};

template <class T>
TList<T>::TList() {
	pFirst = pLast = pPrev = pCurr = pStop = NULL;
	size = 0;
	pos = -1;
}

template <class T>
TList<T>::~TList() {
	while (size)
		DelFirst();
}

template <class T>
void TList<T>::setPos(const int _pos) {
	for (int i = 0; i < _pos; i++)
		GoNext();
}

template <class T>
void TList<T>::insFirst(const T& elem) {
	TNode<T> *tmp = new TNode <T>;
	tmp->val = elem;
	if (!pFirst){
		pFirst = pLast = tmp;
		pFirst->pNext = pStop;
		pos = 0;
	}
	else {
		tmp->pNext = pFirst;
		pFirst = tmp;
	}
	size++;
}

template <class T>
void TList<T>::insLast(const T& elem) {
	if (pFirst == NULL)
		insFirst(elem);
	else {
		TNode<T> *tmp = new TNode<T>;
		tmp->val = elem;
		pLast->pNext = tmp;
		tmp->pNext = pStop;
		pLast = tmp;
		size++;
	}
}

template <class T>
void TList<T>::insCurrent(const T& elem) {
	if (elem > pFirst->val)
		insFirst(elem);
	else {
		if (pCurr == pStop)
			insLast(elem);
		else {
			TNode<T> *tmp = new TNode<T>;
			tmp->val = elem;
			tmp->pNext = pCurr;
			pPrev->pNext = tmp;
			pCurr = tmp;
			size++;
		}
	}
}

template <class T>
void TList<T>::DelFirst() {
	if (size == 1) {
		delete pFirst;
		pFirst = pLast = pCurr = pPrev = pStop;
		pos = -1;
	}
	else {
		TNode<T> *tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
	size--;
}

template <class T>
void TList<T>::DelCurrent() {
	if (pCurr == pFirst)
		DelFirst();
	else
	{
		pCurr = pCurr->pNext;
		delete pPrev->pNext;
		pPrev->pNext = pCurr;
		size--;
	}
	if (size == 1) pLast = pCurr = pFirst;
	if (!size) pFirst = NULL;
}

template <class T>
void TList<T>::DelLast() {
	if (pLast == pFirst)
		DelFirst();
	else {
		for (Reset(); !(pCurr->pNext == pStop); GoNext()) {}
		delete pLast;
		pLast = pCurr = pPrev;
		Reset();
		size--;
		pos--;
	}
}

template <class T>
TNode<T> *TList<T>::GetCurr() {
	return pCurr;
}

template <class T>
TNode<T> *TList<T>::GetPrev() {
	return pPrev;
}

template <class T>
TNode<T> *TList<T>::GetFirst() {
	return pFirst;
}

template <class T>
TNode<T> *TList<T>::GetLast() {
	return pLast;
}

template <class T>
class THeadList : public TList<T> {
protected:
	TNode<T> *pHead;
public:
	THeadList();
	~THeadList();

	void insFirst(const T& elem);
	void DelFirst();
};

template <class T>
THeadList<T>::THeadList() : TList() {
	pHead = new TNode<T>;
	pStop = pHead;
	pHead->pNext = pHead;
}

template <class T>
THeadList<T>::~THeadList() {
	TList<T>::~TList();
	delete[] pHead;
}

template <class T>
void THeadList<T>::insFirst(const T& elem) {
	TList::insFirst(elem);
	pHead->pNext = pFirst;
}

template <class T>
void THeadList<T>::DelFirst() {
	TList::DelFirst();
	pHead->pNext = pFirst;
}
