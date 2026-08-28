class Solution {
public:
    int countSubstrings(string s) {
        int count =  0;

        for(int i = 0;i < s.length();i++){
            for(int j = 0;j <= 1;j++){
                int left = i;
                int right = i + j;

                while(left >= 0  && right < s.length() && s[left] == s[right]){
                    count++;
                    left--;
                    right++;
                }
            }
        }

        return count;
    }
};
