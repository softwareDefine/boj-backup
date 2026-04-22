#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stack>

using namespace std;

int main()
{
	int num = 0;
	int height;
	stack<pair<int, int>> st; // fist <- "높이" ,second<- "인덱스"
	scanf("%d", &num);
	for (int i = 1; i <= num; i++) {
		scanf("%d", &height);	
		while (!st.empty() && st.top().first < height  ) {
			st.pop();
		}	
		if (st.empty()) {
			printf("%d\n", 0);
			st.push({ height,i });
			continue;
		}
		printf("%d\n", st.top().second);	
		st.push({height,i});
		
		
	
	}
}