#include <iostream>

const int level = 3;
const int width = 4;
const int lenght = 5;

bool CalcCommand(const char* a, const char* b) {
  while (*a && *b && *a == *b) {
    ++a;
    ++b;
  }
  return *a == *b;
}

bool CalcPrint(void* data) {
  int*** office = (int***)data;
  for (int i = 0; i < level; ++i) {
    std::cout << "Level " << i + 1 << ":\n";
    for (int j = 0; j < width; ++j) {
      for (int k = 0; k < lenght; ++k) {
        std::cout << office[i][j][k] << " ";
      }
      std::cout << "\n";
    }
  }
  return true;
}

bool CalcReplace(void* data) {
  int*** office = (int***)data;
  int x;
  int y;
  int z;
  int new_pass;
  std::cin >> x >> y >> z >> new_pass;
  if (x < 0 || x >= level || y < 0 || y >= width || z < 0 || z >= lenght) {
    return false;
  }
  for (int i = 0; i < level; ++i) {
    for (int j = 0; j < width; ++j) {
      for (int k = 0; k < lenght; ++k) {
        if (office[i][j][k] == new_pass) {
          return false;
        }
      }
    }
  }
  office[x][y][z] = new_pass;
  return true;
}

int main() {
  // Пусть у нас есть 3 этажный надо, где каждый этаж по прямогугольник из 4 на
  // 5 кабинок
  //  надо рассадить людей, ровно 1 человека в ровно 1 кабинку сотрудника будем
  //  нумеровать по номеру пропуска тогда надо будет использовать int***, а
  //  чтобы узнать расписание, будем выводить массив, он будет типа и делаем
  //  новую функцию, заменить рабочего на номер пропуска другого, тогда у нас
  //  указатели на массив это  void*
  int*** office = new int**[level];
  for (int i = 0; i < level; ++i) {
    office[i] = new int*[width];
    for (int j = 0; j < lenght; ++j) {
      office[i][j] = new int[lenght];
    }
  }
  const char** table_name = new const char*[2]{"replace", "print"};
  bool (**table_func)(void*) = new (bool (*[2])(void*));
  table_func[0] = CalcReplace;
  table_func[1] = CalcPrint;
}