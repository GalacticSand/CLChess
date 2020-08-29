#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

bool running;

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

void clearscr() { cout << "" << endl; }
void pausescr() { cin.get(); }

int main()
{
    running = true;
    while (running) { }
    return 0;
}
