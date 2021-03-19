#include "Paragraph.h"
#include <fstream>
//constructors

Paragraph::Paragraph() = default; //default
Paragraph::Paragraph(const Paragraph &obj) { 
	cout << "I'm a Copy Constructor of Paragraph Class!\n"; 
	EngCCount = obj.EngCCount;
	PuncCount = obj.PuncCount;
	int len = (strlen(obj.array) + 1),i;
	array = new char[len];
	for ( i = 0; i < len; i++){
		array[i] = obj.array[i];  }  } //copy
//setters
void Paragraph::set_Size(int user) {size=user; }
void Paragraph::set_ECCount(int ecc){EngCCount = ecc;}
void Paragraph::set_PCount(int pcc) { PuncCount = pcc; }
void Paragraph::set_array(char *arr) {
	size =( strlen(arr)+1);
	array = new char[size];
	for (int i = 0; i < size; i++){
		array[i] = arr[i];}
}
//getters
int Paragraph::get_Size()const { return size; }
int Paragraph::get_ECCount()const { return EngCCount; }
int Paragraph::get_PCount()const { return PuncCount; }
//cout and cin overloading point 1,2,3
ostream& operator <<(ostream &out, const Paragraph &obj){
	int len = (strlen(obj.array) + 1);
	for (int i = 0; i <len; i++){
		out << obj.array[i];	}
	return out; 
}

istream& operator >>(istream& in,  Paragraph &obj){
	obj.array = nullptr;
	obj.array = new char[obj.size];
	for (int i = 0; i < obj.size; i++) {
		in.get(obj.array[i]);}
	return in;
}
/* + for converting para to uppercase *
 *              &   point 5           *
 * - for converting para to lowercase */
void Paragraph::operator +() {
	for (int i = 0; array[i] != '\0'; i++) {
		if (array[i] >= 'a' && array[i] <= 'z') {
			array[i] = array[i] - 32;
		}
	}
	bool flag = {};
	for (int j = 0; array[j] != '\0'; j++) {
		if (array[j] >= 'a' && array[j] <= 'z') {
			flag = true;
		}
	}
	if (flag == true) {
		cout << "The array is in Uppercase!\n";
	}
}
void Paragraph::operator -() {
	for (int i = 0; array[i] != '\0'; i++) {
		if (array[i] >= 'A' && array[i] <= 'Z') {
			array[i] = array[i] + 32;
		}
	}
	bool flag = {};
	for (int j = 0; array[j] != '\0'; j++) {
		if (array[j] >= 'A' && array[j] <= 'Z') {
			flag = true;
		}
	}
	if (flag == true) {
		cout << "The array is in Lowercase!\n";
	}
}
void  Paragraph::operator %(int key) {
	for (int i = 0; i < size; i++) {
		if (isalpha(array[i])) {
			if (array[i] >= 'A' && array[i] <= 'Z') {
				if (array[i] == 'Z') { array[i] = 'B'; }
				else if (array[i] == 'Y') { array[i] = 'A'; }
				else { array[i] += key; }
			}
			else if (array[i] >= 'a' && array[i] <= 'z') {
				if (array[i] == 'z') { array[i] = 'b'; }
				else if (array[i] == 'y') { array[i] = 'a'; }
				else { array[i] += key; }
			}
		}
	}
}
void  Paragraph::operator *(int key) {
	for (int i = 0; i < size; i++) {
		if (isalpha(array[i])) {
			if (array[i] >= 'A' && array[i] <= 'Z') {
				if (array[i] == 'B') { array[i] = 'Z'; }
				else if (array[i] == 'A') { array[i] = 'Y'; }
				else { array[i] -= key; }
			}
			else if (array[i] >= 'a' && array[i] <= 'z') {
				if (array[i] == 'b') { array[i] = 'z'; }
				else if (array[i] == 'a') { array[i] = 'y'; }
				else { array[i] -= key; }
			}
		}
	}
}
Paragraph Paragraph::operator =(const Paragraph& obj) {
	this->size = obj.size;
	if (this != &obj) {
		int i = 0;
		delete[]this->array;
		this->array = nullptr;
		this->array = new char[size + 1];
		for (; i < size; i++) {
			this->array[i] = obj.array[i];
		}
		this->array[i] = '\0';
		this->EngCCount = obj.EngCCount;
		this->PuncCount = obj.PuncCount;
		bool flag = {};
		//if (this != &obj) { cout << "\nSorry, the operation isn't done\n"; }
		cout << "\nThe assignment operation is successfully done!\n";
	}

	return *this;
}//assignment operator
   //adding 2 paragraphs     point 12
Paragraph Paragraph::operator +(const Paragraph &obj){
	Paragraph temp;
	temp.size = this->size + obj.size;
	temp.array = new char[temp.size + 1];
	int i = 0, j = 0;
	for (; i < this->size; i++) {
		temp.array[i] = this->array[i];
	}
	//	temp.array[i] = ' ';
	for (j = 0; j < obj.size; j++) {
		temp.array[i] = obj.array[j];
		i++;
	}
	return temp;
}
//point 4
bool	Paragraph::operator ==(Paragraph &obj){
	int len1 = strlen(this->array);
	for (int i = 0; i < len1; i++){
		if (this->array[i] != obj.array[i]) {
			return false;}  }
	return true;
}
bool	Paragraph:: operator !=(Paragraph &obj){
	int len1 = strlen(this->array);
	for (int i = 0; i < len1; i++) {
		if (this->array[i] != obj.array[i]) {
			return true; }  }
	return false;
}
/* ++++++++++++++++++++++++++++++++++++++
 *               Methods
 * ++++++++++++++++++++++++++++++++++++++*/

int Paragraph::TotalWord_Count() {
	int words = 1;
	int len = strlen(array);
	for (int i = 0; i < len; i++){
		if (array[i] == ' ') {
			words++;}   }
	return words;
}// total words in a paragraph
//point 6
int Paragraph::TotalParagraph_Count() {
	int c = 1;
	for (int i = 0; i < size; i++) {
		if (array[i] == '\n') { c++; }
	}
	return c;
}//total number of paragraphs
int Paragraph::getEngC_Count() {
	for (int i = 0; array[i]!='\0'; i++){
		if ((array[i] >= 'A' && array[i] <= 'Z') || (array[i] >= 'a' && array[i] <= 'z')) {
			EngCCount++;
		}
	}
	return EngCCount;
} //English character count
int Paragraph::getPunC_Count() {
	for (int i = 0; array[i] != '\0'; i++) {
		if (array[i] == 46||array[i] == 44 || array[i] == 59 || array[i] == 58|| array[i] == 63 || array[i] == '!' || array[i] == 39 || array[i] == '_' || array[i] == 34 || array[i] == '-' || array[i] == '/' || array[i] == '@') {
			PuncCount++;
		}
	}
	return PuncCount;
}//Puncuation character count

 //destructor
Paragraph:: ~Paragraph() {
	cout << "I'm a Destructor of Paragraph Class!\n" << endl;
	if (array != nullptr){
		delete[]array;
		array = nullptr;}
}