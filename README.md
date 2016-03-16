# NDKDemo

                        第一手动编译
生产.class与.h文件

1 cd /Users/yongheshen/Androidworkspace/NDKDemo/src 
2 javah -classpath /Users/yongheshen/Androidworkspace/NDKDemo/src -jni com.syh.ndkdemo.MainActivity

1 cd /Users/yongheshen/Androidworkspace/NDKDemo/src 
2 javah -jni com.syh.ndkdemo.MainActivity

                  java 调用c中的方法的步骤 
1 在java 定义 native方法(public static native String getStringFromC())。
2 调用javah生成对应的头文件，并创建.c文件实现头文件里面的方法
3 编译Android.mk以及Application.mk文件
4 调用ndk -build生成.so库
5 在java调用c的类里面预加载.so库
  static{
		System.loadLibrary("hello");
	}
6 在java中直接调用c的方法
  tv.setText(getStringFromC());
  
eclipse配置自动编译.so文件
1 配置ndk路径(android->ndk)
2 设置项目的builders(新建一个，指定ndk ndk-build.cmd路径 以及工程，并设置为自动编译)

                   在c里面实现Android日志输出
1 在要输出日志的文件里面加入
// for __android_log_print(ANDROID_LOG_INFO, "YourApp", "formatted message");
#include <android/log.h>
#define TAG "Android Log"
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, TAG, __VA_ARGS__)

LOGV("log from c!");

2 在配置文件Android.mk里面加入

# for logging
LOCAL_LDLIBS    += -llog


配置javah(自动生成.h文件)
1 Run->External Tools -> External Tools Configurations 
2 新建一个
  Location:${system_path:javah}
  WorkingDirectory:${project_loc}/jni
  Arguments:-classpath ${project_loc}/src -jni ${java_type_name}
  
配置javap(生成函数签名)

1 Run->External Tools -> External Tools Configurations 
2 新建一个
  Location:${system_path:javap}
  WorkingDirectory:${project_loc}
  Arguments:-classpath ${project_loc}/bin/classes -s -p  ${java_type_name}
  
eclipse C/C++代码提示配置
1 右键工程-> android tools-> add native support
1 右键工程-> Properties-> C/C++ General-> paths and symbols->add->file system->NDK/platforms/android-19/arch-arm/usr/include
