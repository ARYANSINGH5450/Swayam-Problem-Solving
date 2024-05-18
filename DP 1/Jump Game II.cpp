class Solution {
public:
    int jump(vector<int>& nums) {
        int c=0;
        int mj=0;
        int jump=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(i+nums[i]>mj)
            {
                mj=i+nums[i];
            }
            if(i==c)
            {
                jump++;
                c=mj;
            }
        }
        return jump;
    }
};
