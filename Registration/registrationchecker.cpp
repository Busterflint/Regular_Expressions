#include "registrationchecker.h"

RegistrationChecker::RegistrationChecker()
{
    standard = QRegExp("^[B-DF-HJ-NP-TV-Z]{3,3}[0-9]{3,3}(GP|L|NW|EC|FS|MP|NC)$");
    newgp = QRegExp("^[BCDFGHJKLMNPQRSTVWXYZ]{2,2}[0-9]{2,2}[B-DF-HJ-NP-TV-Z]{2,2}GP$");
    wckzn = QRegExp("^(C|N)[A-Z]{1,2}[0-9]{1,6}$");
    personal = QRegExp("^[A-Z0-9]{1,6}(GP|L|NW|EC|FS|MP|NC|WC|ZN)$");
}

QValidator::State RegistrationChecker::validate(QString & s, int &) const
{
    if (standard.exactMatch(s) || newgp.exactMatch(s) || wckzn.exactMatch(s) || personal.exactMatch(s))
        return QValidator::Acceptable;
    return QValidator::Invalid;
}
