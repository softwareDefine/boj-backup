#include <cstdio>

int t;

int min_=210000;
int safe[3];

using namespace std;

int main()
{
    scanf("%d",&t);
    for(int i=0;i<t;i++){
     for(int j=0;j<t;j++){
        for(int k=0;k<t;k++){
            if(t-(300*i+60*j+10*k)==0){
                if(i+j+k<min_){
                    safe[0]=i;
                    safe[1]=j;
                    safe[2]=k;
                    min_=i+j+k;
                }
            }
        }
     }
    }
    if(min_==210000){
        printf("%d",-1);
    }
    else{
        for(int e=0;e<3;e++){
            printf("%d ",safe[e]);
        }
    }

    return 0;
}
