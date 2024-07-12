class Solution {
public:
    int maximum(string temp, int x, int y, int a, int b){
        stack<char> st;
        int ans1  = 0;
        int ans2 = 0;
        int a_cnt = a;
        int b_cnt = b;
        for(int i = temp.size() - 1;i >= 0;i--){
            if(temp[i] == 'b'){
                st.push(temp[i]);
            }
            else if(!st.empty() && temp[i] == 'a' && st.top() == 'b'){
                st.pop();
                ans1 += x;
                a--;
                b--;
            }
        }
        ans1 += min(a,b)*y;

        while(!st.empty())st.pop();
        // Run loop for ba

        for(int i = temp.size() - 1;i >= 0;i--){
            if(temp[i] == 'a')st.push(temp[i]);
            else if(!st.empty()&&temp[i] == 'b' && st.top() == 'a'){
                st.pop();
                ans2 += y;
                a_cnt--;
                b_cnt--;
            }
        }
        ans2 += min(a_cnt,b_cnt)*x;

        return max(ans1,ans2);
    }
    int maximumGain(string s, int x, int y) {

        string temp = "";

        int start = 0;
        int a = 0;
        int b = 0;
        int answer = 0;
        while(start != s.size()){
            if(s[start] == 'a'){
                a++;
                temp += 'a';
            }
            else if(s[start] == 'b'){
                b++;
                temp += 'b';
            }
            else{
                cout<<temp<<a<<b<<endl;
                answer += maximum(temp,x,y,a,b);
                temp = "";
                a = 0;
                b = 0;
            }
            start++;
        }
        answer += maximum(temp,x,y,a,b);

        return answer;
    }
};