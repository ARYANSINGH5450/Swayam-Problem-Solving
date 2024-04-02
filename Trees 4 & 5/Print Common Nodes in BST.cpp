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
void f(node* root)
{
    if(root==NULL)
    {
      return;
    }
    s.insert(root->val);
    f(root->left);
    f(root->right);
}
void print(node* root)
{
    if(root==NULL)
    {
      return;
    }
    if(s.count(root->val))
    {
      cout<<root->val<<" ";
    }
    print(root->left);
    print(root->right);
}
int main()
{
  node* A=new node(10);
  A->left=new node(5);
  A->right=new node(15);
  A->left->left=new node(2);
  A->left->right=new node(7); 
  node* B=new node(10);
  B->left=new node(5);
  B->right=new node(15);
  B->left->left=new node(2);
  B->left->right=new node(7); 
  f(A);
  print(B);
  return 0;
}
