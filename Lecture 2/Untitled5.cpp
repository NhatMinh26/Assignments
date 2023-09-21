#include <bits/stdc++.h>
using namespace std;

class Stack {
	private:
		vector<int> data;
	public:
		bool empty_() {
			return data.empty();
		}
		
		void push(int x) {
			data.push_back(x);
		}
		
		void pop() {
			if (!empty_()) {
				data.pop_back();
			}
		}
		
		void print() {
			for (int i=0; i<data.size(); i++) {
				cout << data[i] << " ";
			}
		}
};

int main() {
	int n;
	cin >> n;
	Stack s;
	while (n--) {
		string method;
		cin >> method;
		if (method == "push") {
			int x;
			cin >> x;
			s.push(x);
		}
		else if (method == "pop") {
			s.pop();
		}
	}
	s.print();
	return 0;
}
