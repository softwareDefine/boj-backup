#include <bits/stdc++.h>

using namespace std;

int n,q1;

pair<int,int> arr[300000];
vector<int> q;
vector<int> ans;
map<int,int> ishouse;
int d[300000];
int sum[300000];
int sum2[300000];

int main(){
    cin >> n >> q1;
    for(int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;
        q.push_back(arr[i].second);
        ishouse[arr[i].second] = 1;
    }
    for(int i=1;i<=q1;i++){
        int qj;
        cin >> qj;
        //isquery[qj] = 1;
        ans.push_back(qj);
        if(!(ishouse[qj])){
            q.push_back(qj);
        }
    }
    sort(q.begin(),q.end());
    for(int i=0;i<q.size();i++){
        d[lower_bound(q.begin(),q.end(),arr[i].second) - q.begin()] += arr[i].first;
    }
    for(int i=1;i<q.size();i++){
        d[i] += d[i-1];
    }
    for(int i=1;i<q.size();i++){
        sum[i] += sum[i-1] + d[i-1]*(q[i]-q[i-1]);
    }
    memset(d,0,sizeof(d));
    for(int i=0;i<n;i++){
        d[lower_bound(q.begin(),q.end(),arr[i].second) - q.begin()] += arr[i].first;
    }
    for(int i=q.size()-2;i>=0;i--){
        d[i] += d[i+1];
    }
    for(int i=q.size()-2;i>=0;i--){
        sum2[i] += sum2[i+1] + d[i+1]*(q[i+1]-q[i]);
    }
    for(int i=0;i<q.size();i++){
        sum[i] += sum2[i];
    }
    for(auto element : ans){
        cout << sum[lower_bound(q.begin(),q.end(),element) - q.begin()] << '\n';
    }
}