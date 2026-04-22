#include <iostream>

using namespace std;

string str, ptr;
int fail[1000010];
int szze;

void pre(string &ptr) {
    int n = ptr.size();
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0 && ptr[i] != ptr[j]) { j = fail[j - 1]; }
        if (ptr[i] == ptr[j]) {
            fail[i] = ++j;
        }
        else {
            fail[i] = 0;
        }
    }
}

int kmp(string& str, string& ptr) {
    int n = str.size();
    int m = ptr.size();
    int cnt = 0;
    int j = 0;
    for (int i = 0; i < n-1; i++) {
        while (j > 0 && str[i] != ptr[j]) { j = fail[j - 1]; }
        if (str[i] == ptr[j]) {
            if (j == m - 1) {
                j = fail[j];
                cnt++;
            }
            else {
                j++;
            }
        }
    }
    return cnt;
}


int main()
{
    cin >> str;
    cin >> ptr;
    str += str;
    pre(ptr);
    cout << kmp(str, ptr);
}