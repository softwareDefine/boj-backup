#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int num;
char str[100];
int alphabet[30];
int main()
{
	stack<double> st;
	cin >> num;
	cin >> str;
	for (int i = 0; i < num; i++) {
		cin >> alphabet[i];
	}
	int size =strlen(str);
	
	for (int i = 0; i < size; i++) {
		if (str[i]=='+' || str[i] == '-' || str[i] == '/' || str[i] == '*') {
			double a = st.top();
			st.pop();
			double b = st.top();
			st.pop();
			switch (str[i]) {
				case '+':
					st.push(a + b);
					break;
				case '-':
					st.push(b - a);
					break;
				case '*':
					st.push(a * b);
					break;
				case '/':
					st.push(b / a);
					break;
			}
		}
		else {
			st.push(alphabet[str[i] - 'A']);
		}
	}
	double result = st.top();
	printf("%.2lf", result);
}
