#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tablewidget.h"

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ~MainWindow();

    static MainWindow* getInstance();

private:
    explicit MainWindow(QWidget *parent = nullptr);

    static MainWindow* m_pInstance;

    TableWidget* m_tableWidget;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
