#include <iostream>
#include <queue>

using namespace std;

int n, k;
queue<int> qu;
vector<int> vc;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        qu.push(i);
    }
    while (!qu.empty()) {
        for (int i = 0; i < k-1; i++) {
            int temp = qu.front();
            qu.push(temp);
            qu.pop();
        }
        vc.push_back(qu.front());
        qu.pop();
    }
    int szze = vc.size();
    cout << "<";
    for (int i = 0; i < szze; i++) {
        if (i == szze - 1) {
            cout << vc[i];
            cout << ">";
            break;
        }
        cout << vc[i] << ", ";
    }
}