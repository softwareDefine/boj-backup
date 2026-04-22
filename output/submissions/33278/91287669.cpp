#include <bits/stdc++.h>

using namespace std;

long long n,t;
pair<long long,long long> xh[310000];
long long sum = 0;
long long nextx = -10000000000LL;

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
        nextx = max(nextx,xh[i].second + xh[i].first*t);
        
        sum += max((long long)0,min(xh[i+1].second,nextx-xh[i+1].first*t));
    }
    cout << sum;
}