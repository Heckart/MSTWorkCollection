// Programmer: Ethan Heckart
// File: linkedlist.hpp
// Date: 11/5/22
// Section: 101

using namespace std;

template <typename T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list) {
	LLNode<T>* tmp = list.m_head;  // ptr to the node to be printed
	out << "[ ";
	for (int i = 0; i < list.m_size; i++) {
		out << tmp->m_data;	 // print the node
		out << ", ";
		tmp = tmp->m_next;	// advance the ptr
	}
	out << "]";
	tmp = NULL;
	return out;
}

template <class T>
LinkedList<T>::~LinkedList() {
	LLNode<T>* tmp;	 // ptr to the node to by deleted
	while (m_head != NULL) {
		tmp = m_head;
		m_head = tmp->m_next;  // advance the head while the previous node is deleted
		delete tmp;
	}
}

template <class T>
const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs) {
	clear();
	LLNode<T>* rp;	// running ptr for the rhs
	rp = rhs.m_head;
	while (rp->m_next != NULL) {  // insert a new node copied from rhs into the back of lhs
		insert_back(rp->m_data);
		rp = rp->m_next;
	}

	return *this;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs) {
	m_size = 0;
	m_head = new LLNode<T>;
	LLNode<T>* rp;	// running ptr to iterate over the rhs object
	rp = rhs.m_head;
	while (rp->m_next != NULL) {
		insert_back(rp->m_data);  // create a new Node copied from rhs into the back of lhs
		rp = rp->m_next;
	}
}

template <class T>
int LinkedList<T>::size() const {
	return m_size;
}

template <class T>
bool LinkedList<T>::isEmpty() const {
	if (m_size == 0) {
		return true;
	}
	return false;
}

template <class T>
LLNode<T>* LinkedList<T>::getFirstPtr() {
	if (m_size == 0) {
		cerr << "!!! ERROR : PANIC in LINKEDLIST !!! Cannot getFirstPtr() when list is empty!\n";
		return NULL;
	}
	return m_head;
}

template <class T>
LLNode<T>* LinkedList<T>::getAtPtr(int i) {
	if (0 <= i && i <= m_size) {
		LLNode<T>* tmp = m_head;  // running ptr to get to the correct node
		for (int k = 0; k < i; k++) {
			tmp = tmp->m_next;
		}
		return tmp;
	} else {
		cerr << "!!! ERROR : PANIC in LINKEDLIST !!! getAtPtr(index) is either < 0 (stupid) or > size of the list (honest mistake)\n";
	}

	return NULL;
}

template <class T>
void LinkedList<T>::clear() {
	LLNode<T>* tmp;	 // running ptr to get to the correct node
	while (m_head != NULL) {
		tmp = m_head;
		m_head = tmp->m_next;  // advance the head while the previous node is deleted
		delete tmp;
	}
	tmp = new LLNode<T>;  // create a new sentinel to be the head
	m_head = tmp;
	m_size = 0;
	return;
}

template <class T>
void LinkedList<T>::insert_front(const T& x) {
	LLNode<T>* tmp = new LLNode<T>;
	tmp->m_data = x;	   // populate new node with correct data
	tmp->m_next = m_head;  // set the new node at the front of the list
	m_head = tmp;
	m_size++;
	tmp = NULL;
	return;
}

template <class T>
void LinkedList<T>::insert_back(const T& x) {
	if (m_size == 0) {
		insert_front(x);
	} else {
		LLNode<T>* pos = getAtPtr(m_size);
		LLNode<T>* tmp = new LLNode<T>;
		tmp->m_data = pos->m_data;
		tmp->m_next = pos->m_next;	// copy the final node of the linked list into the new node
		pos->m_next = tmp;			// make the previously final node point to the newly inserted node instead of sentinel
		pos->m_data = x;
		m_size++;
		tmp = NULL;
	}
	return;
}

template <class T>
void LinkedList<T>::insert(const T& x, LLNode<T>* pos) {
	// attmepting to insert at an invalid index should be caught by the getPtr function
	LLNode<T>* tmp = new LLNode<T>;
	tmp->m_data = pos->m_data;
	tmp->m_next = pos->m_next;
	pos->m_next = tmp;
	pos->m_data = x;
	m_size++;
	tmp = NULL;
	return;
}

template <class T>
void LinkedList<T>::remove_front() {
	if (m_size == 0) {
		cerr << "!!! ERROR : PANIC in LINKEDLIST !!! Cannot remove_front when list is empty!\n";
		return;
	}

	LLNode<T>* tmp;	 // ptr to the new head
	tmp = m_head->m_next;
	delete m_head;
	m_head = tmp;
	m_size--;
	tmp = NULL;
	return;
}

template <class T>
void LinkedList<T>::remove_back() {
	if (m_size == 0) {
		cerr << "!!! ERROR : PANIC in LINKEDLIST !!! Cannot remove_back when list is empty!\n";
		return;
	}

	LLNode<T>* sentinel;  // ptr to the sentinel
	LLNode<T>* tmp;		  // ptr to the second to last node in the list
	sentinel = getAtPtr(m_size);
	sentinel = sentinel->m_next;
	tmp = getAtPtr(m_size - 1);
	delete tmp->m_next;		 // delete the last node in the list
	tmp->m_next = sentinel;	 // point the new final node to the sentinel
	m_size--;
	sentinel = NULL;
	tmp = NULL;
	return;
}

template <class T>
void LinkedList<T>::remove(LLNode<T>* pos) {
	if (m_size == 0) {	// this function should be called with a getPtr function, which will catch the out of bounds errors itself
		cerr << "!!! ERROR : PANIC in LINKEDLIST !!! Cannot remove when list is empty!\n";
		return;
	}

	LLNode<T>* tmp = pos->m_next;  // ptr to the node being removed
	pos->m_data = tmp->m_data;
	pos->m_next = tmp->m_next;
	delete tmp;
	m_size--;
	return;
}

template <class T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const {
	if (m_size != rhs.m_size) {	 // if sizes are not the same, nodes are not equal
		return false;
	}

	LLNode<T>* lhsRP = m_head;		// running ptr for the left side
	LLNode<T>* rhsRP = rhs.m_head;	// running ptr for the right side
	int counter = 0;
	while (counter < m_size) {
		counter++;
		if (lhsRP->m_data != rhsRP->m_data) {  // if the nodes at the same positon do not have the same data,
			lhsRP = NULL;					   // the lists are not equal
			rhsRP = NULL;
			return false;
		}
		lhsRP = lhsRP->m_next;	// run those ptrs
		rhsRP = rhsRP->m_next;
	}
	lhsRP = NULL;
	rhsRP = NULL;
	return true;
}

template <class T>
LLNode<T>* LinkedList<T>::find(const T& x) {
	LLNode<T>* tmp = m_head;						   // running ptr for the list
	while (tmp->m_data != x && tmp->m_next != NULL) {  // while node doesn't have the the right data & the list hasn't been fully travered, advance the ptr
		tmp = tmp->m_next;
	}
	if (tmp->m_next != NULL) {
		return tmp;	 // if the mathching node isn't the sentinel, return it
	}
	return NULL;
}

template <class T>
void LinkedList<T>::reverse() {
	LinkedList<T> tmp;	// new LL to hold the reversed order
	for (int i = m_size; i > 0; i--) {
		tmp.insert_back(getAtPtr(i - 1)->m_data);  // traverse orignal LL from back to front while inserting back
	}
	*this = tmp;  // makes the calling object equal to tmp;
	tmp.clear();
	return;
}

template <class T>
void LinkedList<T>::append(const LinkedList<T>& l2) {
	LLNode<T>* l2Ptr = l2.m_head;  // running ptr to the head of the list to be appended

	for (int i = 0; i < l2.m_size; i++) {  // traverse the list to be appended excluding the sentinel
		insert_back(l2Ptr->m_data);		   // insert each node to the back of the list
		l2Ptr = l2Ptr->m_next;
	}
	return;
}

template <class T>
void LinkedList<T>::slice(const LinkedList<T>& l2, LLNode<T>* start, LLNode<T>* stop) {
	clear();								 // delete nodes in the current list
	while (start->m_next != stop->m_next) {	 // use start as a rp until it equals stop
		insert_back(start->m_data);
		start = start->m_next;
	}
	return;
}