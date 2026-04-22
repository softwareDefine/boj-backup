#include <bits/stdc++.h>

using namespace std;

double sum;
double sum2;
int t = 20;


int main(){
    while(t--){
        string sub,grade; double times;
        cin >> sub >> times >> grade;
        if(grade == "P"){
            continue;
        }
        sum += times;
        if(grade == "F"){continue;}
        sum2+= times *('E'-grade[0] + ((grade[1] == '+')?0.5:0));
    }
    printf("%.6f",sum2/sum);
}