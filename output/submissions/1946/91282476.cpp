#include <bits/stdc++.h>

using namespace std;

int t;
int mmx;
vector<pair<int,int>> vc;
pair<int,int> plus1,minus1,zero1;

int cmp(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while(t--){
        int n;
        int cnt = 0;
        cin >> n;
        vc.clear();
        for(int i=0;i<n;i++){
            int a,b;
            cin >> a >> b;
            vc.push_back({a,b});
        }
        mmx = 0;
        sort(vc.begin(),vc.end(),cmp);
        for(int i=0;i<vc.size();i++){
                if(i ==0 ){
                    mmx = vc[i].second;
                    continue;
                }
                if(vc[i].second < mmx){
                    mmx = vc[i].second;
                }else{
                    cnt++;
                }
        }
        cout << n-cnt << '\n';
    }
}