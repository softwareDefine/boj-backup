#include<bits/stdc++.h>

using namespace std;

int n,k;
int arr[200000];
vector<int> vc;
int mnu = 0;
int sum = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    sum = arr[n-1] - arr[0];
    for(int i=1;i<n;i++){
        vc.push_back(arr[i]-arr[i-1]);
    }
    sort(vc.begin(),vc.end(), [&](int a,int b){return a > b;});
    for(int i=0;i < k-1;i++){
        mnu+=vc[i];
    }
    sum -= mnu;
    cout << sum;
}