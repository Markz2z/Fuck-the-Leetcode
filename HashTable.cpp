#include "pthread.h"
#include "HashTable.h"
/*
* Introduction: A bucket HashTable
* Author: puer
* Date: 3/17/2016
*/
int HashTable::capacity() {
    return capacity_;
}

int HashTable::size() {
    return size_;
}

int HashTable::get_bucket(int key) {
    return key % capacity();
}

int HashTable::get(int key) {
	int bucket = get_bucket(key);
	if(bucket!=-1) {
        int value;
        Entry* entry = &entry_[bucket];
        while(entry && entry_[bucket].key_ != key) {
            entry = entry->next_;
        }
	    return entry == NULL ? -1 : entry->value_;
	}
	return -1;
}

bool HashTable::put(int key, int value) {
	pthread_mutex_t lock;
    pthread_mutex_init(&lock, NULL);
    pthread_mutex_lock(&lock);
    int bucket = get_bucket(key);
    Entry* entry = &entry_[bucket];
    if(!entry->key_ && !entry->value_ && !entry->next_) {
	    entry->key_ = key;
        entry->value_ = value;
	    ++size_; 
	} else {
        while(entry->next_) {
            entry = entry->next_;
        }
        entry->next_ = new Entry(key ,value);
        ++size_;
    }
    pthread_mutex_unlock(&lock);
    pthread_mutex_destroy(&lock); 
    return true;
}

int main() {
    return 1;
}
