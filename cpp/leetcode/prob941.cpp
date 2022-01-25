//
// Created by Dongmin on 2022/01/25.
//

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() <= 2) return false;
        bool isUp = true;
        for (int i = 0 ; i < arr.size() - 1 ; i++){
            if (arr[i] == arr[i+1]){
                return false;
            }

            if (i != 0 && isUp){
                if (arr[i] > arr[i+1]){
                    isUp = false;
                }
            }
            else if (!isUp) {
                if (arr[i] < arr[i+1])
                    return false;
            }
            else {
                if (arr[i] > arr[i+1])
                    return false;
            }
        }

        if (isUp)
            return false;
        else
            return true;
    }
};