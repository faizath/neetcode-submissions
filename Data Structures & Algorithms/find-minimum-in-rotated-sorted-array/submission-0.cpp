class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return (nums[0] < nums[1] ? nums[0] : nums[1]);
        int l = 0, r = nums.size() - 1, mid = (r - l) / 2;
        
        while (r - l > 1) {
            if (nums[l] < nums[mid]) {
                if (nums[mid] > nums[r]) l = mid;
                else return nums[0];
            } else r = mid;
            mid = ((r - l) / 2) + l;
        }

        return (nums[l] < nums[r] ? nums[l] : nums[r]);
    }
};