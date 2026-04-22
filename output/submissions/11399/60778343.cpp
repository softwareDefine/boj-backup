#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
    int i=0,j=0,k=0,n=0,s[1000]={ 0};
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
    scanf("%d", &s[i]);
    }
    sort(s,s+i);
    for(i=1;i<n;i++){
        s[i] = s[i-1]+s[i];
        j+= s[i];
    }
    j+= s[0];
    printf("%d", j);
    return 0;
}
