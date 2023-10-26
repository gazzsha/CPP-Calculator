
#include "../Controller/Controller.h"


int main() {
    s21::Model m;
    std::cout << m.isValidExpression("(2+3+4+5+5+3-321*32)*tan(3)");
    std::cout << "\n";
    //m.RMN("1+2+3+4+5+6+7+8*(1+2+3+4+5)/(1.2+13)",NULL);
   // std::cout << m.calculatingExpression();

    s21::Controller controller(&m);
    double result = controller.calculate("1+2+3+4+5+6+7+8*(1+2+3+4+5)/(1.2+13)",NULL);
    std::cout << result << "============\n";

    m.differentiatedPayment("120","1000000","10");

     const double * arr = m.get_data_arrayOfMonthlyPayment_differentiatedPayment();
     std::cout <<  m.get_data_month();
    for (auto i = 0; i < m.get_data_month(); ++i) { 
        std::cout << std::fixed << arr[i]<< "\n";
    }


    
}