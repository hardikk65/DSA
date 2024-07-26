class Solution {
public:
    int bsearch(int targ, vector<int>& houses) {
        int low = 0;
        int high = houses.size() - 1;
        int mid;
        while (high >= low) {
            mid = (high + low) / 2;
            if (houses[mid] == targ) {
                return mid;
            } else if (houses[mid] > targ) {
                high = mid - 1;
            } else if (houses[mid] < targ) {
                low = mid + 1;
            }
        }
        return mid;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        vector<int> s(houses.size());
        for (int j = 0; j < houses.size(); j++) {
            s[j] = abs(houses[j] - heaters[0]);
        }

        for (int i = 1; i < heaters.size(); i++) {
        int heater = heaters[i];
        int index = bsearch(heater, houses);
        int left = 0, right = index;
        while (left < right) {
            int mid = (right + left) / 2;
            if (abs(houses[mid] - heater) < s[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int leftBoundary = left;
        left = index, right = houses.size() - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2; 
            if (abs(houses[mid] - heater) < s[mid]) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        int rightBoundary = right;
        for (int j = leftBoundary; j <= rightBoundary; j++) {
            s[j] = min(s[j], abs(houses[j] - heater));
        }
    }

        int maxi = INT_MIN;
        for (int i = 0; i < s.size(); i++) {
            maxi = max(maxi, s[i]);
        }
        return maxi;
    }
};