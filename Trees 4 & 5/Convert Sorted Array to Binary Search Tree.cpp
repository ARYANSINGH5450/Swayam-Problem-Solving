class Solution {
public:
    TreeNode* build(vector<int>nums,int low,int high)
    {
            if(low>high)
            {
                return NULL;
            }
            int mid=(low+high)/2;
            TreeNode* root=new TreeNode(nums[mid]);
            root->left=build(nums,low,mid-1);
            root->right=build(nums,mid+1,high);
            return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums,0,nums.size()-1);
    }
};
