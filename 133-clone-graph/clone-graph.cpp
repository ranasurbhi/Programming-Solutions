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
    void fill(Node* node, map<Node*,Node*>& mp){
        if(!node) return;
        mp[node]=new Node(node->val);
        for(auto it:node->neighbors){
            if(mp.count(it)==0){
                fill(it,mp);
            }
        }
        return;
    }
    void build(Node* node,map<Node*,Node*>&mp,set<Node*> &s){
        if(!node) return;
        s.insert(node);
        for(auto it:node->neighbors){
            if(s.count(it)==0){
                build(it,mp,s);
            }
            mp[node]->neighbors.push_back(mp[it]);
        }
        return;
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        map<Node*, Node*> mp;
        fill(node,mp);
        set<Node*> s;
        build(node,mp,s);
        return mp[node];
    }
};