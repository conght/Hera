# Hera

一句话，Hera 是一个简单易用的c++工具库

#### 如何使用

直接引用 Hera 的头文件即可。免编译，免安装。

#### 文档

- [时钟](include/clock.hpp)

    提供获取当前时间戳的方法，支持各种精度级别；

    提供 class ProgressTimer ，支持统计时间段。
    
- [不可复制](include/noncopyable.hpp)

    继承 class noncopyable，子类即可获得不可被复制的能力。

- [单例](include/singleton.hpp)

    提供线程安全的单例模式模板类；

    继承 class Singleton，子类即可变成单例模式。

- [字符串工具](include/string_util.hpp)

    提供基本的字符串工具。

- 日志

    TODO
    
- 锁

    TODO

- 共享内存工具

    TODO

- FIFO工具

    TODO

- 配置工具

    TODO    
