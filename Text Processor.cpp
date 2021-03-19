// Text Processor.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "Sentence.h"
#include <fstream>
#include <iostream>
using namespace std;

int		readSize(const char[], Sentence&);//readsize
void	readFile(const char[], char*, int&); //readdata
void	writeFile(const char[], Sentence&); //savedata
void	frequency(const char[], Sentence&); //frequency
void	Menu(Sentence&, Sentence&);         //driver function

int main() {
	Sentence obj;
	Sentence s2;
	Menu(obj, s2);
}

void Menu(Sentence& obj, Sentence& s2) {
	char*    array  = new char[943];        char*    array2  = new char[526];
	char	 arr[]  = "Para1.txt";          char	 arr2[]  = "Para2.txt";
	char	 arrO[] = "F_output.txt";       char     arrO2[] = "S_output.txt";
	int	     len = {};  int   len2 = {};    int      choice  = {};

	cout << "\t\t\t\t   Welcome to the Text Processor Application\n";
	cout << "\t\t\t\t-----------------------------------------------\n\n";
	cout << "------------------Beyond Grammar and Spelling-----------------------------Write With Your Reader in Mind";
	cout << "----------------\n\n";
	cout << "\t-----FIND out what you can ACCOMPLISH with the POWER of TEXT PROCESSOR at your FINGERTIPS-----\n\n";

	cout << "\n\t\t\t\t Reading Paragraph One\n";
	readFile(arr, array, len); obj.set_array(array); obj.set_Size(len); cout << obj.array << endl;

	cout << "\n\t\t\t\tReading  Paragraph Two\n";
	readFile(arr2, array2, len2); s2.set_array(array2); s2.set_Size(len2); cout << s2.array << endl;


	/*writeFile(arrO,obj);
	writeFile(arrO2,s2);*/
	do {
		cout << "\t\t\t\tInput the operation you want to perform: \n\n";
		cout << "\t\t\t Input 0 : + overloading -> To Merge Both Paragrpah\n";
		cout << "\t\t\t Input 1 : + overloading -> Convert to Uppercase\n";
		cout << "\t\t\t Input 2 : - overloading -> Convert to Lowercase\n";
		cout << "\t\t\t Input 3 : == overloading\n";
		cout << "\t\t\t Input 4 : != overloading\n";
		cout << "\t\t\t Input 5 : = overloading\n";
		cout << "\t\t\t Input 6: << Frequency Data of File One\n";
		cout << "\t\t\t Input 7: << Frequency Data of File Two\n";

		cout << "\t\t\t Input 8:  % overloading -> Encryption Paragraph One\n";
		cout << "\t\t\t Input 9:  % overloading -> Encryption Paragraph Two\n";
		cout << "\t\t\t Input 10: * overloading -> Decryption Paragraph One \n";
		cout << "\t\t\t Input 11: * overloading -> Decryption Paragraph Two \n";

		


		cout << "\t\t\t Input 12: Huffman Algo for Paragrapha One\n";
		cout << "\t\t\t Input 13: Huffman Algo for Paragrapha Two\n";

		cout << "\t\t\t Input 14: SpellCheck  Paragraph One \n";
		cout << "\t\t\t Input 15: SpellCheck  Paragraph Two \n";

		cout << "\t\t\t Input 16: Terminate Program\n";
		cout << "Your Choice: "; cin >> choice;
		if (choice == 0) { Paragraph s = s2 + obj; cout << "\n\t\t\t\tThe Paragraph after Merging is : \n"; cout << s.array; cout << endl; }
		if (choice == 1) { +obj; cout << obj.array << endl; }
		if (choice == 2) { -obj; cout << obj.array << endl; }
		if (choice == 3) { if (obj == s2) { cout << "Both Paragrpahs are Equal\n" << endl; } else { cout << "Both Paragrpahs are Not Equal\n" << endl; } }
		if (choice == 4) { if (obj != s2) { cout << "Both Paragrpahs are NOT Equal\n" << endl; } else { cout << "Both Paragrpahs are Equal\n" << endl; } }
		if (choice == 5) { s2 = obj; cout << "Paragrpah 1 is Equal to Paragrpah 2 by Assignment Operator\n" << endl; cout << "Paragraph 2 is: \n"; cout << s2; }
		if (choice == 6) { frequency("Frequency.txt", obj); }
		if (choice == 7) { frequency("Frequency2.txt", s2); }

		if (choice == 8) { obj % (2); cout << "Encrypted Paragraph is: \n"; cout << obj.array << endl; }
		if (choice == 9) { s2 % (2); cout << "Encrypted Paragraph is: \n"; cout << s2.array << endl; }

		if (choice == 10) { obj* (2); cout << "Decrypted Paragraph is: \n"; cout << obj.array << endl; }
		if (choice == 11) { s2* (2);  cout << "Decrypted Paragraph is: \n"; cout << s2.array << endl; }

		if (choice == 12) { obj.huffman(); }
		if (choice == 13) { s2. huffman(); }
		if (choice == 14) { obj.SpellCheck(); }
		if (choice == 15) { s2.SpellCheck(); }
	} while (choice < 16 && choice>=0);

	cout << "\n\t\t\t\tThank you,do not come next time! \n\n";
	if (array != nullptr) { delete[]array; array = nullptr; }
	if (array2 != nullptr) { delete[]array2; array2 = nullptr; }
}

int readSize(const char file[], Sentence& obj) {
	ifstream fin; fin.open(file);
	if (!fin.is_open()) { cout << "\nError in opeing the Reading the file!    SIZE\n"; }
	int i = 0; while (!fin.eof()) { i++; } return i;
}//readsize

void readFile(const char file[], char* array, int& len) {
	ifstream fin; fin.open(file);
	if (!fin.is_open()) { cout << "\nError in opeing the Reading the file!\n"; }
	else { int i = 0; while (!fin.eof()) { fin.get(array[i]); i++; } 	len = i; }
}//readdata

void writeFile(const char file[], Sentence& obj) {
	ofstream fout; fout.open(file);
	if (!fout.is_open()) { cout << "\nError in opeing the Writing the file!\n"; }
	else { fout << obj; }
	fout.close();
} //savedata

void frequency(const char file[], Sentence& obj) {
	ofstream fout; fout.open(file);
	if (!fout.is_open()) { cout << "\nError in opeing the Writing the file!\n     Frequency"; }
	else {
		fout << "Paragrpah Numbers: " << obj.TotalParagraph_Count() << endl;
		cout << "Paragrpah Numbers: " << obj.TotalParagraph_Count() << endl;
		obj.set_SCount();
		fout << "Sentences in a Paragraph: " << obj.SentenceCount << endl;
		cout << "Sentences in a Paragraph: " << obj.SentenceCount << endl;

		int word = obj.TotalWord_Count(), pun = obj.getPunC_Count(), eng = obj.getEngC_Count();

		fout << "\nTotal Number of Words are: " << word << endl;
		cout << "\nTotal Number of Words are: " << word << endl;
		fout << "Total Number of Puncutation Characters are: " << pun << endl;
		cout << "Total Number of Puncutation Characters are: " << pun << endl;
		fout << "Total Number of English Characters are: " << eng << endl;
		cout << "Total Number of English Characters are: " << eng << endl;
		obj.getWord_Count(); fout << endl; cout << endl;
		obj.get_CCount();
	}
	fout.close();
}//frequency