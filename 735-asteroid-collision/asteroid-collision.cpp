class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> answer;
        vector<int> temp;

        for(int i = 0;i < asteroids.size();i++){

            if(asteroids[i] > 0)st.push(asteroids[i]);

            else if(asteroids[i] < 0){
                while(!st.empty() && (abs(asteroids[i]) > st.top())){
                    st.pop();
                }
                if(!st.empty() && abs(asteroids[i]) == st.top()){
                st.pop();
                continue;
                }
            }
            

            



            if((asteroids[i] < 0) && st.empty())answer.push_back(asteroids[i]);
        }

        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        for(int j = temp.size() - 1;j >= 0;j--){
            answer.push_back(temp[j]);
        }
        return answer;
    }
};