class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int planted = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (i != 0 && flowerbed[i - 1] == 1) continue;
            if (i != flowerbed.size() - 1 && flowerbed[i + 1]) continue;
            if (flowerbed[i] == 0) {
                planted++;
                flowerbed[i] = 1;
            }
        }
        return planted >= n;
    }
};
