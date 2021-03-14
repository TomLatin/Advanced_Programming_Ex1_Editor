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

    //----private methods----
    void checkValidIndex();

public:

    //----Constructor----
    Document() { currentLine = 0; }

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
            while(getline(fileStream,line) && line!=""){
                document.push_back(line);
                this->currentLine++;
            }
        }
    }

    //----public methods----
    void advanceToLine(string str);
    void backToLine(string str);
    void append(string str);
    void insert(string str);
    void replaceLines(string str);
    void searchText(string str);
    void replaceWord(string oldWord, string newWord);
    void writeToFile(string nameOfFile);
    void goToLine(string numOfLine);
    void lastLine();
    void deleteLine();
    void joinLines();

};



