#include <bits/stdc++.h>

using namespace std;

int sum;

string str;

int alpha[10000];

int chk = 1;

char ans[100000];

int cmp(char &a,char &b){

    return a<b;

}

int main(){

cin.tie(0)->sync_with_stdio(0);

cin >> str;

for(int i=0;i<str.size();i++){

alpha[str[i]-'A']++;

}

if(!(str.size()%2)){

for(int i=0;i<26;i++){

if(alpha[i]%2){chk =0; break;}

}

}

else{

int hol =0;

for(int i=0;i<26;i++){

if(alpha[i]%2){hol++;}

}

if(hol!=1){chk=0;}

}

if(chk!=1){

cout << "I'm Sorry Hansoo";

}else{

sort(str.begin(),str.end(),cmp);

if(str.size()%2){

    char bk = NULL;

    int loc;

for(int i=0;i<str.size();i++){

    if(bk)

    {

        str[i-1] = str[i];

        continue;

    }

    if(alpha[str[i]-'A']%2)

    {

    bk = str[i];

    

    }

}

str[str.size()-1] = bk;

}

for(int i=0;i<str.size();i++){

    if(i%2){

      ans[str.size()-i/2-1] = str[i];

    }else{

        ans[i/2] = str[i];

    }

}

cout << ans;

}

}

