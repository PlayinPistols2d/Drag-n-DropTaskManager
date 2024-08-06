#include "TaskSlot.h"
#include "EmployeeCard.h"
#include "ui_TaskSlot.h"
#include <QVBoxLayout>
#include <QMimeData>
#include <QDropEvent>

TaskSlot::TaskSlot(const QString &requiredRole, QWidget *parent)
    : QWidget(parent), ui(new Ui::TaskSlot), role(requiredRole), filled(false) {
    ui->setupUi(this);
    ui->roleLabel->setText(QString("Required: %1").arg(requiredRole));
    setAcceptDrops(true); // Enable accepting drops

    QVBoxLayout *layout = new QVBoxLayout(this);
    setLayout(layout);
}

TaskSlot::~TaskSlot() {
    delete ui;
}

bool TaskSlot::isFilled() const {
    return filled;
}

void TaskSlot::dragEnterEvent(QDragEnterEvent *event) {
    if (event->mimeData()->hasText()) {
        QStringList data = event->mimeData()->text().split(',');
        if (data.size() == 4 && data[1] == role) { // Check if role matches
            event->acceptProposedAction();
        }
    }
}

void TaskSlot::dropEvent(QDropEvent *event) {
    if (event->mimeData()->hasText()) {
        QStringList data = event->mimeData()->text().split(',');
        if (data.size() == 4 && data[1] == role) { // Check if role matches
            event->acceptProposedAction();
            filled = true;

            // Remove existing child widgets if any
            QLayoutItem *child;
            while ((child = layout()->takeAt(0)) != nullptr) {
                delete child->widget();
                delete child;
            }

            // Create a new EmployeeCard and add to the layout
            auto *card = new EmployeeCard(data[0], data[1], data[2].toInt(), data[3], this);
            layout()->addWidget(card);
        }
    }
}

