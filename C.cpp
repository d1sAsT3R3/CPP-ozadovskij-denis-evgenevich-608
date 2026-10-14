#include <iostream>

bool CalcCommand(const char* a, const char* b) {
  while (*a && *b && *a == *b) {
    ++a;
    ++b;
  }
  if (*a == *b) {
    return true;
  }
  return false;
}

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
  char str[100];
  std::cin >> x;
  std::cin >> y;
  std::cin >> str;
  int len = 0;
  while (str[len]) {
    ++len;
  }
  if (10 - x < len) {
    return false;
  }
  for (int i = 0; i < len; ++i) {
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
  const char** table_name = new const char*[4]{"clear", "put", "text", "print"};
  bool (**table_func)(char**&) =
      new (bool (*[4])(char**&)){CalcClear, CalcPut, CalcText, CalcPrint};
  char command[100];
  while (std::cin >> command && !CalcCommand(command, "quit")) {
    bool error = true;
    for (int i = 0; i < 4; ++i) {
      if (CalcCommand(table_name[i], command)) {
        if (!table_func[i](massive)) {
          std::cout << "error" << "\n";
        }
        error = false;
      }
    }
    if (error) {
      std::cout << "error" << "\n";
    }
  }
  for (int i = 0; i < 5; ++i) {
    delete[] massive[i];
  }
  delete[] massive;
  delete[] table_name;
  delete[] table_func;
}