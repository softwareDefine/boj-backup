#include <iostream>

using namespace std;
int n, m;
int ans[10];
bool checker = false;
void backtracking(int now) {
	if (now == 0) {
        for(int i=m;i>=1;i--) {
                cout << ans[i] <<" ";
        }
        cout <<"\n";
        return ;
	}
	for (int i = 1; i <= n;i++) {
        checker = false;
        for(int j=1;j<=n;j++){
            if(ans[j]==i){
                checker = true;
            }
        }
        if(checker == false){
            ans[now] = i;
            backtracking(now-1);
            ans[now] = 0;
        }

	}
}


int main()
{
	cin >> n >> m;
	backtracking(m);
}
