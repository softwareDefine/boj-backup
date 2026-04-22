#include <bits/stdc++.h>

using namespace std;

double arr[10100];
int n;
double mmx = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        double current = 1;
        for(int j=i;j<n;j++){
            current *= arr[j];
            mmx = max(mmx, current); 
        }
    }
    printf("%.3f",mmx);
}