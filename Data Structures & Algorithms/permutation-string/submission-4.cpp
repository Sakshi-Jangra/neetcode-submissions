class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int permlen = s1.length();
        if(s2.length() < permlen)
            return false;
        sort(s1.begin(), s1.end());

        for (int i = 0; i <= s2.length() - permlen; i++) {
            string subStr = s2.substr(i, permlen);
            sort(subStr.begin(), subStr.end());

            if (subStr == s1) {
                return true;
            }
        }
        return false;
    }
};
