#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int> >pq;
int n,m,x;
int a[5000010];
int main()
{
    //scanf, printf 사용시 시간초과
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        pq.push({-x,i});
        while(i-pq.top().second>=m)pq.pop();
        cout<<-pq.top().first<<" ";
    }
    return 0;
}