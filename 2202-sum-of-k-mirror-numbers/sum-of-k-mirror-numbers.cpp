class Solution {
public:
    vector<string> generate(long long min,long long max,int digits){
        vector<string> answer;
        for(long long i = min;i <= max;i++){
            string temp;
            if(!(digits%2)){
                temp = to_string(i);
                reverse(temp.begin(),temp.end());
                string result = to_string(i) + temp;
                answer.push_back(result);
            }

            else{
                temp = to_string(i).substr(0,to_string(i).size() - 1);
                reverse(temp.begin(),temp.end());
                string result = to_string(i) + temp;
                answer.push_back(result);
            }
        }
        return answer;
    }
    bool check_base(string a,int k){
        string b;
        long long num = stoll(a);

        while(num != 0){
            b += num%k;
            num /= k;
        }

        int i = 0;
        int j = b.size() - 1;

        while(i < j){
            if(b[i] == b[j]){
                i++;
                j--;
            }
            else return 0;
        }

        return 1;


    }
    long long kMirror(int k, int b) {
        
        int n = 1;
        long long sum = 0;
        while(b != 0){
            int digits = ceil((float)n/2.0);
            long long min = pow(10,digits - 1);
            long long max = pow(10,digits) - 1;
            vector<string> answers = generate(min,max,n);

            for(int i = 0;i < answers.size();i++){
                if(b == 0)return sum;
                else if(check_base(answers[i],k)){
                    sum += stoll(answers[i]);
                    b--;
                }
            }
            n++;
        }
        return sum;
        
    }
};