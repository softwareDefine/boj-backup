#include <bits/stdc++.h>

using namespace std;

int visited[100010];
int x[100010];
int t[100010];
vector<pair<int,int>> newcost;

int n;
int cnt;
int before;
int beforetime;

int cmt(pair<int,int> a,pair<int,int> b){
    return a.first < b.first;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    for(int i=0;i<n;i++){
        cin >> t[i];
    }
    while(cnt != n){
        newcost.clear();
        for(int i=0;i<n;i++){
            if(!visited[i]){
                newcost.push_back({max(abs(x[i]-before),max(t[i]-beforetime,0)),i});
            }
        }
        sort(newcost.begin(),newcost.end(),cmt);
        visited[newcost[0].second] = 1;
        before = newcost[0].second;
        beforetime += newcost[0].first;
        cnt++;
    }
    beforetime += before;
    cout << beforetime;
}