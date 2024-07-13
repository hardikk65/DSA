class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0: # If input string is empty return 0
            return 0

        maxlen = 0  # Stores the maximum length of substring
        set_a = set()  # Stores the characters of substring

        # left stores starting index, right stores end index of substring
        left = 0  

        for right in range(len(s)):  # Traversing the input string
            
            if s[right] in set_a:   # If current character present in set
                
                while left < right and s[right] in set_a:  # Remove until duplicate
                    
                    set_a.remove(s[left])
                    left += 1
                    
            set_a.add(s[right])  # Add current character to set
            maxlen = max(maxlen,right-left + 1) # Store max lenght in maxlen
            
        return maxlen
        