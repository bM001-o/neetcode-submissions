class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }

        vector<pair<int,int>> arr;
        for(const auto&[key,value] : mp){
            arr.push_back({value,key});
        }
        sort(arr.rbegin(),arr.rend());
        vector<int> res;
        for(int i = 0;i < k;i++){
            res.push_back(arr[i].second);
        }
        return res;
    }
};
