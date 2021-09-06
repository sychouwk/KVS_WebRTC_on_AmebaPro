#ifndef _MODULE_KVS_WEBRTC_AUDIO_H
#define _MODULE_KVS_WEBRTC_AUDIO_H

#include "stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#include "mmf2_module.h"

#define CMD_KVS_WEBRTC_SET_PARAMS			MM_MODULE_CMD(0x00)
#define CMD_KVS_WEBRTC_GET_PARAMS			MM_MODULE_CMD(0x01)
#define CMD_KVS_WEBRTC_SET_APPLY			MM_MODULE_CMD(0x02)

typedef struct audio_buf_s{
    uint8_t *data_buf;
    uint8_t size;
    uint32_t timestamp;
    uint32_t type;
}audio_buf_t;

typedef struct kvs_webrtc_audio_ctx_s
{
    void* parent;

    TaskHandle_t    webrtc_audio_handler;

}kvs_webrtc_audio_ctx_t;

#define WEBRTC_AUDIO_FRAME_SIZE 160

extern mm_module_t kvs_webrtc_audio_module;

#endif /* _MODULE_KVS_WEBRTC_AUDIO_H */