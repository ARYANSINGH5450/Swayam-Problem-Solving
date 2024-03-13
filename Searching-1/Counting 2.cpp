#include<bits/stdc++.h>
using namespace std;
int bs(int ele,int a[],int n,int ans)
{
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]>=ele)
        {
            ans=max(ans,n-mid);
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}
int main()
{
  int n,q,arr[100],qarr[100];
  cin>>n>>q;
  for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    sort(arr,arr+n);
   for(int i=0;i<q;i++)
    {
      cin>>qarr[i];
    }
  for(int i=0;i<q;i++)
    {
      cout<<bs(qarr[i],arr,n,0)<<" ";
    }
  return 0;
}
