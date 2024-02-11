class Solution {
public:
    void getZarr(string str, vector<int>& Z)
{
	int n = str.length();
	int L, R, k;

	// [L,R] make a window which matches with prefix of s
	L = R = 0;
	for (int i = 1; i < n; ++i)
	{
		// if i>R nothing matches so we will calculate.
		// Z[i] using naive way.
		if (i > R)
		{
			L = R = i;

			// R-L = 0 in starting, so it will start
			// checking from 0'th index. For example,
			// for "ababab" and i = 1, the value of R
			// remains 0 and Z[i] becomes 0. For string
			// "aaaaaa" and i = 1, Z[i] and R become 5
			while (R<n && str[R-L] == str[R])
				R++;
			Z[i] = R-L;
			R--;
		}
		else
		{
			// k = i-L so k corresponds to number which
			// matches in [L,R] interval.
			k = i-L;

			// if Z[k] is less than remaining interval
			// then Z[i] will be equal to Z[k].
			// For example, str = "ababab", i = 3, R = 5
			// and L = 2
			if (Z[k] < R-i+1)
				Z[i] = Z[k];

			// For example str = "aaaaaa" and i = 2, R is 5,
			// L is 0
			else
			{
				// else start from R and check manually
				L = i;
				while (R<n && str[R-L] == str[R])
					R++;
				Z[i] = R-L;
				R--;
			}
		}
	};
}
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int final_answer = 0;
        for(int i = 0;i < nums.size() - 1;i++){
            if(nums[i + 1] > nums[i]){
                nums[i]=1;
            }
            if(nums[i + 1] == nums[i]){
                nums[i] = 0;
            }
            if(nums[i + 1] < nums[i]){
                nums[i] = -1;
            }
        }
        nums.pop_back();
        string patterns = "";
        string numss = "";
        
        for(auto p: pattern){
            if(p == 1){
                patterns += 'a';
            }
            if(p == 0){
                patterns += 'b';
            }
            if(p == -1){
                patterns += 'c';
            }
        }
        for(auto p: nums){
            if(p == 1){
                numss += 'a';
            }
            if(p == 0){
                numss += 'b';
            }
            if(p == -1){
                numss += 'c';
            }
        }
        vector<int> Z(numss.size() + patterns.size() + 1);
        // int Z[numss.size() + patterns.size() + 1];
        getZarr(patterns + "$" + numss,Z);
        int count = 0;
        cout<<numss<<" "<<patterns<<endl;
        for(auto c: Z){
            cout<<c<<" ";
        }

        for (int i = 0; i < numss.size() + patterns.size() + 1; ++i)
	{
		// if Z[i] (matched region) is equal to pattern
		// length we got the pattern
		if (Z[i] == patterns.length())count++;
	}
        return count;
    }
};