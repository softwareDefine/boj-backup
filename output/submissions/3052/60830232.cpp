#include <iostream>

using namespace std;

int arr[42];
int x;
int ans;
int main(){
	
	
	for(int i=0;i<10;i++){
		cin >> x;
		arr[x%42] = 1;
	}
	
	for(int i=0;i<42;i++){
        ans += arr[i];
    }
    cout << ans;
	
	return 0;
}