class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<pair<long long, pair<int,int>>, 
        vector<pair<long long, pair<int,int>>>, 
        greater<pair<long long, pair<int,int>>>> pq;
        int n=workerTimes.size();
        for(int i = 0; i <n; i++){
            long long tm = workerTimes[i];
            pq.push({tm, {i, 1}});
        }

        long long res = 0;

        while(mountainHeight > 0){
            auto cur = pq.top();
            pq.pop();

            long long tm = cur.first;
            int id = cur.second.first;
            int x = cur.second.second;

            res = tm;
            mountainHeight--;

            if(mountainHeight > 0){
                long long nx = x + 1;
                long long nt = (long long)workerTimes[id] * (nx * (nx + 1) / 2);
                pq.push({nt, {id, (int)nx}});
            }
        }

        return res;
    }
};