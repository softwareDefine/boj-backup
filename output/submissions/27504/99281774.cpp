#include <bits/stdc++.h>

using namespace std;

vector<int> arr[5000];
vector<int> diffarr[5000];
vector<int> brr;
vector<int> diffbrr;
vector<int> ans;

int pi[2000000];
int n, k, l;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> k;
        for(int j=0;j<k;j++){
            int a;
            cin >> a;
            arr[i].push_back(a);
        }
        for(int j=0;j<k-1;j++){
            diffarr[i].push_back(arr[i][j+1]-arr[i][j]);
        }
    }
    cin >> l;
    for(int i=0;i<l;i++){
        int a;
        cin >> a;
        brr.push_back(a);
    }
    for(int i=0;i<l-1;i++){
        diffbrr.push_back(brr[i+1]-brr[i]);
    }
    int j = 0;
    for(int i=1;i<diffbrr.size();i++){
        while( j > 0 && diffbrr[i] != diffbrr[j]){
            j = pi[j-1];
        }
        if(diffbrr[i] == diffbrr[j]){
            pi[i] = ++j;   
        }
    }
    for(int t=0;t<n;t++){
        j = 0;
        for(int i = 0; i< diffarr[t].size() ; i++){
            while(j > 0 && diffarr[t][i] != diffbrr[j] ){
                j = pi[j-1];
            }
            if(diffarr[t][i] == diffbrr[j]){
                if(j == diffbrr.size()-1){
                    ans.push_back(t+1);
                    break;
                }else{
                    ++j;
                }
            }
        }
    }
    if(ans.empty()){
        cout << -1;
        return 0;
    }
    for(auto element : ans){
        cout << element << ' ';
    }
    return 0;
}