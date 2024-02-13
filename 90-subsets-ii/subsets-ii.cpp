class Solution {
public:
    void powerset(vector<vector<int>>& answer,vector<int> nums,int number,int &ptr){
        int numeric = nums[nums.size() - 1];
        if(nums.size() == 1){
            
            answer.push_back({numeric});
            
            if(number != numeric && number != -11){
                answer.push_back({number});
                answer.push_back({numeric,number});
                ptr = 1;
                return;
            }
            if(number == -11){
                return;
            }

            answer.push_back({numeric,number});
            ptr = 1;
            return;
        }
        nums.pop_back();
        powerset(answer,nums,numeric,ptr);
        if(number == -11){
            return;
        }
        int size = answer.size();
        vector<int> temp;
        if(number == numeric){
            for(int j = ptr;j < size;j++){
                temp = answer[j];
                temp.push_back(number);
                answer.push_back(temp);
            }
        }
        else{
            answer.push_back({number});
            for(int j = 0;j < size;j++){
                temp = answer[j];
                temp.push_back(number);
                answer.push_back(temp);
            }
        }
        ptr = size;
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> answer;
        sort(nums.begin(),nums.end());
        int ptr = 0;
        powerset(answer,nums,-11,ptr);
        answer.push_back({});
        return answer;
        
    }
};