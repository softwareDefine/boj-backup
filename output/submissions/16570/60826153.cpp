#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using ll = long long;
using namespace std;
ll n;
vector<ll> vc;
ll mmx;
ll fail[1000100];
ll cnt;

void pre(vector<ll> &vc) {
    int n = vc.size();
    int j = 0;
    for (int i = 1;i < n;i++) {
        while (j > 0 && vc[i] != vc[j]) { j = fail[j - 1]; }
        if (vc[i] == vc[j]) {
            fail[i] = ++j;
            mmx = max(fail[i],mmx);
        }
        else {
            fail[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0;i < n;i++) {
        ll a;
        cin >> a;
        vc.push_back(a);
    }
    reverse(vc.begin(), vc.end());
    pre(vc);
    for (int i = 0;i < n;i++) {
        if (fail[i] == mmx) {
            cnt++;
        }
    }
    if (mmx == 0) {
        cout << -1;
    }else{
        cout << mmx << ' ' << cnt ;
    }
}