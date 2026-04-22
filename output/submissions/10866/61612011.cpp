#include <iostream>
#include <deque>

using namespace std;
deque<int> dq;
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		if (a == "push_back") {
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if (a == "push_front") {
			int x;
			cin >> x;
			dq.push_front(x);
		}
		else if (a == "pop_front") {
			if (dq.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (a == "pop_back") {
			if (dq.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (a == "size") {
			cout << dq.size() << '\n';
		}
		else if (a == "empty") {
			if (dq.empty()) {
				cout << "1" << '\n';
			}
			else {
				cout << "0" << '\n';
			}
		}
		else if (a == "front") {
			if (dq.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << dq.front() << '\n';
			}
		}
		else if (a == "back") {
			if (dq.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << dq.back() << '\n';
			}
		}
	}
}