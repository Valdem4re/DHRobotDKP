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
};

#endif // TABLEWIDGET_H
