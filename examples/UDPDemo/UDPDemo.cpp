//// UDPDemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
////
//
///*
//    Copyright © 2017-2020, orcaer@yeah.net  All rights reserved.
//
//    Author: orcaer@yeah.net
//
//    Last modified: 2019-10-20
//
//    Description: https://github.com/wlgq2/uv-cpp
//*/
//
//
//#include <iostream>
//
//
//#include "EchoServer.hpp"
//#include "Clinet.hpp"
//#include <chrono>
//
//
//#include <stdio.h>
//#include <winsock2.h>
//
//#include <stdio.h>
//#include <winsock2.h>
//
//
//
//
//#define BUF_LEN  100
//
//using namespace uv;
//using namespace std;
//
////#define      TEST_SIGNAL      1
////#define      TEST_SERVER      1
////#define      TEST_CLIENT      1
////#define      TEST_ASYNC       1
////#define      TEST_TIMER       1
////#define      TEST_LOG         1
////#define      TEST_UDP         1
//
//#define      TEST_SIGNAL      0
//#define      TEST_SERVER      0
//#define      TEST_CLIENT      0
//#define      TEST_ASYNC       0
//#define      TEST_TIMER       0
//#define      TEST_LOG         0
//#define      TEST_UDP         1
//
//#define       TEST_IPV6       0
//
//EventLoop* loop = new EventLoop();
//
////void t1()
////{
////    this_thread::sleep_for(chrono::seconds(1000));
////    loop->runInThisLoop([]() {
////        loop->stop();
////        });
////
////};
////int test_2() {
////
////	
////		WSADATA wsaData;
////		WSAStartup(MAKEWORD(2, 2), &wsaData);
////		//创建套接字
////		SOCKET sock = socket(AF_INET, SOCK_DGRAM, 0);
////		//绑定套接字
//		//struct sockaddr_in servAddr;
////		memset(&servAddr, 0, sizeof(servAddr));  //每个字节都用0填充
////		servAddr.sin_family = PF_INET;  //使用IPv4地址
//		//servAddr.sin_addr.s_addr = htonl(INADDR_ANY); //自动获取IP地址
////		//servAddr.sin_addr.s_addr = inet_addr("192.168.1.56");//自动获取IP地址
////		servAddr.sin_port = htons(10003);  //端口
////		bind(sock, (SOCKADDR*)&servAddr, sizeof(SOCKADDR));
////		//接收客户端请求
////		SOCKADDR clntAddr;  //客户端地址信息
////		int nSize = sizeof(SOCKADDR);
////		char buffer[BUF_LEN];  //缓冲区
////		while (1) {
////			int strLen = recvfrom(sock, buffer, BUF_LEN, 0, &clntAddr, &nSize);
////			sendto(sock, buffer, strLen, 0, &clntAddr, nSize);
////		}
////		closesocket(sock);
////		WSACleanup();
////		return 0;
////	
////}
////
////int test_send() {
////	
////	WSADATA wd;
////	SOCKET ServerSock;
////	//char Buf[BUF_LEN] = { 0 };
////
////
////	char Buf[BUF_LEN] = { '1', '2', '3', '4','\0'};
////	SOCKADDR ClientAddr;
////	SOCKADDR_IN ServerSockAddr;
////	int addr_size = 0;
////
////
////	/* 初始化操作sock需要的DLL */
////	WSAStartup(MAKEWORD(2, 2), &wd);
////
////	/* 创建服务端socket */
////	if (-1 == (ServerSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)))
////	{
////		printf("socket error!\n");
////		exit(1);
////	}
////
////	/* 设置服务端信息 */
////	memset(&ServerSockAddr, 0, sizeof(ServerSockAddr)); 	// 给结构体ServerSockAddr清零
////	ServerSockAddr.sin_family = AF_INET;  
////	// 使用IPv4地址
////	// 
////	//ServerSockAddr.sin_addr.s_addr = htonl(INADDR_ANY); 	// 自动获取IP地址
////	//ServerSockAddr.sin_port = htons(1314);  				// 端口
////	ServerSockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
////	ServerSockAddr.sin_port = htons(10003);  
////
////	/* 绑定套接字 */
////
////	if (-1 == (bind(ServerSock, (SOCKADDR*)&ServerSockAddr, sizeof(SOCKADDR))))
////	{
////		printf("bind error!\n");
////		exit(1);
////	}
////
////	addr_size = sizeof(SOCKADDR);
////
////	while (1)
////	{
////		/* 接受客户端的返回数据 */
////		//int str_len = recvfrom(ServerSock, Buf, BUF_LEN, 0, &ClientAddr, &addr_size);
////
////		//printf("客户端发送过来的数据为：%s\n", Buf);
////
////		/* 发送数据到客户端 */
////		//sendto(ServerSock, Buf, str_len, 0, &ClientAddr, addr_size);
////		printf("a");
////		sendto(ServerSock, Buf, 4, 0, &ClientAddr, addr_size);
////
////		/* 清空缓冲区 */
////	//	memset(Buf, 0, BUF_LEN);
////	}
////
////	/*如果有退出循环的条件，这里还需要清除对socket库的使用*/
////	/* 关闭服务端套接字 */
////	//closesocket(ServerSock);
////	/* WSACleanup();*/
////
////	
////
////	/*如果有退出循环的条件，这里还需要清除对socket库的使用*/
////	/* 关闭服务端套接字 */
////	//closesocket(ServerSock);
////	/* WSACleanup();*/
////
////	return 0;
////
////};
//
//
//
//
//int main(int argc, char** args)
//{
//    //定义事件分发器类
//   
//    //or
//    //EventLoop* loop = EventLoop::DefaultLoop();
//
//#if    TEST_SIGNAL
//    //接管SIGPIPE信号。
//    Signal signal(loop, 13, [](int sig)
//        {
//            //SIGPIPE
//        });
//
//#endif
//
//
//    //server对象
//#if   TEST_SERVER
//#if    TEST_IPV6
//    SocketAddr addr1("0:0:0:0:0:0:0:0", 10002, SocketAddr::Ipv6);
//#else
//
//   // uv::SocketAddr serverAddr("127.0.0.1", 10005, uv::SocketAddr::Ipv4);
//
//
//    SocketAddr addr1("127.0.0.1", 10002, SocketAddr::Ipv4);
//#endif
//
//    EchoServer server(loop);
//    //心跳超时
//    server.setTimeout(40);
//    server.bindAndListen(addr1);
//#endif
//
//
//    //client对象
//#if  TEST_CLIENT
//#if    TEST_IPV6
//    SocketAddr addr2("0:0:0:0:0:0:0:1", 10002, SocketAddr::Ipv6);
//#else
//    SocketAddr addr2("127.0.0.1", 10002, SocketAddr::Ipv4);
//#endif
//    Client client(loop);
//    client.connectToServer(addr2);
//
//#if  1
//
//    //跨线程发送数据
//    std::thread thread([&client]()
//        {
//            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
//            char* data = new char[4]{ 't','e','s','t' };
//
//            //线程安全;
//            client.writeInLoop(data, sizeof(data),
//                [](uv::WriteInfo& info)
//                {
//                    //数据需要在发生完成回调中释放
//                    //write message error.
//                    if (0 != info.status)
//                    {
//                        //打印错误信息
//                        std::cout << "Write error ：" << EventLoop::GetErrorMessage(info.status) << std::endl;
//                    }
//                    delete[] info.buf;
//                });
//        });
//#endif
//
//#endif
//
//
//    //loop线程中异步执行函数，用于跨线程操作。
//    //相对于原生libuv async接口，修复了调用多次可能只运行一次的问题。
//#if  TEST_ASYNC
//    loop->runInThisLoop(
//        []()
//        {
//            std::cout << "run function in loop thread one." << std::endl;
//        });
//
//    loop->runInThisLoop(
//        []()
//        {
//            std::cout << "run function in loop thread two." << std::endl;
//        });
//#endif
//
//
//    //定时器测试
//#if  TEST_TIMER
//    Timer timer(loop, 1000, 1000,
//        [](Timer*)
//        {
//            std::cout << "timer callback test..." << std::endl;
//        });
//    timer.start();
//
//    //定时器只运行一次及释放,可用于tcp重连,单次消息超时等。
//    Timer* pTimer = new Timer(loop, 1000, 0,
//        [](Timer* handle)
//        {
//            std::cout << "timer callback run onice." << std::endl;
//            handle->close([](Timer* ptr)
//                {
//                    std::cout << "release timer ptr." << std::endl;
//                    //释放定时器对象。
//                    delete ptr;
//                });
//        });
//    pTimer->start();
//#endif
//
//    //log接口绑定
//#if  TEST_LOG
//    auto log = uv::LogWriter::Instance();
//    log->registerInterface(
//        [](int level, const std::string& info)
//        {
//            std::cout << uv::LogWriter::Instance()->getLevelName(level) << " :" << info << std::endl;
//        });
//    log->setLevel(uv::LogWriter::Debug);
//    log->debug("debug message");
//    log->info("info message");
//    log->warn("warn message");
//    log->error("error message");
//    log->fatal("fatal message");
//#endif
//
//
//#if  TEST_UDP
// /*   SocketAddr addr3("127.0.0.1", 10003);
//    uv::Udp udpReceive(loop);
//    udpReceive.setMessageCallback(
//        [&udpReceive](SocketAddr& from, const char* data, unsigned size)
//        {
//            std::string msg(data, size);
//            std::cout << "udp receive message from " << from.toStr() << " :" << msg << std::endl;
//            udpReceive.send(from, data, size);
//        });
//    udpReceive.bindAndRead(addr3);*/
//
//
//    SocketAddr addr3("192.168.1.107", 10003);
//  //  SocketAddr addr4("127.0.0.1", 10004);
//   //SocketAddr addr3("192.168.1.107", 10003);
//    int i = 0;
//    uv::Udp udpSend(loop);
//    while (true)
//    {
//       // if(i>10) break;
//        this_thread::sleep_for(chrono::seconds());
//      
//      /*  udpSend.setMessageCallback(
//            [](SocketAddr& from, const char* data, unsigned size)
//            {
//                std::string msg(data, size);
//                std::cout << "udp call message :" << msg << std::endl;;
//            });
//        udpSend.bindAndRead(addr4);*/
//        char udpmsg[] = "udp test...";
//        udpSend.send(addr3, udpmsg, sizeof(udpmsg));
//        i++;
//    }
//#endif
//    std::cout << "serve_run" << std::endl;
//   // loop->run();
//    std::cout << "................................" << std::endl;
//    delete loop;
//
//
//
//
//}


