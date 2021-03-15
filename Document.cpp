//
// Created by TOMLA on 13/03/2021.
//

#include "Document.h"
#include <regex>

//----private methods----
void Document::checkValidIndex()
{

}

void Document::printCurrentLine()
{
    cout<<this->document.at(this->currentLine)<<"\n";
}

//----public methods----
void Document::advanceToLine(string str)
{
    int numOfJump = stoi(str);
    int wantedLine= currentLine+numOfJump;
    if(wantedLine>=0 && wantedLine<=this->numberOfTotalLines-1)
    {
        this->currentLine = wantedLine;
        printCurrentLine();
    }
    else
    {
        cout <<"?\n";
    }
}

void Document::backToLine(string str)
{
    int numOfJump = stoi(str);
    int wantedLine = currentLine - numOfJump;
    if (wantedLine >= 0 && wantedLine <= this->numberOfTotalLines - 1) {
        this->currentLine = wantedLine;
        printCurrentLine();
    } else {
        cout << "?\n";

    }
}

void Document::lastLine()
{
    if(this->currentLine == -1)
    {
        cout<<"?\n";
    }
    else
    {
        this->currentLine = this->numberOfTotalLines-1;
        printCurrentLine();
    }
}

void Document::append()
{
    //local verbals
    string input=""; //Insert the string
    vector<string> anotherVector; // All the strings the user want to add

    //get input
    getline(cin,input);
    while (input!=".")
    {
        anotherVector.push_back(input);
        getline(cin,input);
    }

    //add the strings to the document vector
    this->document.insert(this->document.begin()+this->currentLine+1,anotherVector.begin(),anotherVector.end());
    this->currentLine = this->currentLine+anotherVector.size();
    this->numberOfTotalLines = this->numberOfTotalLines+anotherVector.size();
}

void Document::insert()
{
    //local verbals
    string input=""; //Insert the string
    vector<string> anotherVector; // All the strings the user want to add

    //get input
    getline(cin,input);
    while (input!=".")
    {
        anotherVector.push_back(input);
        getline(cin,input);
    }

    //add the strings to the document vector
    std::vector<string>::iterator it;
    if(this->currentLine == -1)
    {
        it = this->document.begin();
    }
    else
    {
        it = this->document.begin()+this->currentLine-1;
    }
    this->document.insert(it,anotherVector.begin(),anotherVector.end());
    this->currentLine = this->currentLine+anotherVector.size();
    this->numberOfTotalLines = this->numberOfTotalLines+anotherVector.size();
}

void Document::replaceLines()
{
    string input=""; //Insert the string
    vector<string> anotherVector; // All the strings the user want to add

    //get input
    getline(cin,input);
    while (input!=".")
    {
        anotherVector.push_back(input);
        getline(cin,input);
    }

    //add the strings to the document vector
    this->document.insert(this->document.begin()+this->currentLine,anotherVector.begin(),anotherVector.end());
    this->document.erase(this->document.begin()+currentLine+anotherVector.size());
    this->currentLine = this->currentLine-1+anotherVector.size();
    this->numberOfTotalLines = this->numberOfTotalLines-1+anotherVector.size();
}

void Document::deleteLine()
{
    if(currentLine >= 0)
    {
        this->document.erase(this->document.begin()+currentLine);
        this->numberOfTotalLines--;
        this->currentLine--;
    }
    else
    {
        cout << "?\n";
    }
}

void Document::searchText(string str)
{
    bool flag= true;
    regex toFine(str);
    smatch sm;
    if(this->currentLine+1 <= this->numberOfTotalLines-1)
    {

        for(int i = this->currentLine+1; i < this->numberOfTotalLines && flag; i++)
        {
            string line =this->document.at(i);
            if (regex_search(line,sm,toFine) == true)
            {
                currentLine=i;
                printCurrentLine();
                flag = false;
            }
        }
    }
    if(flag  || this->currentLine+1 > this->numberOfTotalLines-1)
    {
        for(int i = 0; i < this->currentLine+1 && flag; i++)
        {
            string line =this->document.at(i);
            if (regex_search(line,sm,toFine) == true)
            {
                currentLine=i;
                printCurrentLine();
                flag = false;
            }
        }
    }
    if(flag)
    {
        cout << "?\n";
    }
}

void Document::replaceWord(string oldWord, string newWord)
{

}

void Document::joinLines()
{
    if(currentLine!=numberOfTotalLines-1)
    {
        replace(this->document.begin()+currentLine,this->document.begin()+currentLine+1,this->document.at(currentLine),this->document.at(currentLine)+this->document.at(currentLine+1));
        this->document.erase(this->document.begin()+currentLine+1);
    }
    else
    {
        cout << "?\n";
    }
}

void Document::writeToFile(string nameOfFile)
{

}

void Document::goToLine(string numOfLine)
{
    int currLineTemp = stoi(numOfLine);
    try
    {
        this->currentLine = currLineTemp-1;
        printCurrentLine();
    }
    catch (const out_of_range& err)
    {
        cout << "?\n";
    }
}
