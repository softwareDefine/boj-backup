#include <iostream>

using namespace std;

char bit[6600][6600];
int n;

void check(int now, int x, int y);
int allcheck(int now, int x, int y);

void check(int now,int x,int y){
    if (now == 1) {
        cout << bit[x][y];
    }
    else if (allcheck(now,x,y)==1) {
        cout << bit[x][y];
    }
    else {
        cout << '(';
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                check(now / 2, x+i*(now/2), y+j*(now/2));
            }
        }   
        cout << ')';
    }
}

int allcheck(int now,int x,int y) {
    int first = bit[x][y];
    for (int i = 0; i < now; i++) {
        for (int j = 0; j < now; j++) {
            if (first != bit[x+i][y+j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
            cin >> bit[i];
    }
    check(n, 0, 0);
}
