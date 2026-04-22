#include <bits/stdc++.h>

using namespace std;

int n;
int arr[4000];
map<int,pair<int,int>> mp[4000];
int mmx;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i]; 
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int beforeN = 1;
            int beforeT = arr[i];
            if(mp[i].find(arr[j]-arr[i]) != mp[i].end()){
                beforeN = mp[i][arr[j]-arr[i]].first;
                beforeT = mp[i][arr[j]-arr[i]].second;
            }
            mp[j][arr[j]-arr[i]] = {beforeN+1,arr[j]+beforeT};
            if(beforeN+1 >= 3){
                mmx = max(mmx,arr[j]+beforeT);
            }
        }
    }
    cout << mmx;
}