//Waheed Gulzar 22i2526 SE-A

#include <iostream>
#include <windows.h>
#include <conio.h>
#include"Header.h"

using namespace std;
int main() 
{
    
    Highest obj[10];
    int count = 1;
    Graph p(100);
    string name;
    int initial = 0;
    int &score=initial;
    int selectedOption = 0;
    bool s = false;
    int start,end;
    while (true) {
        menu(selectedOption);

        char key = _getch();
        // Use _getch() to get a character without waiting for Enter

        switch (key) {
        case 72:
            // Up arrow key
            selectedOption = (selectedOption - 1 + 4) % 4;
            break;
        case 80:
            // Down arrow key
            selectedOption = (selectedOption + 1) % 4;
            break;
        case 13: // Enter key
            // Process the selected option
            system("cls");
            cout << "You selected: ";
            switch (selectedOption) {
            case 0:
                cout << "Start Game\n\n";
                selectedOption = 0;
                while (true) {
                    GameMenu(selectedOption);

                    char key = _getch();
                    // Use _getch() to get a character without waiting for Enter

                    switch (key) 
                    {
                    case 72:
                        // Up arrow key
                        selectedOption = (selectedOption - 1 + 4) % 4;
                        break;
                    case 80:
                        // Down arrow key
                        selectedOption = (selectedOption + 1) % 4;
                        break;
                    case 13: // Enter key
                        // Process the selected option
                        system("cls");
                        cout << "You selected: ";
                        switch (selectedOption)
                        {
                        case 0:
                            cout << "Manual\n\n";
                            cout << "Enter Your Name : ";
                            cin >> name;
                            do {
                                cout << "Enter Start Point(1-100): ";
                                cin >> start;
                                p.set_count(start-1);
                                cout << "Enter End Point(1-100: ";
                                cin >> end;
                            } while (start == end);
                            p.Nodes_Connections();
                            // p.printWeightedGraph();
                             // p.displayGraph();
                            while (true) {
                                if (p.Check_If_End(end))
                                {
                                    fileWriting(name, score);
                                    setTextColor(FOREGROUND_RED);
                                    cout << "congrats!! You Won!!!\n";
                                    system("pause");
                                    break;
                                }
                                p.displayGraph(count, end);

                                char key = _getch();

                                if (key == 27)  // ASCII code for escape key
                                    break;

                                count = p.move(key, count, score);
                                // cout << count;
                            }

                            break;
                        case 1:
                            cout << "Auto Matic\n\n";
                            break;
                        case 2:
                            cout << "Resume\n\n";
                            break;
                        case 3:
                            cout << "Back\n\n";
                             s = true;
                            break;

                            cout << "\n";
                            system("pause"); // Pause to show the result, you can replace it with your logic
                            break;
                        }
                    }
                    if (s)
                        break;
                }
                break;
           
            case 1:
                cout << "Players' Score\n\n";
                fileReading(obj,0);
                break;
            case 2:
                cout << "Leader Board\n\n";
                fileReading(obj, 1);
                break;
            case 3:
                cout << "Help\n";

                break;
            }
            cout << "\n";
            system("pause"); // Pause to show the result, you can replace it with your logic
            break;
        }

    }
    return 0;
}