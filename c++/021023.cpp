class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0, bob = 0;

        if (colors.length() < 3)
            return false;
        
        for (int i = 1; i < colors.length() - 1; i++){
            char curr = colors[i];
            char prev = colors[i - 1];
            char next = colors[i + 1];
            
            if (curr == prev && curr == next){
                if (curr == 'A')
                    alice += 1;
                else bob += 1;
            }
        }

        if (alice > bob) return true;

        return false;
    }
};