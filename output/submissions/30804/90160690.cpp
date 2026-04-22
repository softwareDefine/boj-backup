#include<iostream>
#include<map>

using namespace std;

int n;
int mmx = 0;
int arr[210000];
map<int,int> mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int s = 0, e= 0;
    while(s <= e && e <= n){
        if(mp.size() <= 2){
            mmx = max(mmx, e-s);
            mp[arr[e]]++;
            e++;
        }else{
            mp[arr[s]]--;
            if(!mp[arr[s]]){
                mp.erase(arr[s]);
            }
            s++;
        }
    }
    cout << mmx;
}