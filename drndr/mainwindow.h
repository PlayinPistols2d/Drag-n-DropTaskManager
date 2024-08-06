#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onTaskChanged(const QString &task);
    void onSubmit();

private:
    Ui::MainWindow *ui;
    void clearMainPanel();
    void populateMainPanel(const QString &task);
    bool validateSubmission();
    void collectAndStoreData();
    void createTasks();
};

#endif // MAINWINDOW_H
