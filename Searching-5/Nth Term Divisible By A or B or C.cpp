#include<bits/stdc++.h>
using namespace std;
int hcf(int n1,int n2)
{
  if(n1==0)
  {
    return n2;
  }
  return hcf(n2%n1,n1);
}
int lcm(int n1,int n2)
{
  return (n1*n2)/hcf(n1,n2);
}
int count(int a,int b,int c,int m)
{
  return((m/a)+(m/b)+(m/c)-(m/lcm(a,b))-(m/lcm(b,c))-(m/lcm(a,c))+(m/lcm(a,lcm(b,c))));
}
int main()
{
  int a,b,c,n;
  cin>>a>>b>>c>>n;
  int low=1,high=max(a,max(b,c))*n;
  while(low<=high)
  {
    int mid=(low+high)/2;
    if(count(a,b,c,mid)<n)
    {
      low=mid+1;
    }
    else if(count(a,b,c,mid)>n)
    {
      high=mid-1;
    }
    else{
      cout<<mid;
      break;
    }
  }
  return 0;
}
