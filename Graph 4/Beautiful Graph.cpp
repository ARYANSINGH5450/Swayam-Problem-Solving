#include<bits/stdc++.h>
using namespace std;
bool bfs(queue<int>& q,vector<int>& color,vector<int>& vis,vector<vector<int>>graph,int n1,int n0)
    {
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            vis[temp]=1;
            for(auto i:graph[temp])
            {
                if(!vis[i])
                {
                    q.push(i);
                    color[i]=!color[temp];
                    if(color[i]==0)
                    {
                        n0+=1;
                    }
                    else
                    {
                        n1+=1;
                    }
                }
                else if(color[i]==color[temp])
                {
                    return false;
                }
            }
        }
        return true;
    }
    int f(vector<vector<int>>& graph) {
        queue<int>q;
        vector<int>color(graph.size());
        vector<int>vis(graph.size(),0);
        int n1=0,n0=0,ans=1;
        for(int i=0;i<graph.size();i++)
        {
            if(!vis[i])
            {
                q.push(i);
                color[i]=0;
                n0=1;
                n1=0;
                if(bfs(q,color,vis,graph,n1,n0)==false)
                {
                    ans=0;
                    break;
                }
                else
                {
                    ans=ans*(pow(2,n0)+pow(2,n1));
                }
            }
        }
        return ans;
    }
int main()
{
    int n=4;
    vector<vector<int>>graph(n);
    graph[0].push_back(1);
    graph[0].push_back(3);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(0);
    graph[3].push_back(2);
    cout<<f(graph);
    return 0;
}
