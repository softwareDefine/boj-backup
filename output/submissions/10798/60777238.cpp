#include <cstdio>
#include <string>

using namespace std;

char a[5][16]={};
int n;
int main()
{
    for(int i=0;i<5;i++){
            scanf("%s",&a[i][0]);
    }
   for(int z=0;z<16;z++){
        for(int h=0;h<5;h++){
            if(a[h][z]!='\0' && a[h][z]!=0){
                printf("%c", a[h][z]);
            }

        }
    }
    return 0;
}
