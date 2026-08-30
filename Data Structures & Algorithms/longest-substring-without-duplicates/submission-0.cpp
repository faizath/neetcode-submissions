class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2) return s.size();
        int longest = 1;
        unordered_map<char,int> seen;
        int l = 0, r = 0;
        while (r < s.size()) {
            if (seen.find(s[r]) != seen.end()) {
                l = max(seen[s[r]] + 1, l);
            }
            seen[s[r]] = r;
            longest = max(longest, r - l + 1);
            r++;
        }
        return longest;
    }
};
