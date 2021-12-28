//
// Created by 420 on 2021-10-08.
//

#ifndef FINAL_CONFIGURATOR_H
#define FINAL_CONFIGURATOR_H

#include <jni.h>
#include <stdio.h>
#include <string.h>

#define SUCCESS 1
#define FAIL 0
#define PACKET_MAX_LENGTH 1500
#define KID_LENGTH 43
#define QR_EPUBKEY_LENGTH 125
#define CURVE NID_X9_62_prime256v1
#define KEY_SIZE 32
#define AD1_LEN 6
#define AD2_LEN1 36
#define AD2_LEN2 74
#define AD2_LEN3 41
#define AD2_LEN4 68
#define NONCE_SIZE 16
#define TL_LEN 4
#define CONF_CAP_LEN 1
#define KEY_PMK_LENGTH 32
#define KEY_PRF_RANDOM_LENGTH 32
#define KEY_PRF_INIT "Init Counter\0"
#define KEY_PRF_INIT_LENGTH 13 + ETH_ALEN + sizeof(struct tm)
#define KEY_NONCE_LENGTH 32
#define KEY_MIC_LENGTH 16
#define KEY_IV_LENGTH 16
#define KEY_PKE_LENGTH 100
#define KEY_PTK_LENGTH 80
#define KEY_LENGTH 16
#define KEY_GMK_LENGTH 32
#define KEY_GTK_LENGTH 16
#define PACKED __attribute__((packed))

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned long int u64;

#pragma push(pack)

typedef struct PACKED _AES_SIV_Info
{
    u_int8_t Nonce_Info[NONCE_SIZE + TL_LEN];
    u_int8_t Capability_Info[CONF_CAP_LEN + TL_LEN];
    u_int8_t AD1[AD1_LEN];
    u_int8_t AD2[AD2_LEN1 + AD2_LEN2];
    u_int8_t raw_data[25];

} AESInfo;

//typedef struct PACKED _Key_Gen_Attribute
//{
//    EC_GROUP *ecGroup;
//
//} KeyGenAttr;
//
//typedef struct PACKED _BootstrapingKey_Info
//{
//    EC_KEY *Key;
//    EC_POINT *pubKey;
//    BIGNUM *pubKeyX;
//    BIGNUM *pubKeyY;
//    BIGNUM *privKey;
//    unsigned char SHA256_HASH[SHA256_DIGEST_LENGTH];
//
//} BootstrapingKeyInfo;
//
//typedef struct PACKED _EAPOL_KEY
//{
//    uint8_t pke[KEY_PKE_LENGTH];
//    uint8_t ptk[KEY_PTK_LENGTH];
//    uint8_t kek[16];
//    uint8_t kck[16];
//    uint8_t tk[16];
//    uint8_t gtk[KEY_GTK_LENGTH];
//
//} eapolKey;
//
//typedef struct PACKED _ProtocolKey_Info
//{
//    EC_KEY *Key;
//    EC_POINT *pubKey;
//    BIGNUM *pubKeyX;
//    unsigned char pubKeyX_char[KEY_SIZE];
//    unsigned char pubKeyY_char[KEY_SIZE];
//    //TODO: unsigned char pubKeyX_b64[256];
//    char pubKeyX_b64[256];
//    char pubKeyY_b64[256];
//    BIGNUM *pubKeyY;
//    BIGNUM *privKey;
//    unsigned char SHA256_HASH[SHA256_DIGEST_LENGTH];
//} ProtocolKeyInfo;
//
//typedef struct PACKED _ECDSAKey_Info
//{
//    EC_KEY *Key;
//    EC_POINT *pubKey;
//    BIGNUM *pubKeyX;
//    BIGNUM *pubKeyY;
//    BIGNUM *privKey;
//    //TODO: unsigned char pubKeyX_char[KEY_SIZE]; 4 KEY
//    char pubKeyX_char[KEY_SIZE];
//    char pubKeyY_char[KEY_SIZE];
//    char pubKeyX_b64[256];
//    char pubKeyY_b64[256];
//    //TODO: unsigned char kid[KID_LENGTH];
//    char kid[KID_LENGTH];
//} ECDSAKeyInfo;
//
//typedef struct PACKED _PPKey_Info
//{
//    EC_KEY *Key;
//    EC_POINT *pubKey;
//    BIGNUM *pubKeyX;
//    //TODO: unsigned char pubKeyX_char[KEY_SIZE];
//    char pubKeyX_char[KEY_SIZE];
//    char pubKeyY_char[KEY_SIZE];
//    char pubKeyX_b64[256];
//    char pubKeyY_b64[256];
//    BIGNUM *pubKeyY;
//    BIGNUM *privKey;
//    unsigned char SHA256_HASH[SHA256_DIGEST_LENGTH];
//} PPKeyInfo;
//
//typedef struct PACKED _Key_Info
//{
//    EC_POINT *M;
//    EC_POINT *N;
//    BIGNUM *Mx;
//    BIGNUM *My;
//    BIGNUM *Nx;
//    BIGNUM *Ny;
//    u_int8_t k1[32];
//    u_int8_t k2[32];
//    u_int8_t bk[32];
//    u_int8_t ke[32];
//
//} KeyInfo;
//
//typedef struct PACKED _Configuration_Req_Object
//{
//    char *fullData;
//    char netRole[10];
//    char wifiTech[10];
//} ConReqObject;
//
//typedef struct PACKED _Configurator_Info
//{
//    BootstrapingKeyInfo BootstrapingKey;
//    ProtocolKeyInfo ProtocolKey;
//    ECDSAKeyInfo ECDSAKey;
//    KeyInfo Key;
//    PPKeyInfo PPKey;
//    KeyGenAttr KeyAttr;
//    eapolKey eapolkey;
//    // TODO: unsigned char NIC[20];
//    char NIC[20];
//    unsigned char MACAddr[IEEE80211_ADDR_LEN];
//    u_int8_t Nonce[16];
//    u_int8_t Auth[32];
//    u_int8_t OUI[3];
//    u_int8_t tempPacket[PACKET_MAX_LENGTH];
//    //TODO: uint8_t JWS[1024];
//    char JWS[1024];
//    u_int8_t Sign[1024];
//    u_int8_t ConfResObj[PACKET_MAX_LENGTH];
//    u_int8_t PMK[32];
//    char SSID[20];
//    char PASS[20];
//    u_int8_t Snonce[NONCE_SIZE];
//
//} ConfiguratorInfo;
//
//typedef struct PACKED _Peer_Info
//{
//    BootstrapingKeyInfo BootstrapingKey;
//    ProtocolKeyInfo ProtocolKey;
//    unsigned char MACAddr[IEEE80211_ADDR_LEN];
//    uint8_t encodedKey[QR_EPUBKEY_LENGTH];
//    u_int8_t Nonce[16];
//    u_int8_t Auth[32];
//    unsigned char wrapped_data[TL_LEN * 4 + NONCE_SIZE * 2 + CONF_CAP_LEN + (TL_LEN + KEY_SIZE + AES_BLOCK_SIZE) + AES_BLOCK_SIZE];
//    unsigned char unwrapped_data[TL_LEN * 4 + NONCE_SIZE * 2 + CONF_CAP_LEN + (TL_LEN + KEY_SIZE + AES_BLOCK_SIZE)];
//    u_int16_t DPP_STATUS_ID;
//    u_int8_t Enonce[NONCE_SIZE];
//    u_int8_t Anonce[NONCE_SIZE];
//    ConReqObject reqObj;
//
//} PeerInfo;

