#include <map>
#include <iostream>
#include <queue>

using namespace std;

typedef struct Node {
	struct Node* child1;
	int val;
}Node;

void addchild(queue<Node*>& queue, Node* head) {

}

void BFS(Node* head) {
	std::queue<Node*> to_crawl;
	std::map<Node*, int> crawled;
	if(head) {
		to_crawl.push(head);
		while(to_crawl.size()!=0) {
			Node* cur = to_crawl.front();
			to_crawl.pop();
			if(crawled.count(cur)!=1) {
				printf("%d\n", cur->val);
				crawled.insert(map<Node*, int>::value_type(cur, 1));
				addchild(to_crawl, head);
			}
		}
	}
}

int main () {
	return 1;
}