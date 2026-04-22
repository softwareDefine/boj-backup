#include <cstdio>
#include <queue>

int n, l;
int arr[5000000];

using namespace std;

int input() {
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	return 0;
}

typedef struct insi{
	int val;
	int index;
}I;

int main()
{
	deque<I> insider;
	input();
	for (int j = 0; j < n; j++) {
		if (!insider.empty()) {
			if (insider.front().index < j - l + 1) {
				insider.pop_front();
			}
		}
			while (!insider.empty()&& insider.back().val>arr[j]) {
				insider.pop_back();
			}
			insider.push_back({arr[j],j});
	
		printf("%d ", insider.front().val);
	}
	
}
