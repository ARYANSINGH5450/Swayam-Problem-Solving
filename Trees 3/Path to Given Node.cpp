#include <bits/stdc++.h>
using namespace std;
struct Node{
  int val;
  Node* left;
  Node*right;
  Node(int data)
  {
      val=data;
      left=nullptr;
      right=nullptr;
  }
};
bool path(Node* root,vector<int>&v,int n) 
{
  if (root==NULL)
  {
    return false;
  }
  v.push_back(root->val);
  if (root->val==n)
  {
    return true;
  }
  if(path(root->left,v,n)||path(root->right,v,n))
  {
    return true;  
  }
  v.pop_back();
  return false;
}
int main()
{
  struct Node* root=new Node(10);
  root->left=new Node(11);
  root->right=new Node(12);
  root->left->left=new Node(13);
  root->left->right=new Node(14);
  root->right->left=new Node(15);
  root->right->right=new Node(16);
  vector<int>v;
  if(path(root,v,15))
  {
     for (auto i:v) 
     {
        cout<<i<<" ";
     }
  }
  return 0;
}
