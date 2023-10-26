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
    private: 
    Model * model;
};
} // namespace s21

#endif // _CPP3_SMART_CALC_SRC_CONTROLLER_CONTROLLER_H_
