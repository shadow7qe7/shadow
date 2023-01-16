#include<bits/stdc++.h>
using namespace std;
int sum,n,m;
int a[200010];
int cnt[200010];
long long dist[200010];
vector<pair<int,long long> >v[200010];
vector<int>v2;
priority_queue<pair<long long,int> >pq;
void dfs(int node,int prev)
{
    if(node==1)
    {
        cout<<v2.size()<<"\n";
        for(int i=v2.size()-1;i>=0;i--)
            cout<<v2[i]<<" ";
        exit(0);
    }
    for(int i=0;i<v[node].size();i++)
    {
        int next=v[node][i].first;
		int cost=v[node][i].second;
		if (next==prev)continue;
		if (dist[next]+cost!=dist[node]) continue;
		if (cnt[next]+a[node]!=cnt[node]) continue;
		v2.push_back(next);
		dfs(next,node);
		v2.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<200007;i++)
        dist[i]=1e18;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,e,w;
        cin>>u>>e>>w;
        v[u].push_back({e,w});
        v[e].push_back({u,w});
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    pq.push({0,1});
    cnt[1]=a[1];
    dist[1]=0;
    while(!pq.empty())
    {
        long long cost=-pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(dist[cur]<cost)continue;
        for(int i=0;i<v[cur].size();i++)
        {
            int next=v[cur][i].first;
            long long ncost=v[cur][i].second+cost;
            if(dist[next]>ncost)
            {
                dist[next]=ncost;
                cnt[next]=max(cnt[next],cnt[cur]+a[next]);
                pq.push({-dist[next],next});
            }
            else if(dist[next]==ncost)
                cnt[next]=max(cnt[next],cnt[cur]+a[next]);
        }
    }
    if(cnt[n]!=sum)
    {
        cout<<-1;
        return 0;
    }
    v2.push_back(n);
    dfs(n,0);
    return 0;
}