#include<iostream>
#include<map>
#include<string>
 
using namespace std;
 
int main(void){
 
    map<char, int> m;
    string str;
 
    cin >> str;
 
    char key;
    map<char, int>::iterator iter;
 
    //문자열을 받습니다.
    //소문자 인 경우에는 아스키 코드 상의 관계를 이용하여
    //대문자로 바꾸어서 map에 삽입해줍니다.
    for(int i=0; i< str.size() ; i++){
        if( str[i] >= 'a'){
            str[i] -= ('a' - 'A');
        }
 
        //기존에 존재 하는 값인지 검사.
        iter = m.find(str[i]);
        
        if(iter != m.end()){        //존재할때
            m[iter->first] +=1;
        }else{                      //존재하지 않을때
            m[str[i]] = 1;
        }
 
    }
 
    //횟수가 가장 많은 값을 가리키는 반복자를 찾습니다
    map<char, int>::iterator max_iter = m.begin();
    iter = m.begin()++;
    for( ; iter != m.end() ; iter++){
        if(max_iter->second < iter->second){
            max_iter = iter;
        }
    }
 
    //max인 횟수와 같은 횟수가 존재하고, 그 인자의 key가 동일한지 검사합니다.
    for(iter = m.begin() ; iter != m.end() ; iter++){
        if(max_iter->second == iter->second && max_iter->first != iter->first){
            cout << "?";
            return 0;
        }
    }
    cout << max_iter->first ;
 
    return 0;
}