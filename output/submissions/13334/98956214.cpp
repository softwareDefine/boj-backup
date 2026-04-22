#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n;

vector<pair<lint,lint>> line;
int d;
int cnt;
int mmx;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        lint a,b;
        cin >> a >> b;
        if(a > b){swap(a,b);}
        line.push_back({a,b});
    }
    cin >> d;
    sort(line.begin(),line.end());
    lint start = 0;
    for(int i=0;i<n;i++){
        if(line[i].second <=line[start].first + d){
            cnt++;
        }else{
            mmx = max(mmx,cnt);
            int before = line[start].first;
            while(before==line[start].second){
                start++;
                cnt--;
            }
        }
    }
    mmx = max(mmx,cnt);
    cout << mmx;
}