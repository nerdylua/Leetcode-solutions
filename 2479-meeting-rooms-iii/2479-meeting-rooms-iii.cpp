class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end());
    priority_queue<int, vector<int>, greater<int>> freeRooms;
    for (int i = 0; i < n; ++i) freeRooms.push(i);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busyRooms;
    vector<int> count(n, 0);
    for (auto& m : meetings) {
        int start = m[0], end = m[1];
        while (!busyRooms.empty() && busyRooms.top().first <= start) {
            freeRooms.push(busyRooms.top().second);
            busyRooms.pop();
        }
        if (!freeRooms.empty()) {
            int room = freeRooms.top(); freeRooms.pop();
            busyRooms.push({end, room});
            count[room]++;
        } else {
            auto [availTime, room] = busyRooms.top(); busyRooms.pop();
            long long newEnd = availTime + (end - start);
            busyRooms.push({newEnd, room});
            count[room]++;
        }
    }
    int ans = 0;
    for (int i = 1; i < n; ++i)
        if (count[i] > count[ans]) ans = i;
    return ans;
}
};
