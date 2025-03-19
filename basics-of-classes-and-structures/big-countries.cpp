#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

struct Country {
    std::string name;
    long long population;
    double area;
};

int main() {
    std::ifstream file("input.txt");
    std::ofstream output("output.txt");
    std::string line;
    std::vector<std::string> result;

    // Пропускаем заголовок
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, region, populationStr, areaStr, gdp, literacy;
        std::getline(ss, name, ';');
        std::getline(ss, region, ';');
        std::getline(ss, populationStr, ';');
        std::getline(ss, areaStr, ';');
        std::getline(ss, gdp, ';');
        std::getline(ss, literacy, ';');

        long long population = std::stoll(populationStr);
        double area = std::stod(areaStr);

        if (area > 3000000 || population >= 25000000) {
            result.push_back(name);
        }
    }

    // Сортируем страны в алфавитном порядке
    std::sort(result.begin(), result.end());

    // Записываем в output.txt
    for (const auto& country : result) {
        output << country << std::endl;
    }

    return 0;
}