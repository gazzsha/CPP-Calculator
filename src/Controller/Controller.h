#ifndef _CPP3_SMART_CALC_SRC_CONTROLLER_CONTROLLER_H_
#define _CPP3_SMART_CALC_SRC_CONTROLLER_CONTROLLER_H_


#include "../Model/Model.h"

namespace s21 {
class Controller { 
    public:
    Controller (Model * model_) : model(model_) {}
    double calculate(const char * str, const char * x) {
        model->calculate(str,x);
        return model->get_data();
    }
   void set_Xmax(const double& d) noexcept {
    model->set_Xmax(d); 
    }
    void set_Xmin(const double& d) noexcept {
    model->set_Xmin(d); 
    }
    void set_Ymin(const double& d) noexcept {
    model->set_Ymin(d); 
    }
     void set_Ymax(const double& d) noexcept {
    model->set_Ymax(d); 
    }
    void set_nameFunction(const char* str) noexcept {
     model->set_nameFunction(str);
    }
    void insertData() { 
        model->insertData();
    }
    double get_Xmax() const noexcept { 
        return model->get_Xmax();
    }
    double get_Xmin() const noexcept { 
        return model->get_Xmin();
    }
    double get_Ymax() const noexcept { 
        return model->get_Ymax();
    }
        double get_Ymin() const noexcept { 
        return model->get_Ymin();
    }
    std::vector<double> get_xValueFunction() const noexcept { 
    return model->get_xValueFunction();
    }   
    std::vector<double> get_yValueFunction() const noexcept { 
    return model-> get_yValueFunction();
    }  

    std::string get_nameFunction() const noexcept { 
        return model->get_nameFunction();
    }

    void annuityPaymentCalculation(const char *monthString, const char *loanAmounString,
                       const char *interestRateString) { 
                        model->annuityPaymentCalculation(monthString,loanAmounString,interestRateString);
                       }
    double get_data_annuityRatio() const noexcept { 
        return model->get_data_annuityRatio();
    }
    double get_data_overpaymentLoan() const noexcept {
         return model->get_data_overpaymentLoan();
    }
    double get_data_totalPayout() const noexcept { 
        return model->get_data_totalPayout();
    }
    void differentiatedPayment(const char *monthString,
                           const char *loanAmounString,
                           const char *interestRateString) { 
                            model->differentiatedPayment(monthString,loanAmounString,interestRateString);
                           }
     double get_data_month() const noexcept { 
        return model->get_data_month();
     }
     const double* get_data_arrayOfMonthlyPayment_differentiatedPayment() const noexcept { 
        return model->get_data_arrayOfMonthlyPayment_differentiatedPayment();
     }

    private: 
    Model * model;
};
} // namespace s21

#endif // _CPP3_SMART_CALC_SRC_CONTROLLER_CONTROLLER_H_
