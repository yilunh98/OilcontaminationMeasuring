#ifndef PARA_SET_H
#define PARA_SET_H
#include <QDialog>

namespace Ui{
	class Dialog;
}
class para_set: public QDialog{
	Q_OBJECT

public:
	explicit para_set(QWidget *parent = 0);
	~para_set();
	QString getinput();

private:
	Ui::Dialog *ui;
};

#endif //PARA_SET_H