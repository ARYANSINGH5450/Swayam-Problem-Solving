#include<bits/stdc++.h>
using namespace std;
struct trienode{
    trienode* child[26];
    bool flag;
    trienode()
    {
        for(int i=0;i<26;i++)
        {
            child[i]=nullptr;
        }
        flag=false;
    }
};
int main()
{
    int n;
    string word="apple";
    trienode* root=new trienode();
    trienode* head=root;
    for(int i=0;i<word.size();i++)
    {
        if(head->child['a'-word[i]]==NULL)
        {
            head->child['a'-word[i]]=new trienode();
        }
        head=head->child['a'-word[i]];
    }
    head=root;
    string words="apf";
    for(int i=0;i<words.size();i++)
    {
        if(head->child['a'-words[i]]==NULL)
        {
            cout<<0;
            break;
        }
        else
        {
            head=head->child['a'-words[i]];
        }
    }
    cout<<1;
    return 0;
}