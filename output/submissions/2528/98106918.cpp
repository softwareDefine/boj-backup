#include <bits/stdc++.h>

using namespace std;

int n,l;
vector<pair<int,int>> vc;

pair<int,int> move(int len,int dir,int now){
    if(dir==0){
        if((now/(l-len))%2 == 0){
            return {now%(l-len),len + now%(l-len) -1};
        }else{
            return {l-len-now%(l-len),l-now%(l-len)-1};
        }
    }else{
        if((now/(l-len))%2 != 0){
            return {now%(l-len),len + now%(l-len) -1};
        }else{
            return {l-len-now%(l-len),l-now%(l-len)-1};
        }
    }
    return {0,0};
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> l;
    for(int i=0;i<n;i++){
        int len,dir;
        cin >> len >> dir;
        vc.push_back({len,dir});
    }
    int now = 0;
    for(int i=0;i<n-1;i++){
        while(1){
            pair<int,int> line1 = move(vc[i].first,vc[i].second,now);
            pair<int,int> line2 = move(vc[i+1].first,vc[i+1].second,now);
            if(((line1.second < line2.first-1) || (line2.second+1 < line1.first))){
                //cout << line1.first << ' ' << line1.second << '\n';
                //cout << line2.first << ' ' << line2.second << '\n';
                now++;
                //continue;
            }else{
                break;
            }
        }
    }
    cout << now;
}