#ifndef STRVIEW_H
#define STRVIEW_H

#include <string>
#include <ostream>
namespace dodo {
  class strview {
  public:
    strview(): src_{nullptr}, pos_{0}, len_{0} {}
    strview(const std::string &str);

    strview(const std::string &str, size_t pos, size_t len);

    strview(const strview &rhs);

    bool operator==(const strview& rhs);

    bool operator!=(const strview& rhs);



    strview operator=(const strview &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const strview &sv);

    operator std::string() const;

    const strview &sub_strview(size_t pos, size_t len) const;

  private:
    const char *src_;
    size_t pos_;
    size_t len_;

  };
}

#endif
