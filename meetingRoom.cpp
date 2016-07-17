class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(invervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) { return a.start < b.start; });
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < intervals[i-1].end)
                    return false;
        }
        return true;
    }
};

/**
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
 find the minimum number of conference rooms required.
For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
 https://leetcode.com/discuss/questions/oj/meeting-rooms-ii?sort=votes
**/


int minMeetingRooms(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), [](Interval &i, Interval &j){return i.start < j.start;});
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (auto it : intervals) {
        if (!min_heap.empty() && min_heap.top() <= it.start) min_heap.pop();
        min_heap.push(it.end);
    }
    return min_heap.size();
}

