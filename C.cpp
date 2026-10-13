#include <iostream>

bool CalcClear(char**& massive) {
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 10; ++j) {
      massive[i][j] = ' ';
    }
  }
  return true;
}

bool CalcPut(char**& massive) {
  int x;
  int y;
  char c;
  std::cin >> x;
  std::cin >> y;
  std::cin >> c;
  if (x <= 9 && x >= 0 && y >= 0 && y <= 4) {
    massive[y][x] = c;
    return true;
  }
  return false;
}

bool CalcText(char**& massive) {
  int x;
  int y;
  std::string str;
  std::cin >> x;
  std::cin >> y;
  std::cin >> str;
  if (10 - x < str.size()) {
    return false;
  }
  for (size_t i = 0; i < str.size(); ++i) {
    massive[y][x + i] = str[i];
  }
  return true;
}

bool CalcPrint(char**& massive) {
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 10; ++j) {
      std::cout << massive[i][j];
    }
    std::cout << "\n";
  }
  return true;
}

int main() {
  char** massive = new char*[5];
  for (int i = 0; i < 5; ++i) {
    massive[i] = new char[10];
  }
  std::string* table_name = new std::string[4]{
    "clear", "put", "text", "print"
  };
  bool (**table_func)(char**&) = new (bool (*[4])(char**&)) {
    CalcClear, CalcPut, CalcText, CalcPrint
  };
  std::string command;
  std::cin >> command;
  while (command != "quit") {
    bool error = true;
    for (int i = 0; i < 4; ++i) {
      if (table_name[i] == command) {
        if (!table_func[i](massive)) {
          std::cout << "error" << "\n";
        }
        error = false;
      }
    }
    if (error) {
      std::cout << "error" << "\n";
    }
    std::cin >> command;
  }
}