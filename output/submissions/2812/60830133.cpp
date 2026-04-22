#include <iostream>

#include <stack>

#include <vector>

using namespace std;

stack<char> st;

vector<char> vc;

string str;

int cnt=0;

int n,k;

int main(){

	cin >> n >>k;	cin >> str;

	for(int i=0;i<str.size();i++){

		if(st.empty()){

			st.push(str[i]);

			continue;

		}

		while(!st.empty()&& st.top() < str[i]&& cnt<k){

			st.pop();

			cnt++;

		}

		st.push(str[i]);

	}

	while(!st.empty()){

		vc.push_back(st.top());

		st.pop();

	}

	if(cnt < k){

		for(int i=vc.size()-1;i>=k-cnt;i--){

		cout << vc[i];

	    }

	}else{

	for(int i=vc.size()-1;i>=0;i--){

		cout << vc[i];

	}

	}

}