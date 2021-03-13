//
// Created by TOMLA on 13/03/2021.
//
#include "Editor.h"
#include <stdio.h>
#include <iostream>

using namespace std;

void Editor::loop()
{
    string input="";
    getline(cin,input);

    {
        while (input.compare("q") != 0 ) //input is not "q"
        {
            if(checkInput())
            {
                switch (input[0])
                {
                    case 'a':
                        break;

                    default:
                        cout << "?";
                        break;

                }
            }
            else
            {
                cout << "?";
            }

            getline(cin,input);
        }
    }
}

bool Editor::checkInput() {
    return false;
}

