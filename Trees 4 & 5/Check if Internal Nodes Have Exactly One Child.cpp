#include<bits/stdc++.h>
using namespace std;
bool hasonechild(vector<int>v)
{
    int next,last=v[v.size()-1];
    for(int i=0;i<v.size()-1;i++)
    {
        next=v[i+1];
        int d1=next-v[i];
        int d2=last-v[i];
        if(d1*d2<0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    vector<int>preorder={10,15,12,13,14};
    cout<<hasonechild(preorder);
    return 0;
}
