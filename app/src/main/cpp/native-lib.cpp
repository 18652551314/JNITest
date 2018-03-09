#include <jni.h>
#include <string>
#include <string.h>
#include<stdlib.h>

extern "C" {


JNIEXPORT jstring JNICALL
Java_com_example_android_test_MainActivity_testFrom(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "1**********";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT jstring JNICALL
Java_com_example_android_test_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "2+++++++++";
    return env->NewStringUTF(hello.c_str());
}


char *jstringToChar(JNIEnv *env, jstring jstr) {
    char *rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("GB2312");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid, strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte *ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char *) malloc(alen + 1);
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);
    return rtn;
}
jstring Java_Package_MyTester_NMethod
        (JNIEnv *env, jint num) {

    char buf[64];

    sprintf(buf, "%d",num);
    return env->NewStringUTF(buf);
}
JNIEXPORT jstring JNICALL
Java_com_example_android_test_MainActivity_test2FromJNI(
        JNIEnv *env,
        jobject /* this */, jstring val) {
    std::string str = "3________";
    std::string hello = str + "val:" + jstringToChar(env, val);
    return env->NewStringUTF(hello.c_str());

}
JNIEXPORT jstring JNICALL
Java_com_example_android_test_MainActivity_test3FromJNI(
        JNIEnv *env,
        jobject /* this */, jint val) {
    std::string str = "4---";

    jstring value = Java_Package_MyTester_NMethod(env,val);
    std::string hello = str + "val:" + jstringToChar(env, value);
    return env->NewStringUTF(hello.c_str());

}
JNIEXPORT jdouble JNICALL
Java_com_example_android_test_MainActivity_test4FromJNI(
        JNIEnv *env,
        jobject /* this */, jdouble val) {
    return (jdouble) val;
}


}
