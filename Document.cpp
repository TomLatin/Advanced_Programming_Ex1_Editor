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
    if(wantedLine>=0 && wantedLine<= this->numberOfTotalLines-1)
    {
        this->currentLine = wantedLine;
        printCurrentLine();
    }
    else
    {
        cout << "?"<<"\n";
    }
}

void Document::backToLine(string str)
{
    int numOfJump = stoi(str);
    int wantedLine= currentLine-numOfJump;
    if(wantedLine>=0 && wantedLine<= this->numberOfTotalLines-1)
    {
        this->currentLine = wantedLine;
        printCurrentLine();
    }
    else
    {
        cout << "?"<<"\n";
    }
}

void Document::lastLine()
{
    this->currentLine = this->numberOfTotalLines-1;
    printCurrentLine();
}

void Document::append()
{
    string allSentences = "";
    string input="";
    getline(cin,input);
    while (input!=".")
    {
        allSentences+=input+"\n";
        getline(cin,input);
    }
    regex sentence ("(.+)");
    smatch sm;
    while (regex_search(allSentences,sm,sentence))
    {
        this->document.insert(this->document.begin()+this->currentLine+1,sm.str(1));
        this->currentLine++;
        this->numberOfTotalLines++;
        allSentences = sm.suffix().str();
    }
}

void Document::insert()
{
//    string allSentences = "";
//    string input="";
//    vector<string> anotherVector;
//    getline(cin,input);
//    while (input!=".")
//    {
//        allSentences+=input+"\n";
//        anotherVector.push_back(input);
//        getline(cin,input);
//    }
//    regex sentence ("(.+)");
//    smatch sm;
//    std::vector<string>::iterator it;
//
//    if(this->currentLine == 0)
//    {
//        it = this->document.begin();
//    }
//    else
//    {
//        it = this->document.begin()+this->currentLine;
//        cout<<this->currentLine;
//    }
//    this->document.insert(it,anotherVector.begin(),anotherVector.end());
//    this->currentLine++;
//    this->numberOfTotalLines++;
//    allSentences = sm.suffix().str();

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
        cout << "?"<<"\n";
    }
}
