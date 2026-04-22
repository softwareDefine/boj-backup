#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint l,n,k;

vector<lint> arr;

lint zero;
vector<lint> length;

int main(){
    cin >> l >> n >> k;
    for(int i=0;i<n;i++){
        lint num;
        cin >> num;
        arr.push_back(num);
        zero++;
    }
    for(int i=0;i<n;i++){
        lint now = arr[i];
        if(i==0){
            if(abs(arr[i]-0)){
                length.push_back(abs(arr[i]-0));
            }
        }
        if(i==n-1){
            if(abs(arr[i]-l)){
                length.push_back(abs(arr[i]-l));
            }
        }
        if(i!=n-1){
            lint diff = arr[i+1]-arr[i];
            if(diff <= 0){
                continue;
            }
            if(diff%2){
                length.push_back((arr[i+1]-arr[i])/2);
                length.push_back((arr[i+1]-arr[i])/2);
            }else{
                length.push_back((arr[i+1]-arr[i])/2);
                if((arr[i+1]-arr[i])/2-1 >0){
                    length.push_back((arr[i+1]-arr[i])/2-1);   
                }
            }
        }
    }
    sort(length.begin(),length.end(), [&](lint a, lint b) { return a > b; });
    while(k > 0 && zero > 0){
        cout << 0 << '\n';
        k--;
        zero--;
    }
    int now = 1;
    while(k > 0){
        for(auto element : length){
            if(element >= now && k >0){
                cout << now << '\n';
                k--;
            }else{
                break;
            }
        }  
        now++;
    }
}