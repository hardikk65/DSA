class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0: # If input string is empty return 0
            return 0

        maxlen = -1  # Stores the maximum length of substring. Initialised with -1
        set_a = set()
        l = 0

        for r in range(len(s)):
            if s[r] in set_a:
                while l < r and s[r] in set_a:
                    set_a.remove(s[l])
                    l += 1
            set_a.add(s[r])
            maxlen = max(maxlen,r-l + 1)
            
        return maxlen
        