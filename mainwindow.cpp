#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow* MainWindow::m_pInstance = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow* MainWindow::getInstance()
{
    if (m_pInstance == nullptr) {
        m_pInstance = new MainWindow();
    }
    return m_pInstance;
}
