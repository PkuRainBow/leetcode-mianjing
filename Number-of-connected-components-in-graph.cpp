/**
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:
     0          3
     |          |
     1 --- 2    4
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:
     0           4
     |           |
     1 --- 2 --- 3
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
**/

class NumberOfConnectedIsland {
	vector<int> father;
public:
	int find(int i ) {
		while (i != father[i]) {
			father[i] = father[father[i]];
			i = father[i];
		}
		return i;
	}

	void unions(int p, int q) {
		int x = find(p);
		int y = find(q);
		father[x] = y;
	}

	int countComponents(int n, vector<pair<int, int>>& edges) {
		father.resize(n);
		for (int i = 0; i < n; i++) {
			father[i] = i;
		}
		int count = 0;
		for (const auto& edge : edges) {
			int x = find(edge.first);
			int y = find(edge.second);
			if (x != y) {
				unions(edge.first, edges.second);
				count++;
			}
		}
		return n - count;
	}
}