/*
* Introduction: A bucket HashTable
* Author: puer
* Date: 3/17/2016
*/

int HashTable::get(int key) {
	int bucket = get_bucket(key);
	if(bucket!=-1) {
		return entry_[bucket];
	}
	return -1;
}

bool HashTable::put(int key, int value) {
	int bucket = get_bucket(key);
	if(bucket!=-1) {
		entry_[bucket] = value;
		return true;
	}
	return false;
}