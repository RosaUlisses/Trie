#include <iostream>
#include "trie.h"

using namespace std;

int main(int argc, char** argv){

	Trie my_trie;

	my_trie.insert("rafaela");
	my_trie.insert("ulissao");
	my_trie.insert("gabriel");
	my_trie.insert("black");


	cout << "Prefix 'black' is in the Trie -> " << my_trie.starts_with("black") << "\n";
	cout << "Prefix 'rafa' is in the Trie -> " << my_trie.starts_with("rafa") << "\n";
	cout << "Prefix 'teen' is in the Trie -> " << my_trie.starts_with("teen") << "\n";

	cout << "\n\n";

	cout << "Word 'ulisses' is in the Trie -> " << my_trie.search("ulisses") << "\n";
	cout << "Word 'gabriel' is in the Trie -> " << my_trie.search("gabriel") << "\n";
	cout << "Word 'black' is in the Trie -> " << my_trie.search("black") << "\n";


	cout << "\n\n";

	return 0;
}