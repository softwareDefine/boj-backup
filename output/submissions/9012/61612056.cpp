#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

int main()
{
    stack<int> checker;
    char push[51];
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%s",push);
        for(int j=0;j<strlen(push);j++){
            if(push[j]=='('){
                checker.push(1);
            }else{
                if(!checker.empty()){
                    checker.pop();
                }else{
                    checker.push(999);
                    break;
                }

                }
        }
        if(checker.empty()){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        while(!checker.empty()){
            checker.pop();
        }
    }
    return 0;
}
