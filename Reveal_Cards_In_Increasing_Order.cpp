class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        vector<int> result(deck.size());
        queue<int> q;
        int n=deck.size(),temp=0;
        q.push(deck[n-1]);
        for(int i=n-2;i>=0;i--){
            temp=q.front();
            q.pop();
            q.push(temp);
            q.push(deck[i]);
        }
        for(int i=n-1;i>=0;i--){
            temp=q.front();
            result[i]=temp;
            q.pop();
        }
        return result;
    }
};
