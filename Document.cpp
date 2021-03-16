//
// Created by TOMLA on 13/03/2021.
//

#include "Document.h"
#include <regex>

//----private methods----
void Document::updateCurrentLine(int wantedLine)
{
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

vector<string> Document::getInput()
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

    return anotherVector;
}



//----public methods----
/**
 * Print the current line
 */
void Document::printCurrentLine()
{
    cout<<this->document.at(this->currentLine)<<"\n";
}

/**
 * Move x lines forward, the current line is now x.
 * If the line exceeds the size, print "?".
 * @param str - Which represents a number.
 */
void Document::advanceToLine(string str)
{
    int numOfJump = stoi(str);
    int wantedLine= currentLine+numOfJump;
    updateCurrentLine(wantedLine);
}

/**
 * Go back x lines forward, the current line is now x.
 * If the line exceeds the size, print "?".
 * @param str - Which represents a number
 */
void Document::backToLine(string str)
{
    int numOfJump = stoi(str);
    int wantedLine = currentLine - numOfJump;
    updateCurrentLine(wantedLine);
}

/**
 * Go to the last line, the current line is now the last.
 */
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

/**
 * Add one or more rows after the current row.
 */
void Document::append()
{
    vector<string> anotherVector = getInput(); // All the strings the user want to add

    //add the strings to the document vector
    this->document.insert(this->document.begin()+this->currentLine+1,anotherVector.begin(),anotherVector.end());

    //update currentLine and numberOfTotalLines
    this->currentLine = this->currentLine+anotherVector.size();
    this->numberOfTotalLines = this->numberOfTotalLines+anotherVector.size();
}

/**
 * Add one or more rows before the current row.
 */
void Document::insert()
{
    vector<string> anotherVector = getInput(); // All the strings the user want to add

    //add the strings to the document vector
    std::vector<string>::iterator it;
    if(this->currentLine == -1||this->currentLine == 0)
    {
        it = this->document.begin();
    }
    else
    {
        it = this->document.begin()+this->currentLine;
    }
    this->document.insert(it,anotherVector.begin(),anotherVector.end());

    //update currentLine
    if(currentLine<0) currentLine =0;
    else if(currentLine>document.size()-1) currentLine =document.size()-1;
    else this->currentLine = this->currentLine+anotherVector.size()-1;

    //update numberOfTotalLines
    this->numberOfTotalLines = this->numberOfTotalLines+anotherVector.size();
}

/**
 * Replace the current row with one or more rows.
 */
void Document::replaceLines()
{
    vector<string> anotherVector = getInput(); // All the strings the user want to add

    //add the strings to the document vector
    this->document.insert(this->document.begin()+this->currentLine,anotherVector.begin(),anotherVector.end());
    this->document.erase(this->document.begin()+currentLine+anotherVector.size());

    //update currentLine and numberOfTotalLines
    this->currentLine = this->currentLine-1+anotherVector.size();
    this->numberOfTotalLines = this->numberOfTotalLines-1+anotherVector.size();
    printCurrentLine();
}

/**
 * Delete the current line.
 */
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

/**
 * Look forward starting from the next line (after the current one) that contains the text string.
 * If not found, go to row 1 and continue searching forward to (inclusive) to the current row.
 * The first row found in the search becomes the current row.
 * @param str - Text to look for in a document
 */
void Document::searchText(string str)
{
    bool flag= true;
    regex toFine(str);
    smatch sm;

    //look in [currentLine+1, end] -> If we found we were done
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

    // We did not find or there is no next row because we started from the last row, so we will search in  [0,currentLine]
    if(flag || this->currentLine+1 > this->numberOfTotalLines-1)
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
    if(flag) //not found at all the document
    {
        cout << "?\n";
    }
}

/**
 * Replace the first instance of the old string with the new string in the current row.
 * @param oldWord
 * @param newWord
 */
void Document::replaceWord(string oldWord, string newWord)
{
    regex toFine (oldWord);
    bool flag = true;
    for (int i=0; i< this->numberOfTotalLines & flag; i++)
    {
        string original = this->document.at(i);
        if(regex_replace(this->document.at(i),toFine,newWord,std::regex_constants::format_first_only).compare(original) != 0)
        {
            this->document.at(i) = regex_replace(this->document.at(i),toFine,newWord,std::regex_constants::format_first_only);
            this->currentLine = i;
            printCurrentLine();
            flag = false;
        }
    }
    if(flag)
    {
        cout<<"?\n";
    }
}

/**
 * Connect the current line with the line following it.
 */
void Document::joinLines()
{

    if(currentLine!=numberOfTotalLines-1) //not the last line
    {
        replace(this->document.begin()+currentLine,this->document.begin()+currentLine+1,this->document.at(currentLine),this->document.at(currentLine)+this->document.at(currentLine+1));
        this->document.erase(this->document.begin()+currentLine+1);
        numberOfTotalLines--;
    }
    else
    {
        cout << "?\n";
    }
}

/**
 * Write the document to the file.
 * @param nameOfFile
 */
void Document::writeToFile(string nameOfFile)
{
    ofstream file(nameOfFile);
    for(int i = 0; i< this->numberOfTotalLines; i++)
    {
        file<< this->document.at(i)<<endl;
    }

    file.close();
}

/**
 * Updating currentLine
 * @param numOfLine
 */
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
