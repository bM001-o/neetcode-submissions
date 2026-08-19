class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minProd = nums[0];
        int maxProd = nums[0];
        int result = nums[0];

        for(int i = 1;i < nums.size();i++){
            int curr = nums[i];
            if(curr < 0){
                swap(minProd,maxProd);
            }
           
            maxProd = max(curr,curr*maxProd);
            minProd = min(curr,curr*minProd);

            result = max(result,maxProd);
        }
        return result;
    }
};
