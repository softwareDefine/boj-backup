#include <bits/stdc++.h>

using ll = long long;
using namespace std;
int n,q;
ll arr[200000];
int main(){
    cin >> n;
    for(int i=0;i<n;i++){cin >> arr[i];}
    cin >> q;
    while(q--){
        int a , b,c;
        cin >> a >> b;
        if(a == 1){
            cin >> c;
            int last = c;
            for(int i=b-1;i >=0;i--){
                if(arr[i] < last){
                    last -= arr[i];
                    arr[i] *=2;
                }
                else if(arr[i] >= last){
                    arr[i]+= last;
                    last = 0;
                }
                if(!last){
                    break;
                }
            }
            last = c;
            for(int i=b;i<n;i++){
                if(arr[i] < last){
                    last -= arr[i];
                    arr[i] *=2;
                }
                else if(arr[i] >= last){
                    arr[i]+= last;
                    last = 0;
                }
                if(!last){
                    break;
                }
            }
        }else{
            cout << arr[b-1] << '\n';
        }
    }
}