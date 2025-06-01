class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string rA = a;
        int count = 1;
        //if not repeatition needed
        if(rA.find(b) != std::string::npos) return count;

        //if repeated but size less
        while(rA.size() < b.size()){
            rA += a;
            count++;
            if(rA.find(b) != std::string::npos) return count;
        }
        //once again add to check if is fully contained
        rA+=a;
        count++;
        if(rA.find(b)!=std::string::npos) return count;
        return -1;
        
    }
};