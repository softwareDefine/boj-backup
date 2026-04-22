#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
vector<int> conn[55];
int N;
int rootNode;
int delNode;
int leafCnt;
 
void find_leaf(int node)
{
    if(conn[node].size() == 0)
    {
        leafCnt++;
    }
    
    for(int i = 0; i < conn[node].size(); i++)
    {
        if(conn[node][i] == delNode)
        {
            if(conn[node].size() == 1)
            {
                leafCnt++;    
            }
            
            continue;
        }
        
        find_leaf(conn[node][i]);
    }
}
 
int main(void)
{
    cin >> N;
    
    for(int to = 0; to < N; to++)
    {
        int from;
        cin >> from;
        
        if(from == -1)
        {
            rootNode = to;
            
            continue;
        }
        else
        {
            conn[from].push_back(to);    
        }
    }
    
    cin >> delNode;
    
    if(delNode == rootNode)
    {
        cout << "0";
    }
    else
    {
        find_leaf(rootNode);
        cout << leafCnt;    
    }
    return 0;
}
