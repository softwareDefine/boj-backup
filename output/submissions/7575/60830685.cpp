#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<int> arr[1010];
int t, k,n;
int mnlen = 99999, mnidx;
int flag = 0;

vector<int> ptr;
vector<int> ptre;
int fail[1010];
int fail2[1010];
void preprocessing(vector<int> &ptr) {
	int j = 0;
	for (int i = 1; i < k; i++) {
		while (j > 0 && ptr[i] != ptr[j]) { j = fail[j - 1]; }
		if (ptr[i] == ptr[j]) {
			fail[j] = ++j;
		}
		else {
			fail[j] = 0;
		}
	}
}
void preprocessing2(vector<int> &ptr) {
	int j = 0;
	for (int i = 1; i < k; i++) {
		while (j > 0 && ptr[i] != ptr[j]) { j = fail2[j - 1]; }
		if (ptr[i] == ptr[j]) {
			fail2[j] = ++j;
		}
		else {
			fail2[j] = 0;
		}
	}
}
bool kmp( vector<int> &ptr,vector<int> &str) {
	int j = 0;
	for (int i = 0; i < str.size(); i++) {
		while (j > 0 && str[i] != ptr[j]) { j = fail[j - 1]; }
		if (str[i] == ptr[j]) {
			if (j == k - 1) {
				return 1;
			}
			else {
				j++;
			}
		}
	}
	return 0;
}
bool kmp2(vector<int>& ptr,vector<int>& str ) {
	int j = 0;
	for (int i = 0; i < str.size(); i++) {
		while (j > 0 && str[i] != ptr[j]) { j = fail2[j - 1]; }
		if (str[i] == ptr[j]) {
			if (j == k - 1) {
				return 1;
			}
			else {
				j++;
			}
		}
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> t >> k;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		if (n < mnlen) {
			mnlen = n;
			mnidx = i;
		}
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			arr[i].push_back(a);
		}
	}
	//자르기 ㅇㅇ
	for (int i = 0; i <= mnlen-k; i++) {
		memset(fail, 0, sizeof(fail));
		memset(fail2, 0, sizeof(fail2));
		ptr.clear();
		ptre.clear();
		for (int j = i; j < i+k; j++) {
			ptr.push_back(arr[mnidx][j]);
			ptre.push_back(arr[mnidx][2*i + k-j-1]);
		}
		preprocessing(ptr);
		preprocessing2(ptre);
		flag = 0;
		for (int j = 0; j < t; j++) {
			if (!kmp(ptr, arr[j]) && !kmp2(ptre, arr[j])) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << "YES";
			break;
		}
	}
	if (flag == 1) {
		cout << "NO";
	}
}