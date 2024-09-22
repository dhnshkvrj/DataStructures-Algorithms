class DisjointSet{
    vector<int> parent,size;
public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }
    int findParent(int node){
        if(parent[node]==node)  return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int pu=findParent(u), pv=findParent(v);
        if(pu==pv)  return ;
        else if(size[pu]>=size[pv]){
            size[pu]+=size[pv];
            parent[pv]=pu;
        }
        else{
            size[pv]+=size[pu];
            parent[pu]=pv;
        }
    }
    
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        vector<int> connected(n,0);
    
        
        int extra=0;
        for(auto i:connections){
            int u=i[0], v=i[1];
            int pu=ds.findParent(u), pv=ds.findParent(v);
            if(pu==pv)    extra++;
            else
                ds.unionBySize(u,v);
        }

        int components=0;
        for(int i=0;i<n;i++)
            if(i==ds.findParent(i)) components++;

        if(extra>=components-1) return components-1;
        return -1;
    }
};