#include<iostream>
#include<map>

using namespace std;

int t,n;
int cnt;
int variety;
int total;
map<string,int> mp;
int arr[40];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for(int ti=0;ti<t;ti++){
        cin >> n;
        string str,str2;
        for(int j=0;j<n;j++){
            cin >> str >> str2;
            if(!mp[str2]){
                mp[str2] = cnt++;
            }
            arr[mp[str2]]++;
        }
        variety = mp.size();
        for(int i=0;i<n;i++){
            total*=(arr[0]+1);
        }
        cout << total-1 << '\n';
        mp.clear();
        fill_n(arr,40,0);
        cnt = 0;
        total = 0;
    }
}