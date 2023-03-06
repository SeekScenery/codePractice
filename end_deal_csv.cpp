#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <deque>

using namespace std;

string getItemFromLine(string line, int col)
{
    std::istringstream sin; // 将整行字符串line读入到字符串istringstream中  然后再一个一个读出来
    string word;            // 单个元素
    sin.str(line);

    int col_index = 0;
    while (std::getline(sin, word, ',')) // 将字符串流sin中的字符读到field字符串中，以逗号为分隔符
    {
        // 判断是不是 需要的位置元素
        if (col_index == col)
            return word;
        col_index++;
    }
    return "0";
}

vector<string> dealVecLines(vector<string> &dealVec)
{
    std::istringstream sin;     // 将整行字符串line读入到字符串istringstream中  然后再一个一个读出来
    vector<string> write_words; // 存放补齐后的一行元素  元素为string类型
    string word;                // 单个元素
    sin.str(dealVec[1]);
    int col_index = 0;
    bool flag = true;                    // 取一行的元素 还下一行(第3行) true 为上一行（第一行）
    while (std::getline(sin, word, ',')) // 将字符串流sin中的字符读到field字符串中，以逗号为分隔符
    {
        // 判断是不是要处理的 imu 数据  通过col_index
        if (col_index >= 0 && col_index < 12)
        {
            if (word == " ")
            {
                if (flag)
                    word = getItemFromLine(dealVec[0], col_index);
                else
                    word = getItemFromLine(dealVec[2], col_index);
                flag = !flag;
            }
        }
        col_index++;
        write_words.push_back(word);
    }
    return write_words;
}

int main()
{
    string read_file_path = "./read_data.csv";
    string write_file_path = "./out_data.csv";
    std::ofstream outFile;
    vector<string> write_words; // 存放补齐后的一行元素  元素为string类型
    outFile.open(write_file_path, std::ios::out | std::ios::trunc);

    std::ifstream inFile(read_file_path, std::ios::in);
    std::istringstream sin; // 将整行字符串line读入到字符串istringstream中  然后再一个一个读出来
    string read_line;

    if (!inFile.is_open()) // 判断文件是否被打开
    {
        std::cout << "Error: opening file fail" << std::endl;
        std::exit(1);
    }

    // 读取标题行 如果有的标题话 读取标题 并将标题写入文件
    std::getline(inFile, read_line);
    outFile << read_line << std::endl;

    vector<string> vec_lines;
    string dealEndLine;
    
    while (true)
    {
        vec_lines.clear();
        for (int i = 0; i < 3; i++)
        {
            if (std::getline(inFile, read_line))
                vec_lines.push_back(read_line);
        }
        if (vec_lines.size() != 3)
            break;

        write_words = dealVecLines(vec_lines); // 写一个处理这个3行的函数
        // 将处理好的数据写入文件中
        for(string word: write_words)
        {
            outFile << word << ",";
        }
        outFile << std::endl;
    }

    inFile.close();
    outFile.close();
}
