class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.length()-1;
        
        while(start < end)
        {
            while(start < end && !isalnum(s[start]))
                start++;
            
            while(start < end && !isalnum(s[end]))
                end--;
            
            if(start < end && tolower(s[start++]) != tolower(s[end--]) )
                return false;
        }
        return true;            
    }
};