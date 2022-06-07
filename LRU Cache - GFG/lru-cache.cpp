// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    
    unordered_map<int,int> m;
    unordered_map<int, list<int> :: iterator> pata;
    list<int> l;
    int currsize;
    int size;
    
    
    LRUCache(int cap)
    {
        currsize = cap;
        size = 0;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if(m.find(key) == m.end())
        return -1;
        
        list<int> ::iterator add = pata[key];
        l.erase(add);
        l.push_front(key);
        pata[key] = l.begin();
        
        return m[key];
    }
    
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if(m.find(key) != m.end()){
            m[key] = value;
            list<int>::iterator add = pata[key];
            l.erase(add);
            l.push_front(key);
            pata[key] = l.begin();
        }
        else{
            m[key]=value;
            l.push_front(key);
            pata[key]=l.begin();
            size++;
        
            if(size>currsize){
                int k=l.back();
                l.pop_back();
                m.erase(k);
                pata.erase(k);
        }
    }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends