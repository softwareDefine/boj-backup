#include <iostream>

#include <vector>

using namespace std;

int n;

long long ans = 0;

string ptr;

long long fail[1000100];

void preprocessing(string& ptr) {

    int n = ptr.size();

    int j = 0;

    for (int i = 1; i < n; i++) {

        while (j > 0 && (ptr[i] != ptr[j] || j * 2 >= i)) { j = fail[j - 1]; }

        if (ptr[i] == ptr[j]) {

            fail[i] = ++j;

        }

        else {

            fail[i] = 0;

        }

    }

}

int main(){
    cin >> n;
    cin >> ptr;
    preprocessing(ptr);
    for (int i = 0; i < n; i++) {
        if (fail[i] == 0) {
            //cout << '0' << ' ';
            continue;
        }
        int j = fail[i]-1;
        while (fail[j] > 0) {
            j = fail[j] - 1;
        }
        ans += i - j;
        //cout << i - j << ' ';
    }

    cout << ans;

}