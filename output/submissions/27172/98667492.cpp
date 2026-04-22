#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> q;
int isquery[2000000];
int arr[2000000];

void cal(int now){
    for(int i=1;i*i<=now;i++){
        if(!(now%i)){
            int cnt =0;
            if(isquery[i] && i!=now){
                arr[i]++;
                cnt++;
            }
            if(isquery[now/i] && now/i != now && i != now/i){
                arr[now/i]++;   
                cnt++;
            }
            arr[now] -= cnt;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        isquery[a]++;
        q.push_back(a);
    }
    for(auto element: q){
        cal(element);
    }
    for(auto element: q){
        cout << arr[element] << ' '; 
    }
}