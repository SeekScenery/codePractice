#include<string>
using namespace std;


uint8_t board[19][19]{};

int evaluate_black(string &s) 
{
    string patterns[31] = {
            "B0000", "0B000", "00B00", "000B0", "0000B",
            "BB000", "0BB00", "00BB0", "000BB", "B0B00", "0B0B0", "00B0B", "B00B0", "0B00B", "B000B",
            "BBB00", "0BBB0", "00BBB", "BB0B0", "0BB0B", "B0BB0", "0B0BB", "BB00B", "B00BB", "B0B0B",
            "BBBB0", "BBB0B", "BB0BB", "B0BBB", "0BBBB", "BBBBB",
    };
    int32_t scores[31] = {
            1, 1, 1, 1, 1,
            10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
            100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
            10000, 10000, 10000, 10000, 10000, 1000000,
    };
    for (uint8_t i = 0; i < 31; i++)
        if (s == patterns[i]) return scores[i];
    return 0;
}

int evaluate_white(string &s) {
    string patterns[31] = {
            "W0000", "0W000", "00W00", "000W0", "0000W",
            "WW000", "0WW00", "00WW0", "000WW", "W0W00", "0W0W0", "00W0W", "W00W0", "0W00W", "W000W",
            "WWW00", "0WWW0", "00WWW", "WW0W0", "0WW0W", "W0WW0", "0W0WW", "WW00W", "W00WW", "W0W0W",
            "WWWW0", "WWW0W", "WW0WW", "W0WWW", "0WWWW", "WWWWW",
    };
    int32_t scores[31] = {
            1, 1, 1, 1, 1,
            10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
            1000, 2000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
            100000, 100000, 100000, 100000, 100000, 10000000,
    };
    for (int i = 0; i < 31; i++)
        if (s == patterns[i]) return scores[i];
    return 0;
}

static string convert(uint8_t pos) {
    if (pos == 0) return "0";
    if (pos == 'B') return "B"; else return "W";
}


uint8_t board_identify() {
    for (uint8_t i = 0; i < 19; i++)
        for (uint8_t j = 0; j < 19; j++) {
            if (j + 4 < 19) {
                string s;
                for (uint8_t k = 0; k < 5; k++) s += convert(board[i][j + k]);
                if (s == "BBBBB") return 'B';
                if (s == "WWWWW") return 'W';
            }
            if (i + 4 < 19) {
                string s;
                for (uint8_t k = 0; k < 5; k++) s += convert(board[i + k][j]);
                if (s == "BBBBB") return 'B';
                if (s == "WWWWW") return 'W';
            }
            if (i + 4 < 19 && j + 4 < 19) {
                string s;
                for (uint8_t k = 0; k < 5; k++) s += convert(board[i + k][j + k]);
                if (s == "BBBBB") return 'B';
                if (s == "WWWWW") return 'W';
            }
            if (i + 4 < 19 && j - 4 >= 0) {
                string s;
                for (uint8_t k = 0; k < 5; k++) s += convert(board[i + k][j - k]);
                if (s == "BBBBB") return 'B';
                if (s == "WWWWW") return 'W';
            }
        }
    return 0;
}


void evaluate() {
    int value = 0;
    for (uint8_t i = 0; i < 19; i++)
        for (uint8_t j = 0; j < 19; j++) {
            if (j + 4 < 19) {
                string s;
                for (uint8_t k = 0; k < 5; k++) s += convert(board[i][j + k]);
                value += evaluate_black(s) - evaluate_white(s);
            }
            if (i + 4 < 19) {
                string s;
                for (uint8_t k = 0; k < 5; k++) s += convert(board[i + k][j]);
                value += evaluate_black(s) - evaluate_white(s);
            }
            if (i + 4 < 19 && j + 4 < 19) {
                string s;
                for (uint8_t k = 0; k < 5; k++) s += convert(board[i + k][j + k]);
                value += evaluate_black(s) - evaluate_white(s);
            }
            if (i + 4 < 19 && j - 4 >= 0) {
                string s;
                for (uint8_t k = 0; k < 5; k++) s += convert(board[i + k][j - k]);
                value += evaluate_black(s) - evaluate_white(s);
            }
        }
}