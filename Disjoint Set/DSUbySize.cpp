#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {

    private:
    vector<int> parent;
    vector<int> size;

    public:
    DisjointSet(int n) {

        parent.resize(n+1); //n+1 for 1 based indexing
        size.resize(n+1);

        for(int i = 0 ; i <= n ; i++) {
            parent[i] = i;
            size[i] = 1;
        }

    }


    int findParent(int node) {

        if(parent[node] == node) return node;

        //path compresion while backtracking
        return parent[node] = findParent(parent[node]);
    }


    void unionBySize(int u , int v) {

        //find the ultimate parent
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if(ulp_u == ulp_v) return; //they belong to the same component no need union

        if(size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

int main(){
    
    DisjointSet ds(7);

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if(ds.findParent(3) == ds.findParent(7)) {
        cout << "Same component" << endl;
    } else {
        cout << "Different component" << endl;
    }

    ds.unionBySize(3, 7);

    if(ds.findParent(3) == ds.findParent(7)) {
        cout << "Now in same component" << endl;
    }

    return 0;
}