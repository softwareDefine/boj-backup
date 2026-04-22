#include <cstdio>
int n,m,i[100],j[100],k[100],basket[100];
using namespace std;

int main()
{
    scanf("%d %d",&n,&m);
    for(int a=0;a<m;a++){
        scanf("%d %d %d",&i[a],&j[a],&k[a]);
        for(int b=i[a];b<=j[a];b++){
            basket[b]=k[a];
        }
    }
    for(int c=1;c<=n;c++){
       printf("%d ",basket[c]);
    }

    return 0;
}
