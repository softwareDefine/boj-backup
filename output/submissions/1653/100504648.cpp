#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n, k;
vector<lint> weight;

vector<lint> vc;
lint seq1;
lint seq2;
lint beforeWeight = 0;
lint afterWeight = 0;
lint tenPow[20] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
lint used[20];

int enough = 0;

vector<lint> ans;
void makeBefore(int now);

lint rev(lint n) {
    string s = to_string(n);
    
    int start_index = (n < 0) ? 1 : 0; 
    std::reverse(s.begin() + start_index, s.end());
    
    return std::stoll(s);
}

void makeAfter(int now){
    if(enough){ return; }
    if(now == 5){
        if(afterWeight > beforeWeight){
            enough = 1;
        }else if(beforeWeight == afterWeight){
            //cout << seq1 << ' ' << seq2 << '\n';
            ans.push_back(seq2*100000 + tenPow[(5-(to_string(seq1)).size())]* rev(seq1));
        }
        return;
    }
    for(lint i=0;i<=n;i++){
        if(!(used[weight[i]])){
            if(weight[i]){
                used[weight[i]] = 1;
            }
            seq2 = seq2*10 + weight[i];
            afterWeight += (5-now)*weight[i];
            makeAfter(now+1);
            seq2 /= 10;
            afterWeight -= (5-now)*weight[i];
            used[weight[i]] = 0;
        }
    }
}


void makeBefore(int now){
    if(now == 5){
        makeAfter(0);
        enough = 0;
        return;
    }
    for(lint i=0;i<=n;i++){
        if(!(used[weight[i]])){
            if(weight[i]){
                used[weight[i]] = 1;
            }
            seq1 = seq1*10 + weight[i];
            beforeWeight += (5-now)*weight[i];
            makeBefore(now+1);
            seq1 /= 10;
            beforeWeight -= (5-now)*weight[i];
            used[weight[i]] = 0;
        }
    }
}

int main()
{
    cin >> n;
    weight.push_back(0);
    for(int i=0;i<n;i++){
        lint a;
        cin >> a;
        weight.push_back(a);
    }
    cin >> k;
    makeBefore(0);
    sort(ans.begin(),ans.end());
    cout << ans[min(k,lint(ans.size()-1))] << '\n';
    return 0;
}