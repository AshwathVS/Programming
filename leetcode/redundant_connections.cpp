class Solution {
public:

    int root(vector<int> v, int a) {
        while(v[a] != a) {
            a=v[a];
        }
        return a;
    }


    bool find(vector<int> v, int a, int b) {
        return root(v, a) == root(v, b);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> v(edges.size()+1);
        for(int i=0; i<v.size(); i++) {
            v[i] = i;
        }

        for(vector<int> i : edges) {
            if(find(v, i[0], i[1])) return i;
            else {
                int root_a = root(v, i[0]);
                int root_b = root(v, i[1]);
                v[root_a] = root_b;
            }
        }

        return {};
    }

};