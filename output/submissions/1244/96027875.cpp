#include <bits/stdc++.h>

using namespace std;

int n;
int p;
int arr[200];

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    cin >> p;
    for(int i=0;i<p;i++){
        int s,v;
        cin >> s >> v;
        if(s== 1){
            for(int i=1;i*v<=n;i++){
                arr[i*v] = abs(arr[i*v]-1);
            }
        }else{
            for(int i=0;v+i <=n && v-i >0;i++){
                if(arr[v+i] == arr[v-i]){
                    arr[v+i]=abs(arr[v+i]-1);
                    if(i==0){
                        continue;
                    }
                    arr[v-i]=abs(arr[v-i]-1);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << arr[i] << ' ';
        if(!(n%20)){
            cout << '\n';
        }
    }
}
