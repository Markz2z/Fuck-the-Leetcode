/*
* Introduction: A bucket HashTable
* Author: puer
* Date: 3/17/2016
*/

typedef struct Entry{
	int key_;
	int value_;
    Entry* next_;
    Entry():key_(0), value_(0), next_(NULL) {}
    Entry(int key, int value): key_(key), value_(value), next_(NULL) {}
}Entry;

class HashTable {
public:
	HashTable(int capacity): capacity_(capacity), size_(0){
	    entry_ = new Entry[capacity_];
    }

    ~HashTable() {
        delete[] entry_;
    }

	int  capacity();
	int  size();
	int  get(int key);
	bool put(int key, int value);
    int  get_bucket(int key);

private:
    int capacity_;
	int size_;
	Entry* entry_;
};
