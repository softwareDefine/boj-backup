#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long arr[11000000];

int cmp(int a,int b){
    return a>b;
    }

int main(int argc, char *argv[])
{
	cin >> n;
	
	arr[0]=1;
	arr[1]=1;
	arr[2]=1;
	for(int i=3;i<1100000;i++){
	    arr[i]=arr[i-3]+arr[i-2];
	}
	for(int i=0;i<n;i++){
	    long long a;
	    cin >> a;
	    cout<<arr[a-1] << '\n';
	}
}