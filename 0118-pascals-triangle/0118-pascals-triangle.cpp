class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> pt;

        for(int i =0; i<numRows; ++i){
            vector<int> row;
            long long ans = 1;
                for(int j=0; j<=i; ++j){
                    row.push_back(ans);
                    ans = ans*(i-j)/(j+1);
                }
                pt.push_back(row);
        }
        return pt;
    }
};