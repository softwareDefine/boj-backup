#include<iostream>
#include<string>
 
using namespace std;
 
int solution(string& str){
    int count =0;
    for(int i=0; i<str.length(); i++){
        if(str[i] == 'c'){ //c인경우
            if(str[i+1] == '=' || str[i+1] == '-'){ //뒷글자 확인
                i++;
            }
        }else if(str[i] == 'd'){
 
            if(str[i+1] == '-'){
                i++;
            }else if(str[i+1] == 'z' && str[i+2] == '='){
                i++;
                i++;
            }
 
        }else if(str[i] == 'l'){
 
            if(str[i+1] == 'j'){
                i++;
            }
 
        }else if(str[i] == 'n'){
 
            if(str[i+1] == 'j'){
                i++;
            }
 
        }else if(str[i] == 's'){
 
            if(str[i+1] == '='){
                i++;
            }
 
 
        }else if(str[i] == 'z') {
 
            if (str[i + 1] == '=') {
                i++;
            }
        }
        count++;
    }
    return count;
}
 
 
int main(void){
    string str;
    cin >> str;
 
    int result;
    result = solution(str);
 
    cout << result;
    return 0;
}