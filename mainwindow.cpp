#include<QTimer>

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Mission Timer Setup
    missionTimer = new QTimer(this);
    timeRemainingSeconds = 900;
    connect(missionTimer, &QTimer::timeout, this, &MainWindow::updateTimer);

    //Add stuff to task list here:
    taskList.append("Task 1");
    taskList.append("Task 2");
    taskList.append("Task 3");
    taskList.append("Task 4");
    taskList.append("Task 5");

    currentTaskIndex = 0;

    updateTaskDisplay();

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_finishedButton_clicked(){
    if(currentTaskIndex < taskList.size()){
        currentTaskIndex++;
        updateTaskDisplay();
    }
}


void MainWindow::on_skipButton_clicked(){
    if(currentTaskIndex < taskList.size() - 1){
        currentTaskIndex++;
        updateTaskDisplay();
    }
}


void MainWindow::on_prevButton_clicked(){
    if(currentTaskIndex > 0){
        currentTaskIndex--;
        updateTaskDisplay();
    }
}


void MainWindow::on_startButton_clicked(){
    if(!missionTimer->isActive()){
        missionTimer->start(1000);
    }
}


void MainWindow::on_stopButton_clicked(){
    if(missionTimer->isActive()){
        missionTimer->stop();
    }
}

void MainWindow::updateTimer(){
    if(timeRemainingSeconds > 0){
        timeRemainingSeconds--;

        int minutes = timeRemainingSeconds / 60;
        int seconds = timeRemainingSeconds % 60;

        QString timeText = QString("%1:%2")
                               .arg(minutes, 2, 10, QChar('0'))
                               .arg(seconds, 2, 10, QChar('0'));

        ui->timerLabel->display(timeText);
    }
    else{
        missionTimer->stop();
        ui->timerLabel->display("00:00");
    }
}

void MainWindow::updateTaskDisplay(){
    if(currentTaskIndex >= 0 && currentTaskIndex < taskList.size()){
        ui->taskLabel->setText(taskList[currentTaskIndex]);
    }
    else{
        ui->taskLabel->setText("All tasks completed.");
    }
}