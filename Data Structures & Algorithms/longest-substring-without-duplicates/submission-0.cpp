class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> uniqueChar;
        int leftTrim = 0;
        int length = 0;


        for(int right = 0; right < n; right++){
            // remove duplicates in the substring present in the set by trimming from left
            while(uniqueChar.find(s[right]) != uniqueChar.end()){
                uniqueChar.erase(s[leftTrim]);
                leftTrim++;
            }
            // insert current (right) element to set
            uniqueChar.insert(s[right]);
            length = max(length, right - leftTrim + 1);
        }

        return length;
    }
};
