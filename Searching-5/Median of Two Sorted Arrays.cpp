#include<bits/stdc++.h>
using namespace std;
int count(int arr[],int ele,int n)
{
  int low=0,high=n,ans=INT_MIN;
  while(low<=high)
  {
    int mid=(low+high)/2;
    if(arr[mid]==ele)
    {
      return mid;
    }
    else if(arr[mid]>ele)
    {
      high=mid-1;
    }
    else
    {
      ans=max(ans,mid+1);
      low=mid+1;
    }
  }
  return ans;
}
int main()
{
  int n1,n2,a[100],b[100],ans;
  cin>>n1>>n2;
  for(int i=0;i<n1;i++)
  {
    cin>>a[i];
  }
  for(int i=0;i<n2;i++)
  {
    cin>>b[i];
  }
  int min1=*min_element(a,a+n1);
  int min2=*min_element(b,b+n2);
  int max1=*max_element(a,a+n1);
  int max2=*max_element(b,b+n2);
  int low=min(min1,min2);
  int high=max(max1,max2);
  while(low<=high)
  {
    int mid=(low+high)/2;
    int c=count(a,mid,n1)+count(b,mid,n2);
    if(c<(n1+n2)/2)
    {
      low=mid+1;
    }
    else if(c>(n1+n2)/2)
    {
      high=mid-1;
    }
    else
    {
      ans=mid;
      low=mid+1;
    }
  }
  cout<<low;
  return 0;
}