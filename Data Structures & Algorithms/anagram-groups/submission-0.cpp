class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dictionary;
        for (string s: strs) {
            string key = s;
            sort(key.begin(), key.end());
            dictionary[key].push_back(s);
        }

        vector<vector<string>> result;
        result.reserve(dictionary.size());
        for (auto& p : dictionary) {
            result.push_back(move(p.second));
        }
        return result;
    }
};
