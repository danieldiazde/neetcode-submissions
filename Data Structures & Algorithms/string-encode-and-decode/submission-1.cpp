class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (string s : strs) {
            encoded.append(to_string(s.size()));
            encoded.push_back('#');
            encoded.append(s);
        }
        return encoded;
    }

    vector<string> decode(string encoded) {
        int i = 0; 
        vector<string> response;

        while (i < encoded.size()) {
            int pos = encoded.find('#', i);
            int size = stoi(encoded.substr(i, pos - i));
            response.push_back(encoded.substr(pos + 1, size));
            i = pos + size + 1; 
        }

        return response;

    }
};
