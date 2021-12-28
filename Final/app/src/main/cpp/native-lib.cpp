#include <jni.h>
#include <string.h>
#include <cstring>
//#include "Calculator.h"
//#include "Bootstrapping.h"
#include "test.h"
#include "Configurator.h"
#include <time.h>

//extern "C" JNIEXPORT jstring JNICALL
//Java_com_example_afinal_MainActivity_stringFromJNI(
//        JNIEnv *env,
//        jobject /* this */) {
//    std::string hello = "Hello from C++";
//    return env->NewStringUTF(hello.c_str());
//}

//extern "C" JNIEXPORT jstring JNICALL
//Java_com_example_afinal_MainActivity_stringFromHyunwooCustomizing(
//        JNIEnv *env,
//        jobject) {
//    Calculator ex = Calculator(5);
//    std::string answer = "5+6 = " + std::to_string(ex.getAdd(6));
//    return env->NewStringUTF(answer.c_str());
//}

//extern "C" JNIEXPORT jstring JNICALL
//Java_com_example_afinal_MainActivity_stringFromBootstrapping(JNIEnv *env, jobject, jstring s_) {
//    // TODO: implement stringFromBootstrapping()
//
//
//
//   const char *temp = "[Bootstrapping] Done!\n\n";
//
//    return env->NewStringUTF(temp);
//}

//JNIEXPORT jint JNICALL
//Java_com_example_afinal_MainActivity_getStrLen(JNIEnv *env, jobject instance, jstring s_)
//{
//    const char *s = env->GetStringUTFChars(s_, 0);
////    printf("test\n");
////    printf("%s", s);
////    jint len = strlen(s);
//    jint len = getint(1);
////    env -> ReleaseStringUTFChars ( s_ ,   s ) ;
//    return len;
//}

//extern "C"
//JNIEXPORT jint JNICALL
//Java_com_example_afinal_MainActivity_do_Bootstrapping(JNIEnv *env, jobject instance, jstring s_) {
//    // TODO: implement getStatus()
//
//    const char *s = env->GetStringUTFChars(s_, 0);
//
//    return do_Bootstrapping(s);
//}

static int
Generate_Bootstraping_Key(BootstrapingKeyInfo *_bootsKeyInfo)
{
    if (Generate_EC_key(&_bootsKeyInfo->Key) == FAIL)
        return FAIL;

    EC_POINT *tPoint = (EC_POINT *)EC_KEY_get0_public_key(_bootsKeyInfo->Key);
    if (tPoint == NULL)
    {
        printf("[ERROR] EC_KEY_get0_public_key\n");
        printf("\t%s\n\n", ERR_error_string(ERR_get_error(), NULL));
        return FAIL;
    }
    _bootsKeyInfo->pubKey = tPoint;

    // TODO : Error Handling
    BIGNUM *tX = BN_new(), *tY = BN_new();
    if (tX == NULL || tY == NULL)
    {
        printf("[ERROR] BN_new\n");
        printf("\t%s\n\n", ERR_error_string(ERR_get_error(), NULL));
        return FAIL;
    }

    EC_GROUP *tGroup = (EC_GROUP *)EC_KEY_get0_group(_bootsKeyInfo->Key);
    if (tGroup == NULL)
    {
        printf("[ERROR] EC_KEY_get0_group\n");
        printf("\t%s\n\n", ERR_error_string(ERR_get_error(), NULL));
        return FAIL;
    }

    if (!EC_POINT_get_affine_coordinates_GFp(tGroup, tPoint, tX, tY, NULL))
    {
        printf("[ERROR] EC_POINT_get_affine_coordinates_GFp\n");
        printf("\t%s\n\n", ERR_error_string(ERR_get_error(), NULL));
        return FAIL;
    }

    printf("[KEYGEN] Bootstraping Public Key X Coordinate : ");
    BN_print_fp(stdout, tX);
    printf("\n\n");
    _bootsKeyInfo->pubKeyX = tX;

    printf("[KEYGEN] Bootstraping Public Key Y Coordinate : ");
    BN_print_fp(stdout, tY);
    printf("\n\n");
    _bootsKeyInfo->pubKeyY = tY;

    BIGNUM *tPriv = (BIGNUM *)EC_KEY_get0_private_key(_bootsKeyInfo->Key);
    if (tPriv == NULL)
    {
        printf("[ERROR] EC_KEY_get0_private_key\n");
        printf("\t%s\n\n", ERR_error_string(ERR_get_error(), NULL));
        return FAIL;
    }

    printf("[KEYGEN] Bootstraping Private Key : ");
    BN_print_fp(stdout, tPriv);
    printf("\n\n");
    _bootsKeyInfo->privKey = tPriv;

    return SUCCESS;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_afinal_MainActivity_do_1Bootstrapping(JNIEnv *env, jobject thiz, jstring s_) {
    // TODO: implement do_Bootstrapping()

    if (Generate_Bootstraping_Key(&_configurator->BootstrapingKey) == FAIL)
        return FAIL;
    printf("[SUCCESS] Generate_Bootstraping_Key\n\n");

    const char *s = env->GetStringUTFChars(s_, 0);

    return do_Bootstrapping(s);
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_afinal_MainActivity_do_1Authentication(JNIEnv *env, jobject thiz) {
    // TODO: implement do_Authentication()
    return do_Authentication();
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_afinal_MainActivity_do_1Scanning(JNIEnv *env, jobject thiz, jstring _s) {
    // TODO: implement do_Scanning()

    const char *s = env->GetStringUTFChars(_s, 0);

    const char *temp = do_Scanning(s);

    return env->NewStringUTF(temp);
}



