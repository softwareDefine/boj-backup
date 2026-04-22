#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> vc;
vector<pair<int,int>> rev;

int main() {
	cin >> n;
	vc.resize(n);
	for(auto &e : vc) {
		cin >> e;
	}
	vc.resize(2*n+1);
	for(int i = 0; i < n; i++) {
		vc[n+i] = vc[i];
	}
	for(int i=0; i < n; i++) {
		for( int j = i+1 ; j < i + n ; j++) {
		    int tempj = j%n;
		    if(vc[(tempj-1+n)%n] == vc[tempj]%n+1 && vc[i] == vc[(i+1)%n]%n+1){
    		    swap(vc[i],vc[tempj]);
    		    //swap(vc[i+n],vc[j+n]);
    			if(vc[tempj]%n+1 == vc[(tempj+1)%n] && (vc[((i-1) + n)%n])%n +1 == vc[i]){
    			    rev.push_back({i,j});
    			}
    			swap(vc[i],vc[tempj]);   
    		    //swap(vc[i+n],vc[j+n]);
		    }
		}
	}
	for(auto [i,j] : rev){
	    int mv;
	    for(mv = 1; mv < n; mv++){
	        if(i+mv < n && j +mv < n && (i+mv)%n+1 != vc[j]){
	            break;
	        }else if( i + mv >= n && j + mv >= n && (i+mv)%n+1 != vc[j]){
	            break;
	        }
	    }
	    if(mv != n){
	        if((i+mv)%n+1 < vc[j]){
	            cout << vc[j] - ((i+mv)%n + 1) << '\n';
	        }else if((i+mv)%n+1 > vc[j]){
	            cout << n+vc[j] - ((i+mv)%n+1) << '\n';
	        }else{
	            continue;
	        }
    	    cout << (i+mv)%n+1 << ' ' << (j+mv)%n+1 << '\n';
    	    cout << mv << '\n';
    	    break;
	    }
	}
}