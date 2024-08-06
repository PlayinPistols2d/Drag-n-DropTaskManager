#include "EmployeeCard.h"
#include "ui_EmployeeCard.h"
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include <QPixmap>

EmployeeCard::EmployeeCard(const QString &name, const QString &role, int id, const QString &photoPath, QWidget *parent)
    : QWidget(parent), ui(new Ui::EmployeeCard), employeeName(name), employeeRole(role), employeeID(id), photoPath(photoPath) {
    ui->setupUi(this);

    QPixmap pixmap(photoPath);
    ui->photoLabel->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));

    ui->nameLabel->setText(name);
    ui->roleLabel->setText(role);
    ui->idLabel->setText(QString("ID: %1").arg(id));
}

EmployeeCard::~EmployeeCard() {
    delete ui;
}

void EmployeeCard::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        QDrag *drag = new QDrag(this);
        QMimeData *mimeData = new QMimeData;

        mimeData->setText(QString("%1,%2,%3,%4").arg(employeeName).arg(employeeRole).arg(employeeID).arg(photoPath));
        drag->setMimeData(mimeData);

        QPixmap pixmap(size());
        render(&pixmap);
        drag->setPixmap(pixmap);

        drag->exec(Qt::MoveAction);
    }
}
