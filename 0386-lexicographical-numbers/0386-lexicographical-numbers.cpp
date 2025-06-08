// Using Sort
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        vector<string> c;

        for(int i=1;i<=n;i++){
            string tmp = to_string(i);
            c.push_back(tmp);
        }
        sort(c.begin(),c.end());

        for(auto val:c){
            ans.push_back(stoi(val));
        }

        return ans;
    }
};