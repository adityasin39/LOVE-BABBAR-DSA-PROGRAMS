// Very first thing comes in undirected graph for finding shortest path is bfs. Since, bfs ensures that a node at distance k will be visited first then a node at k+1 distance. But problem given here, is slightly different. Here in the problem it is given that we can visit any node any number of time, even we can use edge more than once.

// This means that we can't use simple bfs (in which we maintain a visited set - to avoid cycle) because in the problem we can visit a node any number of time.
// Take an example to understand why simple bfs will not work?

// 0 -- 1
// | \
// 2  3
// If we start bfs from 0,
// {0} -> {0,1} -> stuck as we have visited 0 already.
// If we start bfs from 1,
// {1}->{1,0}->{1,0,3}-> Stuck as we already visited 0
// You got the idea.

// So, the point which I am trying to make here is this,

// If we apply simple bfs starting from any node(say 0) where we also keep track of visited array (Consecutively meaning we can't visit them again) it will never lead us to the solution.
// On the other hand if we apply bfs from any node (say 0) and don't keep the track of visited array, it will lead to cycle [ {0}->{0,1}->{0,1,0}->{0,1,0,1} and so on]
// What if there is a way, in which we can visit the same node again and still avoid cycle. lets call this type of bfs as intelligent bfs.
// that means,

// If starting node is 0
// {0}->{0,1}->{0,1,0}-{0,1,0,3}->{0,1,0,3,0,2}
// If starting node is 1,
// {1}->{1,0}->{1,0,2}->{1,0,3}->{1,0,3,0}->{1,0,3,0,2}

// That means we still need to iterate this intelligent bfs from each node and see from which node we are getting minimum answer.

// Now, lets assume that we have devised this intelligent bfs.

// Simultaneously BFS
// What if we apply bfs on every node in one go. In other words, start bfs on each node simulatneously? That is, Queue for bfs will now be

// [ {0},{1},{2},{3} ] -> [ {0,1} ,{0,2},{0,3}, {1,0}, {2,0}, {3,0}  ] -> [...]
// where each step(which is [...] ) in bfs will contains set of nodes or path visited in bfs fashion for each of the element in previous step.

// The advantage (If we have that intelligent bfs) we will reach the answer fastly rather then applying bfs individually as in individual bfs we need to extend bfs unecessary for current starting node, while we would have reached to the answer earlier if we would have started using some other starting node.

// Intelligent BFS

// Intelligent bfs should be such which will able to detect if including current node will result into cycle or not.
// Take an example,

// Take individual bfs starting from 0
// {0}->{0,1}->{0,1,0}->Now we should not got to {0,1,0,1}.

// If you see we already visited set of nodes {0,1} while we are at 0. (bold above). So we must not include 1 again as resulting visited list will become {0,1} again.

// Take another example,
// Starting from 1,

// {1}->{1,0}->{1,0,1} = (We should visited this as by visiting 1 again (currently current node is 1) this could lead to some other path which would have connected to 1 only)

// {1}->{1,0}->{1,0,1} -> {1,0,1,0} = (This shouldn't be visited) as by including 0 again, this is just repetition of 0 and 1 again in other words, by including 0 again resulting visited set will become {0,1} which we already visited(bold above)

// In nutshell, for each current head(or leading) node we must maintain a space where we can check whether we visited that set of path again or not).

// We can use (dist) 2d matrix, dist[mask][lead] where mask is rows and lead are columns.
// lead/colums will denote all nodes and mask/rows will denote all possible combination of set of nodes which is visited.

// Mask - Example: 
// 0 0 0 1  => 0th node is visited
// 3 2 1 0 

// 0 1 1 0 => 1 & 2 nodes are visited
// 3 2 1 0
// For bit masking,
// [https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/tutorial/]

// Take 2D Matrix dist[][] where, dist[i][j] represent if jth node is the leading node(end of the path so far), then what is the path distance (min distance) we have covered if all set bits in i nodes are visited.

