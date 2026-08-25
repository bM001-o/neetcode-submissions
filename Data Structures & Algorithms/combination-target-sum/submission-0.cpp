class Solution {
public:
    void findCombinationSum(int idx,int target,vector<int>& arr,vector<int>& ds,vector<vector<int>>& ans){
        if(idx == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(arr[idx] <= target){
            ds.push_back(arr[idx]);
            findCombinationSum(idx,target - arr[idx],arr,ds,ans);
            ds.pop_back();
        }
        findCombinationSum(idx + 1,target,arr,ds,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinationSum(0,target,nums,ds,ans);
        return ans;
    }
};
