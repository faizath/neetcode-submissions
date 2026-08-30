class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> t_map, window;
        for (char c : t) t_map[c]++;
        int need = t_map.size();

        pair<int, int> res = {-1, -1};
        int reslen = INT_MAX;
        int l = 0, have = 0;
        
        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;

            if (t_map.count(c) && t_map[c] == window[c]) have++;

            while (have == need) {
                if ((r - l + 1) < reslen) {
                    reslen = r - l +  1;
                    res = {l, r};
                }

                window[s[l]]--;
                if (t_map.count(s[l]) && window[s[l]] < t_map[s[l]]) have--;
                l++;
            }
        }

        return reslen == INT_MAX ? "" : s.substr(res.first, reslen);
    }
};
