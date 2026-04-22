#include <iostream>
#include <string>
#include <string.h>
#include <stack>

using namespace std;

char arr[120];

int main()
{
    cin >> arr;
    int szze = strlen(arr);
    stack<char> checker;
    for(int i=0;i<szze;i++){
        if(arr[i] >= 'A' && arr[i]<='Z'){
            cout << arr[i];
        }else if(arr[i] == '(' || arr[i] == ')'){
            if(arr[i]=='('){
                checker.push(arr[i]);
            }else{

                while(checker.top() != '('){
                    cout << checker.top();
                    checker.pop();

                  }
                  checker.pop();
            }

        }else{

            if(arr[i]=='*' || arr[i] == '/'){
                // 요기
                while(!checker.empty() && (checker.top() == '*' || checker.top() =='/')){
                    cout <<checker.top();
                    checker.pop();
                }
                checker.push(arr[i]);
            }else{
                //요기 2
                while(!checker.empty() && checker.top() != '('){
                    cout << checker.top();
                    checker.pop();
                }
                checker.push(arr[i]);
            }
        }
    }
    while(!checker.empty()){
        cout << checker.top();
        checker.pop();
    }
    // 우선 순위가 이해가 안됩니다 . ㅠㅠㅠ
    return 0;
}
