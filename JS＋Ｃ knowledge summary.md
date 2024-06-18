# 基础知识
## 一、词法，语法和语句
> token：有效的输入
> 
> 词法
> token
> 关键字 标识符 字符串字面量 数字字面量 正则字面量 运算符 （对象字面量和数组字面量不是token，因为他们并不是不可分割的词法，[]和{}在js里属于语法块，他们里面会嵌套其他词法甚至语句）
> 代码注释
> 空格
> 换行
> 
> 语法
> 表达式
> 表达式包括：
> 标识符
> 字面量
> 字符串字面量
> 数字字面量
> 正则字面量
> 数组字面量
> 对象字面量
> 复合表达式
> 四则运算
> 三目运算
> 一元运算
> 赋值运算
> ...
> 表达式分类：
> 数学表达式
> 除了副作用剩余都是数学表达式
> 副作用表达式
> 赋值运算表达式
> ++，--
> +=，-=，×-，/=
> 
> 语句
> 表达式语句
> 声明语句
> let，const，var，function开头的语句叫声明语句

## 二、理解const与lsh，rsh
> 1.const：
>  并不是它的值不能改变，而是变量本身不能被重新赋值  ， 是房子和房子里住的人的关系  
> ![{61828B35-C3D9-39FA-3119-222A6D7C8F32}.jpg](https://cdn.nlark.com/yuque/0/2023/jpeg/26307378/1679736868954-d2514405-53bb-4664-bd24-86b207849f2b.jpeg#averageHue=%2325312b&clientId=u9bdf1ab6-9b58-4&from=paste&height=193&id=ud3baac78&originHeight=340&originWidth=660&originalType=binary&ratio=1.25&rotation=0&showTitle=false&size=23478&status=done&style=none&taskId=ubb741644-8fc6-43ee-a732-f2b8ac67d0b&title=&width=374)
>  obj.a = 1和obj = {}  ， 第一个obj没有直接出现在等号左边，中间隔了.运算  ， 所有是rhs，也就是对象的值  ， 第二个是obj的存储空间  ， 对象的值可以改  ， obj存储空间存储的内容不能改  
> ![{6230D910-8CD4-837D-7F8A-12701B1CC883}.jpg](https://cdn.nlark.com/yuque/0/2023/jpeg/26307378/1679736909585-52755221-c75b-455d-a6d6-d2bf061b584b.jpeg#averageHue=%23535755&clientId=u9bdf1ab6-9b58-4&from=paste&height=137&id=u5e443a86&originHeight=350&originWidth=1120&originalType=binary&ratio=1.25&rotation=0&showTitle=false&size=50989&status=done&style=none&taskId=u1e572428-5e3b-45eb-a736-1dbd5269390&title=&width=439.4000244140625)
> 2.lsh：直接出现在等号左边，存储空间存储的内容
> rsh：不直接出现在等号左边，对象的值

## 三、数据结构和类型
> 共8种数据类型：
> 
> 7种基本数据类型：(值本身不可改变)
>     布尔值（Boolean），有 2 个值分别是：true 和 false。
>     null，一个表明 null 值的特殊关键字。JavaScript 是大小写敏感的，因此 null 与 Null、NULL或变体完全不	同。
>     undefined，和 null 一样是一个特殊的关键字，undefined 表示变量未赋值时的属性。
>     数字（Number），整数或浮点数，例如： 42 或者 3.14159。
>     任意精度的整数（BigInt），可以安全地存储和操作大整数，甚至可以超过数字的安全整数限制。
>     字符串（String），字符串是一串表示文本值的字符序列，例如："Howdy"。
>     代表（Symbol，在 ECMAScript 6 中新添加的类型）。一种实例是唯一且不可改变的数据类型。
> 1中引用数据类型：（可以被多个变量保存同一份引用，值本身可以被修改）
> 对象（一种用JSON数据格式描述的数据类型）

## 四、作用域
> 块作用域：
> let，const
> try catch
> with
> 函数作用域
> 1.var在块级作用域中也是全局变量
> 2.try catch是js中除了let const(对var的补丁)的块级作用域

## 五、运算
> 数字
> 字符串和数字
> ||，&&

## 六、函数
> 1.函数一等公民
> 含义：让函数和字符串，数字这些基本值等价
> a.首先一个函数可以赋值给变量
> b.其次一个函数可以作为另一个函数的返回值
> c.一个函数可以作为另一个函数的参数
> 满足这三个特性，函数基本就和其他值在使用上没什么本质区别了  。 满足函数一等公民的特性，让函数更接近数学中的那个函数  
> 
> 2.this
> this代表的是函数的调用者，this只和谁调用了函数有关
> 如果函数没有调用者，this就是global对象，也就是windows
> 
> 3.call属性
> 强制指定函数的this
> 
> 4....list
> 
> 5.箭头函数
> this：箭头函数的this看函数在哪声明

## 七、模块化+包管理
## 八、构造器模式
> 函数可作为普通函数，也可作为构造器 
> user1是new User()的返回值 ，是一个对象。User是user1的构造器，user1是User的实例对象。
> ![{3F34311C-2A27-2867-DEA1-78EBB88E0A7F}.jpg](https://cdn.nlark.com/yuque/0/2023/jpeg/26307378/1682424454209-2cbddc00-158b-4bcd-b99a-7eebfbb74b51.jpeg#averageHue=%23403e3e&clientId=u8bf9b349-ae8f-4&from=paste&height=171&id=u9f165d7f&originHeight=418&originWidth=992&originalType=binary&ratio=1.25&rotation=0&showTitle=false&size=43322&status=done&style=none&taskId=ue92af952-321b-4074-976d-8cc3634d599&title=&width=404.79998779296875)

# 进阶知识
## 九、对象模型
> prototype：
> 实例对象的隐式原型指向构造函数的显式原型，显式原型是构造函数的构造器
只要是函数就是Function的实例对象
只要是空对象是Object的实例对象
> 函数也是对象
> object.prototype是真正的空对象，没有原型![{205A66A1-5CC3-1B38-4AA6-E6F3B80D6D88}.jpg](https://cdn.nlark.com/yuque/0/2023/jpeg/26307378/1682663799518-7e72991b-71e8-44d0-a7d2-35ceab9d4e03.jpeg#averageHue=%23f6f5f3&clientId=u49df064b-95bd-4&from=paste&height=603&id=pvDOz&originHeight=1354&originWidth=1092&originalType=binary&ratio=1.25&rotation=0&showTitle=false&size=178149&status=done&style=none&taskId=u1b437975-58d6-4a20-a185-90ad84fb163&title=&width=486.4000244140625)

## 十、event loop事件轮询模型

### c编写eventloop
>  思路：
> 1.ｃ语言实现setTimeout（注意封装性）
> 2.每setTimeout都要创建新线程－＞优化
> a.线程池，多个线程处理
> b.两个线程()
> c.两个线程(setTimeout)
> event loop－>主线程执行一遍，然后把宏任务处理一个，再主任务，再宏任务。。－>宏任务是主线程分配的－>异步说白了就是部分功能不马上执行，我先存起来－>一个线程就可以实现异步了
> setTimeout需要延迟执行－>虽然可以把setTimeout注册的任务放到任务队列,但是它还有个功能就是定时,多长时间后执行,怎么控制时间到了呢.如果放进队列，后面空闲了我应该按着队列顺序一个一个执行，怎么判断时间到没到呢？　　　我取出一个队列里的定时器任务，如果时间没到，怎么办，等待就意味着阻塞，那么不能等待
> 思路：这个队列用来执行到时间的任务，主线程用来从队列里面循环检查谁到时间了，线程２用来执行这个到时间的任务．主线程遇到时间还没到的就跳过，检查下一个，最后一个检查完就从头循环检查．
> 但是有一个问题就是，可能很多任务并不能严格在时间到了后立马执行，要看前面待执行任务的数量和时间．但是好处就是不会阻塞
> 
> 两个线程，一个队列，非定时的延迟任务延迟条件完成就进入队列，定时任务计时完成就进入队列
> 
> 主线程逻辑后面写一个loop()，一直死循环执行队列就行了，有一个线程专门判断定时器的延迟什么时候完成
> 
> 整理：两个线程，线程１管理队列，执行任务，非定时的延迟任务延迟条件完成就进入队列，定时任务计时完成就进入队列．线程２管理链表，链表专门存放定时任务，线程２循环检查计时完成的定时任务，计时结束，就放入线程１管理的队列中．



> 3.理解阻塞：
> “阻塞”通常指的是线程因为某种原因无法继续执行，而进入等待状态直到某个条件满足或某个事件发生。例如：
>     等待I/O操作：线程在读取文件、网络数据或其他I/O操作时，需要等待这些操作完成。在此期间，线程会被阻塞，不能继续执行其他任务。
>     等待锁：线程试图获取一个已经被其他线程持有的锁时，会被阻塞，直到该锁被释放。
>     等待条件变量：线程在调用pthread_cond_wait等待条件变量时会被阻塞，直到其他线程调用pthread_cond_signal或pthread_cond_broadcast通知它。

为什么不能用pthread_mutex_trylock();
> pthread_mutex_trylock 尝试获取锁，但如果锁被其他线程持有（例如 thread1），它会立即返回 EBUSY 而不会阻塞。
> 如果 pthread_mutex_trylock 成功获取锁，thread2 会调用 dequeue 函数。
> dequeue 函数会等待直到队列中有任务（如果队列为空），这会导致 thread2 在 pthread_cond_wait 中阻塞。

```
void *thread2_fun(void *task_queue) {
    TaskQueue queue  = (TaskQueue)task_queue;
    printf("thread2\n");
    while(1) {
        int err = pthread_mutex_trylock(&queue->mtx);
        printf("err is: %d", err);
        if(0 == err) {
            if(EBUSY != err) {  //头文件errno.h
                printf("thread22\n");
                Task task = dequeue(queue);
                printf("task is: %p\n", task);
                if(task == NULL) {
                    continue;
                }
                printf("thread222\n");
                task->func(task->arg);
                printf("thread2222\n");
                free(task);
            }
        }
        
    }
    return NULL;
}
```
为什么线程无法正确输出－＞互斥锁
thread2_fun中dequeue位于互斥锁中间，如果dequeue中也有互斥锁，于是出现错误．．
```
void *thread2_fun(void *task_queue) {
    TaskQueue queue  = (TaskQueue)task_queue;
    while(1) {
        pthread_mutex_lock(&queue->mtx);
        Task task = dequeue(queue);
        if(task == NULL) {
            pthread_mutex_unlock(&queue->mtx);
            continue;
        }
        pthread_mutex_unlock(&queue->mtx);

        task->func(task->arg);
        free(task);        
    }
    return NULL;
}
```
### pthread
> 线程管理
>     pthread_create: 创建一个新的线程
>      pthread_join: 等待一个线程结束
>     pthread_exit: 终止调用线程
>     pthread_cancel: 取消一个线程
>     pthread_detach: 将线程置于分离状态
> 线程属性
>     pthread_attr_init: 初始化线程属性对象
>     pthread_attr_destroy: 销毁线程属性对象
>     pthread_attr_setdetachstate: 设置分离状态属性
>     pthread_attr_getdetachstate: 获取分离状态属性
> 互斥锁（Mutexes）
>     pthread_mutex_init: 初始化互斥锁
>     pthread_mutex_destroy: 销毁互斥锁
>     pthread_mutex_lock: 加锁
>     pthread_mutex_unlock: 解锁
>     pthread_mutex_trylock: 尝试加锁
> 条件变量（Condition Variables）
>     pthread_cond_init: 初始化条件变量
>     pthread_cond_destroy: 销毁条件变量
>     pthread_cond_wait: 等待条件变量
>     pthread_cond_signal: 发送信号
>     pthread_cond_broadcast: 广播信号
> 读写锁（Read-Write Locks）
>     pthread_rwlock_init: 初始化读写锁
>     pthread_rwlock_destroy: 销毁读写锁
>     pthread_rwlock_rdlock: 获取读锁
>     pthread_rwlock_wrlock: 获取写锁
>     pthread_rwlock_unlock: 解锁

#### pthread_create():
> 原型：int pthread_create (pthread_t * tidp,     const pthread_attr_t * attr,    void * (*start_rtn)(void*),      void *arg);
> 各个参数说明：
> 第一个参数为指向线程标识符的指针。
> 第二个参数用来设置线程属性。
> 第三个参数是线程运行函数的起始地址。
> 最后一个参数是运行函数的参数。

#### pthread_exit && 总结exit、return、pthread_exit，pthread_cancel各自退出效果和pthread_join，pthread_detach的作用
> 来自（[https://blog.csdn.net/weixin_44517656/article/details/112253724](https://blog.csdn.net/weixin_44517656/article/details/112253724)）
> 1）return：返回到调用者那里去。注意，在主线程退出时效果与exit,_exit一样。即return有可能会退出进程(放在主线程时)，有可能会退出线程，也有可能什么也不退出。
> 2）pthread_exit()：只退出当前子线程。注意：在主线程退出时，其它线程不会结束。同样可以执行。所以这个只字非常重要。并且，与return一样，pthread_exit退出的线程也需要调用pthread_join去回收子线程的资源(8k左右)，否则服务器长时间运行会浪费资源导致无法再创建新线程。
> 3）exit，_exit： 将进程退出，无论哪个子线程调用整个程序都将结束。
> 4）pthread_join()：阻塞等待回收子线程。
> 5）pthread_cancel()：可以杀死子线程，但必须需要一个契机，这个契机就是系统调用。一般方法是调用pthread_testcancel提供契机处理。并且join再回收该被杀死的子线程的返回值为pthread.h中的宏#define PTHREAD_CANCELED ((void *) -1)。
> 6）pthread_detach：1）注意，所有线程的错误号返回都只能使用strerror这个函数判断，不能使用perror，因为perror是调用进程的全局错误号，不适合单独线程的错误分析，所以只能使用strerror。2）线程可以被置为detach状态，这样的线程一旦终止就立刻回收它占用的所有资源，而不保留终止状态。不能对一个已经处于detach状态的线程调用pthread_join，这样的调用将返回EINVAL错误。也就是说，如果已经对一个线程调用了pthread_detach就不能再调用pthread_join了。


#### 互斥锁的使用
（来自：[https://blog.csdn.net/z_muyangren/article/details/105398871](https://blog.csdn.net/z_muyangren/article/details/105398871)）
##### 1.创建互斥锁： pthread_mutex_t mtx;
##### 2.初始化互斥锁： pthread_mutex_init(&mtx, NULL); 
##### 3.获取互斥锁： 	
a.阻塞调用： pthread_mutex_lock(&mtx);
b.非阻塞调用： pthread_mutex_trylock(&mtx);
```
解释:
如果不想阻塞，而是想尝试获取一下，如果锁被占用就不用，如果没被占用那就用， 可以使用 pthread_mutex_trylock() 函数。 这个函数和 pthread_mutex_lock() 用法一样，只不过当请求的锁正在被占用的时候， 不会进入阻塞状态，而是立刻返回，并返回一个错误代码 EBUSY，意思是说， 有其它线程正在使用这个锁。
int err = pthread_mutex_trylock(&mtx);
if(0 != err) {
    if(EBUSY == err) {
        //The mutex could not be acquired because it was already locked.
    }
}

```
c.超时调用：pthread_mutex_timedlock(&mtx, &abs_timeout);
```
如果不想不断的调用 pthread_mutex_trylock() 来测试互斥锁是否可用， 而是想阻塞调用，但是增加一个超时时间，那么可以使用 pthread_mutex_timedlock() 来解决， 其调用方式如下：
struct timespec abs_timeout;
abs_timeout.tv_sec = time(NULL) + 1;
abs_timeout.tv_nsec = 0;

int err = pthread_mutex_timedlock(&mtx, &abs_timeout);
if(0 != err) {
    if(ETIMEDOUT == err) {
        //The mutex could not be locked before the specified timeout expired.
    }
}
上面代码的意思是，阻塞等待线程锁，但是只等1秒钟，一秒钟后如果还没拿到锁的话， 那就返回，并返回一个错误代码 ETIMEDOUT，意思是超时了。
其中 timespec 定义在头文件 time.h 中，其定义如下：
struct timespec
{
    __time_t tv_sec;        /* Seconds.  */
    long int tv_nsec;       /* Nanoseconds.  */
};
注意：这个函数里面的时间，是绝对时间，所以这里用 time() 函数返回的时间增加了 1 秒。

```
##### 4.释放互斥锁
pthread_mutex_unlock(&mtx);
**获取和释放是一对，必须成对出现**
**malloc与free是一对，必须成对出现**
##### 5.销毁线程锁
pthread_mutex_destroy(&mtx)
```
通过 man pthread_mutex_destroy 命令可以看到 pthread_mutex_destroy() 函数的说明， 在使用此函数销毁一个线程锁后，线程锁的状态变为"未定义"。有的 pthread_mutex_destroy 实现方式，会使线程锁变为一个不可用的值。一个被销毁的线程锁可以被 pthread_mutex_init() 再次初始化。对被销毁的线程锁进行其它操作，其结果是未定义的。
对一个处于已初始化但未锁定状态的线程锁进行销毁是安全的。尽量避免对一个处于锁定状态的线程锁进行销毁操作。

```
#### 生产者消费者模型
解决死锁：条件变量
来自（[https://www.cnblogs.com/liusiluandzhangkun/p/10678293.html](https://www.cnblogs.com/liusiluandzhangkun/p/10678293.html)）
通常情况下，对共享资源（比如 n）保护要用到锁操作，当一个进程进入临界区时会拿到互斥锁（lock 操作），然后其他进程拿不到互斥锁，也就无法进入临界区，因此当进程进入临界区，发现共享资源不满足继续向下执行的条件（n > 0）时，就应该释放锁，让其他进程修改共享资源，以满足自己所需的执行条件。
消费者进入临界区 --> 共享变量不满足继续向下执行的条件 --> 消费者等待在条件变量 --> 释放互斥锁 --> 生产者进入临界区 --> 修改条件变量 --> 生产者通知消费者：现在有多的资源了，快来使用 --> 消费者再次拿互斥锁 --> 消费资源 --> 释放互斥锁。如果有多个消费者进程等待在条件变量上，就可以形成等待队列。
##### 条件变量的使用
###### 条件变量的使用主要有以下五个函数：
1./* 初始化一个条件变量 */
int pthread_cond_init (pthread_cond_t* cond, pthread_condattr_t *cond_attr);
2./* 销毁一个条件变量 */
int pthread_cond_destroy(pthread_cond_t* cond);
3./* 令一个消费者等待在条件变量上 */
int pthread_cond_destroy(pthread_cond_t* cond);
4./* 生产者通知等待在条件变量上的消费者 */
int pthread_cond_signal(pthread_cond_t* cond);
5./* 生产者向消费者广播消息 */
int pthread_cond_broadcast(pthread_cond_t* cond);

###### 消费者等待条件的伪代码：
pthread_mutex_lock(&mutex); // 拿到互斥锁，进入临界区
while( 条件为假)
	pthread_cond_wait(cond, mutex); // 令进程等待在条件变量上
修改条件
pthread_mutex_unlock(&mutex); // 释放互斥锁

###### 生产者通知消费者的伪代码：
pthread_mutex_lock(&mutex); // 拿到互斥锁，进入临界区
设置条件为真
pthread_cond_signal(cond); // 通知等待在条件变量上的消费者
pthread_mutex_unlock(&mutex); // 释放互斥锁
#### 什么是句柄/线程句柄
> 句柄：
> 在计算机编程中，句柄（handle）是一个抽象的引用，它指向系统资源，如文件、窗口、线程等。句柄本身是一个数字或指针，用于唯一标识和访问系统资源。可以把句柄想象成你使用钥匙打开门时，钥匙就是这个“句柄”，它允许你操作和管理对应的资源。
> 
> 线程句柄：
>     创建线程：当你创建一个新线程时，操作系统会返回一个线程句柄。这是一个用于引用该线程的标识符。
>     管理线程：通过线程句柄，你可以对该线程进行各种操作，例如等待线程完成（pthread_join），终止线程（pthread_cancel）等。

#### 什么是语法糖
> 语法糖是指在编程语言中引入的一些语法特性，这些特性使得代码更容易阅读和编写，但并不会引入新的功能。语法糖通常是为了提高代码的可读性和简洁性，让开发者能够用更简单、直观的方式实现某些常见的操作。

### 并行与并发
> 并行（Parallelism）
> 定义：并行是指在同一时间内同时执行多个任务。也就是说，多个任务在物理上是同时进行的。
> 实现方式：
>     多核处理器：在多核处理器中，每个核心可以同时执行一个任务，从而实现真正的并行。
>     多线程：在多线程编程中，如果多个线程在不同的处理器核心上运行，就实现了并行。
> 例子：
>     想象你有两只手，每只手同时切一根胡萝卜。这就是并行：两只手在同一时间内同时进行切胡萝卜的操作。
> 应用场景：
>     科学计算、大数据处理等需要大量计算的场景。
>     图像和视频处理，利用多核处理器加速处理速度。
> 
> 并发（Concurrency）
> 定义：并发是指在同一时间段内多个任务交替进行。任务之间可以快速切换，看起来像是同时进行，但实际上在某一时刻只有一个任务在运行。
> 实现方式：
>     多线程：在单核处理器上，通过快速切换线程来实现并发。这种切换是由操作系统的调度器来控制的。
>     协程：通过用户级的调度机制来实现轻量级的并发。
> 例子：
>     想象你只有一只手，但你要同时处理两根胡萝卜。你可以切几刀第一根胡萝卜，然后放下它，切几刀第二根胡萝卜。虽然你不是同时切两根胡萝卜，但通过快速切换，最终两根胡萝卜都被切完了。
> 应用场景：
>     GUI应用程序，需要同时响应用户输入和进行后台处理。
>     Web服务器，需要处理多个客户端请求。
> 
> 并行与并发的区别
>     同时性：
>         并行：任务在物理上同时执行。
>         并发：任务在逻辑上同时进行，实际上是快速交替进行。
>     依赖硬件：
>         并行：需要多核处理器或多个处理器来实现真正的并行。
>         并发：可以在单核处理器上通过快速任务切换实现。
>     应用领域：
>         并行：适用于需要大量计算和数据处理的领域。
>         并发：适用于需要处理多个任务但不一定需要同时进行的场景。

## 编程习惯小结
> 1.===代替==
2.字符串拼接用字符模板替代
3.let，const代替var

