#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

vector<pair<int, int>> vc;

int cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        vc.push_back({ temp1,temp2 });
    }
    stable_sort(vc.begin(), vc.end(), cmp);
    int szze = vc.size();
    for (int j = 0; j < szze; j++) {
        cout << vc[j].first << ' ' << vc[j].second << '\n';
    }
}
