#include <cstdio>

int node[100][100];
int nv[100];
int cnt;
using namespace std;
int N1,N2;
void dfs(int start,int net){
    int i;
    nv[start]=1;
    cnt++;
    for(int i=1;i<=net;i++){
        if(node[start][i]==1&&nv[i]==0){
            dfs(i,net);
        }
    }
}

int main()
{
    int temp1,temp2;

    scanf("%d",&N1);
    scanf("%d",&N2);
    for(int i=0;i<N2;i++){
        scanf("%d %d",&temp1,&temp2);
        node[temp1][temp2]=1;
        node[temp2][temp1]=1;
    }
    dfs(1,N1);

    printf("%d",cnt-1);
    return 0;
}
