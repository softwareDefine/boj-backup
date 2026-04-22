#include <iostream>
#include <stdio.h>

using namespace std;



int main()
{
    int i,a,j=1;
    scanf("%d",&i);

    for(a=1;a<=i;a++)
    {

        j*=a;
    }
    printf("%d",j );
    return 0;
}
