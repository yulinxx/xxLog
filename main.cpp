#include <iostream>
#include "xxLog.h"

int main()
{
    int i = 0;

    char szData[128] = "此文件包含 main 函数。程序执行将在此处开始并结束";

    for (int i = 0; i < 100; i++)
    {
        RDLOG_TRACE(szData << i);
        RDLOG_DEBUG(szData << i);
        RDLOG_INFO(szData << i);
        RDLOG_WARN(szData << i);
        RDLOG_ERROR(szData << i);
        RDLOG_FATAL(szData << i);

        std::string strInfo = "abc中文+-*/";
        RDLOG_INFO(strInfo);

        const char* pCh = "xxx 1123j另文 朝右两岸三地 f32111\n\naaaabccc";
        RDLOG_INFO(pCh);

        if (i == 30)
        {
            RDLOG_OFF();
        }

        if (i == 80)
            RDLOG_REC_ERROR();

        if (i == 93)
            RDLOG_ON()
    }

    std::cout << "end log \n";
    RDLOG_CLOSE();
    return 0;
}