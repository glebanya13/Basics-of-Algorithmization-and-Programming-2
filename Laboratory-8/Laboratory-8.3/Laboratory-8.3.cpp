#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Функция для разделения стран на две группы
bool divideCountries(const vector<vector<int>>& adjacencyMatrix, vector<int>& groups) {
    int numCountries = adjacencyMatrix.size();
    vector<bool> visited(numCountries, false); // Флаги посещения стран
    vector<bool> colored(numCountries, false); // Флаги раскраски стран
    queue<int> q; // Очередь для обхода в ширину

    // Начинаем обход в ширину со случайной страны
    q.push(0);
    colored[0] = true; // Раскрашиваем первую страну

    while (!q.empty()) {
        int currentCountry = q.front();
        q.pop();
        visited[currentCountry] = true;

        for (int neighborCountry = 0; neighborCountry < numCountries; ++neighborCountry) {
            if (adjacencyMatrix[currentCountry][neighborCountry] == 1) {
                // Если смежная страна еще не раскрашена, раскрашиваем ее в противоположную группу
                if (!colored[neighborCountry]) {
                    colored[neighborCountry] = !colored[currentCountry];
                    groups[neighborCountry] = colored[neighborCountry] ? 1 : 2;
                }
                // Если смежная страна уже раскрашена и принадлежит той же группе, значит разделение невозможно
                else if (colored[neighborCountry] == colored[currentCountry]) {
                    return false;
                }
            }
            if (!visited[neighborCountry] && adjacencyMatrix[currentCountry][neighborCountry] == 1) {
                q.push(neighborCountry);
            }
        }
    }

    return true;
}

int main() {
    vector<vector<int>> adjacencyMatrix = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 0, 0, 1, 1},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    int numCountries = adjacencyMatrix.size();
    vector<int> groups(numCountries, 0); // Вектор для хранения принадлежности стран к группам

    if (divideCountries(adjacencyMatrix, groups)) {
        cout << "Страны успешно разделены на две группы." << endl;
        cout << "Группы стран:" << endl;
        for (int i = 0; i < numCountries; ++i) {
            cout << "Страна " << i << ": Группа " << groups[i] << endl;
        }
    }
    else {
        cout << "Невозможно разделить страны на две группы." << endl;
    }

    return 0;
}
