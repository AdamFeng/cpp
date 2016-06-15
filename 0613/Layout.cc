#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
using namespace std;

int main(int argc, char* argv[])
{
	//指定日志输出的目的地
    log4cpp::OstreamAppender* osAppender = new 
		log4cpp::OstreamAppender("osAppender", &cout);
								//描述     日志输出目的地
    
    //格式化输出日志信息
    log4cpp::PatternLayout * pLayout = 
		new log4cpp::PatternLayout();//定义一个PatternLayout
    pLayout->setConversionPattern("%d: %p %c %x: %m%n");//设置日志输出格式
							//日期 优先级 Category NDC 消息 换行
	osAppender->setLayout(pLayout);
    
    log4cpp::Category & root = log4cpp::Category::getRoot();//从系统中取Category类的根
    log4cpp::Category & infoCategory = 
		root.getInstance("infoCategory");//引号内是给infoCategory取名字
    infoCategory.addAppender(osAppender);//设置输出目的地
    infoCategory.setPriority(log4cpp::Priority::INFO);//设置优先级

	//按优先级输出日志
    infoCategory.info("system is running");
    infoCategory.warn("system has a warning");
    infoCategory.error("system has a error, can't find a file");
    infoCategory.fatal("system has a fatal error,must be shutdown");
    infoCategory.info("system shutdown,you can find some information in system log");

	//关闭new
    log4cpp::Category::shutdown();
    
    return 0;
}
