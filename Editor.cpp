//
// Created by TOMLA on 13/03/2021.
//
#include "Editor.h"
#include <iostream>
using namespace std;

//----public methods----

/**
 *A function that is responsible for waiting for input from the user until he enters q, and activating the correct
 * functions of the document according to the input
 */
void Editor::loop()
{
    bool first = true;
    string input="";
    getline(cin,input);
        while (input.compare("q") != 0 ) //input is not "q"
        {
            string theRestOfTheString = input.substr(1); //input from index 1 until the end

            switch (input[0])
            {
                case '+': // Move x lines forward
                    this->document->advanceToLine(theRestOfTheString);
                    break;

                case '-': // Go back x lines
                    this->document->backToLine(theRestOfTheString);
                    break;

                case '$': // Go to the last line
                    this->document->lastLine();
                    break;

                case 'a': // Add one or more rows after the current row.
                    this->document->append();
                    break;

                case 'i': // Add one or more rows before the current row
                    this->document->insert();
                    break;

                case 'c': // Replace the current row with one or more rows.
                    this->document->replaceLines();
                    break;

                case 'd': // Delete the current line.
                    this->document->deleteLine();
                    break;

                case '/':  // /text/ - Look for a line that contains the text string.

                    this->document->searchText(input.substr(1,getOneBeforeLastIndex(input)));

                    break;

                case 's': // s/old/new - Replace the first instance of the old string with the new string in the current row.
                    this->document->replaceWord(getOldWord(input.substr(2)), getNewWord(input.substr(2)));
                    break;

                case 'j': // Connect the current line with the line following it
                    this->document->joinLines();
                    break;

                case 'w': // w file - Write the document in the file.
                    this->document->writeToFile( input.substr(2));
                    break;
                case 'p': //p - print the current line
                    this->document->printCurrentLine();
                    break;
                default:
                    if(isNum(input)) //Go to line x
                    {
                        this->document->goToLine(input);
                    }
                    else
                    {
                        cout << "?\n";
                    }
                    break;
            }

            getline(cin,input);
        }
}

//----private methods----

/**
 * Checks if the string is any number
 * @param str of input
 * @return true if the str is number, otherwise false
 */
bool Editor::isNum(string str)
{
    for (char const &c : str)
    {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

/**
 * @param str of input
 * @return The index is one before the last
 */
int Editor::getOneBeforeLastIndex(string str) {
    int index = -1;
    for (int i = 0; i < str.length(); i++)
        index++;
    return index-1;
}

/**
 * get the word old from this statement: s/old/new
 * @param str In the following structure: s/old/new
 * @return Filter of the word old
 */
string Editor::getOldWord(string str)
{
    string toReturn = "";
    bool flag = true;
    for (int i =0; i< str.length() && flag; i++)
    {
        if(str[i]!='/')
        {
            toReturn+=str[i];
        }
        else // str[i]=='/'
        {
            flag = false;
        }
    }

    return toReturn;
}

/**
 * get the word new from this statement: s/old/new
 * @param str In the following structure: old/new
 * @return Filter of the word new
 */
string  Editor::getNewWord(string str)
{
    string toReturn = "";
    int count = 0;
    bool flag = true;
    for (int i =0; i< str.length() && flag; i++)
    {
        if(str[i]!='/'&& count == 1)
        {
            toReturn+=str[i];
        }
        else if(str[i] =='/')
        {
            count++;
        }

    }
    return toReturn;
}


