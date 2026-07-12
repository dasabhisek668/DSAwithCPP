#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {

    private:
    vector<int> parent;
    vector<int> rank;

    public:
    DisjointSet(int n) {

        parent.resize(n+1); //n+1 for 1 based indexing
        rank.resize(n+1);

        for(int i = 0 ; i <= n ; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

    }


    int findParent(int node) {

        if(parent[node] == node) return node;

        //path compresion while backtracking
        return parent[node] = findParent(parent[node]);
    }


    void unionByRank(int u , int v) {

        //find the ultimate parent
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if(ulp_u == ulp_v) return; //they belong to the same component no need union

        if(rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        } else {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
};

int main(){
    
    DisjointSet ds(7);

    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    if(ds.findParent(3) == ds.findParent(7)) {
        cout << "Same component" << endl;
    } else {
        cout << "Different component" << endl;
    }

    ds.unionByRank(3, 7);

    if(ds.findParent(3) == ds.findParent(7)) {
        cout << "Now in same component" << endl;
    }

    return 0;
}