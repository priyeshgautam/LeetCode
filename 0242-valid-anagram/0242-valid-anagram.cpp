using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mpp;
        for(int i=0; i<s.length(); i++){
            mpp[s[i]]++;
        }
        for(int i=0; i<t.length(); i++){
            if(mpp[t[i]]>0){
                mpp[t[i]]--;
            } else {
                return false;
            }
            
        }
        for (auto x: mpp){
            if(x.second>0) return false;
        }
        return true;
    }
};