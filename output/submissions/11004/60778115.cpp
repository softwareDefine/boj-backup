#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long long cmp(long long a,long long b){
    return a<b;
    }

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	vector<long long> vc;
	long long n,m;
	cin >> n >> m;
	for(long long i=0;i<n;i++) {long long a;cin >>a;vc.push_back(a);} 
	sort(vc.begin(),vc.end(),cmp);
	cout << vc[m-1];
}