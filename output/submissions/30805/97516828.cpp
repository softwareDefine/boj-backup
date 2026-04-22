#include <bits/stdc++.h>

using namespace std;

int n;
int arr[200];
int m;
int brr[200];
vector<int> vc;
void go(int aStart,int bStart){
    if(aStart >= n || bStart >=m){
        return;
    }
    int aList[200];
    memset(aList,-1,sizeof(aList));
    for(int i=aStart;i<n;i++){
        if(aList[arr[i]] == -1){
            aList[arr[i]] = i;
        }
    }
    int mmx = 0;
    pair<int,int> mmxi;
    for(int i=bStart;i<m;i++){
        if(aList[brr[i]] != -1){
            if(mmx < brr[i]){
                mmx = brr[i];
                mmxi = {aList[brr[i]],i};
            }
        }
    }
    if(mmx > 0){
        vc.push_back(mmx);
        go(mmxi.first+1,mmxi.second+1);
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> brr[i];
    }
    go(0,0);
    cout << vc.size() << '\n';
    for(auto e : vc){
        cout << e << ' ';
    }
}