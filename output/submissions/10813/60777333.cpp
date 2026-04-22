#include <cstdio>

int a[10000];

int t(){
    a[0]=0;
    for(int i=1;i<=100;i++){
        a[i]=a[i-1]+1;
    }
    return 0;
}


using namespace std;

int main()
{
    int n=0,m=0,tem=0,x=0,y=0;

    scanf("%d %d",&n,&m);
    t();
    for(int j=0;j<m;j++){
        scanf("%d %d",&x ,&y);
        tem=a[y];
        a[y]=a[x];
        a[x]=tem;
    }
    for(int k=1;k<=n;k++){
       printf("%d ",a[k]);
    }
    return 0;
}
