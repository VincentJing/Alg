#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class LRUCache
{
    using DataType = list<pair<int, int>>;

public:
    LRUCache(int capacity)
    {
        mSize = capacity;
    }

    int get(int key)
    {
        auto it = mMap.find(key);
        if (it == mMap.end())
            return -1;
        else
        {
            // 当 key 存在时，更新位置到 head
            mData.splice(mData.begin(), mData, it->second);
            return mData.front().second;
        }
    }

    void put(int key, int value)
    {
        auto it = mMap.find(key);

        // key 存在时，删掉
        if (it != mMap.end())
        {
            mData.erase(it->second);
        }

        // 创建新节点到链表头部，并记录位置
        mData.push_front(make_pair(key, value));
        mMap[key] = mData.begin();

        // 如果超出容量，移除 map 中的位置，链表去掉最后一个节点
        if (mData.size() > mSize)
        {
            mMap.erase(mData.back().first);
            mData.pop_back();
        }
    }

private:
    int mSize;
    unordered_map<int, DataType::iterator> mMap;
    DataType mData;
};
