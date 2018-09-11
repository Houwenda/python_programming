#include "dialogdraw.h"
#include "ui_dialogdraw.h"

DialogDraw::DialogDraw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDraw)
{
    ui->setupUi(this);
}

DialogDraw::~DialogDraw()
{
    delete ui;
}
