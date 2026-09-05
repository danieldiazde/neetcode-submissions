/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), [](const auto a, const auto b) {
            return a.start < b.start;
        });

        auto cmt = [](const auto a, const auto b) {
            return a.end > b.end;
        };

        //Keep them in a min-heap, like the other one we used two heaps
        //You had one for cooling down and another one for available
        //Max for ƒrequent available, min for cooling down

        //In here you have one min for end time
        //One max for start time
        priority_queue<Interval, vector<Interval>, decltype(cmt)> minHeap(cmt);

        minHeap.push(intervals[0]);
        int size = 1;
        for (int index = 1; index < intervals.size(); ++index) {
            while (!minHeap.empty() && intervals[index].start >= minHeap.top().end) minHeap.pop();
            minHeap.push(intervals[index]);
            size = max(size, (int)minHeap.size());
        }


        return size;



    

    }
};
