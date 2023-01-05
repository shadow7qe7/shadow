#include<bits/stdc++.h>
using namespace std;
stack<int>sta;
int n;
int a[1000010],ans[1000010];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=n;i>=1;i--)
    {
        while(!sta.empty()&&sta.top()<=a[i])sta.pop();
        if(sta.empty())ans[i]=-1;
        else ans[i]=sta.top();
        sta.push(a[i]);
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    return 0;
}