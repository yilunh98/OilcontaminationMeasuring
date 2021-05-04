#ifndef PARA_SET_H
#define PARA_SET_H
#include <QDialog>
#include <QDebug>
namespace Ui{
	class Dialog;
}
class para_set: public QDialog{
	Q_OBJECT

public:
	explicit para_set(QWidget *parent = 0);
	~para_set();
	QString getinput();

public:
	Ui::Dialog *ui;
};

#endif //PARA_SET_H