#include <iostream>

#include <math.h>

#include <string>

using namespace std;

int cnt1,cnt2;

int main(){

	string a;	string b;

	cin >> a >> b;

	for(int i=0;i<a.size();i++){

		if(a[i]=='1'){

			cnt1++;

		}

	}

for(int i=0;i<b.size();i++){

		if(b[i]=='1'){

			cnt2++;

		}

	}

	if(cnt1 >= cnt2 ){

		cout << "VICTORY";

	}else if(cnt1 %2==1 && abs(cnt1-cnt2)==1){

		cout << "VICTORY";

	}else{

		cout << "DEFEAT";

		}

}