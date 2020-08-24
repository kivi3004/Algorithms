/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 
 *Example
     LRUCache cache = new LRUCache( 2 /* capacity */ );

  /*cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // returns 1
    cache.put(3, 3);    // evicts key 2
    cache.get(2);       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cache.get(1);       // returns -1 (not found)
    cache.get(3);       // returns 3
    cache.get(4);       // returns 4
 */


class LRUCache {
    int cap;
    unordered_map<int,int> mp;
    unordered_map<int,list<int> :: iterator> m2;
    list<int> l;
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        l.erase(m2[key]);
        l.push_front(key);
        m2[key]=l.begin();
        return mp[key];
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
            if(mp.size()>=cap){
                int x = l.back();
                l.pop_back();
                mp.erase(x);
            }
        }
        else
            l.erase(m2[key]);
        l.push_front(key);
        mp[key]=value;
        m2[key]=l.begin();
    }
};
