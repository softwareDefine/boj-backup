#include <bits/stdc++.h>

using namespace std;

int r,c,t;

int mp[100][100];
int tmp[100][100];

vector<int> aircond;

int sum;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> r >> c >> t;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> mp[i][j];
            if(mp[i][j] == -1){
                aircond.push_back(i);
            }
        }
    }
    while(t--){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mp[i][j] == -1){ tmp[i][j] = mp[i][j];}
                if(mp[i][j] > 0){
                    int cnt = 0;
                    if(i+1 < r && mp[i+1][j] != -1){
                        tmp[i+1][j] += mp[i][j]/5;
                        cnt++;
                    }
                    if(i-1 >= 0 && mp[i-1][j] != -1){
                        tmp[i-1][j] += mp[i][j]/5;
                        cnt++;
                    }
                    if(j+1 < c && mp[i][j+1] != -1){
                        tmp[i][j+1] += mp[i][j]/5;
                        cnt++;
                    }
                    if(j-1 >= 0 && mp[i][j-1] != -1){
                        tmp[i][j-1] += mp[i][j]/5;
                        cnt++;
                    }
                    tmp[i][j] += mp[i][j] - (mp[i][j]/5)*cnt;
                }
            }
        }
        int aCircle = aircond[0];
        int bCircle = aircond[1];
        while(aCircle){
            if(tmp[aCircle][0] == -1){
                tmp[aCircle-1][0] = 0;
            }else{
                tmp[aCircle][0] = tmp[aCircle-1][0];
                tmp[aCircle-1][0] = 0;
            }
            aCircle--;
        }
        aCircle = 0;
        while(aCircle != c-1){
            tmp[0][aCircle] = tmp[0][aCircle+1];
            tmp[0][aCircle+1] = 0;
            aCircle++;
        }
        aCircle = 0;
        while(aCircle != aircond[0]){
            tmp[aCircle][c-1] = tmp[aCircle+1][c-1];
            tmp[aCircle+1][c-1] = 0;
            aCircle++;
        }
        aCircle = c-1;
        while(aCircle){
            if(tmp[aircond[0]][aCircle-1] != -1){
                tmp[aircond[0]][aCircle] = tmp[aircond[0]][aCircle-1];
                tmp[aircond[0]][aCircle-1] = 0;   
            }
            aCircle--;
        }
        while(bCircle != r-1){
            if(tmp[bCircle][0] == -1){
                tmp[bCircle+1][0] = 0;
            }else{
                tmp[bCircle][0] = tmp[bCircle+1][0];
                tmp[bCircle+1][0] = 0;
            }
            bCircle++;
        }
        bCircle = 0;
        while(bCircle != c-1){
            tmp[r-1][bCircle] = tmp[r-1][bCircle+1];
            tmp[r-1][bCircle+1] = 0;
            bCircle++;
        }
        bCircle = r-1;
        while(bCircle != aircond[1]){
            tmp[bCircle][c-1] = tmp[bCircle-1][c-1];
            tmp[bCircle-1][c-1] = 0;
            bCircle--;
        }
        bCircle = c-1;
        while(bCircle){
            if(tmp[aircond[1]][bCircle-1] != -1){
                tmp[aircond[1]][bCircle] = tmp[aircond[1]][bCircle-1];
                tmp[aircond[1]][bCircle-1] = 0;   
            }
            bCircle--;
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                mp[i][j] = tmp[i][j];
                tmp[i][j] = 0;
            }
        }
    }
    //cout << '\n';
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mp[i][j] > 0){
                sum += mp[i][j];
            }
            //cout << mp[i][j] << ' ';
        }
        //cout << '\n';
    }
    cout << sum;
}