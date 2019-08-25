#include <vector>
#include <iostream>

template <typename T>
void PrintVectorMeta(const std::vector<T> &someVector) {
    std::cout << "\tCap: " << someVector.capacity() << ", Size: " << someVector.size();
}

template <typename T>
void PrintVector(const std::vector<T> &someVector) {
    std::cout << "===== Print vector =====" << std::endl
        << PrintVectorMeta<T>(someVector) << std::endl;
    for (int i = 0; i < someVector.size(); i++) {
        std::cout << "\t[" << i << "]-th element: " << someVector[i] << std::endl;
    }
}

// You can see vector elements are default initialized
void ConstructWithLen(int len) {
    std::vector<int> carIDs(len);
    PrintVectorMeta<int>(carIDs);
}

int main()
{
    for (int i = 1; i < 2000000; i = i*9) {
        ConstructWithLen(i);
    }
}