#include <iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<vector>

bool is_palindrome(const std::string& str, size_t start, size_t end)
{
    while (start < end)
    {
        if (str[start] != str[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

std::string findLongestPalindrome(const std::string& line)
{
    if (line.empty())
    {
        return "";
    }

    size_t max_length = 1;
    size_t start_index = 0;
    size_t n = line.length();

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i; j < n; j++)
        {
            if (is_palindrome(line, i, j))
            {
                size_t current_length = j - i + 1;
                if (current_length > max_length)
                {
                    max_length = current_length;
                    start_index = i;
                }
            }
        }
    }
    return line.substr(start_index, max_length);
}



size_t find_max_palindrome_length(const std::vector<std::string>& lines)
{
    size_t max = 0;
    for (size_t i = 0; i < lines.size(); ++i) {
        size_t currlength = findLongestPalindrome(lines[i]).length();
        if (currlength > max) {
            max = currlength;
        }
    }
    return max;
}
std::vector<std::string> find_lines_with_max_palindrome(const std::vector<std::string>& lines, size_t max_length) {
    std::vector<std::string> result;
    size_t count = 0;
    for (size_t i = 0; i < lines.size(); ++i) {
        size_t curr_length = findLongestPalindrome(lines[i]).length();
        if (curr_length == max_length) {
            if (count >= 10)
            {
                return result;
            }

            count++;
            result.push_back(lines[i]);

        }
    }
    return result;
}


void print_result(const std::vector<std::string>& result, const int& max_length) {
    std::cout << "Max palindrome length: " << max_length << std::endl;
    std::cout << "Result: " << std::endl;
    for (size_t i = 0; (i < result.size()); ++i) {
        if (result[i].size() == max_length) {
            std::cout << result[i] << std::endl;
        }
    }
}


int main()
{
    std::ifstream file("input.txt");
    if (file.is_open())
    {
        if (!(file.peek() == EOF))
        {
            std::vector<std::string> Lines;
            std::string Line;

            while (std::getline(file, Line))
            {
                Lines.push_back(Line);
            }
            file.close();
            size_t max_length = find_max_palindrome_length(Lines);
            if (max_length <= 1)
            {
                std::cout << "No Palindromes in the file!";
                return 0;
            }
            print_result(find_lines_with_max_palindrome(Lines, max_length), max_length);


        }

        else
        {
            std::cout << "Error!!!Empty file!";
            file.close();
        }
    }
    else std::cout << "Error!!! File isn't open!";


    return 0;
}