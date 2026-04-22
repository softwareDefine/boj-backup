#include <iostream>

#include <string>

using namespace std;

string n;

long long num;

long long sum;

int main(){

	cin >> n;	long long length = n.length();

	num = stoi(n);

	for(int i=1;i<length;i++){

		//if(i==1){sum-=1;}

		sum+=i*(pow(10,i)-1-pow(10,i-1)+1);

	}

	sum += length*(num-pow(10,length-1)+1);

	cout << sum;

}