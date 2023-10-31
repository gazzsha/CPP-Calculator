/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_2;
    QAction *action_3;
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *pushButton_number_8;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_x;
    QPushButton *pushButton_number_0;
    QPushButton *pushButton_number_1;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_number_7;
    QPushButton *pushButton_pi;
    QPushButton *pushButton_div;
    QPushButton *pushButton_number_6;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_number_9;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_mul;
    QLineEdit *lineEdit;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_exp;
    QPushButton *pushButton_log;
    QPushButton *pushButton_number_5;
    QPushButton *pushButton_number_2;
    QPushButton *pushButton_del;
    QPushButton *pushButton_X;
    QPushButton *pushButton_left_bracket;
    QPushButton *pushButton_degree;
    QLabel *result_show;
    QPushButton *pushButton_sub;
    QPushButton *pushButton_equal;
    QPushButton *pushButton_number_3;
    QPushButton *pushButton_right_bracket;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_number_4;
    QPushButton *pushButton_ac;
    QPushButton *pushButton_graph;
    QLineEdit *lineEdit_X_min;
    QLineEdit *lineEdit_X_max;
    QLineEdit *lineEdit_Y_max;
    QLineEdit *lineEdit_Y_min;
    QWidget *page_2;
    QLabel *label_loan_amount;
    QLabel *label_month;
    QLabel *label_month_2;
    QLineEdit *lineEdit_sum;
    QLineEdit *lineEdit_count_month;
    QLineEdit *lineEdit_ratio;
    QLabel *result;
    QPushButton *pushButton_getResult;
    QTextBrowser *textBrowser;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_an;
    QRadioButton *radioButton_dif;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(655, 560);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName("action_2");
        action_3 = new QAction(MainWindow);
        action_3->setObjectName("action_3");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 651, 531));
        page = new QWidget();
        page->setObjectName("page");
        pushButton_number_8 = new QPushButton(page);
        pushButton_number_8->setObjectName("pushButton_number_8");
        pushButton_number_8->setGeometry(QRect(250, 250, 75, 58));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(78);
        sizePolicy.setVerticalStretch(80);
        sizePolicy.setHeightForWidth(pushButton_number_8->sizePolicy().hasHeightForWidth());
        pushButton_number_8->setSizePolicy(sizePolicy);
        pushButton_number_8->setStyleSheet(QString::fromUtf8("font: 600 16pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(124, 125, 138);\n"
"border-radius: 15px;\n"
"color: white\n"
"\n"
""));
        pushButton_acos = new QPushButton(page);
        pushButton_acos->setObjectName("pushButton_acos");
        pushButton_acos->setGeometry(QRect(10, 370, 75, 58));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(80);
        sizePolicy1.setVerticalStretch(80);
        sizePolicy1.setHeightForWidth(pushButton_acos->sizePolicy().hasHeightForWidth());
        pushButton_acos->setSizePolicy(sizePolicy1);
        pushButton_acos->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Candara\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        pushButton_x = new QPushButton(page);
        pushButton_x->setObjectName("pushButton_x");
        pushButton_x->setGeometry(QRect(330, 190, 75, 58));
        sizePolicy1.setHeightForWidth(pushButton_x->sizePolicy().hasHeightForWidth());
        pushButton_x->setSizePolicy(sizePolicy1);
        pushButton_x->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Candara\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        pushButton_number_0 = new QPushButton(page);
        pushButton_number_0->setObjectName("pushButton_number_0");
        pushButton_number_0->setGeometry(QRect(250, 430, 75, 58));
        sizePolicy.setHeightForWidth(pushButton_number_0->sizePolicy().hasHeightForWidth());
        pushButton_number_0->setSizePolicy(sizePolicy);
        pushButton_number_0->setStyleSheet(QString::fromUtf8("font: 600 16pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(124, 125, 138);\n"
"border-radius: 15px;\n"
"color: white\n"
"\n"
""));
        pushButton_number_1 = new QPushButton(page);
        pushButton_number_1->setObjectName("pushButton_number_1");
        pushButton_number_1->setGeometry(QRect(170, 370, 75, 58));
        sizePolicy.setHeightForWidth(pushButton_number_1->sizePolicy().hasHeightForWidth());
        pushButton_number_1->setSizePolicy(sizePolicy);
        pushButton_number_1->setStyleSheet(QString::fromUtf8("font: 600 16pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(124, 125, 138);\n"
"border-radius: 15px;\n"
"color: white\n"
"\n"
""));
        pushButton_sin = new QPushButton(page);
        pushButton_sin->setObjectName("pushButton_sin");
        pushButton_sin->setGeometry(QRect(90, 430, 75, 58));
        sizePolicy1.setHeightForWidth(pushButton_sin->sizePolicy().hasHeightForWidth());
        pushButton_sin->setSizePolicy(sizePolicy1);
        pushButton_sin->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Candara\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        pushButton_asin = new QPushButton(page);
        pushButton_asin->setObjectName("pushButton_asin");
        pushButton_asin->setGeometry(QRect(10, 430, 75, 58));
        sizePolicy1.setHeightForWidth(pushButton_asin->sizePolicy().hasHeightForWidth());
        pushButton_asin->setSizePolicy(sizePolicy1);
        pushButton_asin->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Candara\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        pushButton_cos = new QPushButton(page);
        pushButton_cos->setObjectName("pushButton_cos");
        pushButton_cos->setGeometry(QRect(90, 370, 75, 58));
        sizePolicy1.setHeightForWidth(pushButton_cos->sizePolicy().hasHeightForWidth());
        pushButton_cos->setSizePolicy(sizePolicy1);
        pushButton_cos->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Candara\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        pushButton_number_7 = new QPushButton(page);
        pushButton_number_7->setObjectName("pushButton_number_7");
        pushButton_number_7->setGeometry(QRect(170, 250, 75, 58));
        sizePolicy.setHeightForWidth(pushButton_number_7->sizePolicy().hasHeightForWidth());
        pushButton_number_7->setSizePolicy(sizePolicy);
        pushButton_number_7->setStyleSheet(QString::fromUtf8("font: 600 16pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(124, 125, 138);\n"
"border-radius: 15px;\n"
"color: white\n"
"\n"
""));
        pushButton_pi = new QPushButton(page);
        pushButton_pi->setObjectName("pushButton_pi");
        pushButton_pi->setGeometry(QRect(170, 190, 75, 58));
        sizePolicy1.setHeightForWidth(pushButton_pi->sizePolicy().hasHeightForWidth());
        pushButton_pi->setSizePolicy(sizePolicy1);
        pushButton_pi->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Candara\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        pushButton_div = new QPushButton(page);
        pushButton_div->setObjectName("pushButton_div");
        pushButton_div->setGeometry(QRect(410, 190, 75, 58));
        sizePolicy1.setHeightForWidth(pushButton_div->sizePolicy().hasHeightForWidth());
        pushButton_div->setSizePolicy(sizePolicy1);
        pushButton_div->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Candara\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        pushButton_number_6 = new QPushButton(page);
        pushButton_number_6->setObjectName("pushButton_number_6");
        pushButton_number_6->setGeometry(QRect(330, 310, 75, 58));
        sizePolicy.setHeightForWidth(pushButton_number_6->sizePolicy().hasHeightForWidth());
        pushButton_number_6->setSizePolicy(sizePolicy);
        pushButton_number_6->setStyleSheet(QString::fromUtf8("font: 600 16pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(124, 125, 138);\n"
"border-radius: 15px;\n"
"color: white\n"
"\n"
""));
        pushButton_sqrt = new QPushButton(page);
        pushButton_sqrt->setObjectName("pushButton_sqrt");
        pushButton_sqrt->setGeometry(QRect(10, 190, 75, 58));
        sizePolicy1.setHeightForWidth(pushButton_sqrt->sizePolicy().hasHeightForWidth());
        pushButton_sqrt->setSizePolicy(sizePolicy1);
        pushButton_sqrt->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Candara\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        pushButton_dot = new QPushButton(page);
        pushButton_dot->setObjectName("pushButton_dot");
        pushButton_dot->setGeometry(QRect(330, 430, 75, 58));
        sizePolicy1.setHeightForWidth(pushButton_dot->sizePolicy().hasHeightForWidth());
        pushButton_dot->setSizePolicy(sizePolicy1);
        pushButton_dot->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Candara\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        pushButton_number_9 = new QPushButton(page);
        pushButton_number_9->setObjectName("pushButton_number_9");
        pushButton_number_9->setGeometry(QRect(330, 250, 75, 58));
        sizePolicy.setHeightForWidth(pushButton_number_9->sizePolicy().hasHeightForWidth());
        pushButton_number_9->setSizePolicy(sizePolicy);
        pushButton_number_9->setStyleSheet(QString::fromUtf8("font: 600 16pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(124, 125, 138);\n"
"border-radius: 15px;\n"
"color: white\n"
"\n"
""));
        pushButton_plus = new QPushButton(page);
        pushButton_plus->setObjectName("pushButton_plus");
        pushButton_plus->setGeometry(QRect(410, 370, 75, 58));
        sizePolicy.setHeightForWidth(pushButton_plus->sizePolicy().hasHeightForWidth());
        pushButton_plus->setSizePolicy(sizePolicy);
        pushButton_plus->setStyleSheet(QString::fromUtf8("font: 600 16pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(124, 125, 138);\n"
"border-radius: 15px;\n"
"color: white\n"
"\n"
""));
        pushButton_mul = new QPushButton(page);
        pushButton_mul->setObjectName("pushButton_mul");
        pushButton_mul->setGeometry(QRect(410, 250, 75, 58));
        sizePolicy.setHeightForWidth(pushButton_mul->sizePolicy().hasHeightForWidth());
        pushButton_mul->setSizePolicy(sizePolicy);
        pushButton_mul->setStyleSheet(QString::fromUtf8("font: 600 16pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(124, 125, 138);\n"
"border-radius: 15px;\n"
"color: white\n"
"\n"
""));
        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(490, 380, 161, 41));
        lineEdit->setStyleSheet(QString::fromUtf8("font: 600 20pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(112, 105, 127);\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        lineEdit->setAlignment(Qt::AlignCenter);
        pushButton_tan = new QPushButton(page);
        pushButton_tan->setObjectName("pushButton_tan");
        pushButton_tan->setGeometry(QRect(90, 310, 75, 58));
        sizePolicy1.setHeightForWidth(pushButton_tan->sizePolicy().hasHeightForWidth());
        pushButton_tan->setSizePolicy(sizePolicy1);
        pushButton_tan->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Candara\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        pushButton_exp = new QPushButton(page);
        pushButton_exp->setObjectName("pushButton_exp");
        pushButton_exp->setGeometry(QRect(250, 190, 75, 58));
        sizePolicy1.setHeightForWidth(pushButton_exp->sizePolicy().hasHeightForWidth());
        pushButton_exp->setSizePolicy(sizePolicy1);
        pushButton_exp->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Candara\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        pushButton_log = new QPushButton(page);
        pushButton_log->setObjectName("pushButton_log");
        pushButton_log->setGeometry(QRect(90, 250, 75, 58));
        sizePolicy1.setHeightForWidth(pushButton_log->sizePolicy().hasHeightForWidth());
        pushButton_log->setSizePolicy(sizePolicy1);
        pushButton_log->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Candara\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        pushButton_number_5 = new QPushButton(page);
        pushButton_number_5->setObjectName("pushButton_number_5");
        pushButton_number_5->setGeometry(QRect(250, 310, 75, 58));
        sizePolicy.setHeightForWidth(pushButton_number_5->sizePolicy().hasHeightForWidth());
        pushButton_number_5->setSizePolicy(sizePolicy);
        pushButton_number_5->setStyleSheet(QString::fromUtf8("font: 600 16pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(124, 125, 138);\n"
"border-radius: 15px;\n"
"color: white\n"
"\n"
""));
        pushButton_number_2 = new QPushButton(page);
        pushButton_number_2->setObjectName("pushButton_number_2");
        pushButton_number_2->setGeometry(QRect(250, 370, 75, 58));
        sizePolicy.setHeightForWidth(pushButton_number_2->sizePolicy().hasHeightForWidth());
        pushButton_number_2->setSizePolicy(sizePolicy);
        pushButton_number_2->setStyleSheet(QString::fromUtf8("font: 600 16pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(124, 125, 138);\n"
"border-radius: 15px;\n"
"color: white\n"
"\n"
""));
        pushButton_del = new QPushButton(page);
        pushButton_del->setObjectName("pushButton_del");
        pushButton_del->setGeometry(QRect(570, 70, 75, 58));
        sizePolicy1.setHeightForWidth(pushButton_del->sizePolicy().hasHeightForWidth());
        pushButton_del->setSizePolicy(sizePolicy1);
        pushButton_del->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Candara\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        pushButton_X = new QPushButton(page);
        pushButton_X->setObjectName("pushButton_X");
        pushButton_X->setGeometry(QRect(490, 430, 161, 58));
        sizePolicy1.setHeightForWidth(pushButton_X->sizePolicy().hasHeightForWidth());
        pushButton_X->setSizePolicy(sizePolicy1);
        pushButton_X->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Candara\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        pushButton_left_bracket = new QPushButton(page);
        pushButton_left_bracket->setObjectName("pushButton_left_bracket");
        pushButton_left_bracket->setGeometry(QRect(490, 190, 75, 58));
        sizePolicy1.setHeightForWidth(pushButton_left_bracket->sizePolicy().hasHeightForWidth());
        pushButton_left_bracket->setSizePolicy(sizePolicy1);
        pushButton_left_bracket->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Candara\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        pushButton_degree = new QPushButton(page);
        pushButton_degree->setObjectName("pushButton_degree");
        pushButton_degree->setGeometry(QRect(90, 190, 75, 58));
        sizePolicy1.setHeightForWidth(pushButton_degree->sizePolicy().hasHeightForWidth());
        pushButton_degree->setSizePolicy(sizePolicy1);
        pushButton_degree->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Candara\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        result_show = new QLabel(page);
        result_show->setObjectName("result_show");
        result_show->setGeometry(QRect(10, 70, 551, 111));
        result_show->setLayoutDirection(Qt::LeftToRight);
        result_show->setStyleSheet(QString::fromUtf8("background-color:rgb(126, 126, 126);\n"
"font: 600 36pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: grey;\n"
"border-radius: 10px;\n"
"color: white\n"
""));
        result_show->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_sub = new QPushButton(page);
        pushButton_sub->setObjectName("pushButton_sub");
        pushButton_sub->setGeometry(QRect(410, 310, 75, 58));
        sizePolicy.setHeightForWidth(pushButton_sub->sizePolicy().hasHeightForWidth());
        pushButton_sub->setSizePolicy(sizePolicy);
        pushButton_sub->setStyleSheet(QString::fromUtf8("font: 600 16pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(124, 125, 138);\n"
"border-radius: 15px;\n"
"color: white\n"
"\n"
""));
        pushButton_equal = new QPushButton(page);
        pushButton_equal->setObjectName("pushButton_equal");
        pushButton_equal->setGeometry(QRect(410, 430, 75, 58));
        sizePolicy1.setHeightForWidth(pushButton_equal->sizePolicy().hasHeightForWidth());
        pushButton_equal->setSizePolicy(sizePolicy1);
        pushButton_equal->setStyleSheet(QString::fromUtf8("font: 700 italic 20pt \"Candara\";\n"
"background-color: rgb(201, 140, 255);\n"
"border-radius: 15px;\n"
"color: white;\n"
""));
        pushButton_number_3 = new QPushButton(page);
        pushButton_number_3->setObjectName("pushButton_number_3");
        pushButton_number_3->setGeometry(QRect(330, 370, 75, 58));
        sizePolicy.setHeightForWidth(pushButton_number_3->sizePolicy().hasHeightForWidth());
        pushButton_number_3->setSizePolicy(sizePolicy);
        pushButton_number_3->setStyleSheet(QString::fromUtf8("font: 600 16pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(124, 125, 138);\n"
"border-radius: 15px;\n"
"color: white\n"
"\n"
""));
        pushButton_right_bracket = new QPushButton(page);
        pushButton_right_bracket->setObjectName("pushButton_right_bracket");
        pushButton_right_bracket->setGeometry(QRect(570, 190, 75, 58));
        sizePolicy1.setHeightForWidth(pushButton_right_bracket->sizePolicy().hasHeightForWidth());
        pushButton_right_bracket->setSizePolicy(sizePolicy1);
        pushButton_right_bracket->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Candara\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        pushButton_mod = new QPushButton(page);
        pushButton_mod->setObjectName("pushButton_mod");
        pushButton_mod->setGeometry(QRect(170, 430, 75, 58));
        sizePolicy1.setHeightForWidth(pushButton_mod->sizePolicy().hasHeightForWidth());
        pushButton_mod->setSizePolicy(sizePolicy1);
        pushButton_mod->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Candara\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        pushButton_ln = new QPushButton(page);
        pushButton_ln->setObjectName("pushButton_ln");
        pushButton_ln->setGeometry(QRect(10, 250, 75, 58));
        sizePolicy1.setHeightForWidth(pushButton_ln->sizePolicy().hasHeightForWidth());
        pushButton_ln->setSizePolicy(sizePolicy1);
        pushButton_ln->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Candara\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        pushButton_atan = new QPushButton(page);
        pushButton_atan->setObjectName("pushButton_atan");
        pushButton_atan->setGeometry(QRect(10, 310, 75, 58));
        sizePolicy1.setHeightForWidth(pushButton_atan->sizePolicy().hasHeightForWidth());
        pushButton_atan->setSizePolicy(sizePolicy1);
        pushButton_atan->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Candara\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        pushButton_number_4 = new QPushButton(page);
        pushButton_number_4->setObjectName("pushButton_number_4");
        pushButton_number_4->setGeometry(QRect(170, 310, 75, 58));
        sizePolicy.setHeightForWidth(pushButton_number_4->sizePolicy().hasHeightForWidth());
        pushButton_number_4->setSizePolicy(sizePolicy);
        pushButton_number_4->setStyleSheet(QString::fromUtf8("font: 600 16pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(124, 125, 138);\n"
"border-radius: 15px;\n"
"color: white\n"
"\n"
""));
        pushButton_ac = new QPushButton(page);
        pushButton_ac->setObjectName("pushButton_ac");
        pushButton_ac->setGeometry(QRect(570, 130, 75, 58));
        sizePolicy.setHeightForWidth(pushButton_ac->sizePolicy().hasHeightForWidth());
        pushButton_ac->setSizePolicy(sizePolicy);
        pushButton_ac->setStyleSheet(QString::fromUtf8("font: 600 16pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
"\n"
""));
        pushButton_graph = new QPushButton(page);
        pushButton_graph->setObjectName("pushButton_graph");
        pushButton_graph->setGeometry(QRect(490, 347, 161, 31));
        sizePolicy1.setHeightForWidth(pushButton_graph->sizePolicy().hasHeightForWidth());
        pushButton_graph->setSizePolicy(sizePolicy1);
        pushButton_graph->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Candara\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        lineEdit_X_min = new QLineEdit(page);
        lineEdit_X_min->setObjectName("lineEdit_X_min");
        lineEdit_X_min->setGeometry(QRect(490, 300, 81, 41));
        lineEdit_X_min->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(112, 105, 127);\n"
"border-radius: 20px;\n"
"color: white\n"
""));
        lineEdit_X_min->setAlignment(Qt::AlignCenter);
        lineEdit_X_max = new QLineEdit(page);
        lineEdit_X_max->setObjectName("lineEdit_X_max");
        lineEdit_X_max->setGeometry(QRect(570, 300, 81, 41));
        lineEdit_X_max->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(112, 105, 127);\n"
