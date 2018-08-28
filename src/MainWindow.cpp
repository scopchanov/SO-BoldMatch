#include "MainWindow.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	myString("Today is today")
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
	QRegExp regExp(p_text, Qt::CaseInsensitive, QRegExp::RegExp);
	QString str = myString;

	if (p_text.isEmpty()) {
		label->setText(myString);
		return;
	}

	int count = 0;
	int pos = 0;
	QStringList matches;

	while ((pos = regExp.indexIn(str, pos)) != -1) {
		++count;
		pos += regExp.matchedLength();
		matches.append(regExp.capturedTexts());
	}

	foreach (const QString &match, matches) {
		str.replace(match, "<b>" + match + "</b>");
	}

	label->setText(str);
}
