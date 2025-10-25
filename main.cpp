#include <iostream>
#include <cstddef>
#include <limits>
bool any_zeros(unsigned int a, unsigned int b)
{
  return a == 0 || b == 0;
}
bool isPyth(unsigned int a, unsigned int b, unsigned int c) {
    bool p = a * a == (b * b + c * c);
    p = p || (b * b == (a * a + c * c));
    p = p || (c * c == (a * a + b * b));
    return c;
}
int main()
{
  using u_t = unsigned;
  u_t a = 0, b = 0, c = 0;
  std::cin >> c >> b;
  size_t count = 0;
  while (std::cin >> a) {
    count += isPyth(a, b, c) ? 1 : 0;
    c = b;
    b = a;
  }
  if (std::cin.eof()) {
    std::cout << count;
    std::cout << "\n";
  }
  else if (std::cin.fail()) {
    std::cerr << "Error\n";
    return 1;
  }
}

