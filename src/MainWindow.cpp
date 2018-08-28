#include "MainWindow.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	myString("Today is Tuesday")
{
	auto *widget = new QWidget(this);
	auto *layoutMain = new QVBoxLayout(widget);
	auto *edit = new QLineEdit(this);
	auto *label = new QLabel(myString, this);

	layoutMain->addWidget(edit);
	layoutMain->addWidget(label);
	layoutMain->addStretch();

	connect(edit, &QLineEdit::textEdited, [this, label](const QString &text){
		setBoldForMatching(text, label);
	});

	setCentralWidget(widget);
	resize(200, 100);
}

void MainWindow::setBoldForMatching(const QString &p_text, QLabel *label) const
{
	QRegExp regExp(p_text.toLower(), Qt::CaseInsensitive, QRegExp::RegExp);
	QString str = myString;

	regExp.indexIn(str, 0);

	QStringList matches(regExp.capturedTexts());

	if (matches.isEmpty())
		return;

	QString match(matches.first());

	str.replace(match, "<b>" + match + "</b>");

	label->setText(str);
}
