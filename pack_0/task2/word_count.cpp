#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std;

list <string> split(string line)
{
    list <string> words;
    string word;
    string::iterator p_letter;

    for (p_letter = line.begin(); p_letter != line.end(); ++p_letter)
    {
        if (!word.empty() && !isalnum(*p_letter))
        {
            words.push_back(word);
            word.clear();
        }
        else if (isalnum(*p_letter))
        {
            word += *p_letter;
        }
    }
    if (!word.empty())
    {
        words.push_back(word);
    }
    return words;
}

bool comp (int a, int b)
{
    return a > b;
}

int main(int argc, char **argv)
{
    ifstream input_file(argv[1]);
    if (!input_file.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    map <string, int> dictionary;
    int count_word = 0;
    string line;
    while(getline(input_file, line))
    {
        list <string> words = split(line);
        list <string> :: iterator p_word;

        for (p_word = words.begin(); p_word != words.end(); ++p_word)
        {
            if (dictionary.count(*p_word) == 0)
            {
                dictionary[*p_word] = 0;
            }
            dictionary[*p_word] += 1;
            ++count_word;
        }
    }

    vector <int> values;
    map <string, int> :: iterator it;
    for (it = dictionary.begin(); it != dictionary.end(); ++it)
    {
        int value = it->second;
        if (find(values.begin(), values.end(), value) == values.end())
        {
            values.push_back(value);
        }
    }
    sort(values.begin(), values.end(), comp);

    ofstream outfile;
    if (argc < 2)
        outfile.open("output.csv");
    else
        outfile.open(argv[2]);

    vector <int> :: iterator p_value;
    for (p_value = values.begin(); p_value != values.end(); ++p_value)
    {
        map <string, int> :: iterator p_word;
        for (p_word = dictionary.begin(); p_word != dictionary.end(); ++p_word)
        {
            if (*p_value == p_word->second)
            {
                double frequency = (*p_value) / (double)count_word * 100;
                outfile << p_word->first << "," << *p_value << "," << frequency << endl;
            }
        }
    }

    return 0;
}
