#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QCloseEvent>
#include <QSettings>
#include <QVector>

#include "opencv2/opencv.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_inputImgButton_pressed();

    void on_outputImgButton_pressed();

    void on_applyButton_pressed();

private:
    Ui::MainWindow *ui;
    void loadSettings();
    void saveSettings();
    void processImage();
};

#endif // MAINWINDOW_H
