class Solution {
public:
    struct trie{
        trie* child[2];
        int num;
        trie()
        {
            child[0]=nullptr;
            child[1]=nullptr;
            num=-1;
        }
    };
    int findMaximumXOR(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        trie* root=new trie();
        trie* head=root;
        for(int i=0;i<nums.size();i++)
        {
            int n=nums[i];
            head=root;
            for(int i=31;i>=0;i--)
            {
                int bit=(n>>i)&1;
                if(!head->child[bit])
                {
                    head->child[bit]=new trie();
                }
                head=head->child[bit];
            }
            head->num=n;
        }
        head=root;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int n=nums[i];
            head=root;
            for(int i=31;i>=0;i--)
            {
                int bit=(n>>i)&1;
                if(!head->child[!bit])
                {
                    head=head->child[bit];
                }
                else
                {
                    head=head->child[!bit];
                }
            }
            ans=max(ans,n^head->num);
        }
        return ans;
    }
};
