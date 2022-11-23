#include "myurl.h"

myUrl::myUrl()
{

}

QString myUrl::getBaseUrl()
{
    return baseUrl;
}

QString myUrl::baseUrl
{
    "http://localhost:3000"
    //https://myAzure.com
};
