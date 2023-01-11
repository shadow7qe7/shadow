#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
long long z;
long long a[1<<22];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%d %d %d",&n,&x,&y);
    for(m=1;m<n;m*=2);//시작값 정하는거
    for(int i=0;i<n;i++)scanf("%lld",&a[i+m]);//scanf
    for(int i=m-1;i>0;i--)a[i]=a[i*2]+a[i*2+1];//초기 세그먼트트리 설정
    n=x+y;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %lld",&x,&y,&z);
        if(x==1)//update
        {
            int temp=m+y-1;
            a[temp]=z;
            while(temp/=2)
                a[temp]=a[temp*2]+a[temp*2+1];
        }
        else//query
        {
            long long ans=0;
            int left=m+y-1, right=m+z-1;//left는 짝수인경우 바로 위로, right는 홀수인경우 바로 위로
            while(left<=right)
            {
                if(left%2==1)//홀수인경우
                    ans+=a[left++];
                if(right%2==0)//짝수인경우
                    ans+=a[right--];
                left/=2;
                right/=2;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}