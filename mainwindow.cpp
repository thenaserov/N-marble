#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Marble::MarbleDirs::setMarbleDataPath("/home/traveller/hello-marble/compiled-marble/share/marble/data/");
    map_widget_ = new Marble::MarbleWidget;
    ui->base_widget->layout()->addWidget(map_widget_);
    map_widget_->setProjection(Marble::Spherical);
    map_widget_->setMapThemeId("earth/google Hybrid/google Hybrid.dgml");
    map_widget_->setWindowTitle("Hello Marble!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

