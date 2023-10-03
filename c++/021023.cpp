class Solution {
public:
    bool winnerOfGame(string colors) {
        bool isAlice = true;
        int nextStartingPoint = 0;
        bool isNextStartingPointSet = false;

        if (colors.length() < 3)
            return false;
        
        for (int i = 1; i < colors.length() - 1; i++){
            char curr = colors[i];
            char prev = colors[i - 1];
            char next = colors[i + 1];
            
            if (curr == prev && curr == next){
                if (isAlice){
                    if(curr != 'A' && !isNextStartingPointSet){
                        nextStartingPoint = i;
                        isNextStartingPointSet = true; 
                    } else if(curr == 'A'){
                        if (!isNextStartingPointSet)
                            nextStartingPoint = i;
                        colors.erase(i, 1);
                        i = nextStartingPoint - 1;
                        isAlice = !isAlice;
                        isNextStartingPointSet = false;
                    }
                } else {
                    if(curr != 'B' && !isNextStartingPointSet){
                        nextStartingPoint = i;
                        isNextStartingPointSet = true; 
                    } else if(curr == 'B'){
                        if (!isNextStartingPointSet)
                            nextStartingPoint = i;
                        colors.erase(i, 1);
                        i = nextStartingPoint - 1;
                        isAlice = !isAlice;
                        isNextStartingPointSet = false;
                    }   
                }
            }
            
            if (i == colors.length() - 2 && colors.length() > 2)
                isAlice = !isAlice;
        }

        if (colors.length() < 3)
            isAlice = !isAlice;

        return isAlice;
    }
};