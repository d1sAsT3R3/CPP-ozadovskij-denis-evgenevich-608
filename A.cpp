#include <iostream>

const double cPresicion = 10.0;
const int cBase = 10;

struct Temperatures {
  int minimum;
  int maximum;
};

float CalcMiddle(const int* massive_temperature, const int massive_size) {
  int summ{0};
  for (int i{0}; i < massive_size; ++i) {
    summ += massive_temperature[i];
  }
  summ *= cBase;
  return (summ / massive_size) / cPresicion;
}

Temperatures CalcMaxMin(const int* massive_temperature,
                        const int massive_size) {
  int minimum{massive_temperature[0]};
  int maximum{massive_temperature[0]};
  for (int i{1}; i < massive_size; ++i) {
    if (maximum < massive_temperature[i]) {
      maximum = massive_temperature[i];
    } else if (minimum > massive_temperature[i]) {
      minimum = massive_temperature[i];
    }
  }
  return {minimum, maximum};
}

int CalcFrostyDays(const int* massive_temperature, const int massive_size) {
  int counter{0};
  for (int i{1}; i < massive_size; ++i) {
    if (0 > massive_temperature[i]) {
      ++counter;
    }
  }
  return counter;
}

int main() {
  int number_of_days;
  std::cin >> number_of_days;
  int* massive_temperature = new int[number_of_days];
  int temperature;
  for (int i{0}; i < number_of_days; ++i) {
    std::cin >> temperature;
    massive_temperature[i] = temperature;
  }
  float middle{CalcMiddle(massive_temperature, number_of_days)};
  Temperatures temperature_day{CalcMaxMin(massive_temperature, number_of_days)};
  int frosty_days{CalcFrostyDays(massive_temperature, number_of_days)};
  std::cout << middle << "\n";
  std::cout << temperature_day.minimum << " " << temperature_day.maximum
            << "\n";
  std::cout << frosty_days << "\n";
  delete[] massive_temperature;
}