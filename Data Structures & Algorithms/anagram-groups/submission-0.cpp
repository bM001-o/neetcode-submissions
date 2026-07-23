class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> res;
        for(int i = 0;i < strs.size();i++){
            string word(26,'0');
            for(char c : strs[i]){
                word[c - 'a']++;
            }
            mp[word].push_back(strs[i]);
        }

        for(const auto& [key,group] : mp){
            res.push_back(group);
        }
        return res;
    }
};
