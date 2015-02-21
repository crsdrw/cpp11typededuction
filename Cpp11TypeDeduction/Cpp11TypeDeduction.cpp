#include <boost/type_index.hpp>
#include <iostream>

using boost::typeindex::type_id_with_cvr;

template<typename T>
void func_for_x(T param) {
  std::cout << "T =     " << type_id_with_cvr<T>().pretty_name() << "\n";
  std::cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << "\n";
}

template<typename T>
void func_for_cx(const T param) {
  std::cout << "T =     " << type_id_with_cvr<T>().pretty_name() << "\n";
  std::cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << "\n";
}

template<typename T>
void func_for_rx(const T& param) {
  std::cout << "T =     " << type_id_with_cvr<T>().pretty_name() << "\n";
  std::cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << "\n";
}

int func_returning_int() {
  int x = 27;
  return x;
}

void someFunc(int, double) { }

template<typename T>
void f(T param) { }

template<typename T>
void f_taking_init_list(std::initializer_list<T> initList) {
  std::cout << "T =        " << type_id_with_cvr<T>().pretty_name() << "\n";
  std::cout << "initList = " << type_id_with_cvr<decltype(initList)>().pretty_name() << "\n";
}

int main(){
  auto x = 27;
  const auto cx = x;
  const auto& rx = x;

  std::cout << "x = " << type_id_with_cvr<decltype(x)>().pretty_name() << "\n";
  std::cout << "cx = " << type_id_with_cvr<decltype(cx)>().pretty_name() << "\n";
  std::cout << "rx = " << type_id_with_cvr<decltype(rx)>().pretty_name() << "\n";

  std::cout << "func_for_x:\n";
  func_for_x(27);

  std::cout << "func_for_cx:\n";
  func_for_cx(x);

  std::cout << "func_for_rx:\n";
  func_for_rx(x);

  auto&& uref1 = x;
  std::cout << "uref1 = " << type_id_with_cvr<decltype(uref1)>().pretty_name() << "\n";

  auto&& uref2 = cx;
  std::cout << "uref2 = " << type_id_with_cvr<decltype(uref2)>().pretty_name() << "\n";

  auto&& uref3 = 27;
  std::cout << "uref3 = " << type_id_with_cvr<decltype(uref3)>().pretty_name() << "\n";

  auto&& uref4 = func_returning_int();
  std::cout << "uref4 = " << type_id_with_cvr<decltype(uref4)>().pretty_name() << "\n";

  auto&& uref5 = rx;
  std::cout << "uref5 = " << type_id_with_cvr<decltype(uref5)>().pretty_name() << "\n";

  const char name[] = "R. N. Briggs";

  auto arr1 = name;
  std::cout << "arr1 = " << type_id_with_cvr<decltype(arr1)>().pretty_name() << "\n";

  auto& arr2 = name;
  std::cout << "arr2 = " << type_id_with_cvr<decltype(arr2)>().pretty_name() << "\n";

  auto func1 = someFunc;
  std::cout << "func1 = " << type_id_with_cvr<decltype(func1)>().pretty_name() << "\n";

  auto& func2 = someFunc;
  std::cout << "func2 = " << type_id_with_cvr<decltype(func2)>().pretty_name() << "\n";

  int x1 = 27;
  int x2(27);

  // C++11 "uniform initialization"
  int x3 = {27};
  int x4{27};

  std::cout << "x1 = " << type_id_with_cvr<decltype(x1)>().pretty_name() << "\n";
  std::cout << "x2 = " << type_id_with_cvr<decltype(x2)>().pretty_name() << "\n";
  std::cout << "x3 = " << type_id_with_cvr<decltype(x3)>().pretty_name() << "\n";
  std::cout << "x4 = " << type_id_with_cvr<decltype(x4)>().pretty_name() << "\n";

  auto x1a = 27;
  auto x2a(27);

  // Perhaps a failed attempt at C++11 "uniform initialization"
  auto x3a = { 27 };
  auto x4a{ 27 };

  std::cout << "x1a = " << type_id_with_cvr<decltype(x1a)>().pretty_name() << "\n";
  std::cout << "x2a = " << type_id_with_cvr<decltype(x2a)>().pretty_name() << "\n";
  std::cout << "x3a = " << type_id_with_cvr<decltype(x3a)>().pretty_name() << "\n";
  std::cout << "x4a = " << type_id_with_cvr<decltype(x4a)>().pretty_name() << "\n";

  auto x_init_list = {11, 23, 9};


  //error C2784 : 'void f(T)' : could not deduce template argument for 'T' from 'initializer-list'
  //f({ 11, 23, 9 });

  std::cout << "f_taking_init_list:\n";
  f_taking_init_list({ 11, 23, 9 });


}
