#include <iostream>
#include <vector>
#define minus 16511

using namespace std;

int a,b,c;
vector <pair<int, int>> vc;
int mmn;
int main()
{
    cin >> a;
    for (int i = 0; i < a; i++) {
        int x, y;
        cin >> x >> y;
        vc.push_back({x,y});
    }
    for(int i=0;i<vc.size(); i++) {
        if (vc[i].first < vc[i].second) {
            mmn = min(vc[i].second-vc[i].first, mmn);
        }
    }
    if (mmn == 0) {
        cout << "-1";
    }
    else {
        cout << mmn;
    }
}
