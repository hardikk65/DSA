class Solution {
public:
    bool check(string s,string b){
        vector<pair<char,int>> A;
        vector<pair<char,int>> B;

        int count = 0;
        for(int i = 0;i < s.size();i++){
            count++;
            if(s[i + 1] != s[i]){
                A.push_back({count,s[i]});
                count = 0;
            }
        }

        count = 0;
        for(int i = 0;i < b.size();i++){
            count++;
            if(b[i + 1] != b[i]){
                B.push_back({count,b[i]});
                count = 0;
            }
        }

        if(A.size() != B.size())return 0;

        for(int i = 0;i < A.size();i++){
            if(A[i].second != B[i].second)return 0;
            else if(A[i].first != B[i].first){
                if(A[i].first > B[i].first && A[i].first < 3)return 0;
                else if(A[i].first < B[i].first)return 0;
            }
        }

        return 1;

        
    }
    int expressiveWords(string s, vector<string>& words) {
        int answer = 0;
        for(int i = 0;i < words.size();i++){
            if(check(s,words[i]))answer++;
        }
        return answer;
        
    }
};