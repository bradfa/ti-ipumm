/*
 * Copyright (c) 2013, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __DCE_RPC_H__
#define __DCE_RPC_H__

/* RPC layer types.. these define the payload of messages between IPUMM
 * and MPU.  This should be kept in sync between firmware build and
 * driver.
 *
 * TODO: xxx_control(XDM_GETVERSION) is a bit awkward to deal with, because
 * this seems to be the one special case where status->data is used..
 * possibly we should define a special ioctl and msg to handle this case.
 */

/* Message-Ids:
 */
typedef enum dce_rpc_call {
    DCE_RPC_ENGINE_OPEN = 0,
    DCE_RPC_ENGINE_CLOSE,
    DCE_RPC_CODEC_CREATE,
    DCE_RPC_CODEC_CONTROL,
    DCE_RPC_CODEC_GET_VERSION,
    DCE_RPC_CODEC_PROCESS,
    DCE_RPC_CODEC_DELETE
} dce_rpc_call;



#define MAX_NAME_LENGTH           32

typedef enum dce_codec_type {
    OMAP_DCE_VIDENC2 = 1,
    OMAP_DCE_VIDDEC3 = 2
} dce_codec_type;

/* Structures of RPC */
typedef struct dce_connect {
    uint32_t chipset_id;
    uint32_t debug;
} dce_connect;

typedef struct dce_engine_open {
    char          name[MAX_NAME_LENGTH];      /* engine name (in) */
    Engine_Attrs *engine_attrs;               /* engine attributes (in) */
    Engine_Error  error_code;                 /* error code (out) */
} dce_engine_open;

#endif /* __DCE_RPC_H__ */

