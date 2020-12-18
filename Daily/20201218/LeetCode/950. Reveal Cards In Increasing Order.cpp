class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++)
            ans[i] = -1;
        bool isrev = true;
        int in = 0;
        int i = 0;
        while(in != (n)){
            if (ans[i] == -1){
                if (isrev){
                    ans[i] = in;in++;
                    isrev = false;
                }
                else{
                    isrev = true;
                }
            }
            i++;
            i = i%n;
        }
        sort(deck.begin(), deck.end());
        for (i = 0; i < n; i++){
            ans[i] = deck[ans[i]];
        }
        return ans;
    }
};