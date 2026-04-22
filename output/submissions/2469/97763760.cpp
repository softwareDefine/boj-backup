#include <bits/stdc++.h>

using namespace std;

int n;
int row;
int startseq[30];
int endseq[30];
string res;
int mp[2000][30];
int unknowner;
string order;
int flag = 0;

int main(){
    cin >> n;
    cin >> row;
    cin >> order;
    for(int i=0;i<order.size();i++){
        endseq[i] = order[i]-'A';
        startseq[i] = i;
    }
    for(int i=0;i<row;i++){
        string str;
        cin >> str;
        for(int j=0;j<n-1;j++){
            if(str[j] == '?'){
                unknowner = i;
                break;
            }else{
                if(str[j] == '*'){
                    mp[i][j] = 0;
                }else{
                    mp[i][j] = 1;
                }
            }
        }
    }
    for(int i=0;i<unknowner;i++){
        int nextseq[30] = {0, };
        for(int j=0;j<n;j++){
            if(j-1 >=0 && mp[i][j-1] == 1){
                nextseq[j-1] = startseq[j];
            }
            else if(j+1 < n && mp[i][j] == 1){
                nextseq[j+1] = startseq[j];
            }else{
                nextseq[j] = startseq[j];
            }
        }
        for(int j=0;j<n;j++){
            startseq[j]=nextseq[j]; 
        }
    }
    for(int i=row-1;i> unknowner;i--){
        int nextseq[30] = {0, };
        for(int j=0;j<n;j++){
            if(j-1 >=0 && mp[i][j-1] == 1){
                nextseq[j-1] = endseq[j];
            }
            else if(j+1 < n && mp[i][j] == 1){
                nextseq[j+1] = endseq[j];
            }else{
                nextseq[j] = endseq[j];
            }
        }
        for(int j=0;j<n;j++){
            endseq[j]=nextseq[j]; 
        }
    }
    for(int i=0;i<n-1;){
        if(startseq[i] == endseq[i]){
            res.push_back('*');
            i+=1;
        }else if(startseq[i+1] == endseq[i] && startseq[i] == endseq[i+1]){
            res.push_back('-');
            if(i+2 < n){
            res.push_back('*');   
            }
            i+=2;
        }else{
            flag = 1;
            break;
        }
    }
    if(flag){
        res = "";
        for(int i=0;i<n-1;i++){
            res.push_back('x');
        }
    }
    cout << res;
}