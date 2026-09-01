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
        vector<int>startTime;
        vector<int>endTime;

        for(int i = 0;i < intervals.size();i++){
            startTime.push_back(intervals[i].start);
            endTime.push_back(intervals[i].end);
        }
        sort(startTime.begin(),startTime.end());
        sort(endTime.begin(),endTime.end());

        int start = 0;
        int end = 0;
        int maxCount = 0;
        int count = 0;

        while(start < intervals.size()){
            if(startTime[start] < endTime[end]){
                count++;
                start++;
            }else{
                count--;
                end++;
            }
            maxCount = max(maxCount,count);
        }
        return maxCount;
    }
};
