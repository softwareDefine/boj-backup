#define mod 1000000007
#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint m;
lint n, k;

lint product[4000010];
lint rev[4000010];

lint go(lint a, lint b){
    if(b==1){
        return a%mod;
    }
    if(b==0){
        return 1;
    }
    lint under = go(a,b/2)%mod;
    if(!(b%2)){
        return (under*under + mod)%mod;
    }else{
        return (((under*under + mod)%mod)*a + mod)%mod;
    }
}

int main() {
	product[1] = 1;
	product[0] = 1;
	rev[0] = 1;
	rev[1] = 1;
	for(int i = 2; i < 4000010; i++){
	    product[i] = (i*product[i-1] + mod)%mod;
	    //rev[i] = (((rev[i-1]+mod)%mod)*((go(i,mod-2)+mod)%mod));
	}
	cin >> m;
	while(m--){
	    cin >> n >> k;
	    cout << ((product[n]%mod)* (go(((product[n-k]%mod)*(product[k]%mod))%mod,mod-2)%mod))%mod << '\n';
	}
	return 0;
}