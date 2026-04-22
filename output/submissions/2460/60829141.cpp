#include <cstdio>

using namespace std;
int num;
int cnt;
int arr[10];
int brr[10];
int crr;
int ma=-99999999;

int main()
{
    for(int i=0;i<10;i++){
        scanf("%d",&arr[i]);
        scanf("%d",&brr[i]);
    }
    for(int i=0;i<10;i++){
        cnt=brr[i]-arr[i];
        crr=cnt+crr;
        if(crr>ma){
            ma=crr;
        }
    }
    printf("%d",ma);
    return 0;
}
