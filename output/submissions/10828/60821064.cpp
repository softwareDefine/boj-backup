#include <cstdio>
#include <stack>
#include <string.h>
using namespace std;

int main()
{
    stack<int> st;
    int a;
    char check[7];
    int go;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%s",check);
        if(strcmp(check,"empty")==0){
            if(st.empty()){
                    printf("1\n");
                }else{
                    printf("0\n");
                }
        }else if(strcmp(check,"top")==0){
                 if(st.empty()){
                  printf("-1\n");
                }else{
                    printf("%d\n",st.top());
                }
        }else if(strcmp(check,"size")==0){
                printf("%d\n",st.size());
        }else if(strcmp(check,"pop")==0){
            if(st.empty()){
                  printf("-1\n");
                }else{
                    printf("%d\n",st.top());
                    st.pop();
                }
        }else if(strcmp(check,"push")==0){
                scanf("%d",&go);
                st.push(go);
        }
        }
    return 0;
    }
