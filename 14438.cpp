#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,z;
int a[1000000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%d",&n);
    for(m=1;m<n;m*=2);//시작값 정하는거
    for(int i=1;i<m*2;i++)a[i]=(1<<30);//초기화
    for(int i=0;i<n;i++)scanf("%d",&a[i+m]);//scanf
    for(int i=m-1;i>0;i--)a[i]=min(a[i*2],a[i*2+1]);//초기 세그먼트트리 설정
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        if(x==1)//update
        {
            int temp=m+y-1;
            a[temp]=z;
            while(temp/=2)
                a[temp]=min(a[temp*2],a[temp*2+1]);
        }
        else//query
        {
            int left=m+y-1, right=m+z-1;//left는 짝수인경우 바로 위로, right는 홀수인경우 바로 위로
            int ans=(1<<30);
            while(left<=right)
            {
                if(left%2==1)//홀수인경우
                    ans=min(ans,a[left++]);
                if(right%2==0)//짝수인경우
                    ans=min(ans,a[right--]);
                left/=2;
                right/=2;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}