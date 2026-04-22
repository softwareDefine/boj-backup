#include <bits/stdc++.h>

using namespace std;

int s;
int m,n;
int arr[2000];
int brr[2000];

map<int,int> mp1;
map<int,int> mp2;

int cnt;
int sumA,sumB;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    cin >> m >> n;
    for(int i=0;i<m;i++){
        cin >> arr[i];
        arr[i+m] = arr[i];
        sumA += arr[i];
    }
    for(int i=0;i<n;i++){
        cin >> brr[i];
        brr[i+n] = brr[i];
        sumB += brr[i];
    }
    mp1.insert({0,1});
    mp1.insert({sumA,1});
    for(int i=0;i<m;i++){
        int tmpSum = 0;
        for(int j=0;j<m-1;j++){
            tmpSum += arr[i+j];
            if(mp1.find(tmpSum) == mp1.end()){
                mp1.insert({tmpSum,1});
            }else{
                mp1[tmpSum]++;
            }
        }
    }
    mp2.insert({0,1});
    mp2.insert({sumB,1});
    for(int i=0;i<n;i++){
        int tmpSum = 0;
        for(int j=0;j<n-1;j++){
            tmpSum += brr[i+j];
            if(mp2.find(tmpSum) == mp2.end()){
                mp2.insert({tmpSum,1});
            }else{
                mp2[tmpSum]++;
            }
        }
    }
    for(auto now : mp1){
        if(s-now.first < 0){break;}
        if(mp2.find(s-now.first) != mp2.end()){
            cnt += mp2[s-now.first]*now.second;
        }
    }
    cout << cnt;
    return 0;
}