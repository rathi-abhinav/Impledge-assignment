#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

struct TrieNode {
 bool isEndOfWord;
 unordered_map<char, TrieNodePtr> children;

 TrieNode() : isEndOfWord(false) {
 }
};

using TrieNodePtr = TrieNode*;

void insertWord(TrieNodePtr root, const string& word) {
 TrieNodePtr node = root;
 for (char c : word) {
 if (!node->children.count(c)) {
 node->children[c] = new TrieNode();
 }
 node = node->children[c];
 }
 node->isEndOfWord = true;
}

string findLongestCommonPrefix(TrieNodePtr root, const string& word) {
 string lcp = "";
 TrieNodePtr node = root;
 for (char c : word) {
 if (!node->children.count(c)) {
 break;
 }
 node = node->children[c];
 if (node->isEndOfWord) {
 lcp = word.substr(0, lcp.length() + 1);
 }
 }
 return lcp;
}

int main() {
 TrieNodePtr root = new TrieNode();

 ifstream inputFile("Input_01.txt");
 string word;
 vector<string> words;
 while (inputFile >> word) {
 words.push_back(word);
 insertWord(root, word);
 }
 inputFile.close();

 sort(words.begin(), words.end(), [](const string& a, const string& b) {
 return a.length() > b.length();
 });

 string lcpw = "", slcpw = "";
 auto start = high_resolution_clock::now();

 for (const string& w : words) {
 string lcp = findLongestCommonPrefix(root, w);
 if (lcp == w) {
 if (lcpw.empty()) {
 lcpw = w;
 } else if (w.length() > lcpw.length()) {
 slcpw = lcpw;
 lcpw = w;
 } else if (w.length() > slcpw.length()) {
 slcpw = w;
 }
 }
 }

 auto stop = high_resolution_clock::now();
 auto duration = duration_cast<milliseconds>(stop - start);

 cout << "Longest Compound Word: " << lcpw << endl;
 cout << "Second Longest Compound Word: " << slcpw << endl;
 cout << "Time taken to process file Input_01.txt: " << duration.count() << " milliseconds" << endl;

 delete root;

 return 0;
}
