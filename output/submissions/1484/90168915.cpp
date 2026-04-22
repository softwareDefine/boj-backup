#define fastio cin.tie(0)->sync_with_stdio(false);
#include <iostream>
#include <vector>

using namespace std;

int g;
int s,e;
vector<int> ans;

int main(){
    fastio;
    cin >> g;
    while(s <= e && e<=100000){
        if(e*e - s*s < g){
            e++;
        }else if(e*e - s*s > g){
            s++;
        }else{
            ans.push_back(e);
            s++;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << '\n';
    }
}
