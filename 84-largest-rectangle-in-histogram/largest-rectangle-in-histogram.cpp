
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 1)return heights[0];

        heights.insert(heights.begin(),-1);
        heights.push_back(-1);
        int n = heights.size();
        
        vector<int> result1(n, -1);
        vector<int> result2(n, -1);
        stack<int> s;
        stack<int> s1;

    
        for (int i = n - 1; i >= 0; --i) {
        
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            
            if (!s.empty()) {
                result1[i] = s.top();
            }
            s.push(i);
        }
        
        for (int i = 0; i < n; i++) {
        
            while (!s1.empty() && heights[s1.top()] >= heights[i]) {
                s1.pop();
            }
            
            if (!s1.empty()) {
                result2[i] = s1.top();
            }
            s1.push(i);
        }

        


        int ans = INT_MIN;

        // if(result1[n - 2] == -1)result1[n-2] = n;
        // if(result2[1] == -1)result2[1] = -1;

        for(auto c: result1)cout<<c<<" ";
        cout<<endl;
        for(auto c: result2)cout<<c<<" ";
        
        for(int i = 1;i < n - 1;i++){
            if(result1[i] == -1 && result2[i] == -1)ans = max(ans,heights[i]*n);
            else if(result1[i] == -1 && result2[i] != -1)ans = max(ans,heights[i]*(abs(i - result2[i])));
            else if(result1[i] != -1 && result2[i] == -1 )ans = max(ans,heights[i]*(abs(i - result1[i])));
            else{

                int sum = heights[i]*abs(result1[i] - i) + heights[i]*abs(result2[i] - i) - heights[i];
                ans = max(ans,sum);
            }
        }

        return ans;
        
    }
};