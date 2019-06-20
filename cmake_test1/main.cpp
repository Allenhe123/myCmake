#include<iostream>
#include "src/test1.h"
#include "logging.h"
 
int main(int argc, char** argv)
{
    google::InitGoogleLogging((const char *)argv[0]);
    google::SetLogDestination(google::GLOG_INFO,"./mylog.txt");
    LOG(WARNING) <<"thisis the 1st warning!";

    std::cout<<"Hello word!"<<std::endl;
    print_msg();

#ifdef _DEBUG
     std::cout << "running in debug mode" << std::endl;
#else
     std::cout << "running in release mode" << std::endl;
#endif // _DEBUG

    return 0;
}
