#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/RollingFileAppender.hh>
using namespace std;

int main(int argc, char* argv[])
{
	//Layout与Appender是一对一的关系
	//Category与Appender是一对多的关系
    log4cpp::PatternLayout* pLayout1 = new log4cpp::PatternLayout();
    pLayout1->setConversionPattern("%d: %p %c %x: %m%n");

    log4cpp::PatternLayout* pLayout2 = new log4cpp::PatternLayout();
    pLayout2->setConversionPattern("%d: %p %c %x: %m%n");
    
    log4cpp::Appender* fileAppender = 
		new log4cpp::FileAppender("fileAppender","wxb.log");
									//格式  目标文件名
    fileAppender->setLayout(pLayout1);//设置输出格式

    log4cpp::RollingFileAppender* rollfileAppender = 
    	new log4cpp::RollingFileAppender("rollfileAppender",
    									"rollwxb.log",//文件名
    									5*1024,//文件大小5*1024
    									1);//1个备份文件
    rollfileAppender->setLayout(pLayout2);
    
    log4cpp::Category & root = log4cpp::Category::getRoot().getInstance("RootName");
    root.addAppender(fileAppender);//设置Appender
    root.addAppender(rollfileAppender);//设置Appender
    root.setPriority(log4cpp::Priority::DEBUG);

    for (int i = 0; i < 100; i++)
    {
        ostringstream oss;
        oss<<i<<":Root Error Message!";
        root.error(oss.str());
    }
    
    log4cpp::Category::shutdown();
    return 0;
}
