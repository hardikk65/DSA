class Solution {
public:
    void getZarr(string str, vector<int>& Z)
{
	int n = str.length();
	int L, R, k;
	L = R = 0;
	for (int i = 1; i < n; ++i)
	{
		if (i > R)
		{
			L = R = i;
			while (R<n && str[R-L] == str[R])
				R++;
			Z[i] = R-L;
			R--;
		}
		else
		{
			k = i-L;
			if (Z[k] < R-i+1)
				Z[i] = Z[k];

			else
			{
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
        getZarr(patterns + "$" + numss,Z);
        int count = 0;

        for (int i = 0; i < numss.size() + patterns.size() + 1; ++i)
	{
		if (Z[i] == patterns.length())count++;
	}
        return count;
    }
};