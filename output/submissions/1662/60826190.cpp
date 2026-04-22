#include<stdio.h>
#include<stack>
#include<string.h>

typedef struct train{
    char x;
    int val;
}T;

using namespace std;

int main(){
    stack<T> counter;
    char s[51];
    int string_size;
    int temp=0;
    int total=0;
    int a;
    scanf("%s",s);
    string_size = strlen(s);
    for(int i=0;i<string_size;i++){
        if(s[i]==')'){
            temp=0;
            while(!(counter.top().x=='(')){
                temp+=counter.top().val;
                counter.pop();
            }
            counter.pop();
            temp=(counter.top().x-'0')*temp;
            counter.pop();
            counter.push({'.',temp});
        }
        else if(s[i+1]=='(')
            counter.push({s[i],0});
        else if(s[i]=='(')
            counter.push({'(',0});
        else{
            counter.push({'.',1});
        }
    }
    while(!counter.empty()){
        total+=counter.top().val;
        counter.pop();
    }
    printf("%d",total);
}