class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        // Find the minimum rank for the upper bound calculation.
        int r_min = *min_element(ranks.begin(), ranks.end());
        // Lower bound of time: at least 1 minute.
        long long low = 1;
        // Upper bound: worst-case time for the fastest mechanic repairing all cars.
        long long high = (long long)r_min * cars * cars;
        long long ans = high;
        
        // Binary search on time.
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long totalCars = 0;
            
            // Calculate total cars that can be repaired in 'mid' minutes.
            for (int r : ranks) {
                // For a mechanic with rank 'r', max cars they can repair is floor(sqrt(mid / r)).
                totalCars += (long long)floor(sqrt((long double)mid / r));
                if (totalCars >= cars)  // Early stopping if we already meet the target.
                    break;
            }
            
            // Check if mid time is sufficient.
            if (totalCars >= cars) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
