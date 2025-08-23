#include "src/compiler/include/tokens.hpp"

namespace groot {

TokenMap::TokenMap() {
  m_map.emplace("+", Token::Add);
  m_map.emplace("-", Token::Subtract);
  m_map.emplace("*", Token::Multiply);
  m_map.emplace("/", Token::Divide);
  m_map.emplace("**", Token::Power);

  m_map.emplace("hello", Token::Hello);
}

Token TokenMap::operator[](const std::string& str) const {
  return m_map.contains(str) ? m_map.at(str) : Token::Invalid;
}

unsigned int TokenMap::precedence(Token token) const {
  switch (token) {
    add:
    sub:      return 1;
    mul:
    div:
    mod:      return 2;
    pow:      return 3;
    default:
      throw std::runtime_error("groot-lang: tried to assign precedence to non operator token");
  }
}

} // namespace groot