#include<bits/stdc++.h>
using namespace std;
int n,k,x,ans=(1<<30);
vector<int>v;
priority_queue<pair<int,int> >pq;
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<k+1;i++)
    {
        if(i==0)
            for(int j=0;j<n-k-1;j++)
                pq.push({-(v[j+1]-v[j]),j});
        else
            pq.push({-(v[n-k-1+i]-v[n-k-2+i]),n-k-2+i});
        while(!pq.empty()&&pq.top().second<i)pq.pop();
        ans=min(ans,-pq.top().first+v[n-k-1+i]-v[i]);
    }
    cout<<ans;
    return 0;
}