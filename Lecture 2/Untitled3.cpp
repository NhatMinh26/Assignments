#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* prev;
	Node* next;
	
	Node(int value) {
		this->data = value;
		this->next = NULL;
		this->prev = NULL;
	}
};

class LinkedList {
	private:
		Node* head;
		Node* tail;
	public:
		Node* readList(int n) {
			head = NULL;
			tail = NULL;
			
			for (int i=0; i<n; i++) {
				int num;
				cin >> num;
				Node* newNode = new Node(num);
				if (tail == NULL) {
					head = newNode;
					tail = newNode;
				}
				else {
					tail->next = newNode;
					newNode->prev = tail;
					tail = newNode;
				}
			}
			return head;
		}
		
		int count_triple() {
			int count = 0;
			if (head == NULL || head->next == NULL || head->next->next == NULL) {
				return 0;
			}
			Node* current = head->next;
			while(current->next->next != NULL) {
				int sum = current->data + current->prev->data + current->next->data;
				if (sum == 0) {
					count++;
					//cout << current->prev->data << " " << current->data << current->next->data << endl;
				}
				current = current->next;
			}
			int sum = current->data + current->prev->data + current->next->data;
				if (sum == 0) {
					count++;
				}
			return count;
		}
};

int main() {
	int n;
	cin >> n; 
	LinkedList l;
	Node* head = l.readList(n);
	int result = l.count_triple();
	cout << result;
	return 0;
}
