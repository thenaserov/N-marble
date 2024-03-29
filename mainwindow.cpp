#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
   , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   QWidget::setWindowTitle("Nahid maps");
   Marble::MarbleDirs::setMarbleDataPath("/home/traveller/hello-marble/compiled-marble/share/marble/data/");
//    Marble::MarbleDirs::setMarblePluginPath("/home/traveller/hello-marble/compiled-marble/lib/plugins/");
   map_widget_ = new Marble::MarbleWidget;
   connect(map_widget_, SIGNAL(mouseMoveGeoPosition(QString)), ui->coordinations_indicator_label, SLOT(setText(QString)));
   ui->base_widget->layout()->addWidget(map_widget_);
   map_widget_->setProjection(Marble::Spherical);
   map_widget_->setMapThemeId("earth/google Satelite/google Satelite.dgml");
   map_widget_->setWindowTitle("Hello Marble!");
}


MainWindow::~MainWindow()
{
   delete ui;
}


void MainWindow::SetCoodinates(qreal, qreal, Marble::GeoDataCoordinates::Unit)
{
}


void MainWindow::on_projection_bottun_clicked()
{
   if (ui->projection_bottun->text() == "Spherical")
   {
      ui->projection_bottun->setText("Mercator");
      map_widget_->setProjection(Marble::Mercator);
   }
   else if (ui->projection_bottun->text() == "Mercator")
   {
      ui->projection_bottun->setText("Spherical");
      map_widget_->setProjection(Marble::Spherical);
   }
}


void MainWindow::on_comboBox_currentIndexChanged(const QString& arg1)
{
   if (arg1 == "Google Satelite")
   {
      map_widget_->setMapThemeId("earth/google Satelite/google Satelite.dgml");
   }
   else if (arg1 == "Google Hybrid")
   {
      map_widget_->setMapThemeId("earth/google Hybrid/google Hybrid.dgml");
   }
   else if (arg1 == "Google Terrain")
   {
      map_widget_->setMapThemeId("earth/google Terrain/google Terrain.dgml");
   }
   else if (arg1 == "Google Streets")
   {
      map_widget_->setMapThemeId("earth/google Streets/google Streets.dgml");
   }
   else if (arg1 == "Blue Marble")
   {
      map_widget_->setMapThemeId("earth/bluemarble/bluemarble.dgml");
   }
   else if (arg1 == "City Lights")
   {
      map_widget_->setMapThemeId("earth/citylights/citylights.dgml");
   }
   else if (arg1 == "Open Street Map")
   {
      map_widget_->setMapThemeId("earth/openstreetmap/openstreetmap.dgml");
   }
   else if (arg1 == "Plain")
   {
      map_widget_->setMapThemeId("earth/plain/plain.dgml");
   }
   else if (arg1 == "SRTM")
   {
      map_widget_->setMapThemeId("earth/srtm/srtm.dgml");
   }
}
