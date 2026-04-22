#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n;

vector<pair<lint,lint>> line;
lint d;
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
        mmx = max(mmx,cnt);
        if(line[i].second <=line[start].first + d){
            cnt++;
        }else{
            int before = line[start].first;
            while(before==line[start].first){
                start++;
                cnt--;
            }
            if(line[i].second <=line[start].first + d){
                cnt++;
            }
        }
    }
    mmx = max(mmx,cnt);
    cout << mmx;
}