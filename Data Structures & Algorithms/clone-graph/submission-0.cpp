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

/*
Okay, one approach could be a recursive DFS algorithm.

For each node, we create a copy of it and we iterate through
its neighbors list then for each neighbor we call the same
function to create copies of each neighbor. We need a data structure
to save what nodes are already copied, because we don´t want to create
duplicate copies, that structure cold be a unordered_map, in which
the key is the original node and the value is the copy of that node.

The function must return a pointer reference, because that references
need to be added to the neighbors list.

Node* dfs(Node* node, map<NodeOriginalAsKey, NodeCopyAsValue>& c)
{
    Node* copy = new Node(node->val);
    c[node] = copy;

    int ns = (int)node->neighbors.size();
    for (int i = 0; i < ns; i++)
    {
        if (c[node->neighbors[i]] == c.end())
        {
            Node* n = dfs(node->neighbors[i], c);
            copy->neighbors.push_back(n);
        }
        else
        {
            copy->neighbors.push_back(c[node]);
        }
    }
    return copy;
}

Node* cloneGraph(Node* node)
{
    unordered_map<Node*, Node*> copied;
    Node* copyRoot = dfs(node, copied);
    return copyRoot;
}

*/

class Solution {
public:
    Node* dfs(Node* originalNode, unordered_map<Node*, Node*>& copied)
    {
        Node* copyNode = new Node(originalNode->val);
        copied[originalNode] = copyNode;

        for (int i = 0; i < (int)originalNode->neighbors.size(); i++)
        {
            if (copied.find(originalNode->neighbors[i]) == copied.end())
            {
                Node* copiedNode = dfs(originalNode->neighbors[i], copied);
                copyNode->neighbors.push_back(copiedNode);
            }
            else
            {
                copyNode->neighbors.push_back(copied[originalNode->neighbors[i]]);
            }
        }
        return copyNode;
    }
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> copied;
        Node* copyRoot = dfs(node, copied);
        return copyRoot;
    }
};
