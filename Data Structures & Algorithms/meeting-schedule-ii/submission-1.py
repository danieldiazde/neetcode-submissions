"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        import heapq as hq

        if not intervals:
            return 0

        intervals.sort(key=lambda x: x.start)

        meetings = []

        hq.heappush(meetings, intervals[0].end)

        for i in range(1, len(intervals)):
            if intervals[i].start >= meetings[0]:
                hq.heappop(meetings)
                hq.heappush(meetings,intervals[i].end)
            else:
                hq.heappush(meetings, intervals[i].end)
        
        return len(meetings)




