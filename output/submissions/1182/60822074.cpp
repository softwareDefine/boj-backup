#include <cstdio>

using namespace std;

int n;
int s;
int k[2200000];
int cnt;
int check;
int a[20];
void dfs(int all,int pos){
    all += k[pos];

    if(pos >= n){
        return;
    }
    if(s==all){
        cnt++;
    }
    dfs(all-k[pos],pos+1);
    dfs(all,pos+1);
}

int main()
{
    scanf("%d %d",&n,&s);
    for(int i=0;i<n;i++){
        scanf("%d",&k[i]);
    }
    dfs(0,0);


    printf("%d",cnt);
    return 0;
}
