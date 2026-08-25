#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {

    private:
    vector<int> tree;

    void buildTree(const vector<int> &nums, int node , int start , int end) {

        if(start == end) {
            //leaf node will be the single node
            tree[node] = nums[start];
            return;
        }

        
    }


    
};

int main() {

}