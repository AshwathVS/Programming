/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;

        Node* res = NULL;

        map<int, Node*> m;
        map<int, bool> visited;

        queue<Node*> q;
        q.push(node);
        res = new Node(node->val);
        m.insert({node->val, res});

        while(!q.empty()) {
            Node* source = q.front();
            q.pop();
            Node* n = m.at(source->val);

            if(visited.find(source->val) != visited.end() && visited.at(source->val)) continue;

            visited[source->val] = true;

            for(Node* neighbor : source->neighbors) {
                if(visited.find(neighbor->val) == visited.end()) {
                    q.push(neighbor);
                }


                // if there is no node, create a node and add to map
                if(m.find(neighbor->val) == m.end()) {
                    m[neighbor->val] = new Node(neighbor->val);
                }

                n->neighbors.push_back(m.at(neighbor->val));
            }
        }

        return res;
    }
};