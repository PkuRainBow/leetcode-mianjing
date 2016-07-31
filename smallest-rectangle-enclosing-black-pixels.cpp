class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int left = y, right = y, up = x, down = x;
        for (int i = 0; i < image.size(); ++i) {
            for (int j = 0; j < image[i].size(); ++j) {
                if (image[i][j] == '1') {
                    left = min(left, j);
                    right = max(right, j);
                    up = min(up, i);
                    down = max(down, i);
                }
            }
        }
        return (right - left + 1) * (down - up + 1);
    }
};



class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image[0].size();
        
    }
    int binary_search(vector<vector<char>> &image, bool h, int i, int j, int low, int high, bool opt) {
        while (i < j) {
            int k = low, mid = (i + j) / 2;
            while (k < high && (h ? image[mid][k] : image[k][mid]) == '0') ++k;
            if (k < high == opt) j = mid;
            else i = mid + 1;
        }
        return i;
    }
};