#pragma once

#include "src/compiler/include/tokens.hpp"

#include <string>
#include <tuple>
#include <vector>

namespace groot {

class Lexer {
  using Data = std::tuple<Token, std::string, std::size_t>;

  std::vector<Data> m_tokens;

  public:
    Lexer(const std::string&, const TokenMap& map = TokenMap());
    Lexer(const Lexer&) = default;
    Lexer(Lexer&&) = default;

    ~Lexer() = default;

    Lexer& operator=(const Lexer&) = default;
    Lexer& operator=(Lexer&&) = default;

    std::vector<Data>::const_iterator begin() const;
    std::vector<Data>::const_iterator end() const;
};

} // namespace groot