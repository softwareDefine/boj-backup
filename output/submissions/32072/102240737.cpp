#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n;

vector<int> childern[310000];

priority_queue<pair<int,int>> pq;

int val[310000];

int valToNum[310000];

int parent[310000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 2; i <= n; i++){
        int pi;
        cin >> pi;
        childern[pi].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        cin >> val[i];
    }
    pq.push({-val[1], 1});
    while(!pq.empty()){
        auto [w , now] = pq.top();
        cout << -w << '\n';
        pq.pop();
        for(auto next : childern[now]){
            pq.push({-val[next], next});
        }
    }
    return 0;
}