#include <iostream>
#include <vector>
#include <string>

using namespace std;

int s[750010];
int p[380010];
int ssze;


vector<int> preprocessing(int* p) {
    int m = 360000;
    vector<int> pi(m);
    pi[0] = 0;
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[j] == p[i]) {
            pi[i] = j + 1;
            j += 1;
        }
        else {
            pi[i] = 0;
        }
    }
    return pi;
}

vector<int> kmp(int* s, int* p) {
    int i = 0, j = 0;
    int n = 360000 * 2;
    int m = 360000;
    auto pi = preprocessing(p);
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]) {
            j = pi[j - 1];
        }
        if (s[i] == p[j]) {
            if (j == m - 1) {
                ans.push_back(i - m + 1);
                j = pi[j];
            }
            else {
                j += 1;
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> ssze;
    for (int i = 0; i < ssze; i++) {
        int a;
        cin >> a;
        s[a] = 1;
        s[360000 + a] = 1;
    }
    for (int i = 0; i < ssze; i++) {
        int a;
        cin >> a;
        p[a] = 1;
    }
    auto ans = kmp(s, p);
    if (ans.empty()) {
        cout << "impossible";
    }
    else {
        cout << "possible";
    }
}