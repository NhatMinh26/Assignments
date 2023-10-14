#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    vector<Node*> children;
};

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    return temp;
}

bool isBalaceBinaryTree(Node* root, int& height) {
    if (root == NULL) {
    	height = 0; 
    	return true;
	}
	
	vector<int> childHeights;
	for (Node* child : root->children) {
		int childHeight = 0;
		if (!isBalanceBinaryTree(child, childHeight)) {
			return false;
		}
		childHeights.push_back(childHeight);
	}
	int maxHeight = 0;
	for (int childHeight : childHeights) {
		if (childHeight > maxHeight) {
			maxHeight = childHeight;
		}
	}
	height = maxHeight + 1;
	for (int childHeight : childHeights) {
		if (maxHeight - childHeight > 1) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	
	unordered_map<int, Node*> tree;
	
	for (int i=0; i<n-1; i++) {
		int u, v; 
		cin >> u >> v;
		
		if (tree.find(u) == tree.end()) {
			tree[u] = newNode(u);
		}
		
		if (tree.find(v) == tree.end()) {
			tree[v] = newNode(v);
		}
		tree[u]->children.push_back(tree[v]);
	} 
	int height = 0;
	if (isBalanceBinaryTree(tree[0], height)) {
		cout << "yes";
	} else {
		cout << "no";
	}
	return 0;
}
