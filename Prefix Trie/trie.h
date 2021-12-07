#ifndef TRIE_H
#define TRIE_H


#include <string>
#include <unordered_map>


using namespace  std;


const char EMPTY_CHAR = '^';

typedef struct Node{

	char value;
	unordered_map<char, struct Node*>* children;
	struct Node* parent;

}Node;


class Trie{

	private:
		 Node* root;

	public:
		Trie();
		void insert(string word);
		void remove(string word);
		bool search(string word);
		bool starts_with(string word);
		~Trie();
};


#endif
