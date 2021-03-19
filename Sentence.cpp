#include "Paragraph.h"
#include "Sentence.h"
#include <queue>
#include <vector>
#include <unordered_map>
#define EMPTY_STRING ""
#include <iostream>

//constructors
	//default
Sentence::Sentence():Paragraph(){}
//copy
Sentence::Sentence(const Sentence &obj) :Paragraph(obj){
	SentenceCount = obj.SentenceCount;
	WordCount=obj.WordCount;
}
//setters
void Sentence::set_SCount() {
	int	SCount = 0;
	for (int j = 0; j < size; j++) {
		if (array[j] == '.') {
			SCount++;
		}
	}
	SentenceCount = SCount;
	cout << "Sentences in a Paragraph: " << SentenceCount << endl;

}
void Sentence::set_WCount(int wc) { WordCount = wc; }

//getters
int Sentence::get_SCount()const { return SentenceCount; }
int Sentence::get_WCount()const { return WordCount; }

/* ++++++++++++++++++++++++++++++++++++++
*               Methods
*   +++++++++++++++++++++++++++++++++++*/
//pooint 9

//words point 8 
void Sentence::getWord_Count() {
	ofstream fout;
	fout.open("Frequency.txt", ios::app);
	int wCount = 0, SCount = 1;
	int temp = 0, i;
	for (i = 0; i <= size; i++) {
		if (array[i] == ' ' && array[i] != '.') {
			wCount++;
		}
		if (array[i] == '.') {
			fout << "Sentence: " << SCount;
			cout << "Sentence: " << SCount;
			fout << " : \t";
			cout << " : \t";

			fout << (wCount - temp) << " \twords.\n";
			cout << (wCount - temp) << " \twords.\n";
			temp = wCount;
			SCount++;
		}
	}
	fout << endl;
	fout.close();
} //in  sentence 
void Sentence::get_CCount() {
	ofstream fout;
	fout.open("Frequency.txt", ios::app);
	int character = 0, c = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] != ' ') {
			character++;
		}
		if (array[i] == ' ') {
			fout << "Word " << c + 1 << " : \t" << character << " \tcharacters.\n";
			cout << "Word " << c + 1 << " : \t" << character << " \tcharacters.\n";
			character = 0;
			c++;
		}
	}
	fout.close();
}//in a word
//spellchecker
void Sentence::SpellCheck() {
    char darray[130];
        ifstream fin;
        fin.open("Dictionary.txt");
        if (!fin.is_open()) { cout << "Error in reading the data\n"; }
        else {
            int i = 0;
            while (!fin.eof()) {
                fin.get(darray[i]);
                i++;
            }
        }
        cout << "\tSpellCheck can't find    \n";
        cout << darray;
        fin.close();
}
 // huffman algo reference 
 ///*https://www.techiedelight.com/huffman-coding/#:~:text=Huffman%20Coding%20(also%20known%20as,and%20construction%20of%20Huffman%20Tree*/


 // A Tree node
struct Node
{
    char ch;
    int freq;
    Node* left, * right;
};

// Function to allocate a new tree node
Node* getNode(char ch, int freq, Node* left, Node* right)
{
    Node* node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

// Comparison object to be used to order the heap
struct comp
{
    bool operator()(Node* l, Node* r)
    {
        // the highest priority item has the lowest frequency
        return l->freq > r->freq;
    }
};

// Utility function to check if Huffman Tree contains only a single node
bool isLeaf(Node* root) {
    return root->left == nullptr && root->right == nullptr;
}

// Traverse the Huffman Tree and store Huffman Codes in a map.
void encode(Node* root, string str, unordered_map<char, string>& huffmanCode)
{
    if (root == nullptr) {
        return;
    }

    // found a leaf node
    if (isLeaf(root)) {
        huffmanCode[root->ch] = (str != EMPTY_STRING) ? str : "1";
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// Traverse the Huffman Tree and decode the encoded string
void decode(Node* root, int& index, string str)
{
    if (root == nullptr) {
        return;
    }

    // found a leaf node
    if (isLeaf(root)) {
        cout << root->ch;
        return;
    }

    index++;

    if (str[index] == '0') {
        decode(root->left, index, str);
    }
    else {
        decode(root->right, index, str);
    }
}

// Builds Huffman Tree and decodes the given input text
void buildHuffmanTree(string text)
{
    // base case: empty string
    if (text == EMPTY_STRING) {
        return;
    }

    // count frequency of appearance of each character
    // and store it in a map
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Create a priority queue to store live nodes of Huffman tree
    priority_queue<Node*, vector<Node*>, comp> pq;

    // Create a leaf node for each character and add it
    // to the priority queue.
    for (auto pair : freq) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    // do till there is more than one node in the queue
    while (pq.size() != 1)
    {
        // Remove the two nodes of the highest priority
        // (the lowest frequency) from the queue

        Node* left = pq.top(); pq.pop();
        Node* right = pq.top();    pq.pop();

        // Create a new internal node with these two nodes
        // as children and with frequency equal to the sum
        // of the two nodes' frequencies. Add the new node
        // to the priority queue.

        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    // root stores pointer to the root of Huffman Tree
    Node* root = pq.top();

    // Traverse the Huffman Tree and store Huffman Codes
    // in a map. Also print them
    unordered_map<char, string> huffmanCode;
    encode(root, EMPTY_STRING, huffmanCode);

    cout << "Huffman Codes are:\n" << '\n';
    for (auto pair : huffmanCode) {
        cout << pair.first << " " << pair.second << '\n';
    }

    cout << "\nOriginal string is:\n" << text << '\n';

    // Print encoded string
    string str;
    for (char ch : text) {
        str += huffmanCode[ch];
    }

    cout << "\nEncoded string is:\n" << str << '\n';
    cout << "\nDecoded string is:\n";

    if (isLeaf(root))
    {
        // Special case: For input like a, aa, aaa, etc.
        while (root->freq--) {
            cout << root->ch;
        }
    }
    else
    {
        // Traverse the Huffman Tree again and this time,
        // decode the encoded string
        int index = -1;
        while (index < (int)str.size() - 1) {
            decode(root, index, str);
        }
    }
}
void Sentence::huffman() {
    for (int i = 0; i < size; i++) {
        text[i] = array[i];
    }
    buildHuffmanTree(text);
    cout << endl;
}
 //destructor
Sentence:: ~Sentence(){cout << "I'm a Destructor of Sentence Class!\n" << endl;}