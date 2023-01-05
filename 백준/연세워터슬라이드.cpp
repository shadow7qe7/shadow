#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000010];
long long d[1000010];
priority_queue<pair<long long,int> >pq;///<숫자,번호>
int main()
{
    //freopen("input.txt","r",stdin);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        while(!pq.empty()&&(long long)i-pq.top().second>(long long)k)pq.pop();
        if(pq.empty())d[i]=a[i];
        else
            d[i]=max(/*d[i-k]*/pq.top().first+a[i],(long long)a[i]);
        pq.push({d[i],i});
    }
    long long ans=-(1<<31);
    for(int i=1;i<=n;i++)
        ans=max(ans,d[i]);
        //printf("%d ",d[i]);
    cout<<ans;
    return 0;
}