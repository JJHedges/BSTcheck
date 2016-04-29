#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <functional>

//pair<int, int> shorthand is now P
typedef std::pair<int, int> P;

//Given start node and end node, find the shortest path between them with the
//provided adjacency matrix or -1 if it doesn't exist
int dijkstra(int start, int end, std::vector<std::vector<P> > adj)
{
	//Priority queue in ascending order of pairs of format <node number, distance from start>
	std::priority_queue<P, std::vector<P>, std::greater<P> > pq;
	std::set<int> seen;
	pq.push(std::make_pair(start, 0));
	while(!pq.empty())
	{
		P tmp = pq.top(); pq.pop();
		seen.insert(tmp.first);
		
		if(tmp.first == end) return tmp.second;
				
		for(auto pairs : adj[tmp.first])
		{
			if(seen.count(pairs.first) == 0)
			{
				pq.push(std::make_pair(pairs.first, tmp.second + pairs.second));
			}			
		}
	}
	return -1;
}

//Test for properly graph in diamond shape
void test1()
{
	std::vector<std::vector<P> > adjMat(4, std::vector<P>());
	adjMat[0].push_back(std::make_pair(1, 5));
	adjMat[0].push_back(std::make_pair(2, 1));	
	adjMat[1].push_back(std::make_pair(3, 5));
	adjMat[2].push_back(std::make_pair(3, 1));
	if(dijkstra(0, 3, adjMat) == 2)
	{
		std::cout << "Found path of correct length" << std::endl;
	}
}

//Test for a node thats not connected to start
void test2()
{
	std::vector<std::vector<P> > adjMat(5, std::vector<P>());
	adjMat[0].push_back(std::make_pair(1, 5));
	adjMat[0].push_back(std::make_pair(2, 1));	
	adjMat[1].push_back(std::make_pair(3, 5));
	adjMat[2].push_back(std::make_pair(3, 1));
	if(dijkstra(0, 4, adjMat) == -1)
	{
		std::cout << "Found no path correctly" << std::endl;
	}
}

//Test for more complex connected graph
void test3()
{
	std::vector<std::vector<P> > adjMat(5, std::vector<P>());
	adjMat[0].push_back(std::make_pair(1, 5));
	adjMat[0].push_back(std::make_pair(2, 1));	
	adjMat[1].push_back(std::make_pair(3, 5));
	adjMat[2].push_back(std::make_pair(4, 20));
	adjMat[2].push_back(std::make_pair(3, 1));
	adjMat[2].push_back(std::make_pair(4, 20));
	adjMat[3].push_back(std::make_pair(4, 1));
	if(dijkstra(0, 4, adjMat) == 3)
	{
		std::cout << "Found path of correct length" << std::endl;
	}
}

int main(int argc, char **argv)
{
	test1();
	test2();
	test3();
}
