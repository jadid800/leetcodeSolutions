/*https://leetcode.com/problems/clone-graph/*/
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
        if(node==nullptr){return nullptr;}
        vector<Node*> nodes(101,nullptr);
        cloneGraphUtil(node,nodes);
        return nodes[node->val];
        
    }
    void cloneGraphUtil(Node* node,vector<Node*> &nodes){
        if(node==nullptr){return;}
        if(nodes[node->val]!=nullptr){return;}
        Node* newNode=new Node(node->val);
        nodes[node->val]=newNode;
        for(int i=0; i< node->neighbors.size(); i++){
            cloneGraphUtil(node->neighbors[i],nodes);
            newNode->neighbors.push_back(nodes[node->neighbors[i]->val]);
        }
        
    }
};
