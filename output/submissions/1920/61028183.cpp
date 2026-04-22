#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[100004];
int b[100004];
int p[100004];
int n,m;
int midium;
int main()
{
    int high=n-1;
    int low=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(int j=0;j<m;j++){
        scanf("%d",&b[j]);
    }
    sort(a,a+n);
    for(int k=0;k<m;k++){
         high=n-1;
        low=0;
         while(low<=high){
            midium=(low+high)/2;
            if(a[midium]==b[k]){
                printf("%d\n",1);
                p[k]=1;
                break;
            }
            else if(a[midium]<b[k]){
                low=midium+1;
            }
            else{
                high=midium-1;
            }
        }
        if(p[k]!=1){
                printf("%d\n",0);
        }
    }
    return 0;
}
