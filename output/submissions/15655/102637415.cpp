#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];

vector<int> seq;

void go(int now, int used){
    if(used == m){
        for(auto element : seq){
            cout << element << ' ';
        }
        cout << '\n';
        return;
    }
    if(used >= m || now >= n){ return; }
    for(int i = now+1; i<n; i++){
        seq.push_back(arr[i]);
        go(i, used+1);
        seq.pop_back();
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    go(-1,0);
    return 0;
}