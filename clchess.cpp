#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

////// DATA DIVISION //////

bool running;
int opt;
string b_opt;

vector<int> opt_list;

string white_n;
string black_n;
vector<string> pcap_white;
vector<string> pcap_black;

vector<vector<string>> board;
vector<vector<string>> bsave;
vector<vector<string>> blank_board = {{"    ", "| A|", "| B|", "| C|", "| D|", "| E|", "| F|", "| G|", "| H|", "    "}, 
                                      {"| 8|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "| 8|"}, 
                                      {"| 7|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "| 7|"}, 
                                      {"| 6|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "| 6|"}, 
                                      {"| 5|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "| 5|"}, 
                                      {"| 4|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "| 4|"}, 
                                      {"| 3|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "| 3|"}, 
                                      {"| 2|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "| 2|"}, 
                                      {"| 1|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "| 1|"}, 
                                      {"    ", "| A|", "| B|", "| C|", "| D|", "| E|", "| F|", "| G|", "| H|", "    "}};
vector<vector<string>> def_board = {{"    ", "| A|", "| B|", "| C|", "| D|", "| E|", "| F|", "| G|", "| H|", "    "}, 
                                    {"| 8|", "[bR]", "[bN]", "[bB]", "[bQ]", "[bK]", "[bB]", "[bN]", "[bR]", "| 8|"}, 
                                    {"| 7|", "[bP]", "[bP]", "[bP]", "[bP]", "[bP]", "[bP]", "[bP]", "[bP]", "| 7|"}, 
                                    {"| 6|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "| 6|"}, 
                                    {"| 5|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "| 5|"}, 
                                    {"| 4|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "| 4|"}, 
                                    {"| 3|", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "[  ]", "| 3|"}, 
                                    {"| 2|", "[wP]", "[wP]", "[wP]", "[wP]", "[wP]", "[wP]", "[wP]", "[wP]", "| 2|"}, 
                                    {"| 1|", "[wR]", "[wN]", "[wB]", "[wQ]", "[wK]", "[wB]", "[wN]", "[wR]", "| 1|"}, 
                                    {"    ", "| A|", "| B|", "| C|", "| D|", "| E|", "| F|", "| G|", "| H|", "    "}};


vector<string> ptype_white = {"  ", "wP", "wR", "wN", "wB", "wQ", "wK"};
vector<string> ptype_black = {"  ", "bP", "bR", "bN", "bB", "bQ", "bK"};

vector<string> d_letter_map = {" ", "A", "B", "C", "D", "E", "F", "G", "H"};
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

////// MACRO DIVISON //////

////// ////// SCREEN MANIPULATION

void init_opt(int p)
{
    opt = {};
    for (int i = 0; i < p; i++) { opt_list.push_back(i + 1); }
}

void clearscr() { cout << "\033[2J\033[1;1H"; }
void pausescr() { cin.get(); }

////// ////// MENU RENDERING

void mainrender(int scr)
{
    switch (scr)
    {
        case 0:
            clearscr();
            cout << endl;
            cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout << "::::     ______    _         ______    ______    ______     ::::" << endl;
            cout << "::::    | |    |  | |    |  | |       | |    |  | |    |    ::::" << endl;
            cout << "::::    | |       | |____|  | |____   |_|____   |_|____     ::::" << endl;
            cout << "::::    | |       | |    |  | |        _     |   _     |    ::::" << endl;
            cout << "::::    |_|____|  |_|    |  |_|____   |_|____|  |_|____|    ::::" << endl;
            cout << "::::                                                        ::::" << endl;
            cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
            cout << endl;
            cout << endl;
            cout << "-- CLChess - Version 1.0.0" << endl;
            cout << "-- Galaxius Computer Software" << endl;
            cout << endl;
            cout << endl;
            cout << "== Press Enter to Begin ==" << endl;
            pausescr();
            break;
        case 1:
            init_opt(5);
            clearscr();
            cout << endl;
            cout << "::::" << endl;
            cout << "::::    Main Menu" << endl;
            cout << "::::" << endl;
            cout << "::::    1. Start Game" << endl;
            cout << "::::    2. Continue Game" << endl;
            cout << "::::    3. Help" << endl;
            cout << "::::    4. Credits" << endl;
            cout << "::::    5. Quit" << endl;
            cout << "::::" << endl;
            cout << endl;
            cout << endl;
            cout << "Select: ";
            cin >> opt;
            break;
        case 2:
            clearscr();
            cout << endl;
            cout << "::::    Game Credits" << endl;
            cout << "::::" << endl;
            cout << "::::    Command Line Chess (CLChess)" << endl;
            cout << "::::    Copyright (c) 2020 - Galaxius Computer Software" << endl;
            cout << "::::    Programmed by GalacticSand" << endl;
            cout << endl;
            cout << endl;
            cout << "== Press Enter to Continue ==" << endl;
            pausescr();
            break;
        default:
            break;
    }
}

void startgame_render(int scr)
{
    switch(scr)
    {
        case 0:
            clearscr();
            break;
        case 1:
            clearscr();
            break;
        default:
            break;
        
    }
}

void contngame_render(int scr)
{
    switch(scr)
    {
        case 0:
            break;
        default:
            break;
    }
}

void help_render(int scr)
{
    switch(scr)
    {
        case 0:
            break;
        default:
            break;
    }
}

////// ////// MENU ARRANGEMENT

////// PROCEDURAL DIVISION //////

int main()
{
    running = true;
    while (running) { }
    return 0;
}
