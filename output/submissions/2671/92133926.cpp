#include<bits/stdc++.h>

using namespace std;

string str;
queue<pair<int,pair<int,int>>> qu; // version 몇번째 위치 그 문자열 위치
int chk = 0;
int main(){
    cin >> str;
    if(str[0] == '1'){
        qu.push({1,{0,0}});
    }else{
        qu.push({2,{0,0}});
    }
    while(!qu.empty()){
        int version = qu.front().first;
        int loc = qu.front().second.first;
        int sloc = qu.front().second.second;
        //if(loc == str.size() - 1){ chk = 1;}
        //cout << version << ' ' << loc << '\n';
        qu.pop();
        if(version == 1){
            if(str[loc+1] == '1'){
                if(sloc+1 >2){
                    if(str[loc] == '0'){
                        if(loc+1 == str.length()-1){chk = 1;}
                        qu.push({1,{loc+1,sloc+1}});
                    }else{
                        if(loc+1 == str.length()-1){chk = 1;}
                        qu.push({1,{loc+1,sloc+1}});
                        qu.push({1,{loc+1,0}});
                    }
                }
            }else{
                if(str[loc+1] == '0'){
                    if(str[loc] == '1'){
                        if(sloc == 0){
                            qu.push({1,{loc+1,sloc+1}});
                        }else{
                            qu.push({2,{loc+1,0}});
                        }
                    }else{
                        qu.push({1,{loc+1,sloc+1}});
                    }
                }
            }
        }else{
            if(str[loc+1] == '1'){
                if(sloc+1 >=2){
                    if(str[loc] == '1'){
                        qu.push({1,{loc+1,0}});
                    }
                }else{
                    if(str[loc] == '0'){
                        if(loc+1 == str.length()-1){chk = 1;}
                        qu.push({2,{loc+1,sloc+1}});
                    }
                }            
            }else{
                if(str[loc+1] == '0'){
                    if(str[loc] == '1'){
                        qu.push({2,{loc+1,0}});
                    }
                }
            }
        }
    }
    if(chk){ cout << "SUBMARINE"; }
    else{ cout << "NOISE"; }
}