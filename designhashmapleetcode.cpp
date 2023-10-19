class MyHashMap {
public:
    vector<int> arr;
    MyHashMap() {
        arr.resize(1000001);
        for(int i=0;i<arr.size();i++) arr[i]=0;
    }
    
    void put(int key, int value) {
        if(value==0) arr[key]=-1;
        else arr[key]=value;
    }
    
    int get(int key) {
        if(arr[key]==0) return -1;
        else if(arr[key]==-1) return 0;
        return arr[key]; 
    }
    
    void remove(int key) {
        arr[key]=0;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */