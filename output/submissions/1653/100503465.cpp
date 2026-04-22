#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> weight;

vector<int> vc;
vector<int> sequence;
int tenPow[20] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int used[20];

vector<int> ans;

void makeSet(int now,int many){
    if(now == many){
        int before = 0;
        int after = 0;
        for(int i=0;i<many;i++){
            if(vc[i] <= 4){
                before += (5-vc[i])*sequence[i];
            }else{
                after += (vc[i]-4)*sequence[i];
            }
        }
        if(after == before){
            int tmp = 0;
            for(int i=0;i<many;i++){
                tmp += tenPow[vc[i]]*sequence[i];
            }
            ans.push_back(tmp);
        }
        return;
    }
    for(int i=0;i<n;i++){
        if(!(used[weight[i]])){
            used[weight[i]] = 1;
            sequence.push_back(weight[i]);
            makeSet(now+1, many);
            sequence.pop_back();
            used[weight[i]] = 0;
        }
    }
}

int check(int many, int seq){
    while(((seq)&(-seq))){
        vc.push_back(log2((seq)&(-seq)));
        seq &= ~((seq)&(-seq));
    }
    makeSet(0, many);
    vc.clear();
    return 0;
}

void makeMap(int now, int many, int seq){
    if(many > n){
        return;
    }
    if(now == 10){
        check(many,seq);
        return;
    }
    makeMap(now+1, many, seq*2);
    makeMap(now+1, many+1, seq*2+1);
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        weight.push_back(a);
    }
    cin >> k;
    makeMap(0, 0, 0);
    sort(ans.begin(),ans.end());
    cout << ans[min(k,int(ans.size()-1))];
    return 0;
}