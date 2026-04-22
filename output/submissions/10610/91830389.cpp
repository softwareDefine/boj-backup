#include<bits/stdc++.h>

using namespace std;

int sum,chk;

string str;

int cmp(char &a, char &b){ return a > b;}

int main(){

cin.tie(0)->sync_with_stdio(0);

cin >> str;

for(int i=0;i<str.size();i++){

if(str[i]=='0'){chk=1;}

sum+=str[i]-'0';

}

sort(str.begin(),str.end(),cmp);

if(chk && !(sum %3)){

cout << str;

}else{

cout << -1;

}

}

	