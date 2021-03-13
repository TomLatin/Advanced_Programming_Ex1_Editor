//
// Created by TOMLA on 13/03/2021.
//

#pragma once
#include "Document.h"

class Editor {

private:

    //Fields
    Document * document;
    bool checkInput();

public:

    //Constructor
    Editor(){this->document = new Document;}
    Editor(string fileName){this->document = new Document(fileName);}
    void loop();


};


