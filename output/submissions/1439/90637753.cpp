/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

string str;
int mmn1;
int mmn0;


int main()
{
    cin >> str;
    for(int i=0;i<str.length()-1;i++){
        if(str[i] != str[i+1] && str[i]==0){
            mmn0++;
        }
        if(str[i] != str[i+1] && str[i]==1){
            mmn1++;
        }
    }
    cout << min(mmn1,mmn0);
    return 0;
}