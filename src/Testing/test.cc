
#include "unit_test.h"
#include <cmath>
namespace TEST {

TEST(CalcTest, Test1) {
    s21::Model model;
    s21::Controller controller(&model);
  EXPECT_EQ(controller.calculate("1+3+5+10",NULL), 19);
}

TEST(CalcTest, Test2) {
    s21::Model model;
    s21::Controller controller(&model);
  	EXPECT_LT(std::abs(controller.calculate("tan(10)+cos(1)+10-sqrt(196)+log(5)",NULL) - (-2.112366)),1e-6);
}

TEST(CalcTest, Test3) {
    s21::Model model;
    s21::Controller controller(&model);
  	EXPECT_LT(std::abs(controller.calculate("tan(10)+cos(1)+10-sqrt(196)+log(50)",NULL) - (-1.112366)),1e-6);
}

TEST(CalcTest, Test4) {
    s21::Model model;
    s21::Controller controller(&model);
  	EXPECT_LT(std::abs(controller.calculate("1+2-3/4*5^6+sin(3.1415927)+cos(3.1415927/2)+sqrt(2)+2mod(2)+tan(1)+ln(2)+log(10)+asin(0.3)+acos(0.1)+atan(0.6)+(-2)+(1-(+2))",NULL) - (-11711.769490)),1e-6);
}

TEST(CalcTest, Test5) {
    s21::Model model;
    s21::Controller controller(&model);
  	EXPECT_LT(std::abs(controller.calculate("1+2-3/4*5^6+sin(3.1415927)+cos(3.1415927/2)+sqrt(2)+2mod(2)+tan(1)+ln(2)+log(10)+asin(0.3)+acos(0.1)+atan(0.6)+(-2)+(1-(+x))","2") - (-11711.769490)),1e-6);
}
TEST(CalcTest, Test6) {
    s21::Model model;
    s21::Controller controller(&model);
  	EXPECT_LT(std::abs(controller.calculate("x+2-3/4*5^6+sin(3.1415927)+cos(3.1415927/2)+sqrt(2)+2mod(2)+tan(x)+ln(2)+log(x*10)+asin(0.3)+acos(x/10)+atan(0.6)+(-2)+(x-(+2))","1") - (-11711.769490)),1e-6);
}

TEST(CalcTest, Test7) {
    s21::Model model;
    s21::Controller controller(&model);
  	EXPECT_ANY_THROW(controller.calculate("x+2.-3/4*5^6+sin(3.1415927)+cos(3.1415927/2)+sqrt(2)+2mod(2)+tan(x)+ln(2)+log(x*10)+asin(0.3)+acos(x/10)+atan(0.6)+(-2)+(x-(+2))","1"));
}

TEST(CalcTest, Test8) {
    s21::Model model;
    s21::Controller controller(&model);
  	EXPECT_ANY_THROW(controller.calculate("x//2)","1"));
}
TEST(CalcTest, Test9) {
    s21::Model model;
    s21::Controller controller(&model);
  	EXPECT_ANY_THROW(controller.calculate("x/**2)","1"));
}


TEST(CalcTest, Test10) {
    s21::Model model;
    s21::Controller controller(&model);
    controller.set_nameFunction("x+2");
  EXPECT_EQ(controller.calculate("x+2","2"), 4);
  	EXPECT_STREQ(controller.get_nameFunction().c_str(),"x+2");
}

TEST(CalcTest, Test11) {
    s21::Model model;
    s21::Controller controller(&model);
    controller.annuityPaymentCalculation("10","1000000","10");
  EXPECT_LT(controller.get_data_totalPayout() - 1046403.809899, 1e-6);
  EXPECT_LT(controller.get_data_overpaymentLoan() -46403.82, 1e-2);
  EXPECT_LT(controller.get_data_annuityRatio() -104640.38, 1e-2);

}


TEST(CalcTest, Test12) {
    s21::Model model;
    s21::Controller controller(&model);
    	EXPECT_ANY_THROW(controller.annuityPaymentCalculation("-10","1000000","10"));
}

TEST(CalcTest, Test13) {
    s21::Model model;
    s21::Controller controller(&model);
    	EXPECT_ANY_THROW(controller.annuityPaymentCalculation("10","-1000000","10"));
}

TEST(CalcTest, Test14) {
    s21::Model model;
    s21::Controller controller(&model);
    	EXPECT_ANY_THROW(controller.annuityPaymentCalculation("10","1000000","-10"));
}

TEST(CalcTest, Test15) {
    s21::Model model;
    s21::Controller controller(&model);
    controller.differentiatedPayment("10","1000000","10");
  EXPECT_LT(controller.get_data_totalPayout() - 1045833.33, 1e-2);
  EXPECT_LT(controller.get_data_overpaymentLoan() -45833.33, 1e-2);
  auto arr = controller.get_data_arrayOfMonthlyPayment_differentiatedPayment();
  double answer[] = {8333.33,7500.00,6666.67,5833.33,5000,4166.67,3333.33,2500.00,1666.67,833.33};
  for (auto it = 0; it != controller.get_data_month(); it++) {
  EXPECT_LT(arr[it] - answer[it], 1e-2);
  }

}


TEST(CalcTest, Test16) {
    s21::Model model;
    s21::Controller controller(&model);
   EXPECT_ANY_THROW(controller.differentiatedPayment("-10","1000000","10"));
}

TEST(CalcTest, Test17) {
    s21::Model model;
    s21::Controller controller(&model);
   EXPECT_ANY_THROW(controller.differentiatedPayment("10","-1000000","10"));
}

TEST(CalcTest, Test18) {
    s21::Model model;
    s21::Controller controller(&model);
   EXPECT_ANY_THROW(controller.differentiatedPayment("10","1000000","-10.4"));
}
} // namespace TEST