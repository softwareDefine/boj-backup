#include <cstdio>
#include <vector>
#include <algorithm>

int cnt;
using namespace std;
bool check[2001];
int temp;
int n;
int main()
{
    vector<int> vec;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        if(check[-temp+1000]!=true&&temp<0){
            vec.push_back(temp);
            check[-temp+1000] = true;
        }
        else if(check[temp]!=true&&temp>=0){
            vec.push_back(temp);
            check[temp] = true;
        }
    }
    sort(vec.begin(),vec.begin()+vec.size());
    for(int i=0;i<vec.size();i++){
        printf("%d ",vec[i]);
    }
    return 0;
}
