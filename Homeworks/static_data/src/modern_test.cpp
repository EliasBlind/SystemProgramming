#include <algorithm>
#include <vector>

int main() {
  std::vector<int> v = {1, 2, 3};
  auto it = std::find(v.begin(), v.end(), 2);
  return 0;
}
