class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int ptr = s.size() - 1;
        while(ptr >= 0){
            if(s[ptr] >= '0' && s[ptr] <= '9'){
                // cout<<s[ptr]<<endl;
                int num = 0;
                int multiplier = 1;
                while(ptr >= 0&&s[ptr] >= '0' && s[ptr] <= '9'){
                    num += (s[ptr] - '0') * multiplier;
                    multiplier *= 10;
                    cout<<s[ptr]<<endl;
                    ptr--;
                }
                ptr++;
                st.pop();
                string temp;
                while(!st.empty() && st.top() != ']'){
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                string temporary;
                while(num!= 0){
                    temporary += temp;
                    num--;
                }
                int new_size = temporary.size() - 1;
                while(new_size >= 0){
                    st.push(temporary[new_size]);
                    new_size--;
                }
            }
            else{st.push(s[ptr]);
            }
            ptr--;

        }

        string answer;
        while(!st.empty()){
            answer += st.top();
            st.pop();
        }
        return answer;



        
    }
};