class Solution {
public:
    string topSort(map<char, set<char>> &graph, set<char>& visited, bool &loopFound, char initChar) {
        stack<char> ss;
        set<char> recurseStack;
        ss.push(initChar);
        string res = "";

        while(!ss.empty()) {
            char top = ss.top();
            if(visited.find(top) == visited.end()) {
                visited.insert(top);
                recurseStack.insert(top);
                for(char ch : graph[top]) {
                    if(recurseStack.find(ch) != recurseStack.end()) {
                        loopFound=true;
                        return "";
                    } else if(visited.find(ch) == visited.end()) {
                        ss.push(ch);
                    }
                }
            } else {
                ss.pop();
                recurseStack.erase(top);
                res = top + res;
            }
        }

        return res;
    }

    string initTopSort(map<char, set<char>> &graph, set<char>& visited, bool& loopFound) {
        if(graph.size() == 0) return "";
        else {
            string res = "";
            for(auto it : graph) {
                if(loopFound) return "";
                else if(visited.find(it.first) == visited.end()) {
                    res = topSort(graph, visited, loopFound, it.first) + res;
                }
            }

            return res;
        }
    }

    string alienOrder(vector<string>& words) {
        int size = words.size();
        if(size == 0) return "";
        else if(size == 1) return words[0];
        else {
            map<char, set<char>> graph;
            set<char> allCharacters;
            string s1, s2;
            for(int i=1; i<size; i++) {
                s1 = words[i-1];
                s2 = words[i];

                // have a set to find all characters
                for(int i=0; i<s1.size(); i++) allCharacters.insert(s1[i]);
                for(int i=0; i<s2.size(); i++) allCharacters.insert(s2[i]);

                int iter = 0;
                bool endReached = false;
                bool orderFound = false;
                while(!endReached) {
                    if(iter >= s1.size() || iter >= s2.size()) {
                        endReached = true;
                        // check if s2 is a substring of s1
                        if(iter >= s2.size() && s1.size() != s2.size()) return "";
                    } else {
                        if(s1[iter] != s2[iter]) {
                            orderFound = true;
                            break;
                        }
                        iter++;
                    }
                }

                if(orderFound) {
                    char before = s1[iter];
                    char after = s2[iter];

                    if(graph.find(before) != graph.end()) {
                        graph[before].insert(after);
                    } else {
                        graph.insert({before, {after}});
                    }
                }
            }


            // operate on the graph and get top sort
            set<char> visited;
            bool loopFound = false;
            string res = initTopSort(graph, visited, loopFound);
            // find all the missing elements in the graph and append to the front
            if(loopFound) return "";
            else {
                for(char ch : allCharacters) {
                    if(visited.find(ch) == visited.end()) {
                        res = ch + res;
                    }
                }
            }

            return res;
        }
    }
};