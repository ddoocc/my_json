//
// Created by dodo on 2019-03-22.
//

#include <string>
#include <iostream>
#include "string_view"
#include "strview.h"

int main(void) {
  std::string aaa{"12345"};

  dodo::strview sv(aaa);

  std::cout << sv << std::endl;
  std::cout << sv.sub_strview(1, 2) << std::endl;
}