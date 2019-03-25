#include "strview.h"

using namespace dodo;
strview::strview(const std::string &str) : src_{str.data()}, pos_{0}, len_{str.length()}{}

strview::strview(const std::string &str, size_t pos, size_t len) : src_{str.data()}, pos_{pos} {
  if (pos_ < 0) {
    pos_ = 0;
  }
  if (pos_>= str.length()) {
    pos_ = str.length() - 1;
  }

  if (len_ < 1) {
    len_ = 1;
  }
  if (len_ > str.length() - pos_) {
    len_ = str.length() - pos_;
  }
}


strview::operator std::string() const  {
  return src_;
}

strview::strview(const strview &rhs) : src_{rhs.src_}, pos_{rhs.pos_}, len_{rhs.len_} {

}

strview strview::operator=(const strview &rhs) const  {
  return strview(rhs);
}

const strview &strview::sub_strview(size_t pos, size_t len) const {
  return strview(src_, pos_+ pos, len);
}

std::ostream &dodo::operator<<(std::ostream &os, const strview &sv) {
  for (int i = sv.pos_; i < sv.len_ + sv.pos_; i++) {
    os << sv.src_[i];
  }
  return os;
}
