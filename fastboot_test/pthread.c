#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/usbdevice_fs.h>
#include <pthread.h>


// 线程1 方法
void * fastboot_1(){
	fastboot(1);
    return 0;
}

// 线程2 方法
void * fastboot_2(){
	fastboot(2);
    return 0;
}

// 线程2 方法
/*void * fastboot_3(){
	fastboot(3);
    return 0;
}

// 线程2 方法
void * fastboot_4(){
	fastboot(4);
    return 0;
}*/
/*多线程 烧录*/
int pthread_load()
{
	//pthread_t t1, t2, t3, t4;
	pthread_t t1, t2;

    // 创建线程1
    if(pthread_create(&t1, NULL, fastboot_1, NULL) == -1){
        puts("fail to create pthread t1");
		return -1;
    }
	else{
		printf("线程1创建成功\n");
	}

    if(pthread_create(&t2, NULL, fastboot_2, NULL) == -1){
        puts("fail to create pthread t2");
        return -1;
    }	
	else{
		printf("线程2创建成功\n");
	}
	
	/*if(pthread_create(&t3, NULL, fastboot_3, NULL) == -1){
        puts("fail to create pthread t3");
        return -1;
    }

	if(pthread_create(&t4, NULL, fastboot_4, NULL) == -1){
        puts("fail to create pthread t4");
        return -1;
    }*/


    // 等待线程结束
    void * result;
    if(pthread_join(t1, &result) == -1){
        puts("fail to recollect t1");
        return -1;
    }

    if(pthread_join(t2, &result) == -1){
        puts("fail to recollect t2");
        return -1;
    }
   /* if(pthread_join(t3, &result) == -1){
        puts("fail to recollect t3");
        return -1;
    }

    if(pthread_join(t4, &result) == -1){
        puts("fail to recollect t4");
        return -1;
    }
*/

    return 0;
}
