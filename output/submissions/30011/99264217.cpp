#include <bits/stdc++.h>

using namespace std;

int n;
int sum;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        if(i == 0){
            sum += 180*(a-2);
            continue;
        }
        sum += 180*a;
    }
    cout << sum;
}