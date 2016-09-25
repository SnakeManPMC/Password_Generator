#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
	Q_OBJECT

public:
	explicit Widget(QWidget *parent = 0);
	~Widget();
	QString GetRandomString();

private slots:
	void on_pushButton_clicked();

	void on_pushButton_Clipboard_clicked();

private:
	Ui::Widget *ui;
	QString randomString;
};

#endif // WIDGET_H
