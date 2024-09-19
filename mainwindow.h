#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tablewidget.h"

#include <QMainWindow>
#include <QLabel>


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

public slots:

    void calculate();

private:
    explicit MainWindow(QWidget *parent = nullptr);

    static MainWindow* m_pInstance;

    TableWidget* m_tableWidget;

    QLabel *resultXLabel;
    QLabel *resultYLabel;
    QLabel *resultZLabel;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
