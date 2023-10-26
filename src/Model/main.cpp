#include "Model.h"

int main() { 
    s21::Model m;
    m.calculate("3+x","5");
    std::cout << m.get_data();
}