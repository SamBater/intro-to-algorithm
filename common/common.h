#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

//生成一个长度为size，范围[0,max]的vector
std::vector<int> Create_Random_Vector(int size = 10, int max = 100);
bool is_sorted(std::vector<int> &v);
std::ostream &operator<<(std::ostream &out, std::vector<int> &v);