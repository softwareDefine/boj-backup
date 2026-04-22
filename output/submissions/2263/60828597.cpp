#include <iostream>
#include <vector>

using namespace std;
int n;
int in[1000010];
int post[1000010];
int idx[1000010];
vector<int> vc;
// 뒤에 부모인덱스
void DnC(int start,int end,int right) {
	if (start > end) {
		return;
	}
	int mid;
	mid = post[end - right];
	if (start == end) {
		cout << mid << ' ';
		return;
	}
	//cout << start << ' ' << end<< '\n';
	cout << mid << ' '; 
		//cout << start << ' ' << idx[mid] - 1 << '\n';
		DnC(start, idx[mid] - 1, right);

		//cout << idx[mid]+1 << ' ' << end << '\n';
		DnC(idx[mid] + 1, end, right+1);

	
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> in[i];
		idx[in[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> post[i];
	}
	DnC(1,n,0);
}