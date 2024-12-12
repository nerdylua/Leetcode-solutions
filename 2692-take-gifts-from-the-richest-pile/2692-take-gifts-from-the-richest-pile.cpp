class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxheap(gifts.begin(), gifts.end());
        for(int i =0; i < k; ++i){
            int n = maxheap.top();
            maxheap.pop();
            maxheap.push(floor(sqrt(n)));
        }
        long long int total = 0;
        while (!maxheap.empty()) {
        total += maxheap.top();
        maxheap.pop();
        }
        return total;
    }
};