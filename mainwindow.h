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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_finishedButton_clicked();

    void on_skipButton_clicked();

    void on_prevButton_clicked();

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void updateTimer();

private:
    Ui::MainWindow *ui;
    QTimer *missionTimer;
    int timeRemainingSeconds;
    QVector<QString> taskList;
    int currentTaskIndex;
    void updateTaskDisplay();
};
#endif // MAINWINDOW_H
