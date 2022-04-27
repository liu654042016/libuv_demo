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
//#include <thread>
//
//using namespace uv;
//using namespace std;
//
//
//
//#include <stdio.h>
//#include <winsock2.h>
//
//#define BUF_LEN  100
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
//EventLoop* loop = nullptr;
//
////void threadfun1(uv::EventLoop* loop)
//void threadfun1()
//{
//	cout << "threadfun1 start \r\n";
//	this_thread::sleep_for(chrono::seconds(1000));
//	//loop->runInThisLoop([loop]()
//     loop->runInThisLoop([]()
//		{
//			std::cout << "stop in loop thread id:" << std::this_thread::get_id() << std::endl;
//			loop->stop();
//		});
//    //loop->stop();
//	cout << "threadfun1 end \r\n";
//}
//
//
//int main(int argc, char** args)
//{
//    //定义事件分发器类
//   // EventLoop* loop = new EventLoop();
//     loop = new EventLoop();
//    //or
//    //EventLoop* loop = EventLoop::DefaultLoop();
//
//#if    TEST_SIGNAL
//    //接管SIGPIPE信号。
//    Signal signal(loop,13,[](int sig)
//    {
//        //SIGPIPE
//    });
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
//    {
//        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
//        char* data = new char[4] {'t','e','s','t'};
//       
//        //线程安全;
//        client.writeInLoop(data,sizeof(data),
//            [](uv::WriteInfo& info)
//        {
//            //数据需要在发生完成回调中释放
//            //write message error.
//            if (0 != info.status)
//            {
//                //打印错误信息
//                std::cout << "Write error ：" << EventLoop::GetErrorMessage(info.status) << std::endl;
//            }
//            delete[] info.buf;
//        });
//    });
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
//    {
//        std::cout << "run function in loop thread one." << std::endl;
//    });
//
//    loop->runInThisLoop(
//        []()
//    {
//        std::cout << "run function in loop thread two." << std::endl;
//    });
//#endif
//
//
//    //定时器测试
//#if  TEST_TIMER
//    Timer timer(loop, 1000, 1000,
//        [](Timer*)
//    {
//        std::cout << "timer callback test..." << std::endl;
//    });
//    timer.start();
//
//    //定时器只运行一次及释放,可用于tcp重连,单次消息超时等。
//    Timer* pTimer  =new Timer(loop, 1000, 0,
//        [](Timer* handle)
//    {
//        std::cout << "timer callback run onice."<< std::endl;
//        handle->close([](Timer* ptr)
//        {
//            std::cout << "release timer ptr."<< std::endl;
//            //释放定时器对象。
//            delete ptr;
//        });
//    });
//    pTimer->start();
//#endif
//
//    //log接口绑定
//#if  TEST_LOG
//    auto log = uv::LogWriter::Instance();
//    log->registerInterface(
//        [](int level, const std::string& info)
//    {
//        std::cout <<uv::LogWriter::Instance()->getLevelName( level) << " :" << info << std::endl;
//    });
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
//
//    //std::thread t2(threadfun1);
//   // std::thread t2( std::bind(&threadfun1, loop));
//   // std::thread t2(std::bind(&threadfun1));
//
//    //std::bind(&func, loop)
//    
//    SocketAddr addr3("127.0.0.1", 10003);
//  //  SocketAddr addr3("192.168.1.95", 54321);
//    uv::Udp udpReceive(loop);
//    udpReceive.setMessageCallback(
//        [&udpReceive](SocketAddr& from,const char* data,unsigned size)
//    {
//        std::string msg(data, size);
//        std::cout << "udp receive message from "<< from.toStr()<<" :" << msg << std::endl;
//      //  std::cout << "udp receive message from "<< from.tofloat()<<" :" << msg << std::endl;
//      //  udpReceive.send(from, data, size);
//    });
//    udpReceive.bindAndRead(addr3);
//
// /*   SocketAddr addr4("127.0.0.1", 10004);
//    uv::Udp udpSend(loop );
//    udpSend.setMessageCallback(
//        [](SocketAddr& from, const char* data, unsigned size)
//    {
//        std::string msg(data, size);
//        std::cout << "udp call message :" << msg << std::endl;;
//    });
//    udpSend.bindAndRead(addr4);
//    char udpmsg[] = "udp test...";
//    udpSend.send(addr3, udpmsg, sizeof(udpmsg));*/
//#endif
//    std::cout << "clent_run................." << std::endl;
//   
//    loop->run();
//
//	//loop->runInThisLoop(
//	//[]()
//	//{
// //      cout << this_thread::get_id() << endl;
//	//   std::cout << "run function in loop thread one." << std::endl;
//	//});
//
//   // t2.join();
//    std::cout << "aaaaaaaaa" << std::endl;
//    this_thread::sleep_for(chrono::seconds(10));
//    delete loop;
//}
////int main() {
////	
////	WSADATA wd;
////	SOCKET ClientSock;
////	//char Buf[BUF_LEN] = { 0 };
////	char Buf[BUF_LEN] = { 'a', 'b', 'c', 'd'};
////	SOCKADDR ServerAddr;
////	SOCKADDR_IN  ServerSockAddr;
////	int ServerAddrLen = 0;
////
////	/* 初始化操作sock需要的DLL */
////	WSAStartup(MAKEWORD(2, 2), &wd);
////
////	/* 创建客户端socket */
////	if (-1 == (ClientSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)))
////	{
////		printf("socket error!\n");
////		exit(1);
////	}
////
////	/* 向服务器发起请求 */
////	memset(&ServerSockAddr, 0, sizeof(ServerSockAddr));
////	ServerSockAddr.sin_family = AF_INET;
////	ServerSockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
////	ServerSockAddr.sin_port = htons(10003);
////
////	ServerAddrLen = sizeof(ServerAddr);
////
////	while (1)
////	{
////		//printf("请输入一个字符串，发送给服务端：");
////		//gets(Buf);
////		/* 发送数据到服务端 */
////	//	sendto(ClientSock, Buf, strlen(Buf), 0, (struct sockaddr*)&ServerSockAddr, sizeof(ServerSockAddr));
////
////		/* 接受服务端的返回数据 */
////		recvfrom(ClientSock, Buf, BUF_LEN, 0, &ServerAddr, &ServerAddrLen);
////		printf("服务端发送过来的数据为：%s\n", Buf);
////
////		memset(Buf, 0, BUF_LEN);   // 重置缓冲区
////	}
////
////	closesocket(ClientSock);   // 关闭套接字
////	// WSACleanup();  /*如果有退出循环的条件，这里还需要清除对socket库的使用*/
////	return 0;
////	
////}
//
////int main() {
////	//初始化DLL
////	WSADATA wsaData;
////	WSAStartup(MAKEWORD(2, 2), &wsaData);
////	//创建套接字
////	SOCKET sock = socket(PF_INET, SOCK_DGRAM, 0);
////	//服务器地址信息
////	struct sockaddr_in servAddr;
////	memset(&servAddr, 0, sizeof(servAddr));  //每个字节都用0填充
////	servAddr.sin_family = PF_INET;
////	//servAddr.sin_addr.s_addr = inet_addr("192.168.1.107");
////
////	servAddr.sin_addr.s_addr = inet_addr("192.168.1.56");
////	
////
////
////	servAddr.sin_port = htons(10003);
////	//不断获取用户输入并发送给服务器，然后接受服务器数据
////	struct sockaddr fromAddr;
////	int addrLen = sizeof(fromAddr);
////	while (1) {
////		char buffer[BUF_SIZE] = { 0 };
////		printf("Input a string: ");
////		gets_s(buffer);
////		sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr*)&servAddr, sizeof(servAddr));
////		int strLen = recvfrom(sock, buffer, BUF_SIZE, 0, &fromAddr, &addrLen);
////		buffer[strLen] = 0;
////		printf("Message form server: %s\n", buffer);
////	}
////	closesocket(sock);
////	WSACleanup();
////	return 0;
////}


