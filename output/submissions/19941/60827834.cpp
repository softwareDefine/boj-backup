#include <cstdio>

int n,k;
char lenth[20002];
int cnt,notchanged;
using namespace std;


int main()
{
    scanf("%d %d",&n,&k);
    scanf("%s",&lenth[0]);

    for(int i=0;i<n;i++){
        if(lenth[i]=='P'){
            for(int j=i-k;j<=i+k;j++){
                if(lenth[j]=='H'&&j>=0&&j<n){
                    cnt++;
                    lenth[j]='X';
                    break;
                }
            }
        }
    }
    printf("%d",cnt);
    return 0;

}
