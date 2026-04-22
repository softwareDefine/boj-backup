#include <iostream>
#include <vector>
int cnt;
using namespace std;
void finder(int N){
    for(int i=5;i<=N;i++){
        int k= i;
        while(k%5==0){
            cnt++;
    k/=5;
        }
    }
}
int main()
{
    int a;
    cin >>a;
    finder(a);
    printf("%d",cnt);
    return 0;
}
