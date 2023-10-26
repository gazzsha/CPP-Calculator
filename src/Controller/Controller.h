#include "../Model/Model.h"

namespace s21 {
class Controller { 
    public: 
    Controller (Model * model_) : model(model_) {} 
    const double calculate(const char * str, const char * x) { 
        model->calculate(str,x);
        return model->get_data();
    }
    private: 
    Model * model;
};
} // namespace s21