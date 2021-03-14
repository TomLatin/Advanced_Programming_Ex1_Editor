//
// Created by TOMLA on 13/03/2021.
//

#pragma once
#include "Document.h"

class Editor {

private:

    //----Fields----
    Document * document;

    //----private methods----
    bool checkInput(string input);
    bool isNum(string str);
    int getOneBeforeLastIndex(string str);
    string getOldWord(string str);
    string getNewWord(string str);

public:

    //----Constructor----
    Editor(){this->document = new Document;}
    Editor(string fileName){this->document = new Document(fileName);}

    //----public methods----
    void loop();
};


