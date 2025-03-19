#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

struct RegionData {
    int totalCountries = 0;
    int highLiteracyCountries = 0;
};

int main() {
    std::ifstream file("input.txt");
    std::ofstream output("output.txt");
    std::string line;
    std::map<std::string, RegionData> regionStats;
    std::vector<std::string> result;
    double maxRatio = 0.0;

    // Пропускаем заголовок
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, region, population, area, gdp, literacyStr;
        std::getline(ss, name, ';');
        std::getline(ss, region, ';');
        std::getline(ss, population, ';');
        std::getline(ss, area, ';');
        std::getline(ss, gdp, ';');
        std::getline(ss, literacyStr, ';');

        double literacy = std::stod(literacyStr);

        // Обновляем статистику региона
        regionStats[region].totalCountries++;
        if (literacy > 90.0) {
            regionStats[region].highLiteracyCountries++;
        }
    }

    // Считаем максимальное соотношение
    for (const auto& [region, data] : regionStats) {
        double ratio = static_cast<double>(data.highLiteracyCountries) / data.totalCountries;
        if (ratio > maxRatio) {
            maxRatio = ratio;
            result.clear();
            result.push_back(region);
        } else if (ratio == maxRatio) {
            result.push_back(region);
        }
    }

    // Сортируем регионы в алфавитном порядке
    std::sort(result.begin(), result.end());

    // Записываем результат
    for (const auto& region : result) {
        output << region << std::endl;
    }

    return 0;
}
