#include<bits/stdc++.h>
using namespace std;
int n,g,b,d,x,y,t;
long long ans;
int Next[50050];
stack<pair<int,int> >sta;
vector<pair<int,int> >v;
int main()
{
    cin>>n>>g>>b>>d;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        v.push_back({x,y});
    }
    v.push_back({d,-1});
    sort(v.begin(),v.end());
    for(int i=n;i>=0;i--)
    {
        while(!sta.empty()&&sta.top().first>=v[i].second)sta.pop();
        Next[i]=sta.empty()?-1:sta.top().second;
        sta.push({v[i].second,i});
    }
    //1 4 3 4 -1
    for(int i=0;i<n;i++)
    {
        b-=v[i].first-t;
        if(b<0)
        {
            cout<<-1;
            return 0;
        }
        if(v[Next[i]].first-v[i].first<=g)
        //현재 주유소보다 싼 주유소에 갈 수 있다면
        {
            int cnt=v[Next[i]].first-v[i].first-b;///연료계산
            if(cnt<=0)//그냥 가면 됨
            {
                
            }
            else//필요한 만큼 충전하고 가면 됨
            {
                b+=cnt;
                ans+=(long long)cnt*v[i].second;
            }
        }
        else
        //현재 주유소보다 싼 주유소가 없거나 g보다 멀리 있는 경우
        {
            //가득채우기
            ans+=(long long)v[i].second*(g-b);
            b=g;
        }
        t=v[i].first;
        //다음 주유소로 이동
    }
    cout<<ans;
    return 0;
}