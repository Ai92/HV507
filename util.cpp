#include "util.h"

int splitString(String data, char delimiter, String *dst)
{
    int index = 0;
    int datalength = data.length();
    for (int i = 0; i < datalength; i++)
    {
        char tmp = data.charAt(i);
        if (tmp == delimiter)
        {
            index++;
            if (index > (datalength - 1))
                return -1;
        }
        else
            dst[index] += tmp;
    }
    return (index + 1);
}
