#include<bits/stdc++.h>
using namespace std;
set<int>s;
void f(TreeNode* root)
{
    if(root==NULL)
    {
      return;
    }
    s.insert(root->val);
    f(root->left);
    f(root->right);
}
void print(TreeNode* root)
{
    if(root==NULL)
    {
      return;
    }
    if(s.count(root->val))
    {
      cout<<root->val;
    }
    print(root->left);
    print(root->right);
}
int main()
{
  set<int>s;
  f(s,root);
  print(s,root);
  return 0;
}
