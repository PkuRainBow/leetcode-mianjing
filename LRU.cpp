/**
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Subscribe to see which companies asked this question


分析：为了保持cache的性能，使查找，插入，删除都有较高的性能，我们使用双向链表（std::list）和哈希表（std::unordered_map）作为cache的数据结构，因为：

双向链表插入删除效率高（单向链表插入和删除时，还要查找节点的前节点）
哈希表保存每个节点的地址，可以基本保证在O(1)时间内查找节点

具体实现细节：

越靠近链表头部，表示节点上次访问距离现在时间最短，尾部的节点表示最近访问最少
查询或者访问节点时，如果节点存在，把该节点交换到链表头部，同时更新hash表中该节点的地址
插入节点时，如果cache的size达到了上限，则删除尾部节点，同时要在hash表中删除对应的项。新节点都插入链表头部。     

**/

class LRUCache{
	const int cap;
	//record the key and the corresponding position in the list 
	//we use the map to record the current order of (key, value) in the cache 
	unordered_map<int, list<pair<int, int>>::iterator> map;
	//record the key and value of the data
	list<pair<int, int>> lst;
 public:
    LRUCache(int capacity):cap(capacity) {}

    int get(int key) {
    	auto it = map.find(key);
    	if (it == map.end()) return -1;
    	//push the (key, value) to the top
    	lst.push_front(*it->second);
    	//erase the original occurrence
    	lst.erase(it->second);
    	it->second = lst.begin();
    	//return the fetched value 
    	return it->second->second;
    }

    void set(int key, int value) {
    	auto it = map.find(key);
    	//erase the original occurrence
    	if (it == map.end()) {
    		while (map.size() >= cap) {
    			//erase the tail elements in the lst and map
    			map.erase(lst.crbegin()->first);
    			lst.pop_back();
    		}
    	}
    	else {
    		lst.erase(it->second);
    	}
    	//add the new occurrence and update the map 
    	lst.push_front({key, value});
    	map[key] = lst.begin();
    }
};