// So We will implements simulatneously bfs starting from each node, and keep track of distance using dist 2d matrix.
// Due to simulatneously bfs over all node, whenever we encouter that i where all bits are set, that will be the answer, as it is bfs in undirected graph which ensures that a node at distance k will be visited first then a node at k+1 distance.
//  1. Call BFS from every node {node,{dist,mask}}
//     2. Mask is the how many nodes we are visited.
//     3. When we visited all the nodes then we will return distance(dist)
//     4. How mask will keep track that how many node is visited ?
//     Ans :-   i) Let's n = 5 (number of nodes)
//              ii) allVisitedMask = 11111; When all node will be visted then musk will be allVisitedMask
//                  1 = 1 = (2^1)-1
//                  11 = 3 = (2^2)-1
//                  111 = 7 = (2^3)-1
//                  So, for n nodes allVisitedMask = 1111...111 (n-times) = (2^n)-1 = (1<<n)-1;
//              iii) Initially,
//                 mask of 0-th node is 00001 = 2^0 = 1<<0 
//                 mask of 1-th node is 00010 = 2^1 = 1<<1
//                 mask of 2-nd node is 00100 = 2^2 = 1<<2
//                 mask of 3-rd node is 01000 = 2^3 = 1<<3
//                 mask of 4-th node is 10000 = 2^4 = 1<<4
//                 Then, mask of i-th node is 1<<i or 2^i
//              iv) Suppose we can visit 0-th node to 1-th and 2-nd node than after visiting the mask wiil be
//                  00011 and 00101 respectively.
                 
//                  How this can be maintain ?
//                  Ans :- mask of 0-th | mask of 1-th = 00001 | 00010 = 00011
//                         mask of 0-th | mask of 2-th = 00001 | 00100 = 00101
//                         So, if we visit j-th node from i-th node then mask will be updated to =
//                         mask till i-th node | mask of j-th node
//              v) When cuurent mask of current node will be allVisitedMask then we will stop and will
//                 sure thar all nodes are visited then we will check the comp. curr dist with ans.
//              vi) We will keep track of already visited path using currNode and currMask
             
//              2 --- 1 ---- 0
//              |\    |
//              | \   |
//              |  \  |
//              |   \ |
//              3    4
             
//              Start visiting the nodes from every node -::
             
//              0 : (0) -> (0,1) -> (1,0){don't visit (1,0) again reson is bellow}
//              1 : (1) -> (1,0),(1,4),(1,)
//              2 : (2) -> (2,1),(2,4),(2,3)
//              3 : (3) -> (3,2)
//              4 : (4) -> (4,1),(4,2)
             
//              0 : (0) -> (0,1) -> (1,0){don't visit (1,0) again reson is bellow}
//              Ans : You are visiting (1,0) in setps=2 but (1,0) path is already visited by staring node (1) in
//                    steps = 1 . So, revisiting (1,0) will increas the steps but we want minimum steps that's
//                    why we will not visit the same path that are already visited with smaller steps.
                   
//              --> We will keep tarck the visited path using set<pair<currNode,currMask>>
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        queue<pair<int,pair<int,int>>> q;
        set<pair<int,int>> seen;
        int n=graph.size();
        int allvisitedmask=(1<<n)-1;
        for(int i=0;i<n;i++)
        {
            q.push({0,{i,(1<<i)}});
            seen.insert({i,(1<<i)});
        }
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int distance=it.first;
            int curnode=it.second.first;
            int mask=it.second.second;
            if(mask==allvisitedmask) return distance;
            for(auto it: graph[curnode])
            {
                int nextmask=mask|(1<<it);
                if(!seen.count({it,nextmask}))
                {
                    q.push({distance+1,{it,nextmask}});
                    seen.insert({it,nextmask});
                }
            }
        }
        return 0;
    }
};