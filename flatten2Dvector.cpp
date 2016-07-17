#include <vector>
using namespace std;

class Vector2D {
    //i record the start iterator of the 2dim
    //iEnd record the end iterator of the 2-dim
    //j record the current index of the current iterator
    vector<vector<int>>::iterator i, iEnd;
    int j = 0;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        i = vec2d.begin();
        iEnd = vec2d.end();
    }

    int next() {
        hasNext();
        return (*i)[j++];
    }

    bool hasNext() {
        while (i != iEnd && j == (*i).size())
            i++, j = 0;
        return i != iEnd;
    }
};

/** flatten nested linked list **/


class NestedIterator {
    stack<NestedInteger> nodes;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int size = nestedList.size();
        for (int i = size - 1; i >= 0; i--) {
            nodes.push(nestedList[i]);
        }
    }

    int next() {
        int result = nodes.top().getInteger();
        nodes.pop();
        return result;
    }

    bool hasNext() {
        while (!nodes.empty()) {
            NestedIterator cur = nodes.top();
            //current nodes are integer
            if (cur.isInteger()) {
                return true;
            }
            nodes.pop();
            vector<NestedInteger>& adjs = curr.getList();
            int size = adjs.size();
            for(int i = size - 1; i >= 0; --i) {
                nodes.push(adjs[i]);
            }
        }
        return false;
    }
};