#include "uv.h"
//#include "task.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>

static uv_loop_t* loop;
static uv_udp_t server;

#define _DATA_LEN 208

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

static void sv_send_cb(uv_udp_send_t* req, int status)
{
	uv_close((uv_handle_t*)req->handle, close_cb);
	free(req);
}

static void sv_recv_cb(uv_udp_t* handle,
	ssize_t nread,
	const uv_buf_t* rcvbuf,
	const struct sockaddr* addr,
	unsigned flags)
{
	uv_udp_send_t* req;
	uv_buf_t sndbuf;

	if (nread < 0)
	{
			std::cout<<"ccccc"<<std::endl;
	}

	if (nread == 0)
	{
		std::cout<<"eee"<<std::endl;
		Sleep(3000);
		return;
	}

	float data[_DATA_LEN] = { 0.0 };
	memcpy(data, rcvbuf->base, (66 + 51 + 45 + 45 + 1) * 4);
	for (int i = 0; i < 5; i++) {
		std::cout << data[i] << std::endl;
	}

	std::cout << "*************************************" << std::endl;
	//float data[_DATA_LEN ] = atof(&(rcvbuf->base));
	//printf("I receive the message from client:%s.\n", rcvbuf->base);

	//uv_udp_recv_stop(handle);

	//req = (uv_udp_send_t*)malloc(sizeof * req);

	//sndbuf = uv_buf_init("PONG", 4);
	//uv_udp_send(req, handle, &sndbuf, 1, addr, sv_send_cb);
	//std::cout<<"bbbbbb"<<std::endl;
	//Sleep(10000);
}

int main(void)
{
	struct sockaddr_in addr;
	uv_udp_send_t req;
	uv_buf_t buf;
	int r;

	loop = uv_default_loop();
	r = uv_ip4_addr("0.0.0.0", 8899, &addr);
	r = uv_udp_init(loop, &server);
	r = uv_udp_bind(&server, (const struct sockaddr*)&addr, 0);
	r = uv_udp_recv_start(&server, alloc_cb, sv_recv_cb);

	uv_run(loop, UV_RUN_DEFAULT);
	//uv_run(l);

	return 0;
}