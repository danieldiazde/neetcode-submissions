class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (string word : strs){
            encoded += to_string(word.size());
            encoded += "#";
            encoded += word;
        }
        return encoded;
    }

    vector<string> decode(string s) {
    vector<string> result;
    int i = 0;

    while (i < s.size()) {
        int j = i;

        while (s[j] != '#') {
            ++j;
        }

        int length = stoi(s.substr(i, j - i));

        int wordStart = j + 1;
        result.push_back(s.substr(wordStart, length));

        i = wordStart + length;
    }

    return result;
}
};
