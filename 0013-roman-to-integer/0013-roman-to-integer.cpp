class Solution {
public:
    int romanToInt(string s) {
        map <char,int> mpp = {
            {'I', 1},
            {'V', 5},
            {'X', 10}, 
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int result = 0;
        for(int i = 0;  i< s.size()-1; i++){
            if(mpp[s[i]] < mpp[s[i+1]]){ // IV
                result-= mpp[s[i]];
            } else {
                result+= mpp[s[i]];
            }
        }
        return result +=mpp[s[s.size()-1]];
    }
};