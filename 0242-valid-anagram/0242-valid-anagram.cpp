class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <int,int> mp;
        for(int it: s) mp[it]++;
        for(int ch: t) mp[ch]--;
        for(auto i: mp){
            if(i.second != 0) return false;
        }return true;
    }
};