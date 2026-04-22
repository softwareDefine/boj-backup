#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

bool comp1(pair<ll, ll> a, pair<ll, ll> b){
        return a.second>b.second;
}

bool comp2(pair<ll, ll> a, pair<ll, ll> b){
        return a.first>b.first;
}

int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n, m, k;
        pair<ll, ll> arr[200000];
        cin>>n>>m>>k;
        for(int i=0;i<n;i++)
                cin>>arr[i].first>>arr[i].second;
        sort(arr, arr+n, comp1);
        sort(arr+k, arr+n, comp2);
        ll total=0;
        for(int i=0;i<m+k;i++)
                total+=arr[i].first;
        cout<<total<<'\n';
}