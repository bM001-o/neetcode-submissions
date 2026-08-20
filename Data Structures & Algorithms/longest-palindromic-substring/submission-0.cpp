class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLength = 1;
        int start = 0;

        for(int i = 0;i < n;i++){
            for(int j = 0;j <= 1;j++){
                int low = i;
                int right = i + j;

                while(low >= 0 && right < n && s[low] == s[right]){
                    int currlength = right - low + 1;
                    if(currlength > maxLength){
                        start = low;
                        maxLength = currlength;
                    }
                    low--;
                    right++;
                }
            }
        }
        return s.substr(start,maxLength);
    }
};
