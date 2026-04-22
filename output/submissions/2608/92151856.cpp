#include<bits/stdc++.h>

using namespace std;

int num1,num2;
string str1,str2;
string ans;
map<char,int> mp;

int main(){
    cin >> str1;
    cin >> str2;
    mp['I'] = 1; mp['V'] = 5; mp['X'] = 10; mp['L'] = 50; mp['C'] = 100; mp['D'] = 500; mp['M'] = 1000;
    for(int i=0;i<str1.size();i++){
        if(i != str1.size() - 1 && mp[str1[i]] < mp[str1[i+1]]){
            num1 -= mp[str1[i]];
            continue;
        }
        num1 += mp[str1[i]];
    }
    for(int i=0;i<str2.size();i++){
        if(i != str2.size() - 1 && mp[str2[i]] < mp[str2[i+1]]){
            num2 -= mp[str2[i]];
            continue;
        }
        num2 += mp[str2[i]];
    }
    num1 += num2;
    cout << num1<< '\n';
    while(num1 - 1000 >= 0){ num1 -=1000; ans.push_back('M');  }
    if(num1 - 900 >= 0){ num1 -= 900; ans.push_back('C'); ans.push_back('M'); }
    if(num1 - 500 >= 0){ num1 -= 500; ans.push_back('D');}
    if(num1 - 400 >= 0){ num1 -= 400; ans.push_back('C'); ans.push_back('D');}
    while(num1 - 100 >= 0){ num1 -=100; ans.push_back('C');  }
    if(num1 - 90 >= 0){ num1 -= 90; ans.push_back('X'); ans.push_back('C'); }
    if(num1 - 50 >= 0){ num1 -= 50; ans.push_back('L');}
    if(num1 - 40 >= 0){ num1 -= 40; ans.push_back('X'); ans.push_back('L');}
    while(num1 - 10 >= 0){ num1 -=10; ans.push_back('X');  }
    if(num1 - 9 >= 0){ num1 -= 9; ans.push_back('I'); ans.push_back('X'); }
    if(num1 - 5 >= 0){ num1 -= 5; ans.push_back('V');}
    if(num1 - 4 >= 0){ num1 -= 4; ans.push_back('I'); ans.push_back('V');}
    while(num1 - 1 >= 0){ num1 -=1; ans.push_back('I');  }
    cout << ans;
}