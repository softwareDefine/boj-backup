#include <cstdio>

using namespace std;
int n=0;
int arr[13]={0};
int conf[2600001]={0};
int mmx = 0;
int cor = 0;

void dfs(int l,int r,int cnt){

    if(l>r){
        conf[l-r]=1;
    }
    else{
       conf[r-l]=1;
    }
    if(n==cnt){
        return ;
    }

    dfs(l,r+arr[cnt],cnt+1);
    dfs(l+arr[cnt],r,cnt+1);
    dfs(l,r,cnt+1);

}

int main()
{
    scanf("%d",&n);

    for(int k=0;k<n;k++){
        scanf("%d",&arr[k]);
        mmx=mmx+arr[k];
    }
    dfs(0,0,0);
    for(int j=0;j<mmx;j++){
        if(conf[j]==0){
            cor++;
        }
    }

    printf("%d",cor);

    return 0;
}
