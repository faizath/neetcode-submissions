#include <vector>
#include <unordered_map>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mapper;
        for (int i = 0; i < nums.size(); i++) {
            if (mapper.find(nums[i]) != mapper.end()) {
                return true;
            }
            mapper[nums[i]] = true;
        }
        return false;
    }
};