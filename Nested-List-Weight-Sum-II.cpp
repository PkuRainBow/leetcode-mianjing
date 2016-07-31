/** problem  1 **/
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int res = 0;
        for (auto a : nestedList) {
            res += getSum(a, 1);
        }
        return res;
    }
    int getSum(NestedInteger ni, int level) {
        int res = 0;
        if (ni.isInteger()) return level * ni.getInteger();
        for (auto a : ni.getList()) {
            res += getSum(a, level + 1);
        }
        return res;
    }
};

class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int res = 0;
        vector<int> v;
        for (auto a : nestedList) {
            helper(a, 0, v);
        }
        for (int i = v.size() - 1; i >= 0; --i) {
            res += v[i] * (v.size() - i);
        }
        return res;
    } 


    void help(NestedInteger& ni, int depth, vector<vector<int>> &v) {
        if (depth >= v.size()) v.resize(depth + 1);
        if (ni.isInteger()) {
            v[depth] += ni.getInterger();
        }
        else {
            for (auto a : ni.getList()) {
                help(a, depth + 1, v);
            }
        }
    }
};


class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return helper(nestedList, 1);
    }
    int helper(vector<NestedInteger>& nl, int depth) {
        int res = 0;
        for (auto a : nl) {
            res += a.isInteger() ? a.getInteger() * depth : helper(a.getList(), depth + 1);
        }
        return res;
    }
};

/** problem  2 **/

class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int res = 0;
        vector<int> v;
        for (auto a : nestedList) {
            helper(a, 0, v);
        }
        for (int i = v.size() - 1; i >= 0; --i) {
            res += v[i] * (v.size() - i);
        }
        return res;
    }
    void helper(NestedInteger ni, int depth, vector<int> &v) {
        if (depth >= v.size()) v.resize(depth + 1);
        if (ni.isInteger()) {
            v[depth] += ni.getInteger();
        } else {
            for (auto a : ni.getList()) {
                helper(a, depth + 1, v);
            }
        }
    }
};





// use the method to accumulate the nested elements for multiple times
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int unweighted = 0, weighted = 0;
        while (!nestedList.empty()) {
            vector<NestedInteger> nextLevel;
            for (auto a : nestedList) {
                if (a.isInteger()) {
                    unweighted += a.getInteger();
                } else {
                    nextLevel.insert(nextLevel.end(), a.getList().begin(), a.getList().end());
                }
            }
            weighted += unweighted;
            nestedList = nextLevel;
        }
        return weighted;
    }
}; 