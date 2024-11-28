class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> Pascal;
        for(int i=0; i < numRows; i++){
            vector<int> aux(i+1,1);
            for(int j=1; j<i; j++){
                aux[j]=Pascal[i-1][j-1]+Pascal[i-1][j];
            }
            Pascal.push_back(aux);
        }
        return Pascal;
    }
};