struct gas_config_frame
{
    uint8_t category;
    uint8_t public_Action;
    uint8_t dToken;
    uint8_t APE[3];
    uint8_t API[7];
    uint16_t query_reqlen;
} __attribute__((packed));

struct gas_config_res_frame
{
    uint8_t category;
    uint8_t public_Action;
    uint8_t dToken;
    uint16_t statusCode;
    uint16_t delay;
    uint8_t APE[3];
    uint8_t API[7];
    uint16_t query_reslen;
} __attribute__((packed));

//PACKET
typedef enum _DPP_SUBTYPE_LIST
{
    DPP_AUTHENTICATION_REQUEST = 00,
    DPP_PRESENCE_ANNOUNCEMENT = 13,
    DPP_AUTHENTICATION_CONFIRM = 0X02,
    DPP_AUTHENTICATION_RESPONSE = 1,
    DPP_CONFIGURATION_REQUEST = 0X0A,
    DPP_CONFIGURATION_RESPONSE = 0X0B
} DPPSubType;

typedef struct PACKED _DPP_Fixed_Parameter
{
    u_int8_t categoryCode;
    u_int8_t publicAction;
    u_int8_t OUI[3];
    u_int8_t WFASubtype;
    u_int8_t cryptoSuite;
    u_int8_t DPPSubtype;
} FixedParam;

typedef enum _DPP_UTIL
{
    TRANSACTION_ID = 0x05,
    DPP_VERSION = 0X02,
    DPP_GENERIC = 0X0151

} DPPUTIL;

typedef enum _DPP_ATTRIBUTE_SIZE
{
    SIZE_DPP_GENERIC = 0x0002,
    SIZE_STATUS = 0x0001,

} DPPAttrSize;

typedef enum _DPP_ATTRIBUTE_LIST
{
    ATTR_STATUS = 0x1000,
    ATTR_INITIATOR_BOOTS_KEY_HASH = 0x1001,
    ATTR_RESPONDER_BOOTS_KEY_HASH = 0x1002,
    ATTR_INITIATOR_PROTOCOL_KEY = 0X1003,
    ATTR_DPP_GENERIC = 0x1018,
    ATTR_WRAPPED_DATA = 0X1004,
    ATTR_ENONCE = 0X1014,
    ATTR_CONFIG_REQUEST_OBJECT = 0X100E,
    ATTR_CONFIG_OBJECT = 0X100C,
    ATTR_DPP_CONNECTOR = 0X100D
} DPPAttrType;

typedef struct PACKED _DPP_Attribute
{
    u_int16_t attrID;
    u_int16_t attrLen;
} Attribute;

