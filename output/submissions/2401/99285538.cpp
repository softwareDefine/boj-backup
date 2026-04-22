#include <bits/stdc++.h>
using namespace std;

static vector<int> build_pi(const string &p){
    vector<int> pi(p.size(), 0);
    for (int i=1, j=0; i<(int)p.size(); ++i){
        while (j>0 && p[i]!=p[j]) j = pi[j-1];
        if (p[i]==p[j]) pi[i] = ++j;
    }
    return pi;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; int N;
    if(!(cin >> S)) return 0;
    cin >> N;
    vector<string> P(N);
    for(int i=0;i<N;i++) cin >> P[i];

    const int L = (int)S.size();

    vector<int> valid_idx;
    valid_idx.reserve(N);
    for(int t=0;t<N;t++){
        if(!P[t].empty() && (int)P[t].size() <= L) valid_idx.push_back(t);
    }

    vector<vector<int>> PI;          PI.reserve(valid_idx.size());
    vector<int> J(valid_idx.size());
    for(int k=0; k<(int)valid_idx.size(); ++k){
        PI.push_back(build_pi(P[valid_idx[k]]));
        J[k] = 0;
    }

    vector<int> dp(L+1, 0);

    for(int i=0;i<L;i++){
        if (dp[i+1] < dp[i]) dp[i+1] = dp[i];

        char c = S[i];

        for(int k=0; k<(int)valid_idx.size(); ++k){
            const string &pat = P[valid_idx[k]];
            auto &pi = PI[k];
            int &j = J[k];

            while (j>0 && c != pat[j]) j = pi[j-1];
            if (c == pat[j]){
                if (j == (int)pat.size()-1){
                    int len = (int)pat.size();
                    int s = i - len + 1;
                    int cand = dp[s] + len;
                    if (dp[i+1] < cand) dp[i+1] = cand;
                    j = pi[j];
                }else{
                    ++j;
                }
            }
        }
    }

    cout << dp[L] << '\n';
    return 0;
}
