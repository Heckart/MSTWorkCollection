// Programmer: Ethan Heckart
// File: arraylist.hpp
// Date: 10/19/22
// Section: 101

using namespace std;

template <class T>
void ArrayList<T>::grow() {
	const int DOUBLE_ARRAY_SIZE = m_max * 2;
	T* tmp = new T[DOUBLE_ARRAY_SIZE];
	for (int i = 0; i < m_max; i++) {
		tmp[i] = m_data[i];
	}
	delete[] m_data;
	m_data = tmp;
	tmp = NULL;
	m_max = DOUBLE_ARRAY_SIZE;
	return;
}

template <class T>
void ArrayList<T>::shrink() {
	const int HALF_ARRAY_SIZE = m_max / 2;
	T* tmp = new T[HALF_ARRAY_SIZE];
	for (int i = 0; i < HALF_ARRAY_SIZE; i++) {
		tmp[i] = m_data[i];
	}
	delete[] m_data;
	m_data = tmp;
	tmp = NULL;
	m_max = HALF_ARRAY_SIZE;
	return;
}

template <class T>
ArrayList<T>::ArrayList(int s, const T& x) {
	m_size = s;
	m_max = s;
	m_data = new T[s];
	for (int i = 0; i < m_max; i++) {
		m_data[i] = x;
	}
}

template <class T>
ArrayList<T>::~ArrayList() {
	delete[] m_data;
	m_data = NULL;
	m_size = 0;
	m_max = 0;
}

template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs) {
	T* tmp = new T[rhs.m_max];
	for (int i = 0; i < rhs.m_max; i++) {
		tmp[i] = rhs.m_data[i];
	}
	delete[] m_data;
	m_data = tmp;
	tmp = NULL;
	m_max = rhs.m_max;
	m_size = rhs.m_size;
	return *this;
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy) {
	m_size = cpy.m_size;
	m_max = cpy.m_max;
	m_data = new T[cpy.m_max];
	for (int i = 0; i < cpy.m_max; i++) {
		m_data[i] = cpy.m_data[i];
	}
}

template <class T>
int ArrayList<T>::size() const {
	return m_size;
}

template <class T>
const T& ArrayList<T>::first() const {
	if (m_size == 0) {
		cout << "!!! ERROR : PANIC in ARRAYLIST !!!.first()  (List is empty)\n";
		return m_errobj;
	}

	return m_data[0];
}

template <class T>
T& ArrayList<T>::operator[](int i) {
	if (i >= m_size || i < 0 || m_size == 0) {
		cout << "!!! ERROR : PANIC in ARRAYLIST !!!.[]  (index out of bounds)\n";
		return m_errobj;
	}

	return m_data[i];
}

template <class T>
const T& ArrayList<T>::operator[](int i) const {
	if (i >= m_size || i < 0 || m_size == 0) {
		cout << "!!! ERROR : PANIC in ARRAYLIST !!!.[]  (index out of bounds)\n";
		return m_errobj;
	}
	return m_data[i];
}

template <class T>
int ArrayList<T>::search(const T& x) const {
	for (int i = 0; i < m_size; i++) {
		if (m_data[i] == x) {
			return i;
		}
	}
	return -1;
}

template <class T>
void ArrayList<T>::clear() {
	const int CLEARED_ARRAY_SIZE = 4;
	T* tmp = new T[CLEARED_ARRAY_SIZE];
	delete[] m_data;
	m_data = tmp;
	tmp = NULL;
	m_max = CLEARED_ARRAY_SIZE;
	m_size = 0;
	return;
}

template <class T>
void ArrayList<T>::insert_back(const T& x) {
	if (m_size == m_max) {
		grow();
	}
	m_data[m_size] = x;
	m_size++;
	return;
}

template <class T>
void ArrayList<T>::insert(const T& x, int i) {
	if (i < 0 || i >= m_size) {
		cout << "!!! ERROR : PANIC in ARRAYLIST !!!.insert()  (index out of bounds)\n";
		return;
	}

	if (m_size == m_max) {
		grow();
	}
	for (int k = m_size; k > i; k--) {
		m_data[k] = m_data[k - 1];
	}
	m_data[i] = x;
	m_size++;
	return;
}

template <class T>
void ArrayList<T>::remove(int i) {
	if (i < 0 || i >= m_size || m_size == 0) {
		cout << "!!! ERROR : PANIC in ARRAYLIST !!!.remove()  (index out of bounds)\n";
		return;
	}

	for (int k = i; k < m_size; k++) {
		m_data[k] = m_data[k + 1];
	}
	if (m_size <= m_max * 0.25) {
		shrink();
	}
	m_size--;
	return;
}

template <class T>
void ArrayList<T>::swap(int i, int k) {
	if (i < 0 || i >= m_size || k < 0 || k >= m_size) {
		cout << "!!! ERROR : PANIC in ARRAYLIST !!!.swap()  (index out of bounds)\n";
		return;
	}

	T tmp = m_data[i];
	m_data[i] = m_data[k];
	m_data[k] = tmp;
	return;
}

template <class T>
void ArrayList<T>::purge() {
	for (int i = 0; i < m_size; i++) {
		for (int j = i + 1; j < m_size; j++) {
			if (m_data[i] == m_data[j]) {
				remove(j);
			}
		}
	}
	return;
}

template <class T>
void ArrayList<T>::reverse() {
	T* tmp = new T[m_max];
	for (int i = m_size - 1; i >= 0; i--) {
		tmp[m_size - i - 1] = m_data[i];
	}

	delete[] m_data;
	m_data = tmp;
	tmp = NULL;

	return;
}