class Solution {
public:
vector<string>f(TreeNode* root,string s,vector<string>&ans){
    if(root==NULL)
    {
        return {};
    }
    if(root->left==NULL&&root->right==NULL)
    {
       s+=to_string(root->val);
       ans.push_back(s);
    }
    s+=to_string(root->val);
    s+="->";
    f(root->left,s,ans);
    f(root->right,s,ans);
    s.pop_back();
    return ans;
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string s="";
        return f(root,s,ans);
    }
};
