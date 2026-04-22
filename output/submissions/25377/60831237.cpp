#include <iostream>
#include <vector>
#define minus 16511

using namespace std;

int a,b,c;
vector <pair<int, int>> vc;
int mmn=999999999;
int mmidx;
int main()
{
    cin >> a;
    for (int i = 0; i < a; i++) {
        int x, y;
        cin >> x >> y;
        vc.push_back({x,y});
    }
    
    for(int i=0;i<a; i++) {
        if (vc[i].first <= vc[i].second) {
            mmn = min(mmn, vc[i].second);
        }
    }
    if (mmn == 999999999) {
        cout << "-1";
    }
    else {
        cout << mmn;
    }
}
