class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>countT;
        
        for(char c : t){
            countT[c]++;
        }
        int left = 0; int right = 0;
        int minL = INT_MAX; int minLeft = 0;
        int formed = 0; int required = countT.size();

        unordered_map<char,int>window;

        while(right < s.length()){
            char c = s[right];
            window[c]++;

            if(countT.count(c) && window[c] == countT[c]){
                formed++;
            }
            while(left <= right && formed == required){
                if(right - left + 1 < minL){
                    minL = right - left + 1;
                    minLeft = left;
                }
                char leftChar = s[left];
                window[leftChar]--;

                if(countT.count(leftChar) && window[leftChar] < countT[leftChar]){
                    formed--;
                }
                left++;
            }
            right++;
        }
        return minL == INT_MAX ? "" : s.substr(minLeft,minL); 
    }
};
