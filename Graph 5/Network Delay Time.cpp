class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      vector<pair<int,int>>adj[n+1];
	    for(vector<int>i:times)
	    {
		    adj[i[0]].push_back({i[1],i[2]});
	    }
	    vector<int>dist(n+1,INT_MAX);
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	    dist[k]=0;
	    pq.push({k,0});
	    while(!pq.empty())
      {
		    auto x=pq.top();
		    pq.pop(); 
		    for(auto i:adj[x.first])
        {
		    	if(dist[x.first]+i.second<dist[i.first])
          {
			    	dist[i.first]=dist[x.first]+i.second;
			    	pq.push({i.first,dist[i.first]});
		    	}
		    }  
	    }     
	    int maxi=INT_MIN;  
    	for(int i=1;i<=n;i++)
      {
    		if(dist[i]==INT_MAX)  return -1;
    		else
        {
                maxi=max(maxi,dist[i]);
        }
    	}
	    return maxi;    
    }
};
