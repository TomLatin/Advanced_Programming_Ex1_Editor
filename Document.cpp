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

void Document::replaceLines(string str)
{

}

void Document::deleteLine()
{

}

void Document::searchText(string str)
{

}

void Document::replaceWord(string oldWord, string newWord)
{

}

void Document::joinLines()
{

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
