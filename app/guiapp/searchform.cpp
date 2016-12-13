#include <algorithm>
#include <sstream>
#include <iterator>
#include <QStringList>
#include <QString>
#include <QMessageBox>
#include "RkSearchLibrary.h"
#include "searchform.h"
#include "ui_searchform.h"

SearchForm::SearchForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchForm)
{
    ui->setupUi(this);
}

SearchForm::~SearchForm()
{
    delete ui;
}

void SearchForm::on_buttonBox_rejected()
{
    destroy();
}

void SearchForm::on_buttonBox_accepted()
{
    auto text = ui->textEdit->text();
    auto samples = ui->samplesEdit->toPlainText().split('\n',QString::SkipEmptyParts);
    //validate samples
    try {
        int linelen = -1;
        std::for_each(samples.cbegin(),samples.cend(),[&](const QString &line){
            if (linelen==-1) linelen=line.length();
            else if (linelen!=line.length()) throw std::exception();
        });
        //if samples is empty
        if (linelen == -1) throw std::exception();
    } catch (std::exception) {
        QMessageBox::critical(this,tr("Ошибка"),tr("Образцы должны быть одинаковой длины"));
        return;
    }
    if (text.length()<samples[0].length()) {
        QMessageBox::critical(this,tr("Ошибка"),tr("Длина текста должна быть больше или равна длине образцов"));
        return;
    }
    RkSearchLibrary::StringHashMap sampleHashes(samples.length());
    std::for_each(samples.cbegin(),samples.cend(),[&](const QString &line){
        sampleHashes.add(line.toStdString());
    });
    auto indexes = RkSearchLibrary::find(text.toStdString(),sampleHashes);
    std::ostringstream indexesOs;
    std::copy(indexes.cbegin(),indexes.cend(),std::ostream_iterator<int>(indexesOs,","));
    QMessageBox::information(this,tr("Результат"),tr("Образцы найдены на:\n%1")
                             .arg(QString::fromStdString(indexesOs.str())));
}
