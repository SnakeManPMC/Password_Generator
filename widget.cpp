#include "widget.h"
#include "ui_widget.h"
#include <QTime>
#include <QClipboard>
#include <QRandomGenerator>

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
    QRandomGenerator(timmy.secsTo(QTime::currentTime()));

	QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
	if (ui->checkBox->isChecked()) possibleCharacters = ("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789`~!@#$%^&*()_-+={}[]:;<>,.?/");
	// `~!@#$%^&*()_-+={}[]\|:;"'<>,.?/
	const int randomStringLength = ui->spinBox->value();

	randomString.clear();

	for(int i=0; i<randomStringLength; ++i)
	{
        int index = QRandomGenerator::global()->bounded(possibleCharacters.length());
		QChar nextChar = possibleCharacters.at(index);
		randomString.append(nextChar);
	}
	return randomString;
}

void Widget::on_pushButton_clicked()
{
    ui->lineEdit->setText(GetRandomString());
}

void Widget::on_pushButton_Clipboard_clicked()
{
	QClipboard *clipboard = QApplication::clipboard();
	clipboard->setText(randomString);
}