typedef struct PACKED _Radiotap_Header
{
    u_int8_t Header_revision;
    u_int8_t Header_Pad;
    u_int16_t Header_Len;
    u_int8_t Present_Flags[4];
    u_int8_t flags;

} RadiotapHeader;
//Authentication(Open)
typedef struct PACKED _Auth_Fixed_Param
{
    u_int16_t Auth_Algorithm;
    u_int16_t Auth_SEQ;
    u_int16_t Status_Code;

} AuthFixedParam;

typedef struct PACKED _Tagged_Param
{
    u_int8_t Tag_Num;
    u_int8_t Tag_Length;
    u_int8_t OUI[3];
    u_int8_t OUI_Type;
    u_int8_t OUI_Data[10];
} AuthTaggedParam;

typedef struct PACKED _Tag_Param_SSID
{
    u_int8_t Tag_Num;
    u_int8_t Tag_Length;
} TagParamSSID;

typedef struct PACKED _Tag_Param_RSN
{
    u_int8_t Tag_Num;
    u_int8_t Tag_Length;
    u_int16_t RSN_Version;
    u_int8_t Group_CipherSuite_OUI[3];
    u_int8_t Group_CipherSuite_Type;
    u_int16_t Pairwise_CipherSuite_Cnt;
    u_int8_t Pairwise_CipherSuite_OUI[3];
    u_int8_t Pairwise_CipherSuite_Type;
    u_int16_t AKM_Suite_Cnt;
    u_int8_t AKM_Suite_OUI[3];
    u_int8_t AKM_Suite_Type;
    u_int16_t RSN_Capabilities;
    u_int16_t PMK_Cnt;
    u_int8_t Group_Manager_CipherSuite_OUI[3];
    u_int8_t Group_Manager_CipherSuite_Type;

} TagParamRSN;

typedef struct PACKED _Tag_Supported_Rates
{
    u_int8_t Tag_Num;
    u_int8_t Tag_Length;
    u_int8_t rates1;
    u_int8_t rates2;
    u_int8_t rates5;
    u_int8_t rates11;

} TagParamSupportedRates;

typedef struct PACKED _Tag_Supported_Channels
{
    u_int8_t Tag_Num;
    u_int8_t Tag_Length;
    u_int8_t First_SupportedChannel;
    u_int8_t SupporteChannel_Range;

} TagParamSupportedChannels;

typedef struct PACKED _Tag_Extend
{
    u_int8_t Tag_Num;
    u_int8_t Tag_Length;
    u_int8_t octet1;
    u_int8_t octet2;
    u_int8_t octet3;
    u_int8_t octet4;
    u_int8_t octet5;
    u_int8_t octet6;
    u_int8_t octet7;
    u_int16_t octet89;
    u_int8_t octet10;
} TagExtend;

//Association
typedef struct PACKED _AssoReq_Fixed_Param
{
    u_int16_t Capabilities_Info;
    u_int16_t Listen_Interval;
} AssoReqFixedParam;

typedef struct PACKED _AssoRes_Fixed_Param
{
    u_int16_t Capabilities_Info;
    u_int16_t StatusCode;
    u_int16_t Association_ID;
} AssoResFixedParam;

//4WAY - 1
typedef struct PACKED _Logical_Link_Control
{
    u8 DSAP;
    u8 SSAP;
    u8 ControlField;
    u8 OriginCode[3];
    u16 Type;
} LLC;

typedef struct PACKED _IEEE80211_Authentication
{
    u8 Version;
    u8 Type;
    u16 Length;
    u8 Key_Descriptor_Type;
    u16 Key_Info;
    u16 Key_Length;
    // TODO: counter plus
    u64 Replay_Counter;
    u8 WPA_Key_Nonce[32];
    u8 Key_IV[16];
    u8 WPA_Key_RSC[8];
    u8 WPA_Key_ID[8];
    u8 WPA_Key_MIC[16];
    u16 WPA_Key_DataLen;
} IEEE80211Auth;

typedef struct PACKED _RNS_PMKID
{
    u8 Tag_Number;
    u8 Tag_Length;
    u8 OUI[3];
    u8 Vendor_Specific_OUI;
    u8 PMKID[16];
} RSN_PMKID;

typedef struct PACKED _RSN
{
    u8 oui[3];
    u8 type;
} RSN;

typedef struct PACKED _RSN_INFO
{
    u8 id;
    u8 len;
    u16 version;
    RSN group;
    u16 pairCount;
    RSN pair;
    u16 authCount;
    RSN auth;
    u16 cap;
} RSN_INFO;

typedef struct PACKED _RSN_GTK
{
    u8 id;
    u8 len;
    RSN rsn;
    u8 keyid;
    u8 reserved;
    u8 gtk[16];
} RSN_GTK;

#pragma pop()

JNIEXPORT jint JNICALL do_Bootstrapping(const char *_s);

JNIEXPORT jint JNICALL do_Authentication();

char *do_Scanning(const char *_qrInfo);
//
//JNIEXPORT jint JNICALL do_Configuration();
//
//JNIEXPORT jint JNICALL do_WPA2();


#endif //FINAL_CONFIGURATOR_H
