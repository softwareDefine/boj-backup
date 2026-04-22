#define fastio cin.tie(0)->sync_with_stdio(false);
#include <iostream>
#include <vector>

using namespace std;

long long g;
long long s,e;
vector<int> ans;

int main(){
    fastio;
    cin >> g;
    while(s <= e && e<=10000000){
        if(e*e - s*s < g){
            e++;
        }else if(e*e - s*s > g){
            s++;
        }else{
            ans.push_back(e);
            s++;
        }
    }
    if(!ans.size()){
        cout << -1 ;
        return 0;
    }
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << '\n';
    }
}
