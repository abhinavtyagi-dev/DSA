class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        // ans should be max 2 min 1;
        if (source[0]==target[0]&&source[1]==target[1]){
            return 0;
        }
        if ((abs(source[0]-target[0]))==(abs(source[1]-target[1]))||((source[0]==target[0])||(source[1]==target[1]))){
            return 1;
        }
        return 2;
    }
};