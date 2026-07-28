class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.length(); i++){
            // if string has open bracket, push to stack
            if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                st.push(s[i]);
            }
            else{   // if string has closing bracket
                if(st.size() == 0)  // stack empty, no open bracket for this closing bracket
                    return false;
                
                if( (s[i] == '}' && st.top() == '{') ||
                    (s[i] == ']' && st.top() == '[') ||
                    (s[i] == ')' && st.top() == '('))  // closing brackets in string has corresponding opening brackets in stack top
                    st.pop();
                else    
                    return false;   // wrong brack combination
            }
        }
        return (st.empty() == true); // edge case if # open brackets > # close brackets 
    }
};
