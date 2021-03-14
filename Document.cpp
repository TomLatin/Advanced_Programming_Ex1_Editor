//
// Created by TOMLA on 13/03/2021.
//

#include "Document.h"

//----private methods----
void Document::checkValidIndex()
{

}

void Document::printCurrentLine()
{
    cout<<this->document.at(this->currentLine);
}

//----public methods----
void Document::advanceToLine(string str)
{
    int numOfJump = stoi(str);
    int wantedLine= currentLine+numOfJump;
    if(wantedLine>0 && wantedLine<= this->numberOfTotalLines)
    {
        this->currentLine = wantedLine;
        printCurrentLine();
    }
    else
    {
        cout << "?";
    }
}

void Document::backToLine(string str)
{
    int numOfJump = stoi(str);
    int wantedLine= currentLine-numOfJump;
    if(wantedLine>0 && wantedLine<= this->numberOfTotalLines)
    {
        this->currentLine = wantedLine;
        printCurrentLine();
    }
    else
    {
        cout << "?";
    }
}

void Document::lastLine()
{
    this->currentLine = this->numberOfTotalLines;
    printCurrentLine();
}

void Document::append(string str)
{

}

void Document::insert(string str)
{

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
        this->currentLine = currLineTemp;
        printCurrentLine();
    }
    catch (const out_of_range& err)
    {
        cout << "?";
    }
}
