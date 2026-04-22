#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> preprocessing(string str) {
    int m = str.length();
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
            pi[0] = 0;
        }
    }
    return pi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    do {
        string str;
        cin >> str;
        if (str.compare(".") == 0) {
            break;
        }
        auto pi=preprocessing(str);
        if (str.length() %( str.length() - pi[str.length() - 1])) {
            cout << 1 << '\n';
        }
        else {
            cout << str.length() / (str.length() - pi[str.length() - 1]) << '\n';
        }
    } while (1);
}