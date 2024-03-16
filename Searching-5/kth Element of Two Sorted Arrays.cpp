#include<bits/stdc++.h>
using namespace std;
int kthelement(int arr1[], int arr2[], int n1, int n2, int k){
    if(m>n) 
    {
        return kthelement(arr2,arr1,n,m,k); 
    }   
    int low=max(0,k-m),high=min(k,n);
    while(low<=high) 
    {
        int mid1=(low + high)/2; 
        int mid2=k-mid1;
        int l1 = (mid1==0)?INT_MIN:arr1[mid1 - 1]; 
        int l2 = (mid2==0)?INT_MIN:arr2[mid2 - 1];
        int r1 = (mid1==n2)?INT_MAX:arr1[mid1]; 
        int r2 = (mid2==n1)?INT_MAX:arr2[mid2]; 
        if(l1<=r2&&l2<=r1)
        {
            return max(l1,l2);
        }
        else if (l1>r2) 
        {
            high=mid1-1;
        }
        else 
        {
            low=mid1+1; 
        }
    }
    return 0; 
}
