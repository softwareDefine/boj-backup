#include <cstdio>

using namespace std;
int num;
int arr[1000000];
int mi=99999999;
int ma=-99999999;

int main()
{
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<num;i++){
        if(arr[i]<mi){
            mi=arr[i];
        }
        if(arr[i]>ma){
            ma=arr[i];
        }
    }
    printf("%d %d",mi,ma);
    return 0;
}
