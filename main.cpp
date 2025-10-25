#include <iostream>
#include <cstddef>
#include <limits>
bool any_zeros(unsigned int a, unsigned int b)
{
  return a == 0 || b == 0;
}
unsigned int sum(unsigned int a, unsigned int b)
{
  unsigned int c = 0;
  using lim_unsignedint = std::numeric_limits<unsigned int>;
  const unsigned int MAX = lim_unsignedint::max();
  const unsigned int MIN = lim_unsignedint::min();
  if (MAX - a < b)
{
  return c;
}
  else
{
  c = a + b;
}
  return c;
}
bool is_upper_overflow(unsigned int res, unsigned int a, unsigned int b)
{
  return res == 0 && a > 0 && b > 0;
}
unsigned int multiplies(unsigned int a, unsigned int b)
{
  unsigned int c = 0;
  if (any_zeros(a, b))
{
  return c;
}
  using lim_unsignedint = std::numeric_limits<unsigned int>;
  const unsigned int MAX = lim_unsignedint::max();
  const unsigned int MIN = lim_unsignedint::min();
  if (a > MAX / b)
{
  return c;
}
  else
{
  c = a * b;
}
  return c;
}
bool is_upper_mult_overflow(unsigned int res, unsigned int a, unsigned int b)
{
  return (!any_zeros(a, b) && a > 0 && b > 0 && res == 0);
}
unsigned int is_pyth(unsigned int a, unsigned int b, unsigned int c)
{
  unsigned int a2 = multiplies(a, a);
  unsigned int b2 = multiplies(b, b);
  unsigned int c2 = multiplies(c, c);
  if (is_upper_mult_overflow(a2, a, a))
{
  return 2;
}
  if (is_upper_mult_overflow(b2, b, b))
{
  return 2;
}
  if (is_upper_mult_overflow(c2, c, c))
{
  return 2;
}
  unsigned int k = sum(a2, b2);
  unsigned int f = sum(a2, c2);
  unsigned int g = sum(b2, c2);
  if (is_upper_overflow(k, a2, b2))
{
  return 2;
}
  if (is_upper_overflow(f, a2, c2))
{
  return 2;
}
  if (is_upper_overflow(g, b2, c2))
{
  return 2;
}
  if (a2 + b2 == c2 || a2 + c2 == b2 || b2 + c2 == a2)
{
  return 3;
}
  return 0;
}
  int main()
{
  using u_t = unsigned;
  u_t a = 0, b = 0, c = 0;
  std::cin >> c >> b;
  size_t count = 0;
  unsigned int j = 0;
  while (std::cin >> a)
{
  j = is_pyth(a, b, c);
  if (j == 2)
{
  return 2;
}
  else if (j == 3)
{
    count++;
}
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

