#include "src/compiler/include/tokens.hpp"
#include "src/compiler/include/lexer.hpp"

#include <iostream>
#include <string>

using namespace groot;

int main(int argc, char ** argv) {
  if (argc != 2) {
    std::cout << "correct usage: groot path/to/file.g\n";
    return 1;
  }

  Lexer lexer(argv[1]);

  std::size_t prevLine = 0;
  for (const auto& [token, lit, lineNum] : lexer) {
    if (prevLine != lineNum) {
      std::cout << '\n';
      prevLine = lineNum;
    }

    std::cout << lit << ' ';
  }
}