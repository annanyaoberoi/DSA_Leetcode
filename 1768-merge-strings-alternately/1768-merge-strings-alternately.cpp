class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s;
        int i=0;
        int j=0;
        int n=word1.size();
        int m=word2.size();
        while(i<n || j<m){
            if(i<n) s+=word1[i++];
            if(j<m) s+=word2[j++];
        }
        return s;
    }
};