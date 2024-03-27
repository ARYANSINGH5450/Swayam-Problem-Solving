#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m,k;
cin>>n>>m>>k;
int a[100],b[100];
for(int i=0;i<n;i++)
{
  cin>>a[i];
}
for(int i=0;i<m;i++)
{
  cin>>b[i];
}
sort(a,a+n);
sort(b,b+n);
int l1=0,l2=n-1,r1=0,r2=m-1,j=0,c[100];
while(l1<=l2&&r1<=r2)
{
  if(a[l1]<=a[r1])
  {
    c[j]=a[l1];
    l1++;
    j++;
  }
  else{
    c[j]=a[r1];
    j++;
    r1++;
  }
}
while(l1<=l2)
{
  c[j]=a[l1];
  j++;
  l1++;
}
while(r1<=r2)
{
  c[j]=b[r1];
  j++;
  r1++;
}
int count=0,sum=0;
for(int i=0;i<n+m;i++)
{
  sum+=c[i];
  if(sum>=k)
  {
    break;
  }
  count++;
}
cout<<count;
return 0;
}
