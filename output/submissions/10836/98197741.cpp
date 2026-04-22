#include <bits/stdc++.h>

using namespace std;

int m,n;

int queryed[2000000];
int summed[2000000];
int mp[1000][1000];

int main(){
    cin >> m >> n;
    queryed[0]++;
    for(int i=0;i<n;i++){
        int zero,one,second;
        cin >> zero >> one >> second;
        one += zero;
        queryed[zero]++;
        queryed[one]++;
    }
    for(int i=0;i<2*m-1;i++){
        summed[i] = (i-1>=0?summed[i-1]:0)+queryed[i];
    }
    for(int i=m-1;i>=0;i--){
        mp[i][0] = summed[m-1-i];
    }
    for(int j=1;j<m;j++){
        mp[0][j] = summed[m-1+j];
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<m;j++){
            mp[i][j] = mp[0][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout << mp[i][j] << ' ';
        }
        cout << '\n';
    }
}