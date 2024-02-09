class Solution {
public:
    void calcsum(vector<int>& candidates,vector<vector<int>>& answer,vector<int> ans,int number, int target,int n, int curr){
        
        ans.push_back(number); 
        curr = curr + number;       
        if(curr==target)
        {
            answer.push_back(ans);
            return;
        }

        if(curr>target)
        {
            return;
        }

        for(int i=n; i<candidates.size();i++)
        {
            calcsum(candidates,answer,ans,candidates[i],target,i,curr);
        }



    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> answer;
        vector<int> ans;


        for(int i =0 ; i < candidates.size();i++){
            calcsum(candidates,answer,ans,candidates[i],target,i,0);
        }

        return answer;


        
    }
};