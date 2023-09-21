#include <bits/stdc++.h>
using namespace std;

class Queue {
	private:
		vector<int> data;
	public:
		bool emty_() {
			return data.empty();
		}
		
		void enqueue(int x) {
			data.push_back(x);
		} 
		
		void dequeue() {
			if (!emty_()) {
				data.erase(data.begin());
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
	Queue q;
	while (n--) {
		string method;
		cin >> method;
		if (method == "enqueue") {
			int x;
			cin >> x;
			q.enqueue(x);
		}
		else if (method == "dequeue") {
			q.dequeue();
		}
	}
	q.print();
	return 0;
}
