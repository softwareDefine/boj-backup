#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n, k;
vector<lint> weight;

vector<lint> vc;
vector<lint> sequence;
lint tenPow[20] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
lint used[20];
lint timer;

vector<lint> ans;

void makeSet(lint now,lint many){
    timer++;
    if(now == many){
        lint before = 0;
        lint after = 0;
        for(lint i=0;i<many;i++){
            if(vc[i] <= 4){
                before += (5-vc[i])*sequence[i];
            }else{
                after += (vc[i]-4)*sequence[i];
            }
        }
        if(after == before){
            lint tmp = 0;
            for(int i=0;i<many;i++){
                tmp += tenPow[vc[i]]*sequence[i];
            }
            ans.push_back(tmp);
        }
        return;
    }
    for(lint i=0;i<n;i++){
        if(!(used[weight[i]])){
            used[weight[i]] = 1;
            sequence.push_back(weight[i]);
            makeSet(now+1, many);
            sequence.pop_back();
            used[weight[i]] = 0;
            timer++;
        }
    }
}

void makeMap(lint now, lint many){
    if(many > n){
        return;
    }
    if(now == 10){
        makeSet(0, many);
        return;
    }
    vc.push_back(now);
    makeMap(now+1, many+1);
    vc.pop_back();
    makeMap(now+1, many);
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        lint a;
        cin >> a;
        weight.push_back(a);
    }
    cin >> k;
    makeMap(0, 0);
    sort(ans.begin(),ans.end());
    cout << ans[min(k,lint(ans.size()-1))] << '\n';
    //cout << timer;
    return 0;
}