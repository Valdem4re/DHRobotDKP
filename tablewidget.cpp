#include "tablewidget.h"

TableWidget::TableWidget(size_t rows, size_t cols, QWidget* parent) :
    QTableWidget(rows, cols, parent) {}

void TableWidget::setDefaultSettings()
{
    QStringList labels = {
        "Joint",
        "Theta (degree)",
        "a (m)",
        "d (m)",
        "alpha (rad)"
    };
    this->verticalHeader()->setVisible(false);
    this->setHorizontalHeaderLabels(labels);
    for(int i = 0; i < 6; ++i) {
        this->setItem(i, 0, new QTableWidgetItem(QString("Joint %1").arg(i)));
    }
    this->setItem(0, 1, new QTableWidgetItem(QString("15")));
    this->setItem(1, 1, new QTableWidgetItem(QString("-50")));
    this->setItem(2, 1, new QTableWidgetItem(QString("-60")));
    this->setItem(3, 1, new QTableWidgetItem(QString("95")));
    this->setItem(4, 1, new QTableWidgetItem(QString("50")));
    this->setItem(5, 1, new QTableWidgetItem(QString("0")));

    this->setItem(0, 2, new QTableWidgetItem(QString("0")));
    this->setItem(1, 2, new QTableWidgetItem(QString("-0.8")));
    this->setItem(2, 2, new QTableWidgetItem(QString("-0.590")));
    this->setItem(3, 2, new QTableWidgetItem(QString("0")));
    this->setItem(4, 2, new QTableWidgetItem(QString("0")));
    this->setItem(5, 2, new QTableWidgetItem(QString("0")));

    this->setItem(0, 3, new QTableWidgetItem(QString("0.213")));
    this->setItem(1, 3, new QTableWidgetItem(QString("0.193")));
    this->setItem(2, 3, new QTableWidgetItem(QString("0.16")));
    this->setItem(3, 3, new QTableWidgetItem(QString("0.25")));
    this->setItem(4, 3, new QTableWidgetItem(QString("0.28")));
    this->setItem(5, 3, new QTableWidgetItem(QString("0.25")));

    this->setItem(0, 4, new QTableWidgetItem(QString("%1").arg(3.1415 / 2.f)));
    this->setItem(1, 4, new QTableWidgetItem(QString("0")));
    this->setItem(2, 4, new QTableWidgetItem(QString("0")));
    this->setItem(3, 4, new QTableWidgetItem(QString("%1").arg(3.1415 / 2.f)));
    this->setItem(4, 4, new QTableWidgetItem(QString("%1").arg(-3.1415 / 2.f)));
    this->setItem(5, 4, new QTableWidgetItem(QString("0")));

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}
