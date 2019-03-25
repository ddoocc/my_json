#include "json.h"
#include "../strview/strview.h"

using namespace dodo;

enum token_type {
  js_start = '{',
  js_end = '}',
  jsarr_start = '[',
  jsarr_end = ']',
  js_key,
  js_num,
  js_bool
};

struct token {
  token(const token_type& ty, const strview& str);
  token_type type_;
  strview str_;
  union {
    double num_value;
    int bool_value;
  } value_;
};

class token_stream {
public:
  token_stream(const std::string& str);
  const token& get();

private:
  std::string src_;
  token cur_token_;
};


token::token(const token_type &ty, const strview &str) : type_{ty}, str_{str} {
  switch (type_) {
    case js_num:
      value_.num_value = std::stof(str);
      break;
    case js_bool:
      if (str == )
  }
}
