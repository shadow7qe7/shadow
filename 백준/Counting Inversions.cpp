#include<bits/stdc++.h>
using namespace std;
int n,m,x;
long long ans;
long long a[1<<22];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%d",&n);
    for(m=1;m<n;m*=2);//시작값 정하는거
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        //query x+1~n
        int left=m+x, right=m+n-1;//left는 짝수인경우 바로 위로, right는 홀수인경우 바로 위로
        long long y=0;
        while(left<=right)
        {
            if(left%2==1)//홀수인경우
                y+=a[left++];
            if(right%2==0)//짝수인경우
                y+=a[right--];
            left/=2;
            right/=2;
        }
        ans+=y;
        //add x
        //update
        int temp=m+x-1;
        a[temp]=1;
        while(temp/=2)
            a[temp]=a[temp*2]+a[temp*2+1];
    }
    printf("%lld",ans);
    return 0;
}