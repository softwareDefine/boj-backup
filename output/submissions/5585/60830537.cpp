#include <iostream>

using namespace std;

int num;
int cnt;

int main()
{
    cin >> num;
    num = 1000-num;

    while(num!=0){
        if(num>=500){
            cnt+=num/500;
            num%=500;
        }else if(num>=100){
            cnt+=num/100;
            num%=100;
        }
        else if(num>=50){
            cnt+=num/50;
                num%=50;
        }
        else if(num>=10){
            cnt+=num/10;
            num%=10;
        }
        else if(num>=5){
            cnt+=num/5;
             num%=5;
        }else{
            cnt+=num/1;
            break;
        }
    }
    cout << cnt;
    return 0;
}
