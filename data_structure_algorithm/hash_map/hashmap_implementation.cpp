#include <iostream>
#include <cmath>
using namespace std;

template <typename V>
class Map;

// Use OPEN HASHING (CLOSED ADDRESSING) method to resolve collision 
template <typename V>
class MapNode {
    private:
        string key;
        V value;
        MapNode* next;
    public:
        MapNode(string key, V value) {
            this->key = key;
            this->value = value;
            next = NULL;
        }
        ~MapNode() {
            delete next;
        }
    friend class Map<V>;
};

template <typename V>
class Map {
    private:
        MapNode<V>** buckets; // bucket array
        int count; // num of [key, value]
        int numBuckets; // size of bucket array
        int getBucketIndex(string key);
        void rehash();
    public:
        Map() {
            count = 0;
            numBuckets = 5;
            buckets = new MapNode<V>*[numBuckets];
            for(int i = 0; i < numBuckets; i++) {
                buckets[i] = NULL;
            }       
        }
        ~Map() {
            for(int i = 0; i < numBuckets; i++) {
                delete buckets[i]; 
            }
            delete[] buckets;
        }
        int size() {
            return count;
        }
        V getValue(string key) {
            int bucketIndex = getBucketIndex(key);
            MapNode<V>* head = buckets[bucketIndex];
            while(head != NULL) {
                if(head->key == key) {
                    return head->value;
                }
                head = head->next;
            }
            return 0; // key isn't present
        }
        void insert(string key, V value) {
            int bucketIndex = getBucketIndex(key);
            MapNode<V>* head = buckets[bucketIndex];
            while(head != NULL) {
                if(head->key == key) {
                    head->value = value;
                    return;
                }
                else {
                    head = head->next;
                }
            }
            MapNode<V>* node = new MapNode<V>(key, value);
            node->next = buckets[bucketIndex];;
            buckets[bucketIndex] = node;
            count++;
            double loadFactor = (double)count/numBuckets;
            if(loadFactor >= 0.7) {
                rehash();
            }
        }
        V remove(string key) {
            int bucketIndex = getBucketIndex(key);
            MapNode<V>* currentNode = buckets[bucketIndex];
            MapNode<V>* previousNode = NULL;
            while(currentNode != NULL) {
                if(currentNode->key == key) {
                    V value = currentNode->value;
                    if(previousNode == NULL) { // in case of removing head node
                        buckets[bucketIndex] = currentNode->next;
                    }
                    else {
                        previousNode->next = currentNode->next;
                    }
                    currentNode->next = NULL;
                    delete currentNode;
                    count--;
                    return value;
                }
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
            return 0;
        }
        double getLoadFactor() {
            return (double)count/numBuckets;
        }
};
template <typename V>
int Map<V>::getBucketIndex(string key) {
    int hashCode = 0;
    int base = 1;
    int p = 37;
    for(int i = key.length() - 1; i >= 0; i--) {
        hashCode += key[i] * base; // "abc" = 'a' * p^2 + 'b' * p^1 + 'c' * p^0
        base = base * p;
        // Apply the comression function inside hash function to avoid ...
        // ... out-of-range error while multiplying base if length of string is very big
        hashCode = hashCode % numBuckets;
        base = base % numBuckets;
    }
    return hashCode % numBuckets;
}
template <typename V>
void Map<V>::rehash() {
    MapNode<V>** temp = buckets;
    int oldBucketSize = numBuckets;
    numBuckets = numBuckets*2;
    count = 0;
    buckets = new MapNode<V>*[numBuckets];
    for(int i = 0;  i < numBuckets; i++) {
        buckets[i] = NULL;
    }
    for(int i = 0; i < oldBucketSize; i++) {
        MapNode<V>* head = temp[i];
        while(head != NULL) {
            insert(head->key, head->value);
            head = head->next;
        }
        delete temp[i];
    }
    delete[] temp;
}
int main() {
    Map<int> myMap;
    for(int i = 0; i < 10; i++) {
        char ch = '0' + i;
        string key = "abc";
        key = key + ch;
        // cout << key << endl;
        int value = (i + 1) * 10;
        myMap.insert(key, value);
        cout << myMap.getLoadFactor() << endl;
    }
    cout << "size = " << myMap.size() << endl;
    myMap.remove("abc4");
    cout << "size = " << myMap.size() << endl;
    return 0;
}