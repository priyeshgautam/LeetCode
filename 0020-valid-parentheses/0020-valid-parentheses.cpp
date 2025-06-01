class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        unordered_map <char,char> mpp = {
            {'}','{'},
            {']','['},
            {')','('}
        };
        for(auto a:s){
            if( a=='(' || a=='{' || a=='[') {
                st.push(a);
            }
            else if( a==')' || a=='}' || a==']' ) {
                if (st.empty() || st.top() != mpp[a]) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};