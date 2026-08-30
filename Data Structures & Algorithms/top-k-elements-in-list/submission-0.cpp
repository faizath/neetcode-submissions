class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> tally;
        for (int n : nums) {
            tally[n]++;
        }

        vector<pair<int,int>> sorter;
        for (const auto& p : tally) {
            sorter.push_back({p.second, p.first});
        }
        sort(sorter.rbegin(), sorter.rend());

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(sorter[i].second);
        }
        return result;
    }
};
