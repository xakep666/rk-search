#include <QFileDialog>
#include <QMessageBox>
#include <sstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <QString>
#include <QVector>
#include "RkSearchLibrary.h"
#include "TestFileParser.h"
#include "Timer.h"
#include "searchform.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_validateButton_clicked()
{
    //select file
    auto file = QFileDialog::getOpenFileName(this,tr("Выберете файл с набором данных и ответов"),".",tr("Text file (*.txt)"));
    //parse
    auto testSets = TestFileParser::parseWithAnswer(file.toStdString());
    if (testSets.size()==0) {
        QMessageBox::critical(this,tr("Ошибка"),tr("Не удалось разобрать файл с ответами"));
        return;
    }
    try {
        std::for_each(testSets.cbegin(),testSets.cend(),[&](const TestSetWithAnswer &ts){
           auto result = RkSearchLibrary::find(ts.text,ts.samples);
           if (result!=ts.expectedIndexes) {
               std::ostringstream expected,actual;
               std::copy(ts.expectedIndexes.cbegin(),ts.expectedIndexes.cend(),std::ostream_iterator<int>(expected,","));
               std::copy(result.cbegin(),result.cend(),std::ostream_iterator<int>(actual,","));
               QMessageBox::critical(this,tr("Ошибка"),tr("Строка:%1\n,Ожидалось:%2\n,Получено:%3")
                                     .arg(QString::fromStdString(ts.text))
                                     .arg(QString::fromStdString(expected.str()))
                                     .arg(QString::fromStdString(actual.str())));
               throw std::exception();
           }
        });
    } catch (std::exception) {
        return;
    }
    QMessageBox::information(this,tr(""),tr("На тестовых данных алгоритм работает верно."));
}

void MainWindow::on_speedButton_clicked()
{
    //select file
    auto file = QFileDialog::getOpenFileName(this,tr("Выберете файл с набором данных"),".",tr("Text file (*.txt)"));
    //parse
    auto testSets = TestFileParser::parse(file.toStdString());
    if (testSets.size()==0) {
        QMessageBox::critical(this,tr("Ошибка"),tr("Не удалось разобрать файл"));
        return;
    }
    QVector<double> x;
    QVector<double> y;
    std::for_each(testSets.cbegin(),testSets.cend(),[&](const TestFileParser::testset &ts){
         Timer tm;
         RkSearchLibrary::StringHashMap samples(ts.second.size());
         std::for_each(ts.second.cbegin(),ts.second.cend(),[&](const std::string &s){samples.add(s);});
         tm.start();
         //ignore result
         RkSearchLibrary::find(ts.first,samples);
         tm.stop();
         x.append(static_cast<double>(ts.first.length()));
         y.append(static_cast<double>(tm.getTime()));
         tm.reset();
    });
    //build plot
    QCustomPlot *plot = new QCustomPlot(this);
    plot->clearGraphs();
    plot->addGraph();
    plot->graph(0)->setData(x,y);
    plot->xAxis->setLabel(tr("X, длина строки"));
    plot->yAxis->setLabel(tr("Y, время выполнения, нс"));
    plot->xAxis->setRange(0.0,*std::max_element(x.cbegin(),x.cend()));
    plot->yAxis->setRange(0.0,*std::max_element(y.cbegin(),y.cend()));
    plot->replot();
    plot->show();
}

void MainWindow::on_searchButton_clicked()
{
    SearchForm *sf = new SearchForm(this);
    sf->show();
}
