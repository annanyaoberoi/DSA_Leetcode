class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long buyIndividually = (long long)need1 * cost1 + (long long)need2 * cost2;
        
        long long buyAllBoth = (long long)std::max(need1, need2) * costBoth;
        int sharedMin = std::min(need1, need2);
        long long buyPartialBoth = (long long)sharedMin * costBoth 
                                 + (long long)(need1 - sharedMin) * cost1 
                                 + (long long)(need2 - sharedMin) * cost2;
        
        return std::min({buyIndividually, buyAllBoth, buyPartialBoth});
    }
};