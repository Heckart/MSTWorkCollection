#include "linkedqueue.h"

using namespace std;

template <typename T>
LinkedQueue<T>::LinkedQueue() {
	m_back = NULL;
	m_size = 0;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const LinkedQueue<T>& queue) {
	LQNode<T>* tmp = queue.m_back->m_next;
	for (int i = 0; i < queue.m_size; i++) {
		out << tmp->m_data;
		tmp = tmp->m_next;
	}
	tmp = NULL;
	return out;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
	if (m_size != 0) {
		return false;
	}

	return true;
}

template <typename T>
const T& LinkedQueue<T>::front() const throw(Oops) {
	if (isEmpty()) throw Oops("Error");
	return m_back->m_next->m_data;
}

template <typename T>
const string& LinkedQueue<T>::frontName() const {
	return m_back->m_next->m_name;
}

template <typename T>
const T& LinkedQueue<T>::frontTotal() const {
	return m_back->m_next->m_total;
}

template <typename T>
const T& LinkedQueue<T>::back() const throw(Oops) {
	if (isEmpty()) throw Oops("Error");
	return m_back->m_data;
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& x) {
	LQNode<T>* tmp = new LQNode<T>;
	tmp->m_data = x;
	if (m_size != 0) {	// if m_size !=0, the method discussed in class can be used
		tmp->m_next = m_back->m_next;
		m_back->m_next = tmp;
		m_back = tmp;
		m_size++;
	} else if (m_size == 0) {
		m_back = tmp;  // the back ptr is set to tmp
		m_size++;	   // nothing else needs to be done due to the queue only having one element
		tmp->m_next = tmp;
	}
	tmp = NULL;
	return;
}

template <typename T>
void LinkedQueue<T>::assignName(const string& y) {
	m_back->m_name = y;
	return;
}

template <typename T>
void LinkedQueue<T>::updateTotals(const T& z, const T& w) {
	m_back->m_total = z + w;
	return;
}

template <typename T>
void LinkedQueue<T>::dequeue() {
	if (m_size > 1) {  // if m_size != 0, the method discussed in class can be used
		LQNode<T>* tmp = m_back->m_next;
		m_back->m_next = tmp->m_next;
		delete tmp;
		tmp = NULL;
		m_size--;
	} else {
		delete m_back;	// delete the back ptr
		m_back = NULL;	// nothing else needs to be done due to the queue having only one element
		m_size--;
	}

	return;
}

template <typename T>
void LinkedQueue<T>::clear() {	// the dequeue function/destructor can be effectively used as a clear function if it is repeated for the number of nodes
	if (m_size > 1) {
		for (int i = 0; i < m_size; i++) {
			LQNode<T>* tmp = m_back->m_next;
			m_back->m_next = tmp->m_next;
			delete tmp;
			tmp = NULL;
		}
	} else {
		delete m_back;
		m_back = NULL;
	}
	m_size = 0;
	m_back = NULL;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {  // a modified dequeue function can be effectively used as a destructor
	if (m_size > 1) {
		for (int i = 0; i < m_size; i++) {
			LQNode<T>* tmp = m_back->m_next;
			m_back->m_next = tmp->m_next;
			delete tmp;
			tmp = NULL;
		}
	} else {
		delete m_back;
		m_back = NULL;
	}
	m_size = 0;
	m_back = NULL;
}