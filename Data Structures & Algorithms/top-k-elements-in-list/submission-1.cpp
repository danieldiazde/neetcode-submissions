class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int i : nums) freq[i]++;

        priority_queue<pair<int, int>, 
            vector<pair<int, int>>,
            greater<pair<int,int>>> min_heap;

        for (const auto& [num, frequency] : freq) {
            min_heap.push({frequency, num});

            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        vector<int> answer;

        while (!min_heap.empty()) {
            answer.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return answer;
    }
};
