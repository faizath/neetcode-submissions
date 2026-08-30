#include <string>
#include <unordered_map>

class Solution {
public:
    unordered_map<char, int> mapper(string text) {
        unordered_map<char, int> result;
        for (char &c: text) {
            if (result.find(c) != result.end()) {
                result[c] = result[c] + 1;
            } else {
                result[c] = 1;
            }
        }
        return result;
    }

    bool isAnagram(string s, string t) {
        return mapper(s) == mapper(t);
    }
};
