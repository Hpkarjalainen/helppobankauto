#ifndef MYURL_H
#define MYURL_H

#include <QString>

class myUrl
{
public:
    myUrl();
    static QString getBaseUrl();

private:
    static QString baseUrl;
};

#endif // MYURL_H
