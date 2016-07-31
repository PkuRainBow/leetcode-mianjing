//http://www.cnblogs.com/grandyang/p/5268775.html

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image[0].size();
        //[left, right]
        int up = binary_search(image, true, 0, x, 0, n, true);
        //(left, right)
        int down = binary_search(image, true, x + 1, m, 0, n, false);
        //[left, right]
        int left = binary_search(image, false, 0, y, up, down, true);
        //(left, right)
        int right = binary_search(image, false, y + 1, n, up, down, false);
        return (right - left) * (down - up);
    }


    int binary_search(vector<vector<char>> &image, bool isRow, int i, int j, int low, int high, bool opt) {
        while (i < j) {
            int k = low, mid = (i + j) / 2;
            while (k < high && (isRow ? image[mid][k] : image[k][mid]) == '0') ++k;
            //find the black pixels
            if (k < high == opt) j = mid;
            else i = mid + 1;
        }
        return i;
    }
};