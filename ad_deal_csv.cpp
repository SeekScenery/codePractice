/*
处理 csv 文件 
用下面的元素填充缺失的元素
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <deque>

using namespace std;

// 从一行中读取指定元素
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

int main()
{
    string read_file_path = "./read_data.csv";
    string write_file_path = "./out_data.csv";
    vector<string> write_words; // 存放补齐后的一行元素  元素为string类型
    std::ofstream outFile;
    outFile.open(write_file_path, std::ios::out | std::ios::trunc);

    std::ifstream inFile(read_file_path, std::ios::in);
    std::istringstream sin; // 将整行字符串line读入到字符串istringstream中  然后再一个一个读出来
    string read_line;
    string current_deal_line;
    std::deque<string> read_lines; // 定义一个队列存放多行数据  作为待处理队列
    string word; // 单个元素

    if (!inFile.is_open()) // 判断文件是否被打开
    {
        std::cout << "Error: opening file fail" << std::endl;
        std::exit(1);
    }

    // 读取标题行 如果有的标题话 读取标题 并将标题写入文件
    std::getline(inFile, read_line);
    outFile << read_line << std::endl;

    // 定义处理的数据是 第几列
    int col_index;

    while (!read_lines.empty() || std::getline(inFile, read_line))
    {
        if (read_lines.empty())
            read_lines.push_back(read_line);

        current_deal_line = read_lines.front();   // 从队列中取出最前面的元素 作为当前要处理的元素
        read_lines.pop_front();   // 从队列中删除正在处理的元素 

        sin.clear();
        sin.str(current_deal_line);
        write_words.clear();
        col_index = 0;

        // 读取一行元素
        while (std::getline(sin, word, ',')) // 将字符串流sin中的字符读到field字符串中，以逗号为分隔符
        {
            // 判断是不是要处理的 imu 数据  通过col_index
            if (col_index >= 0 && col_index < 12)
            {
                // 判断word是不是空
                if (word == " ")
                {
                    string temp_line;
                    // 如果是空 从队列中找替补元素  遍历队列中的所有元素
                    for (int i = 0; i < read_lines.size(); i++)
                    {
                        temp_line = read_lines.at(i);  
                        word = getItemFromLine(temp_line, col_index); 
                        if (word != " ")
                            break;
                    }

                    // 如果队列中没有找到替补元素，则从 文件流中(inFile) 中读取新的行，从新的行中寻找替补元素。并将新行添加到待处理队列中（read_lines）
                    while (word == " " && std::getline(inFile, read_line))
                    {
                        read_lines.push_back(read_line); // 并将新行添加到待处理队列中（read_lines）
                        word = getItemFromLine(read_line, col_index);
                    }
                }
            }

            write_words.push_back(word); // 存储处理好元素
            col_index++;
        }

        // 将处理好的数据写入文件中
        for (string word : write_words)
        {
            outFile << word << ",";
        }
        outFile << std::endl;
    }

    inFile.close();
    outFile.close();
}
