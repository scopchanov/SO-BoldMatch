#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLabel;

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = nullptr);

private:
	void setBoldForMatching(const QString &p_text, QLabel *label) const;

	const QString myString;
};

#endif // MAINWINDOW_H
