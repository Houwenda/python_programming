#ifndef DIALOGDRAW_H
#define DIALOGDRAW_H

#include <QDialog>

namespace Ui {
class DialogDraw;
}

class DialogDraw : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDraw(QWidget *parent = 0);
    ~DialogDraw();

private:
    Ui::DialogDraw *ui;
};

#endif // DIALOGDRAW_H
