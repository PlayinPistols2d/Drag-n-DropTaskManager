#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "EmployeeCard.h"
#include "TaskSlot.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);


    // Populate side panel with employee cards
    int j = 0;
    for (int i = 1; i <= 3; ++i) {
        j++;
        auto *card = new EmployeeCard(QString("Employee %1").arg(j), "Developer", j, "./employeePlaceholder.png", this);
        ui->sidePanelLayout->addWidget(card);
    }

    for (int i = 1; i <= 3; ++i) {
        j++;
        auto *card = new EmployeeCard(QString("Employee %1").arg(j), "Designer", j, "./employeePlaceholder.png", this);
        ui->sidePanelLayout->addWidget(card);
    }

    for (int i = 1; i <= 3; ++i) {
        j++;
        auto *card = new EmployeeCard(QString("Employee %1").arg(j), "Manager", j, "./employeePlaceholder.png", this);
        ui->sidePanelLayout->addWidget(card);
    }

    // Create and populate tasks
    createTasks();

    // Connect signals
    connect(ui->taskComboBox, &QComboBox::currentTextChanged, this, &MainWindow::onTaskChanged);
    connect(ui->submitButton, &QPushButton::clicked, this, &MainWindow::onSubmit);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::createTasks() {
    // Add tasks to the combo box
    ui->taskComboBox->addItem("Task A");
    ui->taskComboBox->addItem("Task B");
    ui->taskComboBox->addItem("Task C");
}

void MainWindow::onTaskChanged(const QString &task) {
    clearMainPanel();
    populateMainPanel(task);
}

void MainWindow::onSubmit() {
    if (validateSubmission()) {
        collectAndStoreData();
    } else {
        // Handle invalid submission
    }
}

void MainWindow::clearMainPanel() {
    QLayoutItem *child;
    while ((child = ui->mainPanelLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
}

void MainWindow::populateMainPanel(const QString &task) {
    if (task == "Task A") {
        for (int i = 0; i < 3; ++i) {
            auto *slot = new TaskSlot("Developer", this);
            ui->mainPanelLayout->addWidget(slot);
        }
    } else if (task == "Task B") {
        for (int i = 0; i < 2; ++i) {
            auto *slot = new TaskSlot("Manager", this);
            ui->mainPanelLayout->addWidget(slot);
        }
    } else if (task == "Task C") {
        for (int i = 0; i < 4; ++i) {
            auto *slot = new TaskSlot("Designer", this);
            ui->mainPanelLayout->addWidget(slot);
        }
    }
}

bool MainWindow::validateSubmission() {
    for (int i = 0; i < ui->mainPanelLayout->count(); ++i) {
        auto *slot = qobject_cast<TaskSlot *>(ui->mainPanelLayout->itemAt(i)->widget());
        if (!slot->isFilled()) {
            return false;
        }
    }
    return true;
}

void MainWindow::collectAndStoreData() {
    for (int i = 0; i < ui->mainPanelLayout->count(); ++i) {
        auto *slot = qobject_cast<TaskSlot *>(ui->mainPanelLayout->itemAt(i)->widget());
        // Store the assigned employee information
        // ...
    }
}
