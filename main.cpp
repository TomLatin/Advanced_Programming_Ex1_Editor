#include "Editor.h"

int main(int argc, char **argv) {

    switch (argc) {
        case 1: // ed
        {
            Editor editor;
            editor.loop();
            break;
        }
        case 2: // ed name.txt
        {
            const char *fileName = argv[1];
            Editor editor(fileName);
            editor.loop();
            break;
        }
    }

    return 0;
}
