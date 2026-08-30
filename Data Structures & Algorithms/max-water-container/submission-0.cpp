class Solution {
public:
    int maxArea(vector<int>& heights) {
        if (heights.size() < 2) return 0;
        int max_area = 0;
        int l = 0, r = heights.size() - 1;
        while (l < r) {
            max_area = max(max_area, (r - l) * min(heights[l], heights[r]));
            if (heights[l] < heights[r]) l++;
            else r--;
        }
        return max_area;
    }
};
