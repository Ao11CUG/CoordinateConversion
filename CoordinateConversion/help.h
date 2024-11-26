#pragma once

#include <QWidget>
#include "ui_help.h"
#include <QTextEdit>
#include <QVBoxLayout>

class help : public QWidget
{
	Q_OBJECT

public:
	help(QWidget *parent = nullptr);
	~help();

private:
	Ui::helpClass ui;
	QTextEdit* textEdit;
};
