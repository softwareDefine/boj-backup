#include <bits/stdc++.h>

using namespace std;

int T;

class Node{
    public :
        char c;
        Node *before;
        Node *after;
    Node(char val, Node *a, Node *b) : c(val), before(a) ,after(b){ }
};

void solve(){
    string query;
    Node *ptr;
    Node *root = new Node('-',nullptr,nullptr);
    ptr = root;
    cin >> query;
    for(auto c : query){
            switch(c){
                case '<':{
                    if(ptr->before != nullptr){
                        ptr = ptr->before;
                    }
                    break;
                }
                case '>':{
                    if(ptr->after != nullptr){
                        ptr = ptr->after;
                    }
                    break;
                }
                case '-':{
                    if(ptr->after != nullptr){
                        ptr->after->before = ptr->before;
                    }
                    if(ptr->before != nullptr){
                        ptr->before->after = ptr->after;
                    }
                    Node *tmp = ptr;
                    ptr = ptr->before;
                    delete tmp;
                    break;
                }
                default:{
                    Node *tmp = new Node(c,ptr, ptr->after);
                    if(ptr->after != nullptr){
                        ptr->after->before = tmp;
                    }
                    ptr->after = tmp;
                    ptr = tmp;
                    break;
                }
            }   
    }
    for(Node *i = root; i != nullptr; i=i->after){
        if(i == root){ continue; }
        cout << i->c;
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> T;
    while(T--){
        solve();
    }
	return 0;
}