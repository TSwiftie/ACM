#include <bits/stdc++.h>
using namespace std;
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {

    }
    
    void add(int key) {
        mlt.insert(key);
    }
    
    void remove(int key) {
        if(mlt.count(key)) mlt.erase(mlt.find(key));
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return mlt.count(key);
    }
private:
    set<int>mlt;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
