#include <bits/stdc++.h>
using namespace std;

static vector<int> kmp_pi(const string &p){
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
    cin >> S >> N;
    vector<string> P(N);
    for (int i=0;i<N;i++) cin >> P[i];

    const int L = (int)S.size();

    vector<vector<int>> endMatches(L);

    for (int t=0; t<N; ++t){
        const string &pat = P[t];
        if (pat.empty() || pat.size() > S.size()) continue;

        auto pi = kmp_pi(pat);
        for (int i=0, j=0; i<L; ++i){
            while (j>0 && S[i]!=pat[j]) j = pi[j-1];
            if (S[i]==pat[j]){
                if (j == (int)pat.size()-1){
                    endMatches[i].push_back((int)pat.size());
                    j = pi[j];
                }else{
                    ++j;
                }
            }
        }
    }

    vector<int> dp(L+1, 0);
    for (int i=0; i<L; ++i){
        if (dp[i+1] < dp[i]) dp[i+1] = dp[i];

        for (int len : endMatches[i]){
            int s = i - len + 1;
            if (s >= 0){
                int cand = dp[s] + len;
                if (dp[i+1] < cand) dp[i+1] = cand;
            }
        }
    }

    cout << dp[L] << '\n';
    return 0;
}
