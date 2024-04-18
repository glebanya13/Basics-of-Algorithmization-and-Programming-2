#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream infile("FILE1.txt");
    ofstream outfile("FILE2.txt");
    string line;
    int wordCount = 0;

    while (getline(infile, line))
    {
        if (line[0] == 'A' || line[0] == 'a') // проверка первого символа
        {
            outfile << line << endl; // запись строки в FILE2
            // подсчёт количества слов
            bool inWord = false;
            for (char c : line)
            {
                if (isalpha(c) && !inWord)
                {
                    inWord = true;
                    wordCount++;
                }
                else if (!isalpha(c))
                {
                    inWord = false;
                }
            }
        }
    }

    cout << "Количество слов в FILE2: " << wordCount << endl;

    infile.close();
    outfile.close();

    return 0;
}
