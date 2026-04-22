#include <cstdio>
int r;
int c;
using namespace std;
char map1[21][21];
bool alphabet[300];
int mmx=-1;
void bfs(int h,int w,int cnt){
    alphabet[map1[h][w]]=1;
    if(mmx<cnt){
        mmx=cnt;
    }
    if(h-1>=0 && alphabet[map1[h-1][w]]!=1){
        bfs(h-1,w,cnt+1);
    }
    if(h+1<r && alphabet[map1[h+1][w]]!=1){
        bfs(h+1,w,cnt+1);
    }
    if(w+1<c && alphabet[map1[h][w+1]]!=1){
        bfs(h,w+1,cnt+1);
    }
    if(w-1>=0 && alphabet[map1[h][w-1]]!=1){
        bfs(h,w-1,cnt+1);
    }
    alphabet[map1[h][w]]=0;
}
int main()
{
    scanf("%d %d",&r ,&c);
    for(int i=0;i<r;i++){
            scanf("%s",&map1[i][0]);

    }
    bfs(0,0,1);
    printf("%d",mmx);
    return 0;
}