#include "uv.h"
//#include "task.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

static uv_udp_t client;

static uv_loop_t *loop;

static void alloc_cb(uv_handle_t* handle,
    size_t suggested_size,
    uv_buf_t* buf)
{
    static char slab[65536];
    buf->base = slab;
    buf->len = sizeof(slab);
}

static void close_cb(uv_handle_t* handle)
{
    uv_is_closing(handle);
}

static void cl_recv_cb(uv_udp_t* handle,
    ssize_t nread,
    const uv_buf_t* buf,
    const struct sockaddr* addr,
    unsigned flags)
{
    if (nread < 0)
    {

    }

    if (nread == 0)
    {
        return;
    }

    printf("I receive the message from server:%s\n", buf->base);

    uv_close((uv_handle_t*) handle, close_cb);

	//std::cout<<"zzzzzzz"<<std::endl;
	Sleep(6000);


}


static void cl_send_cb(uv_udp_send_t* req, int status)
{
    uv_udp_recv_start(req->handle, alloc_cb, cl_recv_cb);
}

int main(void)
{
    struct sockaddr_in addr;
    uv_udp_send_t req;
    uv_buf_t buf;
    int r;

    loop = uv_default_loop();

    // r = uv_ip4_addr("0.0.0.0", 0, &addr);
    // r = uv_udp_init(loop, &client);
    // r = uv_udp_bind(&client, (const struct sockaddr*) &addr, 0);
    // r = uv_udp_set_broadcast(&client, 1);
    // uv_ip4_addr("255.255.255.255", 8899, &addr);
    // buf = uv_buf_init((char*)"PING", 4);
    // printf("I am sending message to server:%s.\n", buf.base);




	r = uv_ip4_addr("0.0.0.0", 0, &addr);
  // 	uv_ip4_addr("255.255.255.255", 8899, &addr);
    r = uv_udp_init(loop, &client);
    r = uv_udp_bind(&client, (const struct sockaddr*) &addr, 0);
    r = uv_udp_set_broadcast(&client, 1);
    uv_ip4_addr("255.255.255.255", 8899, &addr);
   // buf = uv_buf_init((char*)"PING", 4);
    while (true)
    {
        float data[208] = { 5.3,2.8,4.5, 1.9, -0.7 };
		//buf = uv_buf_init((char*)"PING11111111", 12);
        buf = uv_buf_init((char*)data, 208*4);
		printf("I am sending message to server\n");
		uv_udp_send(&req,
			&client,
			&buf,
			1,
			(const struct sockaddr*)&addr,
			cl_send_cb);
    }
 
//	Sleep(10000);
  //  uv_run(loop, UV_RUN_DEFAULT);

    return 0;
}