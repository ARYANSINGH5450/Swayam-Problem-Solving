#include<bits/stdc++.h>
using namespace std;
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
bool leaf(node* root)
{
    if(root->left==NULL&root->right==NULL)
    {
        return true;
    }
    return false;
}
void leftb(node* root,vector<int>& res)
{
    node* temp=root->left;
    while(temp)
    {
        if(!leaf(temp))
        {
            res.push_back(temp->val);
        }
        if(temp->left)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
}
void leafb(node* root,vector<int>& res)
{
    if(leaf(root))
    {
        res.push_back(root->val);
        return;
    }
    if(root->left)
    {
        leafb(root->left,res);
    }
    if(root->right)
    {
        leafb(root->right,res);
    }
}
void rightb(node* root,vector<int>& res)
{
    node* temp=root->right;
    vector<int>v;
    while(temp)
    {
        if(!leaf(temp))
        {
            v.push_back(temp->val);
        }
        if(temp->right)
        {
            temp=temp->right;
        }
        else
        {
            temp=temp->left;
        }
    }
    for(int i=v.size()-1;i>=0;i--)
    {
        res.push_back(v[i]);
    }
}
int main()
{
    vector<int>res;
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    if(!leaf(root))
    {
        res.push_back(root->val);
    }
    leftb(root,res);
    leafb(root,res);
    rightb(root,res);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    return 0;
}
