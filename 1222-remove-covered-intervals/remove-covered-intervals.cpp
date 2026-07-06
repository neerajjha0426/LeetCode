class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        //sorting on basis of 0th and 1st index
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1]; 
            return a[0] < b[0];
        });

        int count = 0;
        int maxEnd = 0;
        //simple hai agar kisi ka end alreday ho jo chika hai like 1 bje tk meeting schedule hai to kisi aur ko kuch nhi hoga tb tk 
        for (auto& it : intervals) {
            if (it[1] > maxEnd) {
                count++;               // not covered
                maxEnd = it[1];
            }
        }

        return count;
    }
};