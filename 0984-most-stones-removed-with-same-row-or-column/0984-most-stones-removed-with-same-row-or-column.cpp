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
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=0, maxcol=0;
        for(auto i:stones){
            maxrow=max(maxrow,i[0]);
            maxcol=max(maxcol,i[1]);
        }
        
        DisjointSet ds(maxrow+maxcol+1);
        unordered_map<int,int>mp;
        for(auto i:stones){
            int row=i[0], col=i[1];
            int col_num=maxrow+1+col;
            int row_num=row;
            ds.unionBySize(row_num,col_num);
            mp[row_num]=1;
            mp[col_num]=1;
        }
        
        int cnt=0;
        for(auto i:mp)
            if(ds.findParent(i.first)==i.first) 
                cnt++;
        //  We use a map to traverse because, if we just traverse from i=0 to i<maxrow+maxcol+1
        //  We will consider nodes(rows/cols) that don not have any stones in them
        //  As they themselves will be their Ultimate Parent, it will increase cnt     
        //  unnecessarily
        return stones.size()-cnt;
    }
};