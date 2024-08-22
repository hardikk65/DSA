struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        return a.second < b.second;
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        for(auto i: nums)freq[i]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,myComp> pq;
        for(auto i: freq)pq.push({i.first,i.second});
        vector<int> answer;

        // while(!pq.empty()){
        //     cout<<pq.top().first<<" "<<pq.top().second<<endl;
        //     pq.pop();
        // }

        for(int i = 0;i < k;i++){
            answer.push_back(pq.top().first);
            pq.pop();
        }

        // return {1,2};
        return answer;
        
    }
};