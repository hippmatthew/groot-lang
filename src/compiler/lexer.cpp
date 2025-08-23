#include "src/compiler/include/lexer.hpp"

#include <fstream>
#include <stdexcept>
#include <sstream>

namespace groot {

Lexer::Lexer(const std::string& source_path, const TokenMap& tokenMap) {
  std::ifstream file(source_path);
  if (!file) throw std::runtime_error("groot-lang: lexer could not open file");

  std::string line, token;
  std::size_t lineNum = 0;
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    while (ss >> token)
      m_tokens.emplace_back(Data{ tokenMap[token], token, lineNum });
    ++lineNum;
  }
}

std::vector<Lexer::Data>::const_iterator Lexer::begin() const {
  return m_tokens.begin();
}

std::vector<Lexer::Data>::const_iterator Lexer::end() const {
  return m_tokens.end();
}

} // namespace groot