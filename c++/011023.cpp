#include <string>
using namespace std;

// beats 5% :(
  
class Solution {
public:
    string reverseWords(string s) {

        // 0. base case
        if (s.length() == 0)
            return s;

        // 1. get the next word (starting with the first)
        string word = "";
        int index = 0; 
        while (s[index] != ' ' && s[index] != '\0')
            word += s[index++];
        
        // 2. reverse that word
        string reversedWord = "";
        for (int i = word.length() - 1; i >= 0; i--)
            reversedWord += word[i];
        
        // 3. go to 1.
        string remainingStr = s.substr(index);

        if (remainingStr[0] == ' '){
            reversedWord += " ";
            remainingStr = s.substr(index + 1);
        }
        
        return reversedWord + reverseWords(remainingStr);
    }
};