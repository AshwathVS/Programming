class Solution {
public:

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> v(N+1);
        for(int i=0; i<=N; i++) {
            v[i] = {};
        }

        for(vector<int> i : dislikes) {
            v[i[0]].push_back(i[1]);
        }

        vector<int> colors(N + 1, -1);

        while(true) {
            // this is done to ensure all disconnected components are also taken into account
            int i;
            for(i=1; i<=N; i++) {
                if(colors[i] == -1) break;
            }

            if(i == N+1) break;
            else {
                int source = i;
                bool initcolor = true;
                for(int i: v[source]) {
                    if(colors[i] != -1)  {
                        initcolor = !colors[i];
                        break;
                    }
                }

                colors[source]=initcolor;

                queue<int> q;
                q.push(source);

                while(!q.empty()) {
                    int node = q.front();
                    q.pop();

                    bool color = !colors[node];
                    for(int i : v[node]) {
                        if(colors[i] == -1) {
                            colors[i] = color;
                            q.push(i);
                        }
                        else if(colors[i] != color) return false;
                    }
                }
            }
        }
        return true;
    }
};