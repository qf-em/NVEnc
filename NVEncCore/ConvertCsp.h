﻿// -----------------------------------------------------------------------------------------
// NVEnc by rigaya
// -----------------------------------------------------------------------------------------
//
// The MIT License
//
// Copyright (c) 2014-2016 rigaya
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// ------------------------------------------------------------------------------------------

#ifndef _CONVERT_CSP_H_
#define _CONVERT_CSP_H_

#include <tchar.h>

typedef void (*funcConvertCSP) (void **dst, const void **src, int width, int src_y_pitch_byte, int src_uv_pitch_byte, int dst_y_pitch_byte, int height, int dst_height, int *crop);

enum NV_ENC_CSP {
    NV_ENC_CSP_NA,
    NV_ENC_CSP_NV12,
    NV_ENC_CSP_YV12,
    NV_ENC_CSP_YUY2,
    NV_ENC_CSP_YUV422,
    NV_ENC_CSP_YUV444,
    NV_ENC_CSP_YV12_09,
    NV_ENC_CSP_YV12_10,
    NV_ENC_CSP_YV12_12,
    NV_ENC_CSP_YV12_14,
    NV_ENC_CSP_YV12_16,
    NV_ENC_CSP_P010,
    NV_ENC_CSP_YUV444_09,
    NV_ENC_CSP_YUV444_10,
    NV_ENC_CSP_YUV444_12,
    NV_ENC_CSP_YUV444_14,
    NV_ENC_CSP_YUV444_16,
    NV_ENC_CSP_YC48,
};

static const TCHAR *NV_ENC_CSP_NAMES[] = {
    _T("Invalid"),
    _T("nv12"),
    _T("yv12"),
    _T("yuy2"),
    _T("yuv422"),
    _T("yuv444"),
    _T("yv12(9bit)"),
    _T("yv12(10bit)"),
    _T("yv12(12bit)"),
    _T("yv12(14bit)"),
    _T("yv12(16bit)"),
    _T("p010"),
    _T("yuv444(9bit)"),
    _T("yuv444(10bit)"),
    _T("yuv444(12bit)"),
    _T("yuv444(14bit)"),
    _T("yuv444(16bit)"),
    _T("yc48")
};

static const int NV_ENC_CSP_BIT_DEPTH[] = {
     0, //NV_ENC_CSP_NA
     8, //NV_ENC_CSP_NV12
     8, //NV_ENC_CSP_YV12
     8, //NV_ENC_CSP_YUY2 
     8, //NV_ENC_CSP_YUV422
     8, //NV_ENC_CSP_YUV444
     9, //NV_ENC_CSP_YV12_09
    10,
    12,
    14,
    16, //NV_ENC_CSP_YV12_16
    16, //NV_ENC_CSP_P010
     9, //NV_ENC_CSP_YUV444_09
    10,
    12,
    14,
    16, //NV_ENC_CSP_YUV444_16
    10, //NV_ENC_CSP_YC48
};

typedef struct ConvertCSP {
    NV_ENC_CSP csp_from, csp_to;
    bool uv_only;
    funcConvertCSP func[2];
    unsigned int simd;
} ConvertCSP;

const ConvertCSP *get_convert_csp_func(NV_ENC_CSP csp_from, NV_ENC_CSP csp_to, bool uv_only);
const TCHAR *get_simd_str(unsigned int simd);

#endif //_CONVERT_CSP_H_
