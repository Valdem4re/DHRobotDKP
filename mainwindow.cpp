#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dhforwardkinematics.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMessageBox>
#include <memory>
#include <iostream>


MainWindow* MainWindow::m_pInstance = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("KFP for DH-Robot");
    this->setFixedSize(621, 400);

    QWidget* centralWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    QVBoxLayout *buttonLayout = new QVBoxLayout();

    QPushButton *addRowButton = new QPushButton("Add Row", this);
    QPushButton *removeRowButton = new QPushButton("Remove Row", this);
    QPushButton *calculateButton = new QPushButton("Calculate", this);

    resultXLabel = new QLabel("X: ", this);
    resultYLabel = new QLabel("Y: ", this);
    resultZLabel = new QLabel("Z: ", this);

    buttonLayout->addWidget(addRowButton);
    buttonLayout->addWidget(removeRowButton);
    buttonLayout->addWidget(calculateButton);

    buttonLayout->addWidget(resultXLabel);
    buttonLayout->addWidget(resultYLabel);
    buttonLayout->addWidget(resultZLabel);

    buttonLayout->setSpacing(1);
    buttonLayout->setContentsMargins(0, 0, 0, 0);

    m_tableWidget = new TableWidget(6, 5, this);
    m_tableWidget->setDefaultSettings();

    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(m_tableWidget);

    setCentralWidget(centralWidget);

    connect(addRowButton, &QPushButton::clicked, m_tableWidget, &TableWidget::pushBackRow);
    connect(removeRowButton, &QPushButton::clicked, m_tableWidget, &TableWidget::popRow);
    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::calculate);
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

void MainWindow::calculate()
{
    size_t rows = m_tableWidget->rowCount();
    size_t cols = m_tableWidget->columnCount();
    DHRobot robot;
    for(int i = 0; i < rows; ++i) {
        DHJoint joint;
        for(int j = 0; j < cols; ++j) {
            QTableWidgetItem* item = m_tableWidget->item(i, j);
            if(item == nullptr || item->text().isEmpty()) {
                QMessageBox::warning(this,
                "Warning", "There should be no empty cells.");
                break;
            }

            switch(j) {
            case 0:
                joint.setName(item->text());
                break;
            case 1:
                joint.setDHTheta(item->text().toDouble());
                break;
            case 2:
                joint.setDHa(item->text().toDouble());
                break;
            case 3:
                joint.setDHd(item->text().toDouble());
                break;
            case 4:
                joint.setDHAlpha(item->text().toDouble());
                break;
            default:
                QMessageBox::warning(this, "Error", "Something went wrong");
                break;
            }
        }
        joint.getInfo();
        robot.addJoint(std::make_shared<DHJoint>(joint));
    }

    DHForwardKinematics fk(robot);
    std::vector<std::vector<double>> resultMatrix = fk.computeEndEffectorPose();
    double x = resultMatrix[0][3];
    double y = resultMatrix[1][3];
    double z = resultMatrix[2][3];
    resultXLabel->setText("X: " + QString::number(x));
    resultYLabel->setText("Y: " + QString::number(y));
    resultZLabel->setText("Z: " + QString::number(z));
}
