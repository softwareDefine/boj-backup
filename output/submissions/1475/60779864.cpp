#include <iostream>

#include <algorithm>

using namespace std;

 

int N;

int plasticNum[10];

 

int numOfSet(void)

{

        //기저 사례

        if (N == 0)

                 return 1;

 

        int result = 0;

 

        while (N)

        {

                 int idx = N % 10;

                 //사용할 수 있는 숫자가 갖고 있는 세트에 없을 경우

                 if (!plasticNum[idx])

                 {

                         //6과 9는 뒤집어서 사용 가능

                         if (idx == 6 && plasticNum[9] != 0)

                                 plasticNum[9]--;

                         else if (idx == 9 && plasticNum[6] != 0)

                                 plasticNum[6]--;

                         //세트를 추가하고 해당 숫자 사용

                         else

                         {

                                 for (int i = 0; i < 10; i++)

                                          plasticNum[i]++;

                                 result++;

                                 plasticNum[idx]--;

                         }

                 }

                 else

                         plasticNum[idx]--;

                

                 N /= 10;

        }

 

        return result;

}

 

int main(void)

{

        cin >> N;

 

        cout << numOfSet() << endl;

        return 0;

}