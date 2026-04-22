#include<iostream>
#include<map>

using namespace std;

int t,n;
int total;
map<string,int> mp;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for(int ti=0;ti<t;ti++){
        total = 1;
        cin >> n;
        string str,str2;
        for(int j=0;j<n;j++){
            cin >> str >> str2;
            mp[str2]++;
        }
        for(const auto& pair : mp){
            total*=(pair.second+1);
        }
        cout << total-1 << '\n';
        mp.clear();
    }
}