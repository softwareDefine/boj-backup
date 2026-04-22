#include <cstdio>

using namespace std;
int num;
int cnt;
int arr[9];
int ma=-99999999;

int main()
{
    for(int i=0;i<9;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<9;i++){
        if(arr[i]>ma){
            ma=arr[i];
            cnt=i;
        }
    }
    printf("%d %d",ma,cnt+1);
    return 0;
}
