#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QVBoxLayout>
#include <QPushButton>
MainWindow* MainWindow::m_pInstance = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedWidth(502);
    this->setFixedHeight(400);
    m_tableWidget = new TableWidget(6, 5, this);
    m_tableWidget->setDefaultSettings();

    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    layout->addWidget(m_tableWidget);

    QPushButton *addRowButton = new QPushButton("Add Row", this);
    layout->addWidget(addRowButton);

    //connect(addRowButton, &QPushButton::clicked, m_tableWidget, &QTableWidget::addRow);
    setCentralWidget(m_tableWidget);

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
