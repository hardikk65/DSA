class Solution {
public:
    int find(int n,vector<int>& mapping){
        vector<int> number;
        if(n == 0)return mapping[n];

        while (n != 0){
            int x = n%10;
            number.push_back(mapping[x]);
            n = n/10;
        }
        reverse(number.begin(),number.end());
        int answer = 0;
        for(int i = 0;i < number.size();i++){
            answer = answer*10 + number[i];
        }
        return answer;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> k;
        vector<int> a;
        unordered_map<int,queue<int>> mp;
        for(int i=0;i<nums.size();i++){
            int l=find(nums[i],mapping);
            mp[l].push(nums[i]);
            k.push_back(l);
        }
        sort(k.begin(),k.end());
        // return k;
        for(int i=0;i<k.size();i++){
            a.push_back(mp[k[i]].front());
            mp[k[i]].pop();
        }
        return a;
    }
};