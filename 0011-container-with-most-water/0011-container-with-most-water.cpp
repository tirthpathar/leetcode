class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp = 0;
        int rp = height.size()-1;
        int w;
        int max_Water = 0;

        while(lp < rp){
            w = rp - lp;
            int ht = min(height[lp],height[rp]);
            int area = w*ht;
            max_Water = max(max_Water,area);
            height[lp] < height[rp] ? lp++ : rp--;
        }

        return max_Water;



    }
    
};