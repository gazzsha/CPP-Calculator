#include "Model.h"

int main() { 
    s21::Model m;
//     const char * s = "X+2";
//     m.set_nameFunction(s);
//     m.set_Xmin(-3);
//     m.set_Xmax(3);
//     m.set_Ymin(-3);
//     m.set_Ymax(3);
//     m.insertData();
//   //  auto vec = m.get_yValueFunction();
// //    for ( auto v : vec) { 
// //     std::cout << v << " ";
// //    }
// //    std::cout << "\n";
//     const char * ss = "cos(x)+tan(x)+sqrt(x)";
//      m.set_nameFunction(ss);
//     m.set_Xmin(-3);
//     m.set_Xmax(3);
//     m.set_Ymin(-3);
//     m.set_Ymax(3);
//  //   std::cout << m.get_nameFunction();
//    m.insertData();
//  auto vec1 = m.get_yValueFunction();
//    for ( auto v : vec1) { 
//     std::cout << v << " ";
//    }
m.annuityPaymentCalculation("12","100000","10");
std::cout << m.get_data_annuityRatio();
}