"border-radius: 20px;\n"
"color: white\n"
""));
        lineEdit_X_max->setAlignment(Qt::AlignCenter);
        lineEdit_Y_max = new QLineEdit(page);
        lineEdit_Y_max->setObjectName("lineEdit_Y_max");
        lineEdit_Y_max->setGeometry(QRect(570, 250, 81, 41));
        lineEdit_Y_max->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(112, 105, 127);\n"
"border-radius: 20px;\n"
"color: white\n"
""));
        lineEdit_Y_max->setAlignment(Qt::AlignCenter);
        lineEdit_Y_min = new QLineEdit(page);
        lineEdit_Y_min->setObjectName("lineEdit_Y_min");
        lineEdit_Y_min->setGeometry(QRect(490, 250, 81, 41));
        lineEdit_Y_min->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(112, 105, 127);\n"
"border-radius: 20px;\n"
"color: white\n"
""));
        lineEdit_Y_min->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_loan_amount = new QLabel(page_2);
        label_loan_amount->setObjectName("label_loan_amount");
        label_loan_amount->setGeometry(QRect(10, 230, 331, 51));
        label_loan_amount->setStyleSheet(QString::fromUtf8("font: 18pt \"Segoe UI Variable\";"));
        label_month = new QLabel(page_2);
        label_month->setObjectName("label_month");
        label_month->setGeometry(QRect(10, 280, 391, 51));
        label_month->setStyleSheet(QString::fromUtf8("font: 18pt \"Segoe UI Variable\";"));
        label_month_2 = new QLabel(page_2);
        label_month_2->setObjectName("label_month_2");
        label_month_2->setGeometry(QRect(10, 330, 541, 51));
        label_month_2->setStyleSheet(QString::fromUtf8("font: 18pt \"Segoe UI Variable\";"));
        lineEdit_sum = new QLineEdit(page_2);
        lineEdit_sum->setObjectName("lineEdit_sum");
        lineEdit_sum->setGeometry(QRect(450, 240, 201, 31));
        lineEdit_sum->setStyleSheet(QString::fromUtf8("font: 600 20pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(112, 105, 127);\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        lineEdit_sum->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_count_month = new QLineEdit(page_2);
        lineEdit_count_month->setObjectName("lineEdit_count_month");
        lineEdit_count_month->setGeometry(QRect(450, 290, 201, 31));
        lineEdit_count_month->setStyleSheet(QString::fromUtf8("font: 600 20pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(112, 105, 127);\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        lineEdit_count_month->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_ratio = new QLineEdit(page_2);
        lineEdit_ratio->setObjectName("lineEdit_ratio");
        lineEdit_ratio->setGeometry(QRect(450, 340, 201, 31));
        lineEdit_ratio->setStyleSheet(QString::fromUtf8("font: 600 20pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(112, 105, 127);\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        lineEdit_ratio->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        result = new QLabel(page_2);
        result->setObjectName("result");
        result->setGeometry(QRect(10, 410, 641, 121));
        result->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Arial\";\n"
"background-color: white;\n"
"border-radius: 15px;\n"
"color: black;\n"
"\n"
""));
        result->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        pushButton_getResult = new QPushButton(page_2);
        pushButton_getResult->setObjectName("pushButton_getResult");
        pushButton_getResult->setGeometry(QRect(10, 170, 251, 71));
        pushButton_getResult->setStyleSheet(QString::fromUtf8("font: 600 20pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(112, 105, 127);\n"
"border-radius: 15px;\n"
"color: white"));
        textBrowser = new QTextBrowser(page_2);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setEnabled(true);
        textBrowser->setGeometry(QRect(450, 30, 201, 192));
        textBrowser->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Arial\";\n"
"background-color: white;\n"
"border-radius: 15px;\n"
"color: black;\n"
"\n"
""));
        widget = new QWidget(page_2);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 90, 249, 71));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_an = new QRadioButton(widget);
        radioButton_an->setObjectName("radioButton_an");
        radioButton_an->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";"));
        radioButton_an->setChecked(true);

        verticalLayout->addWidget(radioButton_an);

        radioButton_dif = new QRadioButton(widget);
        radioButton_dif->setObjectName("radioButton_dif");
        radioButton_dif->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";"));

        verticalLayout->addWidget(radioButton_dif);

        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 655, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_3);
        menu->addSeparator();
        menu->addAction(action_2);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\320\265\320\264\320\270\321\202\320\275\321\213\320\271", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\320\266\320\265\320\275\320\265\321\200\320\275\321\213\320\271", nullptr));
        pushButton_number_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        pushButton_x->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        pushButton_number_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_number_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        pushButton_number_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_pi->setText(QCoreApplication::translate("MainWindow", "PI", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_number_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_number_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_mul->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        lineEdit->setText(QString());
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        pushButton_exp->setText(QCoreApplication::translate("MainWindow", "E", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        pushButton_number_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_number_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_del->setText(QCoreApplication::translate("MainWindow", "DEL", nullptr));
        pushButton_X->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        pushButton_left_bracket->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_degree->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        result_show->setText(QString());
        pushButton_sub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_equal->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_number_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_right_bracket->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        pushButton_number_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_ac->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_graph->setText(QCoreApplication::translate("MainWindow", "Build graph", nullptr));
        lineEdit_X_min->setText(QString());
        lineEdit_X_max->setText(QString());
        lineEdit_Y_max->setText(QString());
        lineEdit_Y_min->setText(QString());
        label_loan_amount->setText(QCoreApplication::translate("MainWindow", "\320\241\321\203\320\274\320\274\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\320\260:", nullptr));
        label_month->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\274\320\265\321\201\321\217\321\206\320\265\320\262", nullptr));
        label_month_2->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260(\320\263\320\276\320\264\320\276\320\262\320\260\321\217),%", nullptr));
        result->setText(QString());
        pushButton_getResult->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214", nullptr));
        radioButton_an->setText(QCoreApplication::translate("MainWindow", "\320\220\320\275\320\275\321\203\320\270\321\202\320\265\321\202\320\275\321\213\320\271", nullptr));
        radioButton_dif->setText(QCoreApplication::translate("MainWindow", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
