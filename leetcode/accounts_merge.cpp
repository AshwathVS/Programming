class Solution {
public:
   vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, set<string>> graph;
        map<string, string> mailToName;

        //creating the graph
        for(vector<string> account: accounts) {
            string name = account[0];

            for(int i=1; i<account.size(); i++) {
                mailToName.insert({account[i], name});

                if(i+1 < account.size()) {
                    string mail1 = account[i];
                    string mail2 = account[i+1];

                    // creating an edge from mail1 to mail2
                    if(graph.find(mail1) != graph.end()) {
                        graph[mail1].insert(mail2);
                    } else {
                        graph[mail1] = {mail2};
                    }

                    // creating an edge from mail2 to mail1
                    if(graph.find(mail2) != graph.end()) {
                        graph[mail2].insert(mail1);
                    } else {
                        graph[mail2] = {mail1};
                    }

                } else {
                    graph.insert({account[i], {}});
                }
            }
        }


        set<string> visitedSet;
        stack<string> stck;
        vector<vector<string>> res;

        while(visitedSet.size() != graph.size()) {
            vector<string> xx;
            for(pair<string, string> entry: mailToName) {

                // start the dfs from this node
                if(visitedSet.find(entry.first) == visitedSet.end()) {
                    stck.push(entry.first);
                    xx.push_back(entry.second);
                    break;
                }
            }

            while(!stck.empty()) {
                string id = stck.top();
                stck.pop();
                xx.push_back(id);
                visitedSet.insert(id);

                for(string edge: graph.at(id)) {
                    if(visitedSet.find(edge) == visitedSet.end()) {
                        stck.push(edge);
                        visitedSet.insert(edge);
                    }
                }
            }


            sort(xx.begin() + 1, xx.end());
            res.push_back(xx);
        }

        return res;

    }
};