#include <iostream>
#include "Editor.h"
#include <iostream>
#include <string>
#include <regex>
int main(int argc, char **argv) {

//    string path = "C:/Users/TOMLA/CLionProjects/ed/pome.txt";
//    Editor edir(path);
//    edir.loop();

    switch (argc) {
        case 1:
        {
            Editor editor;
            editor.loop();
            break;
        }
        case 2:
        {
            const char *fileName = argv[1];
            Editor editor(fileName);
            editor.loop();
            break;
        }
    }

    return 0;

}
