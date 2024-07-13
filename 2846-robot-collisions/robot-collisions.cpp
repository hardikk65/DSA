class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        map<int,pair<int,char>> mp1;
        stack<pair<int,char>> st;
        for(int i = 0;i < positions.size();i++){
            mp1[positions[i]] = {healths[i],directions[i]};
        }

        for(auto i = mp1.rbegin();i != mp1.rend();i++){
            
            if(i->second.second == 'L')st.push({i->first,i->second.second});

            else if(!st.empty() && i->second.second == 'R'){
                while(!st.empty() && i->second.first > mp1[st.top().first].first){
                    i->second.first = i->second.first - 1;
                    mp1[st.top().first].first = 0;
                    st.pop();
                }
                if(!st.empty() && i->second.first == mp1[st.top().first].first){
                    i->second.first = 0;
                    mp1[st.top().first].first = 0;
                    st.pop();
                }
                else if(!st.empty() && i->second.first < mp1[st.top().first].first){
                    i->second.first = 0;
                    mp1[st.top().first].first--;
                }
            }
        }
        vector<int> answer;

        for(int i = 0;i < positions.size();i++){
            if(mp1[positions[i]].first != 0)answer.push_back(mp1[positions[i]].first);
        }



        return answer;


        
    }
};