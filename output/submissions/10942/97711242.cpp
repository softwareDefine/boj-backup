#include <bits/stdc++.h>

using namespace std;

int n;
int arr[3000];
int m;
int query[3000][3000];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        int start = i;
        int end = i;
        while(start >=0 && end <n && arr[start] == arr[end]){
            query[start][end] = 1;
            start--;
            end++;
        }
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int s,e;
        cin >> s >> e;
        cout << query[s-1][e-1] << '\n';
    }
}