#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    MainWindow(QWidget *parent = nullptr);

    static MainWindow* m_pInstance;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
