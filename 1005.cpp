#include<bits/stdc++.h>
using namespace std;
int t,n,m,s,e;
int c[1010],a[1010],d[1010];
int main()
{
    cin>>t;
    for(int temp=0;temp<t;temp++)
    {
        vector<int>v[1010];
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=m;i++)
        {
            cin>>s>>e;
            v[s].push_back(e);
            c[e]++;
        }
        queue<int>q;
        for(int i=1;i<=n;i++)
            d[i]=a[i];
        for(int i=1;i<=n;i++)
            if(c[i]==0)q.push(i);
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(int i=0;i<v[x].size();i++)
            {
                d[v[x][i]]=max(d[v[x][i]],d[x]+a[v[x][i]]);
                if(--c[v[x][i]]==0)q.push(v[x][i]);
            }
        }
        int y;
        cin>>y;
        cout<<d[y]<<"\n";
    }
    return 0;
}