#pragma once
#include "Paragraph.h"
#include "Sentence.h"
#include <queue>
#include <unordered_map>
#define EMPTY_STRING ""
#include <iostream>
using namespace std;
class Sentence:public Paragraph{
public:
	int SentenceCount = {};
	int WordCount = {};
	string text = string(array);
//constructors
	//default
	Sentence();
	//copy
	Sentence(const Sentence&);
	//setters
	void set_SCount();
	void set_WCount(int);
	
	//getters
	int get_SCount()const;
	int get_WCount()const;
	
	/* ++++++++++++++++++++++++++++++++++++++
 *               Methods
 *   +++++++++++++++++++++++++++++++++++*/
//words point 8 & 9
	void getWord_Count(); //in  sentence 
	void get_CCount();//in a word
//spellchecker
	void SpellCheck();
// huffman algo
	void huffman();
//destructor
	virtual ~Sentence();
};

