#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
using namespace std;

int main(int argc, char* argv[])
{
	//创建一个osAppender对象,并指定其包含的Layout
    log4cpp::OstreamAppender* osAppender = 
		new log4cpp::OstreamAppender("osAppender",&cout);
						//osAppender的输出定向到标准输出cout
    osAppender->setLayout(new log4cpp::BasicLayout());
    
	//从系统中得到Category类的根,将osAppender添加到该Category中
    log4cpp::Category & root = log4cpp::Category::getRoot();
    root.addAppender(osAppender);

	//设置Category优先级
    root.setPriority(log4cpp::Priority::DEBUG);//设置优先级
    
	//记录日志
    root.error("Hello log4cpp in a Error Message!");//error级日志
    root.warn("Hello log4cpp in a Warning Message!");//warn级日志
    
	//关闭Category
    log4cpp::Category::shutdown();//释放内存，销毁new
    return 0;
}
