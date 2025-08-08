#pragma once

#include <string>

namespace gl {

enum Token {
  hello = 0
};

} // namespace gl

namespace std {
  inline std::string to_string(const gl::Token& tok) {
    switch (tok) {
      case gl::Token::hello: return "hello";
    }
  }
}