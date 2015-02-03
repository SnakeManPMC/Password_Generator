#include "widget.h"
#include "ui_widget.h"
#include <QTime>

Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Widget)
{
	ui->setupUi(this);
}

Widget::~Widget()
{
	delete ui;
}

QString Widget::GetRandomString()
{
	// initialize random seed:
	QTime timmy(0, 0, 0);
	qsrand(timmy.secsTo(QTime::currentTime()));

	QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
	if (ui->checkBox->isChecked()) possibleCharacters = ("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789`~!@#$%^&*()_-+={}[]:;<>,.?/");
	// `~!@#$%^&*()_-+={}[]\|:;"'<>,.?/
	const int randomStringLength = ui->spinBox->value();

	QString randomString;
	for(int i=0; i<randomStringLength; ++i)
	{
		int index = qrand() % possibleCharacters.length();
		QChar nextChar = possibleCharacters.at(index);
		randomString.append(nextChar);
	}
	return randomString;
}

void Widget::on_pushButton_clicked()
{
    ui->lineEdit->setText(GetRandomString());
}
