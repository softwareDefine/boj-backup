#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n;

lint arr[30000];
int visited[30000];

vector<lint> thing;

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            lint cnt = 0;
            lint now = i;
            while(!visited[now]){
                visited[now] = 1;
                now = arr[now];
                cnt++;
            }
            thing.push_back(cnt);
        }
    }
    lint now = 1;
    for(auto element : thing){
        lint divider = gcd(now,element);
        now = now / divider  * element / divider;
        //now = lcm(now,element);
        //cout << element << ' ';
    }
    cout << now;
}