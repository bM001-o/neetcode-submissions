class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(int i = 0;i < strs.size();i++){
            res.append(to_string(strs[i].size()));
            res.push_back('#');
            res.append(strs[i]);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.length()){
            int j = i;
            while(s[j] != '#'){
                j += 1;
            }

            int length = stoi(s.substr(i,j - i));
            i = j + 1;
            j = i + length;
            res.push_back(s.substr(i,length));
            i = j; 
        }
        return res;
    }
};
