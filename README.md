# Impledge-assignment
**Overview**

This program finds the longest compound word and the second longest compound word from a given list of words. A compound word is a word that is formed by combining two or more smaller words. For example, the words "football" and "baseball" are both compound words, formed by combining the words "foot" and "ball" and "base" and "ball", respectively.

The program uses a trie data structure to store the list of words. A trie is a tree-like data structure that is well-suited for storing strings. Each node in the trie represents a character in the string, and the children of a node represent the characters that can follow the character represented by the node.

**Approach taken**

The program first inserts all of the words in the list into the trie. Then, it iterates over the words in the list, finding the longest common prefix of each word and its descendants in the trie. The longest common prefix is the longest substring of the word that is also a substring of all of its descendants in the trie.

If the longest common prefix of a word and its descendants is equal to the word itself, then the word is a compound word. The program keeps track of the longest compound word and the second longest compound word that it finds.

This program uses dynamic memory allocation to store the trie data structure. This avoids stack overflow when processing large inputs.

To allocate memory dynamically, the program uses the `new` and `delete` operators. The `new` operator allocates a block of memory of the specified size and returns a pointer to the first byte of the allocated memory. The `delete` operator deallocates the memory block pointed to by the given pointer.

The following code shows how the program uses dynamic memory allocation to allocate the trie data structure:

"TrieNode* root = new TrieNode();"

The `root` pointer points to the root node of the trie. The root node is allocated dynamically using the `new` operator.

When the program is finished using the trie data structure, it deallocates the memory using the `delete` operator:

"delete root;"

This deallocates the memory block pointed to by the `root` pointer, which includes all of the nodes in the trie.

Using dynamic memory allocation to store the trie data structure allows the program to process large inputs without encountering stack overflow.

**Steps to execute the code**

1. Compile the code using the following command:

"g++ -o main main.cpp"

2. Run the program using the following command:

"./main Input_01.txt"

The program will output the longest compound word and the second longest compound word from the file `Input_01.txt`. It will also output the time taken to process the file.
Design decisions
Some of the design decisions that went into the code include:

Using a trie data structure to store the list of words. A trie is well-suited for storing strings and allows for efficient searching and prefix matching.
Using dynamic memory allocation to store the trie data structure. This avoids stack overflow when processing large inputs.
Iterating over the words in the list in reverse order of their length. This allows the program to find the longest compound words first.
Keeping track of the longest compound word and the second longest compound word. This allows the program to output both of these words to the user.

**Conclusion**

This program provides an efficient way to find the longest and second longest compound words in a given list of words. The program uses dynamic memory allocation to store the trie data structure, which allows it to process large inputs without encountering stack overflow.
