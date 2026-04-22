#include <stdio.h>
#include <stack>

using namespace std;

int main(){
    int number;
    scanf("%d",&number);
    stack<int> icansee;
    int total[100000];
    for(int h=0;h<number;h++){
        scanf("%d",&total[h]);
    }
    for(int j=number-1;j>=0;j--){
        if(icansee.empty()){
            icansee.push(total[j]);
        }
        if(icansee.top()<total[j]){
            icansee.push(total[j]);
        }
    }
    printf("%d",icansee.size());
    
}