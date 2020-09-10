#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

////// DATA DIVISION //////

bool running;
bool proc_running;
int opt;
string b_opt;

vector<int> opt_list;
map<string, bool> b_opt_map = {{"Y", true}, {"y", true}, 
                               {"N", false}, {"n", false}};

int game_mode;
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

void print_board(vector<vector<string>> p_board)
{
    for (int i = 0; i < p_board.size(); i++)
    {
        cout << "::::    ";
        for (int j = 0; j < p_board[i].size(); j++) { cout << p_board[i][j]; }
        cout << "    ::::" << endl;
    }
}

void print_pcap()
{
    cout << "::::    White - Pieces Captured: ";
    for (int i = 0; i < pcap_white.size(); i++) { cout << pcap_white[i] << " "; }
    cout << endl << "::::    Black - Pieces Captured: ";
    for (int i = 0; i < pcap_black.size(); i++) { cout << pcap_black[i] << " "; }
    cout << endl;
}

////// ////// MENU RENDERING

void main_render(int scr)
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
        case 3:
            clearscr();
            cout << endl;
            cout << "::::" << endl;
            cout << "::::" << endl;
            cout << "::::" << endl;
            cout << "::::" << endl;
            cout << endl;
            cout << "Are you sure you want to quit? (Y/N) ";
            cin >> b_opt;
            if (b_opt == "Y" || b_opt == "y") { running = false; }
        default:
            break;
    }
}

void start_render(int scr)
{
    switch(scr)
    {
        case 0:
            clearscr();
            cout << endl;
            cout << "::::" << endl;
            cout << "::::    Start Game / Game Mode" << endl;
            cout << "::::" << endl;
            cout << "::::    Choose Game Mode:" << endl;
            cout << "::::    1. Regular Game" << endl;
            cout << "::::    2. Sandbox Game (WIP)" << endl;
            cout << "::::" << endl;
            cout << endl;
            cout << endl;
            cout << "Select: ";
            cin >> game_mode;
        case 1:
            clearscr();
            cout << endl;
            cout << "::::" << endl;
            cout << "::::    Start Game / Players" << endl;
            cout << "::::" << endl;
            cout << "::::    Player 1 (White): " << endl;
            cout << "::::    Player 2 (Black): " << endl;
            cout << "::::" << endl;
            cout << endl;
            cout << endl;
            cout << "Enter Player 1: ";
            cin >> white_n;
        case 2:
            clearscr();
            cout << endl;
            cout << "::::" << endl;
            cout << "::::    Start Game / Players" << endl;
            cout << "::::" << endl;
            cout << "::::    Player 1 (White): " << white_n << endl;
            cout << "::::    Player 2 (Black): " << endl;
            cout << "::::" << endl;
            cout << endl;
            cout << endl;
            cout << "Enter Player 2: ";
            cin >> black_n;
        case 3:
            clearscr();
            cout << endl;
            cout << "::::" << endl;
            cout << "::::    Start Game / Players" << endl;
            cout << "::::" << endl;
            cout << "::::    Player 1 (White): " << white_n << endl;
            cout << "::::    Player 2 (Black): " << black_n << endl;
            cout << "::::" << endl;
            cout << endl;
            cout << endl;
            cout << "Start Game with these settings? (Y/N) ";
            cin >> b_opt;
            break;
            if (b_opt == "Y" || b_opt == "y") { proc_running = false; }
        default:
            break;
        
    }
}

void cont_render(int scr)
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

////// ////// GAME RENDERING

void game_render(int scr)
{
    switch(scr)
    {
        case 0:
            clearscr();
            print_board(board);
            cout << "::::" << endl;
            cout << "::::" << endl;
            cout << "::::    " << white_n << " - " << black_n << endl;
            cout << "::::" << endl;
            print_pcap();
            cout << "::::" << endl;
            cout << "::::" << endl;
            break;
        case 1:
            break;
        default:
            break;
    }
}

////// ////// GAME ARRANGEMENT

void game_arrng()
{
    
}

////// ////// MENU ARRANGEMENT

void menu_arrng()
{
    main_render(1);
    switch(opt)
    {
        case 1:
            proc_running = true;
            while (proc_running) { start_render(0); }
            break;
        case 2:
            proc_running = true;
            while (proc_running) { cont_render(0); }
            break;
        case 3:
            proc_running = true;
            while (proc_running) { help_render(0); }
            break;
        case 4:
            main_render(2);
            break;
        case 5:
            main_render(3);
            break;
    }
}

////// PROCEDURAL DIVISION //////

int main()
{
    main_render(0);
    running = true;
    while (running) { menu_arrng(); }
    return 0;
}
