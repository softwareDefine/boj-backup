#include <iostream>
#include <vector>

using namespace std;

int n;

int mmx;

vector<int> preprocessing(string str) {
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
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        auto pi = preprocessing(str.substr(i,str.length()));
        for (int j = 0; j < pi.size(); j++) {
            mmx = max(pi[j], mmx);
        }
    }
    
    cout << mmx;
}