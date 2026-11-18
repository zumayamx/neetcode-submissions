/*
I think this problem must be approached from the edge cases.
Because that would help us to construct and algorithm considering
this things before something broke.

The first thing is, if you want to identify a cyle in the graph,
how do you do that in code?, you need to maintain some type of reference
to visited nodes, if some node of your current path is in this memory
already, you found a cicle, so return false.

Another edge case that comes to my mind, is what happens with separated graphs
for example 1->2, 3->4, are separated graphs, but they are courses possible to finish
whihtout problem, so this give me the idea we need to check the path for all nodes,
we need to check the path from node 1 and from node 3. This is really necessary
since is a directed graph, is not possible to reach all nodes from one unique node,
we need to check all of them.

Once, you check one node and all its neighbors (branches) do not contain a cycle,
you could clear its neighbor list, to not recompute from that node.

Other edge case is, what happens with courses without dependences, the unique way
to know that there exist is by numCourses, becuase if it had dependences, it would be
a pair in the prerequisites list, it that case its neighbors list would be [] and is
a perfect possible finish course, just to keep in mind.

With this in mind a think one approach could be a DFS algorithm with backtrack.
You go as deep as possible in the current branch to find for a cycle, if there is no
cicle return true and go to another branch (if the node has more than one neighbors)
once you end all the neighbors (branches) for a given node without having found a cycle,
that means from that node there is no cycles, so you don't recompute again.

If one of the branches in any given node contains a cycle, therefore all courses cannot
be completed, so you return false.

Pseudo-instructions:

- Create a map to save, node (int) (as key) -> neighbors (array) [as value]
(is a vector actually)
- Iterate over the map:

    Check if the current node is already in our visited  (is a set in reality),
    If that is true, there is a cycle so we return false.
    If that is not the case, add the current node to our current visited map.

    Then iterate over its current node
    neighbors list:
    for each neighbor call the same function.
        If some of the neighbors returns a cycle, then all the courses
        cannot be completed, so return false.

    If the iteration ends, that means we don't have cycles on
    its neighbors so we could clean the current node neighbor list
    is a way to say "from this node is guaranted there are not cycles
    so you dont need to go far".

    pop the current node from our current map (backtrack)
    clean the list and return true;

    And I think we can go with the implementation.

One thing worth to mention, is how the relation ship [a, b] is modeled in the graph
the problem says: prerequisites[i] = [a, b] indicates that you must take course b
first if you want to take course a. But us we are modeling, like an edge from a to b
its like, okay from course a what more I need to course this and that "more" are the paths,
the neighbors and the neighbors of the neighbors...
*/

class Solution {
   private:
    bool dfs(int node, vector<vector<int>>& nodes, unordered_set<int>& visited) {
        if (visited.find(node) != visited.end())
            return false;
        else
            visited.insert(node);

        vector<int> n = nodes[node];
        for (int i = 0; i < (int)n.size(); i++) {
            if (!dfs(n[i], nodes, visited)) return false;
        }

        nodes[node].clear();
        visited.erase(node);
        return true;
    }

   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> nodes(numCourses);
        for (int i = 0; i < (int)prerequisites.size(); i++) {
            int src = prerequisites[i][1];
            int dst = prerequisites[i][0];
            nodes[src].push_back(dst);
        }

        for (int i = 0; i < (int)nodes.size(); i++) {
            unordered_set<int> visited;
            if (!dfs(i, nodes, visited)) return false;
        }
        return true;
    }
};
