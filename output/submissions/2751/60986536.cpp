#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> vc;
    cin >> a; 
    int temp;
    for (int i = 0; i < a;i++) {
       
        cin >> temp;
        vc.push_back(temp);
    }
    sort(vc.begin(), vc.end());
    for (int i = 0; i < a; i++) {
        cout <<vc[i]<< "\n";
    }
}
