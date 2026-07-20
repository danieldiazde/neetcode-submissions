class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        else{
            unordered_map<char, int> freq1;
            unordered_map<char, int> freq2;
            for (int i = 0; i < s.size(); ++i) {
                freq1[s[i]]++;
            }
            for (int i = 0; i < t.size(); ++i) {
                freq2[t[i]]++;
            }
            if (freq1 == freq2) return true;
            return false;
        }
    }
};
