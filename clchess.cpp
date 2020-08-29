#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

// DATA DIVISION

bool running;
int opt;
string b_opt;

string white_n;
string black_n;
vector<string> pcap_white;
vector<string> pcap_black;

vector<vector<string>> board;
vector<vector<string>> def_board = {{"   ", " A ", " B ", " C ", " D ", " E ", " F ", " G ", " H ", "   "}, 
                                    {" 8 ", "[r]", "[n]", "[b]", "[q]", "[k]", "[b]", "[n]", "[r]", " 8 "}, 
                                    {" 7 ", "[p]", "[p]", "[p]", "[p]", "[p]", "[p]", "[p]", "[p]", " 7 "}, 
                                    {" 6 ", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", " 6 "}, 
                                    {" 5 ", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", " 5 "}, 
                                    {" 4 ", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", " 4 "}, 
                                    {" 3 ", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", " 3 "}, 
                                    {" 2 ", "[P]", "[P]", "[P]", "[P]", "[P]", "[P]", "[P]", "[P]", " 2 "}, 
                                    {" 1 ", "[R]", "[N]", "[B]", "[Q]", "[K]", "[B]", "[N]", "[R]", " 1 "}, 
                                    {"   ", " A ", " B ", " C ", " D ", " E ", " F ", " G ", " H ", "   "}};

map<string, int> letter_map = {{"A", 1}, 
                               {"B", 2}, 
                               {"C", 3}, 
                               {"D", 4}, 
                               {"E", 5}, 
                               {"F", 6}, 
                               {"G", 7}, 
                               {"H", 8}};
map<string, int> piece_map = {{"P", 1}, {"p", 1}, 
                              {"R", 2}, {"r", 2}, 
                              {"N", 3}, {"n", 3}, 
                              {"B", 4}, {"b", 4}, 
                              {"Q", 5}, {"q", 5}, 
                              {"K", 6}, {"k", 6}};

// MACRO DIVISON

void clearscr() { cout << "\033[2J\033[1;1H"; }
void pausescr() { cin.get(); }

void renderscr(int scr)
{
    switch (scr)
    {
      case 1:
        cout << "::::" << endl;
        cout << "::::    Command Line Chess" << endl;
        cout << "::::" << endl;
        cout << "::::" << endl;
        cout << "::::    Version 1.0.0" << endl;
        cout << "::::    Copyright (C) 2020 - Galaxius Computer Software" << endl;
        cout << "::::" << endl;
        cout << endl;
        cout << endl;
        cout << "== Press Enter to Begin ==" << endl;
        break;
      case 2:
        cout << endl;
        cout << "Main Menu" << endl;
        cout << endl;
        cout << "1. Start New Game" << endl;
        cout << "2. Options" << endl;
        cout << "3. Credits" << endl;
        cout << "4. Quit" << endl;
        cout << endl;
        cout << endl;
        cout << "Select Option: ";
        break;
      case 3:
        cout << endl;
        cout << "" << endl;
        break;
      case 4:
        cout << endl;
        cout << "Game Credits" << endl;
        cout << endl;
        cout << "Command Line Chess" << endl;
        cout << "Copyright (C) 2020 - Galaxius Computer Software" << endl;
        cout << endl;
        cout << endl;
        cout << "== Press Enter to Continue ==" << endl;
        break;
      default:
        break;
    }
}

// PROCEDURAL DIVISION

int main()
{
    running = true;
    while (running) { }
    return 0;
}
