/**
* Created by Yu(Khitan) Wu on 12/14/2014
* Copyright (C) 2014 Yu(Khitan) Wu All rights reserved.
* Email: wuxiao356@gmial.com
*/
#include <unordered_map>
#include <forward_list>
#include <utility>

struct Node{
	int val, key;
	Node *next, *previous;
	Node(int v, int k){ val = v; key = k; next = NULL; previous = NULL; }
};

class LRUCache{
public:
	LRUCache(int capacity) {
		_capacity = capacity; _size = 0;
		head = NULL; tail = NULL;
	}

	int get(int key) {
		unordered_map<int, Node*>::const_iterator got = hashmap.find(key);
		if (got == hashmap.end()) return -1;
		// put this node in the head, then return value
		moveToHead(got->second);
		return got->second->val;
	}

	void set(int key, int value) {
		unordered_map<int, Node*>::const_iterator got = hashmap.find(key);
		if (got == hashmap.end()) {
			//insert new node at head
			Node *newNode = new Node(value, key);
			if (_size == 0) { head = newNode; tail = newNode; }
			else{
				newNode->next = head;
				head->previous = newNode;
				head = newNode;
			}
			hashmap.insert(pair<int, Node*>(key, newNode));
			++_size;
			// delete least recently unused node from both list and hashmap
			if (_size > _capacity){
				Node *temp = tail;
				hashmap.erase(tail->key);
				tail = tail->previous;
				if (tail != NULL) tail->next = NULL;
				delete temp;
				--_size;
			}
		}
		else{
			//update value, then put it in the head
			got->second->val = value;
			moveToHead(got->second);
		}
	}
private:
	unordered_map<int, Node*> hashmap;
	Node *head, *tail;
	int _capacity;
	int _size;

	void moveToHead(Node *current){
		if (current == head){
			return;
		}
		else if (current == tail){
			tail = current->previous;
			tail->next = NULL;
			current->next = head;
			head->previous = current;
			head = current;
			head->previous = NULL;
		}
		else{
			current->previous->next = current->next;
			current->next->previous = current->previous;
			current->next = head;
			head->previous = current;
			head = current;
			head->previous = NULL;
		}
	}
};
