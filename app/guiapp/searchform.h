#ifndef SEARCHFORM_H
#define SEARCHFORM_H

#include <QDialog>

namespace Ui {
class SearchForm;
}

class SearchForm : public QDialog
{
    Q_OBJECT

public:
    explicit SearchForm(QWidget *parent = 0);
    ~SearchForm();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::SearchForm *ui;
};

#endif // SEARCHFORM_H
