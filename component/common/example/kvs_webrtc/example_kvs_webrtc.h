#ifndef _EXAMPLE_KVS_WEBRTC_H_
#define _EXAMPLE_KVS_WEBRTC_H_

void example_kvs_webrtc(void);

/* Enter your AWS KVS key here */
#define KVS_WEBRTC_ACCESS_KEY   "xxxxxxxxxxxxxxxxxxxx"
#define KVS_WEBRTC_SECRET_KEY   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"

/* Setting your signaling channel name */
#define KVS_WEBRTC_CHANNEL_NAME "xxxxxxxxxxxxxxxxxxxx"

/* Setting your AWS region */
#define KVS_WEBRTC_REGION       "us-west-2"

/* Cert path */
#define TEMP_CERT_PATH          "0://cert.pem"  // path to CA cert

/* log level */
#define KVS_WEBRTC_LOG_LEVEL    LOG_LEVEL_WARN  //LOG_LEVEL_VERBOSE

/* Video resolution setting (if using webrtc mmf example, please set video parameter in example_kvs_webrtc_mmf.c) */
#include "sensor.h"
#if SENSOR_USE == SENSOR_PS5270
    #define KVS_VIDEO_HEIGHT    VIDEO_1440SQR_HEIGHT
    #define KVS_VIDEO_WIDTH     VIDEO_1440SQR_WIDTH
#else
    #define KVS_VIDEO_HEIGHT    VIDEO_1080P_HEIGHT   //VIDEO_720P_HEIGHT
    #define KVS_VIDEO_WIDTH     VIDEO_1080P_WIDTH    //VIDEO_720P_WIDTH
#endif
#define KVS_WEBRTC_BITRATE      512*1024    //1*1024*1024
#define KVS_VIDEO_OUTPUT_BUFFER_SIZE    KVS_VIDEO_HEIGHT*KVS_VIDEO_WIDTH/10

/* Audio format setting */
#define AUDIO_G711_MULAW        1
#define AUDIO_G711_ALAW         0
#define AUDIO_OPUS              0

/* Audio frame size */
#define AUDIO_G711_FRAME_SIZE    160     // if sample rate=8kHz, frame duration=20ms. then, there is 8000/(1/0.02)=160 samples in one audio frame 

/* Enable two-way audio communication (not support opus format now)*/
//#define ENABLE_AUDIO_SENDRECV

/*
 * Testing Amazon KVS WebRTC with IAM user key is easy but it is not recommended.
 * With AWS IoT Thing credentials, it can be managed more securely.(https://iotlabtpe.github.io/Amazon-KVS-WebRTC-WorkShop/lab/lab-4.html)
 * Script for generate iot credential: https://github.com/awslabs/amazon-kinesis-video-streams-webrtc-sdk-c/blob/master/scripts/generate-iot-credential.sh
 */
#define ENABLE_KVS_WEBRTC_IOT_CREDENTIAL    0

/* IoT credential configuration */
#if ENABLE_KVS_WEBRTC_IOT_CREDENTIAL

#define KVS_WEBRTC_IOT_CREDENTIAL_ENDPOINT      "xxxxxxxxxxxxxx.credentials.iot.us-west-2.amazonaws.com"  // IoT credentials endpointiot
#define KVS_WEBRTC_ROLE_ALIAS                   "webrtc_iot_role_alias"  // IoT role alias
#define KVS_WEBRTC_THING_NAME                   KVS_WEBRTC_CHANNEL_NAME  // iot thing name, recommended to be same as your channel name
   
#define KVS_WEBRTC_ROOT_CA \
"-----BEGIN CERTIFICATE-----\n" \
"......\n" \
"-----END CERTIFICATE-----\n"

#define KVS_WEBRTC_CERTIFICATE \
"-----BEGIN CERTIFICATE-----\n" \
"......\n" \
"-----END CERTIFICATE-----\n"

#define KVS_WEBRTC_PRIVATE_KEY \
"-----BEGIN RSA PRIVATE KEY-----\n" \
"......\n" \
"-----END RSA PRIVATE KEY-----\n"
#endif /* ENABLE_KVS_WEBRTC_IOT_CREDENTIAL */

#endif /* _EXAMPLE_KVS_WEBRTC_H_ */

