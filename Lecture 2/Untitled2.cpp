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

class LinkedList {
	private:
		Node* head;
	public:
		LinkedList() {
			head = NULL;
		}
		
		void insertNode(int pos, int data) {
			Node* newNode = new Node(data);
			
			if (pos == 0) {
				newNode->next = head;
				head = newNode;
			}
			else {
				Node* current = head;
				for (int i=0; i<pos-1; i++) {
					current = current->next;
				}
				if (current) {
					newNode->next = current->next;
					current->next = newNode;
				}
			}
		}
		
		void deleteNode(int pos) {
			if (pos == 0) {
				if (head) {
					Node* temp = head;
					head = head->next;
					delete temp;
				}
			}
			else {
				Node* current = head;
				for (int i=0; i<pos-1; i++) {
					current = current->next;
				}
				if (current && current->next) {
					Node* temp = current->next;
					current->next = current->next->next;
					delete temp;
				}
			}
		}
		
		void print() {
			Node* current = head;
			while (current) {
				cout << current->data << " ";
				current = current->next;
			}
			cout << endl;
		}
};

int main() {
	int n;
	cin >> n;
	LinkedList l;
	for (int i=0; i<n; i++) {
		string method;
		cin >> method;
		if (method == "insert") {
			int p, x;
			cin >> p >> x;
			l.insertNode(p, x);
		}
		else if (method == "delete") {
			int p;
			cin >> p;
			l.deleteNode(p);
		}
	}
	l.print();
	return 0;
}
