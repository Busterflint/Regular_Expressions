#ifndef REGISTRATIONCHECKER_H
#define REGISTRATIONCHECKER_H

#include <QValidator>
#include <QRegExp>

class RegistrationChecker: public QValidator
{
public:
    RegistrationChecker();
    QValidator::State validate(QString & s, int &) const;
private:
    QRegExp standard;
    QRegExp newgp;
    QRegExp wckzn;
    QRegExp personal;
};

#endif // REGISTRATIONCHECKER_H
