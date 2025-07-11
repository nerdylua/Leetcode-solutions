class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> ongoing;

        set<int> available;
        for (int i = 0; i < n; ++i) available.insert(i);

        vector<int> room_counts(n, 0);

        for (auto& meeting : meetings) {
            long long start = meeting[0], end = meeting[1];
            long long duration = end - start;

            while (!ongoing.empty() && ongoing.top().first <= start) {
                available.insert(ongoing.top().second);
                ongoing.pop();
            }

            if (!available.empty()) {
                int room = *available.begin();
                available.erase(available.begin());

                room_counts[room]++;
                ongoing.push({end, room});
            } else {
                auto [end_time, room] = ongoing.top();
                ongoing.pop();

                room_counts[room]++;
                ongoing.push({end_time + duration, room});
            }
        }

        int max_count = 0, answer = 0;
        for (int i = 0; i < n; ++i) {
            if (room_counts[i] > max_count) {
                max_count = room_counts[i];
                answer = i;
            }
        }
        return answer;
    }
};
