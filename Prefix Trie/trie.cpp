#include "trie.h"

Node* create_node(char value){

	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->children = new unordered_map<char, Node*>;
	new_node->parent = NULL;
	new_node->value = value;

	return new_node;
}

void delete_node(Node* node){

	if (node == NULL) return;

	unordered_map<char, Node*>* children = node->children;

	for(auto it = children->begin(); it != children->end(); it++){
		delete_node(it->second);
	}
	delete node->children;
	free(node);
}


Trie::Trie(){
	root = create_node(EMPTY_CHAR);
}

void Trie::insert(string word){

	Node* current = root;

	for (char character : word){

		auto it = current->children->find(character);

		if(it == current->children->end()){
			Node* new_node = create_node(character);
			new_node->parent = current;
			current->children->insert(pair<char, Node*>(character, new_node));
			current = new_node;
		}

		else current = it->second;
	}

	current->children->insert(pair<char, Node*>(EMPTY_CHAR, NULL));
}


void Trie::remove(string word){

	Node* current = root;

	for (char character : word) {
		auto it = current->children->find(character);
		current = it->second;
	}

	for(int i = 0; i < word.size(); i++){

		if(current->children->size() <= 1){
			Node* aux = current;
			current = current->parent;
			current->children->erase(aux->value);
			free(aux);
		}
	}
}

bool Trie::search(string word){

	Node* current = root;

	for(char character : word){

		auto it = current->children->find(character);

		if(it == current->children->end()) return false;
			
		current = it->second;
	}

	if(current->children->find(EMPTY_CHAR) != current->children->end()) return true;
}


bool Trie::starts_with(string word){

	Node* current = root;

	for (char character : word) {

		auto it = current->children->find(character);

		if (it == current->children->end()) return false;

		current = it->second;
	}

	if (current->children->find(EMPTY_CHAR) != current->children->end()) return false;

	return true;
}

Trie::~Trie(){
	delete_node(root);
}




