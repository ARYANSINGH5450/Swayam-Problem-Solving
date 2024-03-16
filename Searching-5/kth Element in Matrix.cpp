int kthele(int a[][],int n,int k)
	{
        int low=a[0][0];
        int high=a[n-1][a[0].size()-1];
        int ans;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(a,mid)<k)
            {
                low=mid+1; 
            }
            else
            {
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
    int check(int arr[][],int m)
    {
        int i=0 ;
        int r=0;
        int j=arr[0].size()-1;
        while(i<arr.size()&&j>=0){
            if(arr[i][j]>m)
            {
                j--;
            }
            else
            {
                r+=j+1;
                i++;
            }
        }
        return r;
    }
