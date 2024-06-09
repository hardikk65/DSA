class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int i = 0;i < s.size();i++){
            st.push(s[i]);
            if(st.top() == ')'){
                st.pop();
                if(st.empty())return false;
                else if(st.top() == '('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(st.top() == ']'){
                st.pop();
                if(st.empty())return false;
                else if(st.top() == '['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(st.top() == '}'){
                st.pop();
                if(st.empty())return false;
                else if(st.top() == '{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(!st.empty())return false;
        return true;
    }
};