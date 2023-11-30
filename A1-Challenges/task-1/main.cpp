#include <iostream>
std::string getTitleScreen() { //Return string, can be called in multiple areas
    //Using "R" to create a "Raw String Literal", allowing all data to be formatted in a more approiate and readable manner
    const char* title = R"( 
    db   db d88888b db      db       .d88b.    db   d8b   db  .d88b.  d8888b. db      d8888b. 
    88   88 88'     88      88      .8P  Y8.   88   I8I   88 .8P  Y8. 88  `8D 88      88  `8D 
    88ooo88 88ooooo 88      88      88    88   88   I8I   88 88    88 88oobY' 88      88   88 
    88~~~88 88~~~~~ 88      88      88    88   Y8   I8I   88 88    88 88`8b   88      88   88 
    88   88 88.     88booo. 88booo. `8b  d8'   `8b d8'8b d8' `8b  d8' 88 `88. 88booo. 88  .8D 
    YP   YP Y88888P Y88888P Y88888P  `Y88P'     `8b8' `8d8'   `Y88P'  88   YD Y88888P Y8888D' 
    )";
    return title;
}
int main() {
    std::cout << getTitleScreen(); //Print title 
}