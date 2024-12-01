class Item {
public:
    int friendId;
    int chair = -1;
    int startTime;
    int endTime;

    Item(int friendId, int startTime, int endTime) {
        this->friendId = friendId;
        this->startTime = startTime;
        this->endTime = endTime;
    }

    void setChair(int chair) {
        this->chair = chair;
    }
};

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<Item> arrival;

        priority_queue<int, vector<int>, greater<int>> available; 
        priority_queue<Item, vector<Item>, function<bool(Item, Item)>> assigned([](Item a, Item b) {
            return a.endTime > b.endTime;
        });

        for (int i = 0; i < times.size(); i++) {
            arrival.emplace_back(i, times[i][0], times[i][1]);
            available.push(i);
        }

        sort(arrival.begin(), arrival.end(), [](Item a, Item b) {
            return a.startTime < b.startTime;
        });

        for (int i = 0; i < arrival.size(); i++) {
            Item& item = arrival[i];

            while (!assigned.empty() && assigned.top().endTime <= item.startTime) {
                available.push(assigned.top().chair);
                assigned.pop();
            }

            item.setChair(available.top());
            available.pop();
            assigned.push(item);

            if (item.friendId == targetFriend) {
                return item.chair;
            }
        }

        return -1;
    }
};
