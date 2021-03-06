#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topSort(vector<int>& deg, vector<vector<int>>& graph, vector<int>& items) {
        queue<int> q;
        for (auto& item: items) if (!deg[item]) q.push(item);
        vector<int> res;
        while (!q.empty()) {
            int u = q.front();q.pop();
            res.emplace_back(u);
            for (auto& v: graph[u]) if (!--deg[v]) q.push(v);
        }
        return res.size() == items.size() ? res : vector<int>{};
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> groupItem(n + m);
        vector<vector<int>> groupGraph(n + m);
        vector<vector<int>> itemGraph(n);
        vector<int> groupDegree(n + m, 0);
        vector<int> itemDegree(n, 0);
        vector<int> id;
        for (int i = 0; i < n + m; ++i) id.emplace_back(i);
        int leftId = m;
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = leftId;
                ++leftId;
            }
            groupItem[group[i]].emplace_back(i);
        }
        for (int i = 0; i < n; ++i) {
            int curGroupId = group[i];
            for (auto& item: beforeItems[i]) {
                int beforeGroupId = group[item];
                if (beforeGroupId == curGroupId) {
                    itemDegree[i] += 1;
                    itemGraph[item].emplace_back(i);   
                } else {
                    groupDegree[curGroupId] += 1;
                    groupGraph[beforeGroupId].emplace_back(curGroupId);
                }
            }
        }
        vector<int> groupTopSort = topSort(groupDegree, groupGraph, id); 
        if (groupTopSort.size() == 0) return vector<int>{};
        vector<int> ans;
        for (auto& curGroupId: groupTopSort) {
            int size = groupItem[curGroupId].size();
            if (size == 0) continue;
            vector<int> res = topSort(itemDegree, itemGraph, groupItem[curGroupId]);
            if (res.size() == 0) return vector<int>{};
            for (auto& item: res) ans.emplace_back(item);
        }
        return ans;
    }
};
