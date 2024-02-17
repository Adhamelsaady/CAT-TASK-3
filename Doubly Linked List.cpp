#include <iostream>
using namespace std;
struct Node {
	int data{ };
	Node* next{ };
	Node* prev{ };
	Node(int data) : data(data) {}
	void set(Node* next, Node* prev) {
		this->next = next;
		this->prev = prev;
	}
	~Node() {
	
	}
};
class DoublyLinkedList {
private:
	Node* head{ };
	Node* tail{ };
	int length = 0;
	void link(Node* first, Node* second) {
		if (first)
			first->next = second;
		if (second)
			second->prev = first;
	}
	Node* delete_and_link(Node* cur) {
		Node* ret = cur->prev;
		link(cur->prev, cur->next);
		delete cur;
		length--;
		return ret;
	}
public:
	void print() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
	}
	void inser_end(int val) {
		Node* item = new Node(val);
		if (!head)
			head = tail = item;
		else {
			link(tail, item);
			tail = item;
		}
		length++;
	}
	void insert_front(int val) {
		Node* item = new Node(val);
		if (!head)
			head = item = tail;
		else {
			link(item, head);
			head = item;
		}
		length++;
	}
	void delete_front() {
		if (!head)
			return;
		Node* cur = head->next;
		--length;
		delete head;
		head = cur;
		if (head)
			head->prev = nullptr;
		else if (!length)
			tail = nullptr;
	}
	void delete_end() {
		if (!head)
			return;
		Node* cur = tail->prev;
		delete tail;
		tail = cur;
		if (tail)
			tail->next = nullptr;
		else if (!length)
			head = nullptr;
	}

	//HW1
	void delete_nodes_with_key(int value) {
		if (!length)
			return;
		insert_front(-value);
		for (Node* cur = head; cur;) {
			if (cur->data == value) {
				cur = delete_and_link(cur);
				if (!cur->next)
					tail = cur;
			}
			else
				cur = cur->next;
		}

		delete_front();
	}
	//HW2
	void delete_even_positions() {
		if (length <= 1)
			return;
		for (Node* cur = head; cur && cur->next; cur = cur->next) {
			delete_and_link(cur->next);
			if (!cur->next)
				tail = cur;
		}
	}
	//HW3
	void delete_odd_positions() {
		insert_front(0);	
		delete_even_positions();
		delete_front();
	}
	//HW4
	bool is_pal() {
		if (length <= 1)
			return true;
		int len = length / 2;
		Node* start = head;
		Node* end = tail;
		while (len--) {
			if (start->data != end->data)
				return false;
			start = start->next;
			end = end->prev;
		}
		return true;
	}
	//HW5
	int mid_value() {
		Node* h = head;
		Node* t = tail;
		while (h != t && h->next != t)
			h = h->next, t = t->prev;
		return t->data;
	}
	//HW6
	void reverse() {
		if (length <= 1)
			return;
		Node* first = head, * second = head->next;
		while (second) {
			Node* fst = second;
			Node* sec = second->next;
			link(second, first);
			first = fst, second = sec;
		}		
		swap(head, tail);
		head->prev = tail->next = nullptr;
	}

};
int main()
{
}

