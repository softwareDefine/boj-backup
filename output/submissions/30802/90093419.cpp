#include<iostream>
#include<vector>

using namespace std;

int n;
int arr[7];
int t,p;

int leastT;
int maxP,oneP;

int main(){
    cin >> n;
    for(int i=0;i<6;i++){
        cin >> arr[i];
    }
    cin >> t >> p;
    for(int i=0;i<6;i++){
        if(arr[i] > 0){
            if(arr[i]%t == 0){
                leastT += arr[i]/t;
            }else{
                leastT += arr[i]/t + 1;
            }
        }
       maxP += arr[i];
    }
    oneP = maxP % p;
    maxP /= p; 
    cout << leastT << '\n';
    cout << maxP << ' ' << oneP;    
}