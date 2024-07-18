#ifndef CHAREDIT_H
#define CHAREDIT_H

#include <QtWidgets>
class CharEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit CharEdit(QWidget* parent = nullptr);
private:
    void focusOutEvent(QFocusEvent* e);
    void focusInEvent(QFocusEvent* e);
private slots:
    void onTextChanged();
};

#endif // CHAREDIT_H
