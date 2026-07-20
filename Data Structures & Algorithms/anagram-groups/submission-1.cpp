class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> answer;

        unordered_map<string, vector<string>> groups;

        for (const string& s : strs) {
            vector<int> frequency(26, 0);
            
            for (char c : s) {
                frequency[c - 'a']++;
            }

            string key;

            for (int i : frequency) {
                key += "#";
                key += to_string(i);
            }

            groups[key].push_back(s);
        }

        for (auto& [key, group] : groups) answer.push_back(move(group));
       
        return answer;
    }
};
