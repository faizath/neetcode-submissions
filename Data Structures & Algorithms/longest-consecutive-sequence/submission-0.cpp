class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int longest = 0;
        for (int n: nums) {
            if (set.find(n - 1) == set.end()) {
                int length = 0;
                while(set.find(n + length) != set.end()) length++;
                longest = length > longest ? length : longest;
            }
        }
        return longest;
    }
};
