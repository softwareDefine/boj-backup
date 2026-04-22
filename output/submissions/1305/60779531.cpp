#include <iostream>
#include <vector>

using namespace std;

int n;
string str;

vector<int> preprocessing() {
    int m = str.size();
    vector<int> pi(m);
    pi[0] = 0;
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && str[i] != str[j]) {
            j = pi[j - 1];
        }
        if (str[i] == str[j]) {
            pi[i] = j + 1;
            j += 1;
        }
        else {
            pi[i] = 0;
        }
    }
    return pi;
}


int main()
{
    int n = 0;
    cin >> n;
    cin >> str;
    auto szze = preprocessing();
    cout << n - szze[n-1];
}