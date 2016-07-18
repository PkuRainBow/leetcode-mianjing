class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> parents(n,0);
        for(int i=0; i<n; i++) parents[i] = i;
        for (int i = 0; i < edges.size(); i++) {
            int root1 = find(edges[i].first);
            int root2 = find(edges[i].second);
            if (root1 == root2) return false;
            parents[root1] = root2;
        }
        return parents.size() == n - 1;
    }

    int find(int index, vector<int>& parents) {
        while (index != parents[index]) {
            parents[index] = parents[parents[index]];
            index = parents[index];
        }
        return index;
    }
};