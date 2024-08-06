#ifndef TASKSLOT_H
#define TASKSLOT_H

#include <QWidget>
#include <QLabel>
#include <QDragEnterEvent>
#include <QDropEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class TaskSlot; }
QT_END_NAMESPACE

class TaskSlot : public QWidget {
    Q_OBJECT

public:
    TaskSlot(const QString &requiredRole, QWidget *parent = nullptr);
    ~TaskSlot();

    bool isFilled() const;

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;

private:
    Ui::TaskSlot *ui;
    QString role;
    bool filled;
};

#endif // TASKSLOT_H
