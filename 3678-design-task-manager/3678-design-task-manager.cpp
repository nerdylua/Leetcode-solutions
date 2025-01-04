class TaskManager {
private:
    unordered_map<int, pair<int, int>> mp; 
    set<pair<int, int>, greater<>> pq; 

public:
    TaskManager(const vector<vector<int>>& tasks) {
        for (const auto& task : tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            mp[taskId] = {priority, userId};
            pq.emplace(priority, taskId);
        }
    }

    void add(int userId, int taskId, int priority) {
        mp[taskId] = {priority, userId};
        pq.emplace(priority, taskId);
    }

    void edit(int taskId, int newPriority) {
        if (mp.find(taskId) != mp.end()) {
            int oldPriority = mp[taskId].first;
            pq.erase({oldPriority, taskId}); 
            mp[taskId].first = newPriority;
            pq.emplace(newPriority, taskId); 
        }
    }

    void rmv(int taskId) {
        if (mp.find(taskId) != mp.end()) {
            int priority = mp[taskId].first;
            pq.erase({priority, taskId});
            mp.erase(taskId);
        }
    }

    int execTop() {
        if (pq.empty()) {
            return -1; 
        }
        auto topTask = *pq.begin();
        int taskId = topTask.second, userId = mp[taskId].second;
        pq.erase(pq.begin()); 
        mp.erase(taskId); 
        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */