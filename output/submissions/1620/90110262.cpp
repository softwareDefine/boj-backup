#include<iostream>
#include<map>
#include<string>

using namespace std;

ios_base::sync_with_stdio(false);
cin.tie(null);
cout.tie(null);

int n,m;

map<string,int> revdict;
string dict[200000];

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> dict[i];
        revdict.insert({dict[i],i});
    }
    for(int i=0;i<m;i++){
        string pbm;
        cin >> pbm;
        if(pbm[0] >= 'A' && pbm[0] <='Z'){
            cout << revdict[pbm] << '\n';
        }else{
            cout << dict[stoi(pbm)] << '\n';
        }
    }
}