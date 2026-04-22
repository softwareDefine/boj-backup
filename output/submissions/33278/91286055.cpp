#include <bits/stdc++.h>

using namespace std;

int n,t;
pair<int,int> xh[310000];
long long sum = 0;
int nextx = 0;

int cmp(pair<int,int> a,pair<int,int> b){
    return a < b;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> t;
    for(int i=0;i<n;i++){
        cin >> xh[i].first >>  xh[i].second;
    }
    sort(xh,xh+n,cmp);
    for(int i=0;i<n-1;i++){
        nextx = max(nextx,xh[i].second/t + xh[i].first);
        sum +=max(0,min(xh[i+1].second,(nextx-xh[i+1].first)*t));
    }
    cout << sum;
}