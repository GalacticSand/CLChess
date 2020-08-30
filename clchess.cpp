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
vector<vector<string>> blank_board = {{"    ", "| A|", "| B|", "| C|", "| D|", "| E|", "| F|", "| G|", "| H|"}, 
                                      {"| 8|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]"}, 
                                      {"| 7|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]"}, 
                                      {"| 6|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]"}, 
                                      {"| 5|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]"}, 
                                      {"| 4|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]"}, 
                                      {"| 3|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]"}, 
                                      {"| 2|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]"}, 
                                      {"| 1|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]"}};
vector<vector<string>> def_board = {{"    ", "| A|", "| B|", "| C|", "| D|", "| E|", "| F|", "| G|", "| H|"}, 
                                    {"| 8|", "[bR]", "[bN]", "[bB]", "[bQ]", "[bK]", "[bB]", "[bN]", "[bR]"}, 
                                    {"| 7|", "[bP]", "[bP]", "[bP]", "[bP]", "[bP]", "[bP]", "[bP]", "[bP]"}, 
                                    {"| 6|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]"}, 
                                    {"| 5|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]"}, 
                                    {"| 4|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]"}, 
                                    {"| 3|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]"}, 
                                    {"| 2|", "[wP]", "[wP]", "[wP]", "[wP]", "[wP]", "[wP]", "[wP]", "[wP]"}, 
                                    {"| 1|", "[wR]", "[wN]", "[wB]", "[wQ]", "[wK]", "[wB]", "[wN]", "[wR]"}};

vector<string> d_letter_map = {"A", "B", "C", "D", "E", "F", "G", "H"};
map<string, int> c_letter_map = {{"A", 1}, {"a", 1}, 
                                 {"B", 2}, {"b", 2}, 
                                 {"C", 3}, {"c", 3}, 
                                 {"D", 4}, {"d", 4}, 
                                 {"E", 5}, {"e", 5}, 
                                 {"F", 6}, {"f", 6}, 
                                 {"G", 7}, {"g", 7}, 
                                 {"H", 8}, {"h", 8}};
map<string, int> piece_map = {{"wP", 11}, {"bP", 21}, 
                              {"wR", 12}, {"bR", 22}, 
                              {"wN", 13}, {"bN", 23}, 
                              {"wB", 14}, {"bB", 24}, 
                              {"wQ", 15}, {"bQ", 25}, 
                              {"wK", 16}, {"bK", 26}};

// MACRO DIVISON

void init_opt(int p)
{
    opt = {};
    for (int i = 0; i < p; i++) { opt.push_back(i + 1); }
}

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
        cout << "Programmed by GalacticSand" << endl;
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
