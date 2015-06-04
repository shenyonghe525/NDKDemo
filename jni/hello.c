#include<stdio.h>
#include<stdlib.h>
#include"com_syh_ndkdemo_MainActivity.h"

// for __android_log_print(ANDROID_LOG_INFO, "YourApp", "formatted message");
#include <android/log.h>
#define TAG "Android Log"
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, TAG, __VA_ARGS__)

JNIEXPORT jstring JNICALL Java_com_syh_ndkdemo_MainActivity_getStringFromC(
		JNIEnv * env, jclass jclas) {

	LOGV("log from c!");
	return (*env)->NewStringUTF(env, "Hello from audto C!");

}


JNIEXPORT void JNICALL Java_com_syh_ndkdemo_MainActivity_sendStringToC
(JNIEnv *env, jclass jclas, jstring filepath) {

	const char* file_path = (*env)->GetStringUTFChars(env,filepath,NULL);

	if(file_path != NULL) {
		LOGV("from c str %s",file_path);
	}

	FILE* file = fopen(file_path,"a+");
	if(file != NULL) {
		LOGV("from c open file succeed");
	}

	char data[] = "The end!";
	int count = fwrite(data,strlen(data),1,file);
	if(count > 0) {
		LOGV("from c write file succeed");
	}

	if(file != NULL) {
		fclose(file);
	}

	(*env)->ReleaseStringUTFChars(env,filepath,file_path);
}
