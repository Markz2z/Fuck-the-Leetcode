/*
* Introduction: A bucket HashTable
* Author: puer
* Date: 3/17/2016
*/

typedef struct Entry{
	int key;
	int value;
}Entry;

class HashTable {
public:
	HashTable(int capacity): capacity_(capacity), size(0){
	}

	int  get_capacity();
	int  get_size();
	int  get(int key);
	bool put(int key, int value);

private:
	int bit_[10000];
	int capacity_;
	int size_;
	Entry entry_[capacity_];
}