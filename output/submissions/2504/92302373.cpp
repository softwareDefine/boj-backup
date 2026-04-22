#include <bits/stdc++.h>

using namespace std;

stack<char> st;
long long weight = 1;
int chk =1;
long long sum;
string str;

int main(){
    cin >> str;
    for(int i=0;i<str.size();i++){
        //cout << weight << '\n';
        if(str[i] == '('){
            st.push('(');
            weight *= 2;
        }
        if(str[i] == '['){
            st.push('[');
            weight *= 3;
        }
        if(str[i] == ')'){
            if(!st.empty() && st.top() == '('){
                st.pop();
                if((str[i-1] != ')' && str[i-1] != ']')){
                sum += weight;
                }
                weight /= 2;
            }else{
                chk = 0;
                break;
            }
        }
        if(str[i] == ']' ){
            if(!st.empty() && st.top() == '['){
                st.pop();
                if((str[i-1] != ')' && str[i-1] != ']')){
                sum += weight;
                }
                weight /= 3;
            }else{
                chk = 0;
                break;
            }
        }
    }
    if(!chk){sum = 0;}
    cout << sum;
}