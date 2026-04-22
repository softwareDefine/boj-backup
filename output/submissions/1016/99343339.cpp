#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint mmn, mmx; 
bool poss[2000000];
int ans;

lint err;

int main(){
    fill(poss,poss+2000000,1);
    cin >> mmn >> mmx;
    for(lint i=2;i*i<=mmx;i++){
        for(lint divider = mmn/(i*i);divider <= mmx/(i*i);divider++){
            if((i*i)*divider >= mmn){
                poss[(i*i)*divider - mmn] = 0;
            }
        }
    }
    for(int i=0;i<=(mmx-mmn);i++){
        if(poss[i]){
            ans++;
        }
    }
    cout << ans;
}