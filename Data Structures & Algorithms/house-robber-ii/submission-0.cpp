class Solution {
public:
    int maxSum(int start,vector<int>& nums,int end){
        int prevMax = 0;
        int currMax = 0;

        for(int i = start;i <= end;i++){
            int tempMax = max(prevMax,currMax);
            currMax = nums[i] + prevMax;
            prevMax = tempMax;
        }
        return max(prevMax,currMax);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        return max(maxSum(0,nums,n - 2),maxSum(1,nums,n - 1));
    }
};
