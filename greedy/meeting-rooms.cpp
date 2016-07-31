class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){return a.start < b.start;});
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < intervals[i - 1].end) {
                return false;
            }
        }
        return true;
    }
};

//solution 1 method 
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
    	//m store the interval in sorted order
        map<int, int> m;
        for (auto a : intervals) {
            ++m[a.start];
            --m[a.end];
        }
        int rooms = 0, res = 0;
        for (auto it : m) {
        	rooms += it.second;
            res = max(res, rooms);
        }
        return res;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){return a.start < b.start;});
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto a : intervals) {
        	if (!q.empty() && q.top() <= a.start) q.pop();
        	q.push(a.end);
        }
        return q.size();
    }
};