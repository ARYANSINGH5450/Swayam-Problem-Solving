#include <bits/stdc++.h>
using namespace std;
int count(vector<int>v,int mid)
{
  int l=0,h=v.size()-1;
  while (l<=h)
  {
    int m=(l+h)/2;
    if (v[m] <= mid)
    {
      l=m+1;
    }
    else
    {
      h=m-1;
    }
  }
  return l;
}
int findMedian(vector<vector<int>> &A)
{
  int low=1;
  int high=INT_MAX;
  int n=A.size();
  int m=A[0].size();
  while (low<=high)
  {
    int mid=(low+high)/2;
    int c=0;
    for (int i=0;i<n;i++)
    {
      c+=count(A[i],mid);
    }
    if (c<=(n *m)/2){
      low=mid+1;
    }
    else{
      high=mid-1;
    }
  }
  return low;
}
