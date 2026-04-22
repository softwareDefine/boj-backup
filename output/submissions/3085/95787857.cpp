#include <bits/stdc++.h>

using namespace std;

int n;
string mp[500];
int mmx = 0;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> mp[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            swap(mp[i][j],mp[i][j+1]);
            int cnt = 0;
            for(int p=0;p<n;p++){
                for(int q=0;q<n-1;q++){
                    if(mp[p][q] == mp[p][q+1]){
                        cnt++;
                    }else{
                        cnt = 0;
                    }
                    mmx = max(cnt,mmx);
                }
                cnt = 0;
            }
            cnt = 0;
            for(int q=0;q<n;q++){
                for(int p=0;p<n-1;p++){
                    if(mp[p+1][q] == mp[p][q]){
                        cnt++;
                    }else{
                        cnt = 0;
                    }
                    mmx = max(cnt,mmx);
                }
                cnt = 0;
            }
            swap(mp[i][j],mp[i][j+1]);
        }
        if(i == n-1){continue;}
        for(int j=0;j<n;j++){
            swap(mp[i][j],mp[i+1][j]);
            int cnt = 0;
            for(int p=0;p<n;p++){
                for(int q=0;q<n-1;q++){
                    if(mp[p][q] == mp[p][q+1]){
                        cnt++;
                    }else{
                        cnt = 0;
                    }
                    mmx = max(cnt,mmx);
                } cnt = 0;
            }
            cnt = 0;
            for(int q=0;q<n;q++){
                for(int p=0;p<n-1;p++){
                    if(mp[p+1][q] == mp[p][q]){
                        cnt++;
                    }else{
                        cnt = 0;
                    }
                    mmx = max(cnt,mmx);
                } cnt = 0;
            }
            swap(mp[i][j],mp[i+1][j]);
        }
    }
    cout << mmx+1;
}