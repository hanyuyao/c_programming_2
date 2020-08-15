#include "function.h"

const int Vector::operator[](int index) const
{
    if (index < 0 || index >= v_size) {
        std::cout << "OUT OF BOUND\n";
        return 0;
    }
    return v[index];
}

int Vector::operator*(const Vector& a)
{
    int ans = 0;
    for(int i = 0; i < a.v_size; i++)
        ans += this->v[i] * a.v[i];
    return ans;
}
