#pragma once

// Узел односвязного списка
template<class T>
struct Node {
	T val; // Значение узла
	Node<T>* pNext; // Указатель на следующий узел
	Node() : val(T()), pNext(nullptr) {} // Конструктор по умолчанию
};

// Очередь на основе односвязного списка
template<class T>
class LQueue {
	Node<T>* pFirst, * pLast; // Указатели на первый и последний элементы
public:
	LQueue() : pFirst(nullptr), pLast(nullptr) {} // Конструктор по умолчанию
	LQueue(const LQueue& q); // Конструктор копирования
	~LQueue(); // Деструктор

	bool IsEmpty() const { return pFirst == nullptr; } // Проверка на пустоту
	T Pop(); // Удаление элемента из начала очереди
	void Push(T v); // Добавление элемента в конец очереди
	T PeekHead(); // Просмотр первого элемента
	T PeekTail(); // Просмотр последнего элемента

	LQueue& operator =(const LQueue& q); // Оператор присваивания
	bool operator ==(const LQueue& q) const; // Оператор сравнения на равенство
	bool operator !=(const LQueue& q) const; // Оператор сравнения на неравенство
};

// Конструктор копирования
template<class T>
LQueue<T>::LQueue(const LQueue<T>& q)
{
	Node<T>* tmp = q.pFirst;
	if (tmp == nullptr) pFirst = pLast = nullptr;
	else {
		Node<T>* previous = new Node<T>();
		previous->val = tmp->val;
		pFirst = pLast = previous;
		tmp = tmp->pNext;
		while (tmp != nullptr) {
			Node<T>* append = new Node<T>();
			append->val = tmp->val;
			pLast = append;
			previous->pNext = pLast;
			previous = previous->pNext;
			tmp = tmp->pNext;
		}
	}
}

// Деструктор: освобождение памяти
template <class T>
LQueue<T>::~LQueue() {
	while (pFirst != nullptr) Pop();
}

// Удаление элемента из начала очереди
template <class T>
T LQueue<T>::Pop() {
	if (IsEmpty()) throw - 1;
	Node<T>* tmp = pFirst;
	T res = tmp->val;
	pFirst = pFirst->pNext;
	delete tmp;
	if (IsEmpty()) pLast = nullptr; // Обновляем указатель pLast, чтобы избежать висячего указателя
	return res;
}

// Добавление элемента в конец очереди
template <class T>
void LQueue<T>::Push(T v) {
	Node<T>* res = new Node<T>();
	res->val = v;
	if (IsEmpty()) {
		pLast = pFirst = res;
	}
	else {
		pLast->pNext = res;
		pLast = res;
	}
}

// Просмотр первого элемента
template<class T>
T LQueue<T>::PeekHead()
{
	if (IsEmpty()) throw - 1;
	return pFirst->val;
}

// Просмотр последнего элемента
template<class T>
T LQueue<T>::PeekTail()
{
	if (IsEmpty()) throw - 1;
	return pLast->val;
}

// Оператор присваивания
template<class T>
LQueue<T>& LQueue<T>::operator =(const LQueue<T>& q) {
	if (this == &q) return *this;
	while (!IsEmpty()) Pop();
	if (!q.IsEmpty()) {
		Node<T>* tmp = q.pFirst;
		while (tmp != nullptr) {
			Push(tmp->val);
			tmp = tmp->pNext;
		}
	}
	return *this;
}

// Оператор сравнения на равенство
template<class T>
bool LQueue<T>::operator==(const LQueue& q) const
{
	Node<T>* tmp1 = pFirst, * tmp2 = q.pFirst;
	while ((tmp1 != nullptr || tmp2 != nullptr) && (tmp1->val == tmp2->val)) {
		tmp1 = tmp1->pNext;
		tmp2 = tmp2->pNext;
	}
	if (tmp1 == nullptr && tmp2 == nullptr) return true;
	return false;
}

// Оператор сравнения на неравенство
template<class T>
bool LQueue<T>::operator!=(const LQueue& q) const
{
	return !(*this == q);
}
