#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

////// DATA DIVISION //////

bool running, proc_running, game_running;
int opt;
string b_opt, s_move;

vector<int> opt_list;
map<string, bool> b_opt_map = {{"Y", true}, {"y", true}, 
                               {"N", false}, {"n", false}};

int game_mode;
string white_n, black_n;
vector<string> pcap_white, pcap_black;

string piece_moved, piece_taken, spot_a, spot_b;

string current;
vector<vector<string>> current_col = {{"GAME BOARD READY!"}, 
                                      {"WHITE", "AT", "SELECTED"}, 
                                      {"BLACK", "AT", "SELECTED"}, 
                                      {"MOVED WHITE", "FROM", "TO"}, 
                                      {"MOVED BLACK", "FROM", "TO"}, 
                                      {"WHITE", "CAPTURED AT"}, 
                                      {"BLACK", "CAPTURED AT"}};

vector<vector<string>> board, bsave;
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
vector<string> ptype_names = {"  ", "PAWN", "ROOK", "KNIGHT", "QUEEN", "KING"};

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
            cout << "-- CLCHESS - VERSION 1.0.0" << endl;
            cout << "-- GALAXIUS COMPUTER SOFTWARE" << endl;
            cout << endl;
            cout << endl;
            cout << "== PRESS ENTER TO BEGIN ==" << endl;
            pausescr();
            break;
        case 1:
            init_opt(5);
            clearscr();
            cout << endl;
            cout << "::::" << endl;
            cout << "::::    MAIN MENU" << endl;
            cout << "::::" << endl;
            cout << "::::    1. START GAME" << endl;
            cout << "::::    2. CONTINUE GAME" << endl;
            cout << "::::    3. HELP" << endl;
            cout << "::::    4. CREDITS" << endl;
            cout << "::::    5. QUIT" << endl;
            cout << "::::" << endl;
            cout << endl;
            cout << endl;
            cout << "SELECT: ";
            cin >> opt;
            break;
        case 2:
            clearscr();
            cout << endl;
            cout << "::::    GAME CREDITS" << endl;
            cout << "::::" << endl;
            cout << "::::    COMMAND LINE CHESS (CLCHESS)" << endl;
            cout << "::::    COPYRIGHT (c) 2020 - GALAXIUS COMPUTER SOFTWARE" << endl;
            cout << "::::    PROGRAMMED BY GALACTICSAND" << endl;
            cout << endl;
            cout << endl;
            cout << "== PRESS ENTER TO CONTINUE ==" << endl;
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
            cout << "ARE YOU SURE YOU WANT TO QUIT? (Y/N) ";
            cin >> b_opt;
            if (b_opt_map[b_opt]) { running = false; }
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
            cout << "::::    START GAME / GAME MODE" << endl;
            cout << "::::" << endl;
            cout << "::::    CHOOSE GAME MODE:" << endl;
            cout << "::::    1. REGULAR GAME" << endl;
            cout << "::::    2. SANDBOX GAME (WIP)" << endl;
            cout << "::::" << endl;
            cout << endl;
            cout << endl;
            cout << "SELECT: ";
            cin >> game_mode;
        case 1:
            clearscr();
            cout << endl;
            cout << "::::" << endl;
            cout << "::::    START GAME / PLAYERS" << endl;
            cout << "::::" << endl;
            cout << "::::    PLAYER 1 (WHITE): " << endl;
            cout << "::::    PLAYER 2 (BLACK): " << endl;
            cout << "::::" << endl;
            cout << endl;
            cout << endl;
            cout << "ENTER PLAYER 1: ";
            cin >> white_n;
        case 2:
            clearscr();
            cout << endl;
            cout << "::::" << endl;
            cout << "::::    START GAME / PLAYERS" << endl;
            cout << "::::" << endl;
            cout << "::::    PLAYER 1 (WHITE): " << white_n << endl;
            cout << "::::    PLAYER 2 (BLACK): " << endl;
            cout << "::::" << endl;
            cout << endl;
            cout << endl;
            cout << "ENTER PLAYER 2: ";
            cin >> black_n;
        case 3:
            clearscr();
            cout << endl;
            cout << "::::" << endl;
            cout << "::::    START GAME / PLAYERS" << endl;
            cout << "::::" << endl;
            cout << "::::    PLAYER 1 (WHITE): " << white_n << endl;
            cout << "::::    PLAYER 2 (BLACK): " << black_n << endl;
            cout << "::::" << endl;
            cout << endl;
            cout << endl;
            cout << "START GAME WITH THESE SETTINGS? (Y/N) ";
            cin >> b_opt;
            if (b_opt_map[b_opt]) 
            { 
                board = def_board;
                proc_running = false; 
            }
            break;
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
    cout << "::::    WHITE - PIECES CAPTURED: ";
    for (int i = 0; i < pcap_white.size(); i++) { cout << pcap_white[i] << " "; }
    cout << endl << "::::    BLACK - PIECES CAPTURED: ";
    for (int i = 0; i < pcap_black.size(); i++) { cout << pcap_black[i] << " "; }
    cout << endl;
}

void print_current(int msg)
{
    cout << "::::    ";
    switch(msg)
    {
        case 0:
            cout << current_col[0][0];
            break;
        case 1:
            break;
    }
    cout << endl;
}

void game_render(int scr)
{
    switch(scr)
    {
        case 0:
            bsave = board;
            clearscr();
            cout << "::::" << endl;
            print_board(board);
            cout << "::::" << endl;
            cout << "::::" << endl;
            cout << "::::    " << white_n << " - " << black_n << endl;
            cout << "::::" << endl;
            print_pcap();
            cout << "::::" << endl;
            print_current(0);
            cout << "::::" << endl;
            cout << endl;
            cout << "> ";
            cin >> s_move;
            break;
        case 1:
            break;
        default:
            break;
    }
}

////// ////// GAME MECHANICS

void move_piece(int sr, int sc, int dr, int dc)
{
    string cpiece = bsave[sr][sc];
    string dpiece = to_string(bsave[dr][dc].at(1));
    dpiece.append(to_string(bsave[dr][dc].at(2)));
    if (bsave[sr][sc] != "[  ]" && to_string(dpiece.at(0)) == "w") { pcap_black.push_back(dpiece); }
    else if (bsave[sr][sc] != "[  ]" && to_string(dpiece.at(0)) == "b") { pcap_white.push_back(dpiece); }
    bsave[sr][sc] = "[  ]";
    bsave[dr][dc] = cpiece;
}

////// ////// GAME ARRANGEMENT

void game_arrng()
{
    game_render(0);
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
            proc_running = true;
            while (proc_running) { game_arrng(); }
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
    clearscr();
    return 0;
}
