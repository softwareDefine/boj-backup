#include <iostream>

using namespace std;

struct Node {
	Node* pre;
	int data;
	Node() {
		pre = nullptr;
		data = -1;
	}
	Node(Node* con, int v) {
		pre = con;
		data = v;
	}
};

int n;
Node* top[1000100];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	top[0] = new Node();
	for (int i = 1; i <= n; i++) {
		char a; int b;
		cin >> a;
		if (a == 'a') {
			cin >> b;
			top[i] = new Node(top[i - 1], b);
		}
		else if (a == 't') {
			cin >> b;
			top[i] = top[b - 1];
		}
		else {
			top[i] = top[i - 2];
		}
		cout << top[i]->data << '\n';
	}
}