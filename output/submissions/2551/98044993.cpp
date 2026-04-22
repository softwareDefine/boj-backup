#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n;
lint numbers[20000];
lint sum;
lint beforesum = 999999999999999;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        lint a;
        cin >> a;
        numbers[a]++;
    }
    for(int i=1;i<=10000;i++){
        sum = 0;
        for(int j=1;j<=10000;j++){
            sum += abs(i-j)*numbers[j];
        }
        if(beforesum <= sum){
            cout << i-1 << ' ';
            break;
        }
        beforesum = sum;
    }
    beforesum = 999999999999999;
    for(int i=1;i<=10000;i++){
        sum = 0;
        for(int j=1;j<=10000;j++){
            sum += pow((i-j),2)*numbers[j];
        }
        if(beforesum <= sum){
            cout << i-1;
            break;
        }
        beforesum = sum;
    }
}