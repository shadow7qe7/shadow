#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,z;
int a[1<<22];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n=1000000;
    for(m=1;m<n;m*=2);//시작값 정하는거
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(x==2)//update
        {
            scanf("%d %d",&y,&z);
            int temp=m+y-1;
            a[temp]+=z;
            while(temp/=2)
                a[temp]=a[temp*2]+a[temp*2+1];
        }
        else//query
        {
            scanf("%d",&y);
            int ans=1;
            while(ans<m)
            {
                if(a[ans*2]>=y)ans*=2;
                else ans=ans*2+1;
            }
            a[ans]--;
            printf("%d\n",ans-m+1);
            //update
            while(ans/=2)
                a[ans]=a[ans*2]+a[ans*2+1];
        }
    }
    return 0;
}
