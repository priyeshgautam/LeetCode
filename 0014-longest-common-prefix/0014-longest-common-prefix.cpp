class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        // sort all strings
        sort(v.begin(),v.end());

        //compare first and last words
        string ans = "";
        string first = v[0];
        string last = v[v.size() - 1];
        for(int i = 0; i< min(first.size(), last.size()); i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans +=first[i];
        }
        return ans;
    }
};