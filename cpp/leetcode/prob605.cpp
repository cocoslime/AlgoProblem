//
// Created by Dongmin on 2022/01/18.
//

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int idx = 0;
        if (n == 0) return true;
        if (flowerbed.size() == 1) return !flowerbed[idx];

        while (idx < flowerbed.size()) {
            if (canPlaceFlower(idx, flowerbed)) {
                if (--n == 0) return true;
                flowerbed[idx] = 1;
                idx += 2;
            } else {
                idx++;
            }
        }

        return false;
    }

    bool canPlaceFlower(int idx, vector<int> &flowerbed) {
        if (idx == 0) {
            if (flowerbed[idx] || flowerbed[idx + 1]) {
                return false;
            }
        } else if (idx == flowerbed.size() - 1) {
            if (flowerbed[idx - 1] || flowerbed[idx]) {
                return false;
            }

        } else {

            if (flowerbed[idx - 1] || flowerbed[idx] || flowerbed[idx + 1]) {
                return false;
            }
        }
        return true;
    }
};