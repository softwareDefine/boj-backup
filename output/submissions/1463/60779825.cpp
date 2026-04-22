#include <iostream>
#include <math.h>

using namespace std;
int arr[1000010];

int cnt;
int main()
{
    int now;
    cin >> now;
    for(int i=2;i<=now;i++){
        arr[i] = arr[i-1]+1;
        if(i%2==0){
            arr[i] = min(arr[i],arr[i/2]+1);
        }
        if(i%3==0){
            arr[i] = min(arr[i],arr[i/3]+1);
        }
    }
    cout << arr[now] ;
    return 0;
}
