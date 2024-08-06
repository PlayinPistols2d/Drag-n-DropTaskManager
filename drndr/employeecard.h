#ifndef EMPLOYEECARD_H
#define EMPLOYEECARD_H

#include <QWidget>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class EmployeeCard; }
QT_END_NAMESPACE

class EmployeeCard : public QWidget {
    Q_OBJECT

public:
    EmployeeCard(const QString &name, const QString &role, int id, const QString &photoPath, QWidget *parent = nullptr);
    ~EmployeeCard();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::EmployeeCard *ui;
    QString employeeName;
    QString employeeRole;
    int employeeID;
    QString photoPath;
};

#endif // EMPLOYEECARD_H
