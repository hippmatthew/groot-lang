#include "src/compiler/include/tokens.hpp"
#include "src/engine/include/engine.hpp"

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

int main(int argc, char ** argv) {
  if (argc != 2) {
    std::cout << "correct usage: groot path/to/file.g\n";
    return 1;
  }

  std::ifstream file(argv[1]);
  if (!file) {
    std::cout << "failed to load file\n";
    return 1;
  }

  std::string line;
  while (std::getline(file, line)) {
    std::istringstream ss(line);
    std::string token;

    while (ss >> token) {
      if (token == std::to_string(gl::Token::hello))
        gl::helloworld();
    }
  }
}