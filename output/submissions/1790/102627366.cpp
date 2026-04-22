#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n, k;
lint border;
lint cnt;
lint diff;

int main(){
    cin >> n >> k;
    border = 10, diff = 1;
    for(lint i = 1; i <= n; i++){
        if(i == border){
            border *= 10;
            diff++;
        }
        cnt += diff;
        if(cnt-diff < k  && k <= cnt ){
            string str = to_string(i);
            cout << str[k-cnt+diff-1];
            return 0;
        }
    }
    cout << -1;
}