class Solution {
public:
    int binarySearch(const vector<int>& nums, int l, int r, int target) {
        if (l > r) return -1;
        while (r - l > 1) {
            int mid = ((r - l) / 2) + l;
            if (nums[mid] <= target) l = mid;
            else r = mid;
        }
        if (nums[l] == target) return l;
        else if (nums[r] == target) return r;
        else return -1;
    }

    int binarySearch(const vector<int>& nums, int target) {
        return binarySearch(nums, 0, (int)nums.size() - 1, target);
    }

    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) return (nums[0] == target ? 0 : -1);
        if (nums.size() == 2) {
            if (nums[0] == target) return 0;
            else if (nums[1] == target) return 1;
            else return -1;
        }

        int l = 0, r = (int)nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) l = mid + 1;
            else r = mid;
        }
        int pivot = l;

        if (pivot == 0) return binarySearch(nums, target);
        
        int left = binarySearch(nums, 0, pivot - 1, target);
        if (left > -1) return left;

        return binarySearch(nums, pivot, (int)nums.size() - 1, target);
    }
};
