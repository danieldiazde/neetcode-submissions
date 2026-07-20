class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> sublists;

        for (auto s : strs) {
            bool added = false;
            if (sublists.empty()) sublists.push_back({s});
            else {

                vector<int> freq_string(26, 0);
                for (char c : s) freq_string[c - 'a']++;

                for (int i = 0; i < sublists.size(); ++i) {

                    if (sublists[i][0].size() != s.size()) continue;

                    vector<int> freq(26, 0);
                    for (char c: sublists[i][0]) freq[c - 'a']++;

                    if (freq == freq_string) {
                        sublists[i].push_back(s);
                        added = !added;
                        break;
                        }
                }
                if (!added) sublists.push_back({s});
            }
        }

        return sublists;
    }
};
