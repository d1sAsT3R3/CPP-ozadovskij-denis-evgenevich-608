#include <iostream>

bool CalcDeposit(int& moneybox) {
  int k;
  std::cin >> k;
  if (k <= 0) {
    return false;
  }
  moneybox += k;
  return true;
}

bool CalcWithdraw(int& moneybox) {
  int k;
  std::cin >> k;
  if (k <= 0) {
    return false;
  }
  if (moneybox < k) {
    return false;
  }
  moneybox -= k;
  return true;
}

bool CalcBalance(int& moneybox) {
  std::cout << moneybox << "\n";
  return true;
}

bool CalcReset(int& moneybox) {
  moneybox = 0;
  return true;
}

bool CaclInc(int& moneybox) {
  moneybox += 1;
  return true;
}

int main() {
  std::string command;
  std::cin >> command;
  int moneybox{0};
  int number;
  std::string* table_name = new std::string[5]{
    "deposit", "withdraw", "balance", "reset", "inc"
  };
  bool (**table_func)(int&) = new (bool (*[5])(int&)) {
    CalcDeposit, CalcWithdraw, CalcBalance, CalcReset, CaclInc
  };
  while (command != "stop") {
    bool error = true;
    for (int i{0}; i < 5; ++i) {
      if (table_name[i] == command) {
        if (!table_func[i](moneybox)) {
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
  delete[] table_name;
  delete[] table_func;
}