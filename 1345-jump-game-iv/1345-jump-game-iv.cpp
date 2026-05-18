#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        if(n == 1) return 0;

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<int> vis(n, 0);

        q.push(0);
        vis[0] = 1;

        int step = 0;

        while(!q.empty()) {

            int sz = q.size();

            while(sz--) {

                int i = q.front();
                q.pop();

                if(i == n - 1) return step;

                // i - 1
                if(i - 1 >= 0 && !vis[i - 1]) {
                    vis[i - 1] = 1;
                    q.push(i - 1);
                }

                // i + 1
                if(i + 1 < n && !vis[i + 1]) {
                    vis[i + 1] = 1;
                    q.push(i + 1);
                }

                // same value jump
                for(int j : mp[arr[i]]) {

                    if(!vis[j]) {
                        vis[j] = 1;
                        q.push(j);
                    }
                }

                // important optimization
                mp[arr[i]].clear();
            }

            step++;
        }

        return -1;
    }
};