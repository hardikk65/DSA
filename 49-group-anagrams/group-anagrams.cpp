class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> a = strs;
        map<string,int> visited;
        vector<vector<string>> answer;
        for(int i = 0;i < strs.size();i++){
            sort(strs[i].begin(),strs[i].end());
        }

        for(int i = 0;i < strs.size();i++){
            if(visited[strs[i]] == 0){
                vector<string> temporary;
                temporary.push_back(a[i]);
                for(int j = i + 1;j < strs.size();j++){
                    if(strs[i] == strs[j])temporary.push_back(a[j]);
                }
                answer.push_back(temporary);
                visited[strs[i]]++;
            }
        }
        for(auto i : strs)cout<<i<<" ";
        cout<<endl;
        return answer;
    }
};