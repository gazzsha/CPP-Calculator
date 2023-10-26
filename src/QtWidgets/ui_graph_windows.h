/********************************************************************************
** Form generated from reading UI file 'graph_windows.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_WINDOWS_H
#define UI_GRAPH_WINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Graph_Windows
{
public:
    QCustomPlot *widget;
    QPushButton *pushButton;
    QLineEdit *lineEdit_expression;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_Y_min;
    QLineEdit *lineEdit_Y_max;
    QLineEdit *lineEdit_X_min;
    QLineEdit *lineEdit_X_max;

    void setupUi(QDialog *Graph_Windows)
    {
        if (Graph_Windows->objectName().isEmpty())
            Graph_Windows->setObjectName("Graph_Windows");
        Graph_Windows->resize(817, 532);
        widget = new QCustomPlot(Graph_Windows);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 90, 801, 441));
        pushButton = new QPushButton(Graph_Windows);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 10, 241, 71));
        pushButton->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Candara\";\n"
"background-color: grey;\n"
"border-radius: 15px;\n"
"color: white\n"
""));
        lineEdit_expression = new QLineEdit(Graph_Windows);
        lineEdit_expression->setObjectName("lineEdit_expression");
        lineEdit_expression->setGeometry(QRect(260, 10, 551, 31));
        lineEdit_expression->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(112, 105, 127);\n"
"border-radius: 20px;\n"
"color: white"));
        widget1 = new QWidget(Graph_Windows);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(260, 50, 551, 35));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_Y_min = new QLineEdit(widget1);
        lineEdit_Y_min->setObjectName("lineEdit_Y_min");
        lineEdit_Y_min->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(112, 105, 127);\n"
"border-radius: 20px;\n"
"color: white\n"
""));
        lineEdit_Y_min->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEdit_Y_min);

        lineEdit_Y_max = new QLineEdit(widget1);
        lineEdit_Y_max->setObjectName("lineEdit_Y_max");
        lineEdit_Y_max->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(112, 105, 127);\n"
"border-radius: 20px;\n"
"color: white\n"
""));
        lineEdit_Y_max->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEdit_Y_max);

        lineEdit_X_min = new QLineEdit(widget1);
        lineEdit_X_min->setObjectName("lineEdit_X_min");
        lineEdit_X_min->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(112, 105, 127);\n"
"border-radius: 20px;\n"
"color: white\n"
""));
        lineEdit_X_min->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEdit_X_min);

        lineEdit_X_max = new QLineEdit(widget1);
        lineEdit_X_max->setObjectName("lineEdit_X_max");
        lineEdit_X_max->setStyleSheet(QString::fromUtf8("font: 600 14pt \"Segoe UI Variable Small Semibol\";\n"
"background-color: rgb(112, 105, 127);\n"
"border-radius: 20px;\n"
"color: white\n"
""));
        lineEdit_X_max->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEdit_X_max);


        retranslateUi(Graph_Windows);

        QMetaObject::connectSlotsByName(Graph_Windows);
    } // setupUi

    void retranslateUi(QDialog *Graph_Windows)
    {
        Graph_Windows->setWindowTitle(QCoreApplication::translate("Graph_Windows", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Graph_Windows", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", nullptr));
        lineEdit_Y_min->setText(QString());
        lineEdit_Y_max->setText(QString());
        lineEdit_X_min->setText(QString());
        lineEdit_X_max->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Graph_Windows: public Ui_Graph_Windows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_WINDOWS_H
