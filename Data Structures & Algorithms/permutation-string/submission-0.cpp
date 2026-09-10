class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        unordered_map<int, int> s1map, s2map;

        for (int i = 0; i < s1.length(); i++) {
            s1map[s1[i] - 'a']++;
            s2map[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) matches += (s1map[i] == s2map[i] ? 1 : 0);

        int l = 0;
        for (int r = s1.length(); r < s2.length(); r++) {
            if (matches == 26) return true;

            int add = s2[r] - 'a';
            s2map[add]++;
            if (s1map[add] == s2map[add]) matches++;
            else if (s1map[add] == s2map[add] - 1) matches--;

            int rem = s2[l] - 'a';
            s2map[rem]--;
            if (s1map[rem] == s2map[rem]) matches++;
            else if (s1map[rem] == s2map[rem] + 1) matches--;

            l++;
        }

        return matches == 26;
    }
};
