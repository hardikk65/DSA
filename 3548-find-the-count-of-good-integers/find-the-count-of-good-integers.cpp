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

    int count_zeros(string number){
        int zero_count = 0;
        for(auto i : number){
            if(i == '0')zero_count++;
        }
        return zero_count;
    }


    long long factorial(int n) 
    { 
        
        return (n==1 || n==0) ? 1: n * factorial(n - 1);  
    } 


    long long same_numbers(string number){
        map<char,int> freq;
        for(auto i: number)freq[i]++;

        long long combs = 1;

        for(auto i: freq){
            combs *= factorial(i.second);
        }

        return combs;
    }



    long long countGoodIntegers(int n, int k) {
        
        int digits = ceil((float)n/2.0);
        long long min = pow(10,digits - 1);
        long long max = pow(10,digits) - 1;
        
        vector<string> answers = generate(min,max,n);

        long long final_answer = 0;

        unordered_set<string> myset;

        for(auto i: answers){
            string temp = i;
            sort(temp.begin(),temp.end());
            if(stoll(i)%k == 0 && !(myset.find(temp) != myset.end())){
                cout<<i<<endl;
                final_answer += ((n - count_zeros(i))*(factorial(n - 1)))/same_numbers(i);
                cout<<((n - count_zeros(i))*(factorial(n - 1)))/same_numbers(i)<<endl;
                sort(i.begin(),i.end());
                myset.insert(i);
            }
        }

        return final_answer;
        
    }
};