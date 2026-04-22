#include <iostream>
#include <stack>

using namespace std;

int main()
{
    
    while (1) {
        stack<char> st;
        char a[20000];
        cin.getline(a, 100100, '\n');
        if (a[0] == '.') {
            break;
        }
        for (int i = 0; a[i] != '.'; i++) {
            if (a[i] == '(') {
                st.push('(');
            }
            else if (a[i] == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
                else {
                    st.push(')');
                }
            }
            else if (a[i] == '[') {
                st.push('[');
            }
            else if (a[i] == ']') {
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                }
                else {
                    st.push(']');
                }
            }
        }
        if (st.empty()) {
            cout << "yes" << '\n';
        }
        else {
            cout << "no" << '\n';
        }
    }
}