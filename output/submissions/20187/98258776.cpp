#include <bits/stdc++.h>

using namespace std;

int k;

pair<int,int> st, ed;

vector<char> seq;

int hole;
int mp[500][500];
int wide,height;

int main(){
    cin >> k;
    for(int i=0;i<2*k;i++){
        char act;
        cin >> act;
        seq.push_back(act);
    }
    cin >> hole;
    wide = pow(2,k);
    height = pow(2,k);
    st = {1,1};
    ed = {pow(2,k),pow(2,k)};
    for(int i=0;i<2*k;i++){
        char act = seq[i];
        if(act == 'R'){
            wide/=2;
            st = {st.first + wide, st.second};
        }else if(act == 'L'){
            wide/=2;
            ed = {ed.first - wide, ed.second};
        }else if(act == 'U'){
            height /=2;
            ed = {ed.first, ed.second - height};
        }else{
            height/=2;
            st = {st.first, st.second + height };
        }
    }
    mp[st.second][st.first] = hole;
    reverse(seq.begin(),seq.end());
    for(int i=0;i<2*k;i++){
        char act = seq[i];
        int movement = pow(2,i/2);
        if(act == 'R'){
            for(int i=st.first;i<=ed.first;i++){
                for(int j=st.second;j<=ed.second;j++){
                    if(mp[j][i] == 0){
                        mp[j][st.first-1-(i-st.first)] = 1;
                    }else if(mp[j][i] == 1){
                        mp[j][st.first-1-(i-st.first)] = 0;
                    }else if(mp[j][i] == 2){
                        mp[j][st.first-1-(i-st.first)] = 3;
                    }else{
                        mp[j][st.first-1-(i-st.first)] = 2;
                    }
                }
            }
            st = {st.first - wide, st.second};
            wide *= 2;
        }else if(act == 'L'){
            for(int i=st.first;i<=ed.first;i++){
                for(int j=st.second;j<=ed.second;j++){
                    if(mp[j][i] == 0){
                        mp[j][ed.first+wide-(i-st.first)] = 1;
                    }else if(mp[j][i] == 1){
                        mp[j][ed.first+wide-(i-st.first)] = 0;
                    }else if(mp[j][i] == 2){
                        mp[j][ed.first+wide-(i-st.first)] = 3;
                    }else{
                        mp[j][ed.first+wide-(i-st.first)] = 2;
                    }
                }
            }
            ed = {ed.first + wide, ed.second};
            wide*=2;
        }else if(act == 'U'){
            for(int i=st.first;i<=ed.first;i++){
                for(int j=st.second;j<=ed.second;j++){
                    if(mp[j][i] == 0){
                        mp[ed.second+height-(j-st.second)][i] = 2;
                    }else if(mp[j][i] == 1){
                        mp[ed.second+height-(j-st.second)][i] = 3;
                    }else if(mp[j][i] == 2){
                        mp[ed.second+height-(j-st.second)][i] = 0;
                    }else{
                        mp[ed.second+height-(j-st.second)][i] = 1;
                    }
                }
            }
            ed = {ed.first, ed.second + height};
            height *=2;
        }else{
            for(int i=st.first;i<=ed.first;i++){
                for(int j=st.second;j<=ed.second;j++){
                    if(mp[j][i] == 0){
                        mp[st.second-1-(j-st.second)][i] = 2;
                    }else if(mp[j][i] == 1){
                        mp[st.second-1-(j-st.second)][i] = 3;
                    }else if(mp[j][i] == 2){
                        mp[st.second-1-(j-st.second)][i] = 0;
                    }else{
                        mp[st.second-1-(j-st.second)][i] = 1;
                    }
                }
            }
            //cout << movement << '\n';
            st = {st.first, st.second - height };
            height *= 2;
        }
    //     for(int i=1;i<=pow(2,k);i++){
    //     for(int j=1;j<=pow(2,k);j++){
    //         cout << mp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    //     cout << '\n';
    }
    for(int i=1;i<=pow(2,k);i++){
        for(int j=1;j<=pow(2,k);j++){
            cout << mp[i][j] << ' ';
        }
        cout << '\n';
    }
}