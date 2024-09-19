#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QTableWidget>
#include <QTableView>
#include <QTableWidgetItem>
#include <QHeaderView>


class TableWidget : public QTableWidget
{
public:
    TableWidget(size_t rows = 6, size_t cols = 5, QWidget* parent = nullptr);

    void setDefaultSettings();

public slots:
    void pushBackRow() {
        int rowCount = this->rowCount();
        this->insertRow(rowCount);
    }

    void popRow() {
        int rowCount = this->rowCount();
        if (rowCount > 0) {
            this->removeRow(rowCount - 1);
        }
    }
};

#endif // TABLEWIDGET_H
