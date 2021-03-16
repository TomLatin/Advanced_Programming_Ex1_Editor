//
// Created by TOMLA on 13/03/2021.
//

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Document {
private:

    //----Fields----
    vector<string> document;
    int currentLine;
    int numberOfTotalLines;

    //----private methods----
    void updateCurrentLine(int wantedLine);
    vector<string> getInput();

public:

    //----Constructor----
    Document() { currentLine = -1, numberOfTotalLines=0; }

    Document(string fileName)
    {
        ifstream fileStream(fileName);
        if(!fileStream)
        {
            throw std::invalid_argument("Invalid file name");
        }
        else
        {
            this->currentLine= -1;
            string line;
            while(getline(fileStream,line) && line!="")
            {
                document.push_back(line);
                this->currentLine++;
                this->numberOfTotalLines++;
            }
        }
    }

    //----public methods----
    void advanceToLine(string str);
    void backToLine(string str);
    void append();
    void insert();
    void replaceLines();
    void searchText(string str);
    void replaceWord(string oldWord, string newWord);
    void writeToFile(string nameOfFile);
    void goToLine(string numOfLine);
    void lastLine();
    void deleteLine();
    void joinLines();
    void printCurrentLine();

};



