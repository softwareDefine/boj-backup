#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

deque<char> qu;
string arr;


int main()
{
	cin >> arr;
	for (int i = 0; i < arr.length(); i++) {
		if (qu.empty()) {
			qu.push_back(arr[i]);
			continue;
		}
		if (qu.front() >= arr[i]) {
			qu.push_front(arr[i]);
		}
		else {
			qu.push_back(arr[i]);
		}
	}
	int szze = qu.size();
	for (int i = 0; i < szze; i++) {
		cout << qu[i];
	}
}