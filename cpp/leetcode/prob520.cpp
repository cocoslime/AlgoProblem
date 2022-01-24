//
// Created by Dongmin on 2022/01/24.
//

class Solution {
public:
    char checkCapital(char c){
        return c >= 'A' && c <= 'Z';
    }

    bool detectCapitalUse(string word) {
        int capitalNum = 0;
        for (int i = 0; i < word.length() ; i++){
            bool isCapital = checkCapital(word[i]);
            if (isCapital)
                capitalNum += 1;
        }

        if (capitalNum == 0 || capitalNum == word.length())
            return true;
        if (capitalNum == 1){
            if (checkCapital(word[0]))
                return true;
            else
                return false;
        }
        return false;
    }
};