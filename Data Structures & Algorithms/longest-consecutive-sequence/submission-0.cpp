class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int maxCount = 0;

        for(auto x : s){
            if(s.find(x - 1) == s.end()){
                int curr = x;
                int count = 1;

                while(s.find(curr + 1) != s.end()){
                    curr++;
                    count++;
                }
                maxCount = max(maxCount,count);
            }
        }
        return maxCount;
    }
};
