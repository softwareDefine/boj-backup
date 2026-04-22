#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
int rate[300000];
double avg;

int main(){
    cin >> n;
    if(n != 0){
        int cut = round(n*0.15);
        for(int i=0;i<n;i++){
            cin >> rate[i];
        }
        sort(rate, rate+n);
        for(int i=cut;i<n-cut;i++){
            avg += rate[i];
        }
        avg/= double(n-cut*2);
        cout << round(avg);
    }else{
        cout << 0;
    }
}