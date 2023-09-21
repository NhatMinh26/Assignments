#include <bits/stdc++.h>
using namespace std;

class Node {
	public:
		int data;
		Node* next;
		
		Node(int data) {
			this->data = data;
			this->next = NULL;
		}
};

class Queue {
	private:
		Node* head;
		Node* tail;
	public:
		Queue() {
			this->head = NULL;
			this->tail = NULL;
		}
		
		void enqueue(int x) {
			Node* newNode = new Node(x);
			if (tail == NULL) {
				head = tail = newNode;
			}
			else {
				tail->next = newNode;
				tail = newNode;
			}
		}
		
		void dequeue() {
			if (head == NULL) {
				return;
			}
			head = head->next;
			if (head == NULL) {
				tail = NULL;
			}
		}
		
		void print() {
			Node* current = head;
			while (current != NULL) {
				cout << current->data << " ";
				current = current->next;
			}
		}
};

int main() {
	int n;
	cin >> n;
	Queue q;
	while (n--) {
		string method;
		cin >> method;
		if (method == "enqueue") {
			int x; 
			cin >> x;
			q.enqueue(x);
		} else if (method == "dequeue") {
			q.dequeue();
		}
	}
	q.print();
	return 0;
}
