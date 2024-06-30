class DSU{
    vector<int> size,parent;

    public:
    DSU(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        parent[i]=i;
    }

    int findpar(int node){
        if(node==parent[node])
        return node;

        return parent[node]=findpar(parent[node]);
    }

    bool Union(int n1, int n2){
        int par1=findpar(n1);
        int par2=findpar(n2);

        if(par1==par2)
        return false;
        if(size[par1]<size[par2]){
            parent[par1]=par2;
            size[par2]+=size[par1];
        }
        else{
            parent[par2]=par1;
            size[par1]+=size[par2];
        }
            return true;
    }

};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n);
        DSU bob(n);

        int result=0,alice_edge=0,bob_edge=0;

        for(auto & edge:edges){
            if(edge[0]==3){
            bool a=alice.Union(edge[1],edge[2]);
            bool b=bob.Union(edge[1],edge[2]);

            if(a){
            alice_edge++;
            bob_edge++;}
            else
            result++;

            }

        }

        for(auto & edge:edges){
            if(edge[0]==1){
                if(alice.Union(edge[1],edge[2])){
                    alice_edge++;
                }
                else
                result++;
            }
            else if(edge[0]==2){
                if(bob.Union(edge[1],edge[2])){
                    bob_edge++;
                }
                else
                result++;
            }
        }

        if(alice_edge==n-1 && bob_edge==n-1){
            return result;
        }
        return -1;
    }
};
