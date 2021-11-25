using namespace std;

const char
*green = "\033[1;32m",
*yellow = "\033[1;33m",
*blue = "\033[1;34m",
*cyan = "\033[36m",
*red = "\033[31m",
*white = "\e[0m",
*reset = "\e[0m";

void Author_Stuffs(){
    cout << red << "\n[**] "<< cyan << "Author: AbdulRahman AbdulAzeez" << red << "  [**]\n" << red;
    cout << "[**] " << cyan << "Github: https://github.com/abdulrahmanabdulazeez" << red << "  [**]\n";
    #if defined(_WIN32)
    cout << "[**] " << cyan << "Special greetz to: Anonymous Hacks" << red << "  [**]";

    #else
    cout << "[**] " << cyan << "Special greetz to: Ãñøñymöus Hãçks" << red << "  [**]";
    #endif // defined
    cout << reset;
}

void header_Windows(){
    cout << green << "=============================\n\n";
    cout << cyan << "|| Port-Fin(Port Finder)   ||\n\n";
    cout << green << "=============================\n";
    Author_Stuffs();
}

void header_Unix(){
    cout << " 🔳🔳🔳                        🔳                 🔳🔳🔳            \n";
    cout << " 🔳   🔳    🔳🔳     🔳🔳🔳    🔳                🔳              \n";
    cout << " 🔳🔳🔳   🔳    🔳  🔳     🔳🔳🔳🔳🔳  ⬜🔳⬜🔳  🔳🔳🔳 🔘  🔳🔳🔳         \n";
    cout << " ⬜      ⬜      ⬜ ⬜         ⬜                ⬜     ⬜ ⬜    ⬜     \n";
    cout << " ⬜       ⬜    ⬜  ⬜         ⬜  ⬜            ⬜     ⬜ ⬜    ⬜      \n";
    cout << " ⬜	    ⬜⬜    ⬜          ⬜⬜             ⬜     ⬜ ⬜    ⬜  " << red << "[" << yellow << "V1.0" << red << "]\n";
    Author_Stuffs();
}
