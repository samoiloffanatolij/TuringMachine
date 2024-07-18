#include "actionparser.h"

ActionParser::ActionParser()
{

}

QStringList ActionParser::Parse(QString s) {
    QStringList list;
    bool stateInput = false;
    QString stateIndex = "";
    for (auto c: s) {
        if (c.isDigit() && stateInput) {
            stateIndex += c;
        } else {
           if (stateInput) {
               list << "Q" + stateIndex;
               stateIndex = "";
           }
           stateInput = false;
           if (c.toLower() == 'q') {
               stateInput = true;
           } else {
                list << c;
           }
        }
    }
    if (stateInput) {
        list << "Q" + stateIndex;
        stateIndex = "";
    }
    return list;
}
