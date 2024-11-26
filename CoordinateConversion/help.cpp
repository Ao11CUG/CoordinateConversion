#include "help.h"

help::help(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    textEdit = findChild<QTextEdit*>("textEdit");
    if (textEdit) {
        textEdit->setReadOnly(true);

        textEdit->setText(
            "���ߣ������\n"
            "ѧУ���й����ʴ�ѧ\n"
            "ѧԺ����������Ϣ����ѧԺ\n"
            "��ʾ��\n"
            "1.�鿴��λͼʱ���ε���Ŵ�ť��\n"
            "2.����Ҫ�����ı����棬�������ɱ���󣬵�������ļ���ť���������ı��棻"
        );
    }

    setWindowTitle(tr("Help"));
}

help::~help()
{}
