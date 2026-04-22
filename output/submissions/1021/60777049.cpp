#define _CRT_SECURE_NO_WARNINGS
#include <queue>
#include <cstdio>

using namespace std;


deque<int> du;

void insert(int num) {
	for (int i = 1; i <= num; i++) {
		du.push_back(i);
	}
}
int num;
int fn;
int finder[50];
int cnt = 0;
int main()
{
	scanf("%d %d", &num, &fn);
	for (int z = 0; z < fn; z++) {
		scanf("%d", &finder[z]);
	}
	insert(num);
	for (int i = 0; i < fn; i++) {
		int inx=0;
		int size = du.size();
		for (int j = 0; j < size; j++) {
			if (du[j] == finder[i]) {
				// 참고 함.
				if (j * 2 <= du.size()) goto one;
				else goto two;
			}
		}
		one :
			//2번 작업 수행
			while (du.front()!=finder[i]) {
				du.push_back(du.front());
				du.pop_front();
				cnt++;
			}
			du.pop_front();
		continue;
		two :
			//3번 작업 수행
			while (du.front() != finder[i]) {
				du.push_front(du.back());
				du.pop_back();
				cnt++;
			}
			du.pop_front();
	}
	printf("%d ", cnt);
}