#pragma once

#include <map>
#include <string>

namespace groot {

enum Token {
  Invalid = -1,
  Hello,
  Variable,
  Literal,

  // -- types --
  Int,
  Uint,
  Float,
  Bool,
  String,
  Vec2,
  Vec3,
  Vec4,
  Mat2,
  Mat3,
  Mat4,
  Array,
  Map,
  Tuple,

  // -- operators --
  Add,      // +
  Subtract, // -
  Multiply, // *
  Divide,   // /
  Modulus,  // %
  Power,    // **
  Assign,   // =
  Typing,   // ->

  // -- symbols --
  OpenParen,
  CloseParen,
};

class TokenMap {
  std::map<std::string, Token> m_map;

  public:
    TokenMap();
    TokenMap(const TokenMap&) = default;
    TokenMap(TokenMap&&) = default;

    ~TokenMap() = default;

    TokenMap& operator=(const TokenMap&) = default;
    TokenMap& operator=(TokenMap&&) = default;

    Token operator[](const std::string&) const;

    unsigned int precedence(Token) const;
};

} // namespace groot