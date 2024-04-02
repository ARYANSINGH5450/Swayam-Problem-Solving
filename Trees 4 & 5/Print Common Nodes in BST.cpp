#include<bits/stdc++.h>
using namespace std;
set<int>s;
struct node{
    int val;
    node* left;
    node* right;
    node(int data)
    {
        val=data;
        left=nullptr;
        right=nullptr;
    }
};
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
    
  f(A);
  print(B);
  return 0;
}
