#include <iostream>
#include <vector>

long long Euc(const long long A, const long long B) {
  if (B > A) {
    return Euc(B, A);
  }

  if (A % B == 0) {
    return B;
  }

  return Euc(B, (A % B));
}

int main(void) {
  long long A, B, C;

  std::cin >> A >> B >> C;

  long long tmp = Euc(A, B);
  long long tmp2 = Euc(tmp, C);

//  std::cout << tmp << ":" << tmp2 << std::endl;

  std::cout << (A / tmp2) + (B / tmp2) + (C / tmp2) - 3 << std::endl;

  return 0;
}
