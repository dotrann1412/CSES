#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

struct Node
{
	int data;
	Node *next, *prev;
	
	Node() {
		data = 0;
		next = prev = nullptr;
	}

	Node(int value) {
		data = value;
		next = prev = nullptr;
	}
};

class LinkedList
{
private:
	Node *head;
	Node *tail;
	int len;

public:
	LinkedList() {
		this->head = this->tail = nullptr;
		this->len = 0;
	}

	LinkedList(int n) {
		this->len = 0;
		this->head = this->tail = nullptr;
		while(n--) 
			this->addHead(0);
	}

	LinkedList(const LinkedList& another) {
		Node* cur = another.head;
		
		this->head = this->tail = nullptr;
		this->len = 0;

		while(cur) {
			this->addHead(cur->data);
			cur = cur->next;
		}
	}

	~LinkedList() {
		Node* cur = this->head;
		
		while(this->head) {
			cur = this->head;
			this->head = this->head->next;
			delete cur;
		}

		this->head = this->tail = nullptr;
	}

	void addTail(int value) {
		if(!this->head) this->head = this->tail = new Node(value);
		else {
			Node* cur = new Node(value);
			cur->prev = this->tail;
			this->tail->next = cur;
			this->tail = cur;
		}
		++this->len;
	}

	void addHead(int value) {
		if(!this->head) this->head = this->tail = new Node(value);
		else {
			Node* cur = new Node(value);
			cur->next = this->head;
			this->head->prev = cur;
			this->head = cur;
		}
		++this->len;
	}

	void popHead() {
		if(!this->head) return;
		Node* cur = this->head;
		this->head = this->head->next;
		this->head->prev = nullptr;
		delete cur;
		--this->len;
	}

	void popTail() {
		if(!this->tail) return;
		Node* cur = this->tail;
		this->tail = this->tail->prev;
		this->tail->next = nullptr;
		delete cur;
		--this->len;
	}

	void remove(Node* node) {
		if(node->next)
			node->next->prev = node->prev;

		if(node->prev)
			node->prev->next = node->next;
		
		delete node;
	}

	void remove(int value) {
		Node* cur = this->head;
		while(cur) {
			if(cur->data == value) {
				Node* next = cur->next;
				this->remove(cur);
				cur = next;
				--this->len;
			} else cur = cur->next;
		}
	}

	void printList(std::ostream& s = std::cout) const {
		for(Node* cur = this->head; cur; cur = cur->next)
			s << cur->data << ' ';
	}

	bool empty() {
		return this->head == nullptr;
	}

	int size() {
		return this->len;
	}
};

std::ostream& operator << (std::ostream& s, const LinkedList& a) {
	a.printList(s);
	return s;
}

class Stack
{
private:
	Node* head;
	int len;

public:
	Stack() {
		this->len = 0;
		this->head = nullptr;
	}

	Stack(const Stack& another) {
		Node* cur = another.head;
		this->head = nullptr;
		while(cur) 
			this->push(cur->data), 
			cur = cur->next;
	}

	~Stack() {
		Node* cur = head;
		while(head) {
			cur = head;
			head = head->next;
			delete cur;
		}
	}

	bool empty() {
		return this->head == nullptr;
	}

	int size() {
		return this->len;
	}

	int top() {
		return this->head->data;
	}

	void push(int value) {
		Node* cur = new Node(value);
		cur->next = head;
		head = cur;
		++len;
	}

	void pop() {
		if(head) {
			Node* cur = head;
			head = head->next;
			delete cur;
			--len;
		}
	}
};

class Queue
{
private:
	Node *head, *tail;
	int len;
public:
	Queue() {
		this->head = this->tail = nullptr;
		this->len = 0;
	}

	Queue(const Queue& another) {
		this->head = this->tail = nullptr;

	}
};

int main(int argcount,char** argvalue) {
	Stack st;
	int n = 13;
	while(n) st.push(n % 2), n /= 2;
	while(!st.empty()) std::cout << st.top() << ' ', st.pop();
	return 0;
}