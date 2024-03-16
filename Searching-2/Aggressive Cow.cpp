#include<bits/stdc++.h>
using namespace std;
bool check(int a[],int d,int n,int cows)
{
     int tc=1;
     int last=a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i]-last>=d)
            {
               tc++;
               last=a[i];
            }
        }
        if(tc>=cows)
        {
            return true;
        }
        return false;
     }
int main()
{
    int n,cows;
    int a[100];
    cin>>n>>cows;
    sort(a,a+n);
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ma=*max_element(a,a+n);
    int mi=*min_element(a,a+n);
    int low=1,high=ma-mi;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(check(a,mid,n,cows))
        {
            ans=max(ans,mid);
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
