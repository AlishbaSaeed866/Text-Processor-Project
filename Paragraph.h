#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Paragraph {
public:
    //attributes
    char *array=new char[1000];
    int size = 1;
    int EngCCount = {}; //English character count
    int PuncCount = {};//Puncuation character count
    public:
                /* ++++++++++++++++++++++++++++++++++++++
                 *             constructors
                 * +++++++++++++++++++++++++++++++++++++*/
    //
    Paragraph(); //default
    Paragraph(const Paragraph&); //copy

    //setters
    void set_Size(int);
    void set_ECCount(int);
    void set_PCount(int);
    void set_array(char*);
    //getters
    int get_Size()const;
    int get_ECCount()const;
    int get_PCount()const;
                /* ++++++++++++++++++++++++++++++++++++++
                 *               Operator Overloading
                 * +++++++++++++++++++++++++++++++++++++*/
    //cout and cin overloading point 1,2,3
    friend	ostream& operator <<(ostream&, const Paragraph&);
    friend	istream& operator >>(istream&,  Paragraph&);
               /* ++++++++++++++++++++++++++++++++++++++++++
                  * + for converting para to uppercase *
                  *              &   point 5           *
                  * - for converting para to lowercase *
                  +++++++++++++++++++++++++++++++++++++++++*/
    void operator +();
    void operator -();
    //adding 2 paragraphs     point 12
    Paragraph operator +(const Paragraph&);
    //point 10
    void operator %(int Key);
    void operator *(int Key);
    Paragraph operator =(const Paragraph&); //assignment operator
    //point 4
    bool	 operator ==(Paragraph&);
    bool	 operator !=(Paragraph&);

                /* ++++++++++++++++++++++++++++++++++++++
                 *               Methods
                 * +++++++++++++++++++++++++++++++++++++*/
    int TotalWord_Count();// total words in a paragraph
    int TotalParagraph_Count(); //total number of paragraphs

//point 6
    int getEngC_Count(); //English character count
    int getPunC_Count(); //Puncuation character count

//destructor
    virtual ~Paragraph();
};