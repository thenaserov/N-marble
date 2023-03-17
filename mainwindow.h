#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "compiled-marble/include/marble/MarbleWidget.h"
#include "compiled-marble/include/marble/MarbleDirs.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Marble::MarbleWidget *map_widget_ = nullptr;
};
#endif // MAINWINDOW_H