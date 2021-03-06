﻿// -----------------------------------------------------------------------------------------
// NVEnc by rigaya
// -----------------------------------------------------------------------------------------
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

#pragma once

#include <Windows.h>

#include "auo.h"
#include "auo_pipe.h"
#include "auo_conf.h"
#include "auo_settings.h"
#include "auo_system.h"
#include "auo_util.h"
#include "auo_clrutil.h"

#include "frmConfig_helper.h"

#include "NVEncParam.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;


namespace NVEnc {

    /// <summary>
    /// frmConfig の概要
    ///
    /// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
    ///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
    ///          変更する必要があります。この変更を行わないと、
    ///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
    ///          正しく相互に利用できなくなります。
    /// </summary>
    public ref class frmConfig : public System::Windows::Forms::Form
    {
    public:
        frmConfig(CONF_GUIEX *_conf, const SYSTEM_DATA *_sys_dat)
        {
            try {
                featureCache = nvfeature_create();
            } catch (...) {
                ;
            }
            if (featureCache)
                nvfeature_createCacheAsync(featureCache, 0);
            InitData(_conf, _sys_dat);
            cnf_stgSelected = (CONF_GUIEX *)calloc(1, sizeof(CONF_GUIEX));
            InitializeComponent();
            //
            //TODO: ここにコンストラクタ コードを追加します
            //
        }

    protected:
        /// <summary>
        /// 使用中のリソースをすべてクリーンアップします。
        /// </summary>
        ~frmConfig()
        {
            if (featureCache) {
                nvfeature_close(featureCache);
                featureCache = nullptr;
            }
            if (components)
            {
                delete components;
            }
            CloseBitrateCalc();
            if (cnf_stgSelected) free(cnf_stgSelected); cnf_stgSelected = NULL;
        }




    private: System::Windows::Forms::ToolStrip^  fcgtoolStripSettings;

    private: System::Windows::Forms::TabControl^  fcgtabControlMux;
    private: System::Windows::Forms::TabPage^  fcgtabPageMP4;
    private: System::Windows::Forms::TabPage^  fcgtabPageMKV;
    private: System::Windows::Forms::TextBox^  fcgTXCmd;

    private: System::Windows::Forms::Button^  fcgBTCancel;

    private: System::Windows::Forms::Button^  fcgBTOK;
    private: System::Windows::Forms::Button^  fcgBTDefault;




    private: System::Windows::Forms::ToolStripButton^  fcgTSBSave;

    private: System::Windows::Forms::ToolStripButton^  fcgTSBSaveNew;

    private: System::Windows::Forms::ToolStripButton^  fcgTSBDelete;

    private: System::Windows::Forms::ToolStripSeparator^  fcgtoolStripSeparator1;
    private: System::Windows::Forms::ToolStripDropDownButton^  fcgTSSettings;





























































































































































































































































    private: System::Windows::Forms::TabPage^  fcgtabPageMux;












    private: System::Windows::Forms::ComboBox^  fcgCXMP4CmdEx;

    private: System::Windows::Forms::Label^  fcgLBMP4CmdEx;
    private: System::Windows::Forms::CheckBox^  fcgCBMP4MuxerExt;
    private: System::Windows::Forms::Button^  fcgBTMP4BoxTempDir;
    private: System::Windows::Forms::TextBox^  fcgTXMP4BoxTempDir;


    private: System::Windows::Forms::ComboBox^  fcgCXMP4BoxTempDir;
    private: System::Windows::Forms::Label^  fcgLBMP4BoxTempDir;
    private: System::Windows::Forms::Button^  fcgBTTC2MP4Path;
    private: System::Windows::Forms::TextBox^  fcgTXTC2MP4Path;
    private: System::Windows::Forms::Button^  fcgBTMP4MuxerPath;
    private: System::Windows::Forms::TextBox^  fcgTXMP4MuxerPath;

    private: System::Windows::Forms::Label^  fcgLBTC2MP4Path;
    private: System::Windows::Forms::Label^  fcgLBMP4MuxerPath;


    private: System::Windows::Forms::Button^  fcgBTMKVMuxerPath;

    private: System::Windows::Forms::TextBox^  fcgTXMKVMuxerPath;

    private: System::Windows::Forms::Label^  fcgLBMKVMuxerPath;
    private: System::Windows::Forms::ComboBox^  fcgCXMKVCmdEx;
    private: System::Windows::Forms::Label^  fcgLBMKVMuxerCmdEx;
    private: System::Windows::Forms::CheckBox^  fcgCBMKVMuxerExt;
    private: System::Windows::Forms::ComboBox^  fcgCXMuxPriority;
    private: System::Windows::Forms::Label^  fcgLBMuxPriority;
    private: System::Windows::Forms::CheckBox^  fcgCBMuxMinimize;
    private: System::Windows::Forms::Label^  fcgLBVersionDate;


    private: System::Windows::Forms::Label^  fcgLBVersion;
    private: System::Windows::Forms::FolderBrowserDialog^  fcgfolderBrowserTemp;
    private: System::Windows::Forms::OpenFileDialog^  fcgOpenFileDialog;










private: System::Windows::Forms::ToolTip^  fcgTTEx;






private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
private: System::Windows::Forms::ToolStripButton^  fcgTSBOtherSettings;















































































































private: System::Windows::Forms::ToolStripButton^  fcgTSBBitrateCalc;
private: System::Windows::Forms::TabControl^  fcgtabControlNVEnc;

private: System::Windows::Forms::TabPage^  tabPageVideoEnc;












private: System::Windows::Forms::GroupBox^  fcgGroupBoxAspectRatio;
private: System::Windows::Forms::Label^  fcgLBAspectRatio;
private: System::Windows::Forms::NumericUpDown^  fcgNUAspectRatioY;
private: System::Windows::Forms::NumericUpDown^  fcgNUAspectRatioX;
private: System::Windows::Forms::ComboBox^  fcgCXAspectRatio;
private: System::Windows::Forms::ComboBox^  fcgCXInterlaced;
private: System::Windows::Forms::Label^  fcgLBInterlaced;
private: System::Windows::Forms::NumericUpDown^  fcgNUGopLength;
private: System::Windows::Forms::Label^  fcgLBGOPLength;
private: System::Windows::Forms::ComboBox^  fcgCXCodecLevel;
private: System::Windows::Forms::ComboBox^  fcgCXCodecProfile;
private: System::Windows::Forms::Label^  fcgLBCodecLevel;
private: System::Windows::Forms::Label^  fcgLBCodecProfile;




private: System::Windows::Forms::Label^  fcgLBMaxBitrate2;
private: System::Windows::Forms::Label^  fcgLBEncMode;
private: System::Windows::Forms::ComboBox^  fcgCXEncMode;
private: System::Windows::Forms::Label^  fcgLBMaxkbps;
private: System::Windows::Forms::NumericUpDown^  fcgNUMaxkbps;
private: System::Windows::Forms::Label^  fcgLBQPB;
private: System::Windows::Forms::Label^  fcgLBQPP;
private: System::Windows::Forms::Label^  fcgLBQPI;

private: System::Windows::Forms::NumericUpDown^  fcgNUQPB;
private: System::Windows::Forms::NumericUpDown^  fcgNUQPP;
private: System::Windows::Forms::NumericUpDown^  fcgNUQPI;



private: System::Windows::Forms::Label^  fcgLBBitrate2;
private: System::Windows::Forms::NumericUpDown^  fcgNUBitrate;
private: System::Windows::Forms::Label^  fcgLBBitrate;

























private: System::Windows::Forms::TabPage^  tabPageExOpt;
private: System::Windows::Forms::Label^  fcgLBTempDir;

private: System::Windows::Forms::Button^  fcgBTCustomTempDir;
private: System::Windows::Forms::TextBox^  fcgTXCustomTempDir;

private: System::Windows::Forms::ComboBox^  fcgCXTempDir;


private: System::Windows::Forms::Label^  fcgLBGOPLengthAuto;






























private: System::Windows::Forms::NumericUpDown^  fcgNUSlices;

private: System::Windows::Forms::Label^  fcgLBSlices;

private: System::Windows::Forms::ToolStripLabel^  fcgTSLSettingsNotes;
private: System::Windows::Forms::ToolStripTextBox^  fcgTSTSettingsNotes;
private: System::Windows::Forms::TabPage^  fcgtabPageBat;
private: System::Windows::Forms::Button^  fcgBTBatAfterPath;

private: System::Windows::Forms::TextBox^  fcgTXBatAfterPath;

private: System::Windows::Forms::Label^  fcgLBBatAfterPath;

private: System::Windows::Forms::CheckBox^  fcgCBWaitForBatAfter;

private: System::Windows::Forms::CheckBox^  fcgCBRunBatAfter;

private: System::Windows::Forms::CheckBox^  fcgCBMP4MuxApple;











private: System::Windows::Forms::Panel^  fcgPNBitrate;
private: System::Windows::Forms::Panel^  fcgPNQP;



private: System::Windows::Forms::CheckBox^  fcgCBCABAC;









private: System::Windows::Forms::Button^  fcgBTMP4RawPath;

private: System::Windows::Forms::TextBox^  fcgTXMP4RawPath;
private: System::Windows::Forms::Label^  fcgLBMP4RawPath;





private: System::Windows::Forms::TabPage^  fcgtabPageMPG;
private: System::Windows::Forms::Button^  fcgBTMPGMuxerPath;

private: System::Windows::Forms::TextBox^  fcgTXMPGMuxerPath;

private: System::Windows::Forms::Label^  fcgLBMPGMuxerPath;

private: System::Windows::Forms::ComboBox^  fcgCXMPGCmdEx;
private: System::Windows::Forms::Label^  fcgLBMPGMuxerCmdEx;


private: System::Windows::Forms::CheckBox^  fcgCBMPGMuxerExt;

private: System::Windows::Forms::ContextMenuStrip^  fcgCSExeFiles;
private: System::Windows::Forms::ToolStripMenuItem^  fcgTSExeFileshelp;




private: System::Windows::Forms::Label^  fcgLBBatAfterString;

private: System::Windows::Forms::Label^  fcgLBBatBeforeString;
private: System::Windows::Forms::Panel^  fcgPNSeparator;
private: System::Windows::Forms::Button^  fcgBTBatBeforePath;
private: System::Windows::Forms::TextBox^  fcgTXBatBeforePath;
private: System::Windows::Forms::Label^  fcgLBBatBeforePath;
private: System::Windows::Forms::CheckBox^  fcgCBWaitForBatBefore;
private: System::Windows::Forms::CheckBox^  fcgCBRunBatBefore;
private: System::Windows::Forms::LinkLabel^  fcgLBguiExBlog;



























private: System::Windows::Forms::Label^  fcgLBCABAC;


private: System::Windows::Forms::CheckBox^  fcgCBAuoTcfileout;

private: System::Windows::Forms::CheckBox^  fcgCBDeblock;


private: System::Windows::Forms::GroupBox^  fcgGroupBoxQulaityStg;
private: System::Windows::Forms::Button^  fcgBTQualityStg;
private: System::Windows::Forms::ComboBox^  fcgCXQualityPreset;

private: System::Windows::Forms::NumericUpDown^  fcgNUBframes;
private: System::Windows::Forms::Label^  fcgLBBframes;


private: System::Windows::Forms::Label^  fcgLBFullrangeH264;
private: System::Windows::Forms::CheckBox^  fcgCBFullrangeH264;
private: System::Windows::Forms::ComboBox^  fcgCXVideoFormatH264;
private: System::Windows::Forms::Label^  fcgLBVideoFormatH264;
private: System::Windows::Forms::GroupBox^  fcggroupBoxColorH264;
private: System::Windows::Forms::ComboBox^  fcgCXTransferH264;
private: System::Windows::Forms::ComboBox^  fcgCXColorPrimH264;
private: System::Windows::Forms::ComboBox^  fcgCXColorMatrixH264;
private: System::Windows::Forms::Label^  fcgLBTransferH264;
private: System::Windows::Forms::Label^  fcgLBColorPrimH264;
private: System::Windows::Forms::Label^  fcgLBColorMatrixH264;
private: System::Windows::Forms::NumericUpDown^  fcgNURefFrames;
private: System::Windows::Forms::Label^  fcgLBRefFrames;
private: System::Windows::Forms::ComboBox^  fcgCXBDirectMode;
private: System::Windows::Forms::Label^  fcgLBBDirectMode;
private: System::Windows::Forms::Label^  fcgLBMVPRecision;
private: System::Windows::Forms::ComboBox^  fcgCXMVPrecision;
private: System::Windows::Forms::TabPage^  tabPageNVEncFeatures;
private: System::Windows::Forms::DataGridView^  fcgDGVFeaturesH264;

private: System::Windows::Forms::Label^  fcgLBOSInfo;
private: System::Windows::Forms::Label^  fcgLBOSInfoLabel;
private: System::Windows::Forms::Label^  fcgLBCPUInfoOnFeatureTab;
private: System::Windows::Forms::Label^  fcgLBCPUInfoLabelOnFeatureTab;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  fcgLBGPUInfoOnFeatureTab;
private: System::Windows::Forms::Label^  fcgLBGPUInfoLabelOnFeatureTab;
private: System::Windows::Forms::PictureBox^  fcgPBNVEncLogoEnabled;

private: System::Windows::Forms::PictureBox^  fcgPBNVEncLogoDisabled;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::ComboBox^  fcgCXEncCodec;
private: System::Windows::Forms::Panel^  fcgPNH264;
private: System::Windows::Forms::ComboBox^  fcgCXAdaptiveTransform;
private: System::Windows::Forms::Label^  fcgLBAdaptiveTransform;
private: System::Windows::Forms::Panel^  fcgPNHEVC;


private: System::Windows::Forms::Label^  fcgLBHEVCProfile;
private: System::Windows::Forms::Label^  fxgLBHEVCTier;
private: System::Windows::Forms::ComboBox^  fcgCXHEVCTier;





private: System::Windows::Forms::ComboBox^  fxgCXHEVCLevel;


















private: System::Windows::Forms::Label^  fcgLBHEVCMinCUSize;
private: System::Windows::Forms::ComboBox^  fcgCXHEVCMinCUSize;
private: System::Windows::Forms::Label^  fcgLBHEVCMaxCUSize;
private: System::Windows::Forms::ComboBox^  fcgCXHEVCMaxCUSize;
private: System::Windows::Forms::Label^  fcgLBDeblock;
private: System::Windows::Forms::TabControl^  fcgTabControlFeatures;
private: System::Windows::Forms::TabPage^  fcgTabPageH264;
private: System::Windows::Forms::TabPage^  fcgTabPageHEVC;
private: System::Windows::Forms::DataGridView^  fcgDGVFeaturesHEVC;
private: System::Windows::Forms::CheckBox^  fcgCBAFS;
private: System::Windows::Forms::NumericUpDown^  fcgNUVBVBufsize;
private: System::Windows::Forms::Label^  fcgLBVBVBufsize;
private: System::Windows::Forms::Label^  fcgLBBluray;
private: System::Windows::Forms::CheckBox^  fcgCBBluray;
private: System::Windows::Forms::TabControl^  fcgtabControlAudio;
private: System::Windows::Forms::TabPage^  fcgtabPageAudioMain;
private: System::Windows::Forms::ComboBox^  fcgCXAudioDelayCut;
private: System::Windows::Forms::Label^  fcgLBAudioDelayCut;
private: System::Windows::Forms::Label^  fcgCBAudioEncTiming;
private: System::Windows::Forms::ComboBox^  fcgCXAudioEncTiming;
private: System::Windows::Forms::ComboBox^  fcgCXAudioTempDir;
private: System::Windows::Forms::TextBox^  fcgTXCustomAudioTempDir;
private: System::Windows::Forms::Button^  fcgBTCustomAudioTempDir;
private: System::Windows::Forms::CheckBox^  fcgCBAudioUsePipe;
private: System::Windows::Forms::Label^  fcgLBAudioBitrate;
private: System::Windows::Forms::NumericUpDown^  fcgNUAudioBitrate;
private: System::Windows::Forms::CheckBox^  fcgCBAudio2pass;
private: System::Windows::Forms::ComboBox^  fcgCXAudioEncMode;
private: System::Windows::Forms::Label^  fcgLBAudioEncMode;
private: System::Windows::Forms::Button^  fcgBTAudioEncoderPath;
private: System::Windows::Forms::TextBox^  fcgTXAudioEncoderPath;
private: System::Windows::Forms::Label^  fcgLBAudioEncoderPath;
private: System::Windows::Forms::CheckBox^  fcgCBAudioOnly;
private: System::Windows::Forms::CheckBox^  fcgCBFAWCheck;
private: System::Windows::Forms::ComboBox^  fcgCXAudioEncoder;
private: System::Windows::Forms::Label^  fcgLBAudioEncoder;
private: System::Windows::Forms::Label^  fcgLBAudioTemp;
private: System::Windows::Forms::TabPage^  fcgtabPageAudioOther;
private: System::Windows::Forms::Panel^  panel2;
private: System::Windows::Forms::Label^  fcgLBBatAfterAudioString;
private: System::Windows::Forms::Label^  fcgLBBatBeforeAudioString;
private: System::Windows::Forms::Button^  fcgBTBatAfterAudioPath;
private: System::Windows::Forms::TextBox^  fcgTXBatAfterAudioPath;
private: System::Windows::Forms::Label^  fcgLBBatAfterAudioPath;
private: System::Windows::Forms::CheckBox^  fcgCBRunBatAfterAudio;
private: System::Windows::Forms::Panel^  panel1;
private: System::Windows::Forms::Button^  fcgBTBatBeforeAudioPath;
private: System::Windows::Forms::TextBox^  fcgTXBatBeforeAudioPath;
private: System::Windows::Forms::Label^  fcgLBBatBeforeAudioPath;
private: System::Windows::Forms::CheckBox^  fcgCBRunBatBeforeAudio;
private: System::Windows::Forms::ComboBox^  fcgCXAudioPriority;
private: System::Windows::Forms::Label^  fcgLBAudioPriority;

private: System::Windows::Forms::Label^  fcgLBAQ;
private: System::Windows::Forms::Label^  fcgLBFullrangeHEVC;
private: System::Windows::Forms::CheckBox^  fcgCBFullrangeHEVC;


private: System::Windows::Forms::ComboBox^  fcgCXVideoFormatHEVC;

private: System::Windows::Forms::Label^  fcgLBVideoFormatHEVC;
private: System::Windows::Forms::GroupBox^  fcggroupBoxColorHEVC;
private: System::Windows::Forms::ComboBox^  fcgCXTransferHEVC;
private: System::Windows::Forms::ComboBox^  fcgCXColorPrimHEVC;
private: System::Windows::Forms::ComboBox^  fcgCXColorMatrixHEVC;
private: System::Windows::Forms::Label^  fcgLBTransferHEVC;
private: System::Windows::Forms::Label^  fcgLBColorPrimHEVC;
private: System::Windows::Forms::Label^  fcgLBColorMatrixHEVC;
private: System::Windows::Forms::Label^  fcgLBLookaheadDisable;
private: System::Windows::Forms::NumericUpDown^  fcgNULookaheadDepth;

private: System::Windows::Forms::Label^  fcgLBAQStrengthAuto;
private: System::Windows::Forms::NumericUpDown^  fcgNUAQStrength;
private: System::Windows::Forms::Label^  fcgLBAQStrength;
private: System::Windows::Forms::ComboBox^  fcgCXAQ;

private: System::Windows::Forms::Label^  fcgLBLookaheadDepth;
private: System::Windows::Forms::Label^  fcgLBHEVCOutBitDepth;
private: System::Windows::Forms::ComboBox^  fcgCXHEVCOutBitDepth;
private: System::Windows::Forms::GroupBox^  fcggroupBoxVpp;
private: System::Windows::Forms::CheckBox^  fcgCBVppResize;
private: System::Windows::Forms::GroupBox^  fcggroupBoxResize;
private: System::Windows::Forms::ComboBox^  fcgCXVppResizeAlg;
private: System::Windows::Forms::Label^  fcgLBVppResize;

private: System::Windows::Forms::NumericUpDown^  fcgNUVppResizeHeight;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppResizeWidth;
private: System::Windows::Forms::GroupBox^  fcggroupBoxVppDenoise;

private: System::Windows::Forms::ComboBox^  fcgCXVppDenoiseMethod;
private: System::Windows::Forms::Panel^  fcgPNVppDenoisePmd;
private: System::Windows::Forms::Label^  fcgLBVppDenoisePmdThreshold;
private: System::Windows::Forms::Label^  fcgLBVppDenoisePmdStrength;
private: System::Windows::Forms::Label^  fcgLBVppDenoisePmdApplyCount;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppDenoisePmdThreshold;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppDenoisePmdStrength;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppDenoisePmdApplyCount;
private: System::Windows::Forms::Panel^  fcgPNVppDenoiseKnn;
private: System::Windows::Forms::Label^  fcgLBVppDenoiseKnnThreshold;
private: System::Windows::Forms::Label^  fcgLBVppDenoiseKnnStrength;
private: System::Windows::Forms::Label^  fcgLBVppDenoiseKnnRadius;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppDenoiseKnnThreshold;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppDenoiseKnnStrength;
private: System::Windows::Forms::NumericUpDown^  fcgNUVppDenoiseKnnRadius;
private: System::Windows::Forms::CheckBox^  fcgCBVppPerfMonitor;



















































































































    private: System::ComponentModel::IContainer^  components;


    

    private:
        /// <summary>
        /// 必要なデザイナ変数です。
        /// </summary>


#pragma region Windows Form Designer generated code
        /// <summary>
        /// デザイナ サポートに必要なメソッドです。このメソッドの内容を
        /// コード エディタで変更しないでください。
        /// </summary>
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmConfig::typeid));
            this->fcgtoolStripSettings = (gcnew System::Windows::Forms::ToolStrip());
            this->fcgTSBSave = (gcnew System::Windows::Forms::ToolStripButton());
            this->fcgTSBSaveNew = (gcnew System::Windows::Forms::ToolStripButton());
            this->fcgTSBDelete = (gcnew System::Windows::Forms::ToolStripButton());
            this->fcgtoolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
            this->fcgTSSettings = (gcnew System::Windows::Forms::ToolStripDropDownButton());
            this->fcgTSBBitrateCalc = (gcnew System::Windows::Forms::ToolStripButton());
            this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
            this->fcgTSBOtherSettings = (gcnew System::Windows::Forms::ToolStripButton());
            this->fcgTSLSettingsNotes = (gcnew System::Windows::Forms::ToolStripLabel());
            this->fcgTSTSettingsNotes = (gcnew System::Windows::Forms::ToolStripTextBox());
            this->fcgtabControlMux = (gcnew System::Windows::Forms::TabControl());
            this->fcgtabPageMP4 = (gcnew System::Windows::Forms::TabPage());
            this->fcgBTMP4RawPath = (gcnew System::Windows::Forms::Button());
            this->fcgTXMP4RawPath = (gcnew System::Windows::Forms::TextBox());
            this->fcgLBMP4RawPath = (gcnew System::Windows::Forms::Label());
            this->fcgCBMP4MuxApple = (gcnew System::Windows::Forms::CheckBox());
            this->fcgBTMP4BoxTempDir = (gcnew System::Windows::Forms::Button());
            this->fcgTXMP4BoxTempDir = (gcnew System::Windows::Forms::TextBox());
            this->fcgCXMP4BoxTempDir = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBMP4BoxTempDir = (gcnew System::Windows::Forms::Label());
            this->fcgBTTC2MP4Path = (gcnew System::Windows::Forms::Button());
            this->fcgTXTC2MP4Path = (gcnew System::Windows::Forms::TextBox());
            this->fcgBTMP4MuxerPath = (gcnew System::Windows::Forms::Button());
            this->fcgTXMP4MuxerPath = (gcnew System::Windows::Forms::TextBox());
            this->fcgLBTC2MP4Path = (gcnew System::Windows::Forms::Label());
            this->fcgLBMP4MuxerPath = (gcnew System::Windows::Forms::Label());
            this->fcgCXMP4CmdEx = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBMP4CmdEx = (gcnew System::Windows::Forms::Label());
            this->fcgCBMP4MuxerExt = (gcnew System::Windows::Forms::CheckBox());
            this->fcgtabPageMKV = (gcnew System::Windows::Forms::TabPage());
            this->fcgBTMKVMuxerPath = (gcnew System::Windows::Forms::Button());
            this->fcgTXMKVMuxerPath = (gcnew System::Windows::Forms::TextBox());
            this->fcgLBMKVMuxerPath = (gcnew System::Windows::Forms::Label());
            this->fcgCXMKVCmdEx = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBMKVMuxerCmdEx = (gcnew System::Windows::Forms::Label());
            this->fcgCBMKVMuxerExt = (gcnew System::Windows::Forms::CheckBox());
            this->fcgtabPageMPG = (gcnew System::Windows::Forms::TabPage());
            this->fcgBTMPGMuxerPath = (gcnew System::Windows::Forms::Button());
            this->fcgTXMPGMuxerPath = (gcnew System::Windows::Forms::TextBox());
            this->fcgLBMPGMuxerPath = (gcnew System::Windows::Forms::Label());
            this->fcgCXMPGCmdEx = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBMPGMuxerCmdEx = (gcnew System::Windows::Forms::Label());
            this->fcgCBMPGMuxerExt = (gcnew System::Windows::Forms::CheckBox());
            this->fcgtabPageMux = (gcnew System::Windows::Forms::TabPage());
            this->fcgCXMuxPriority = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBMuxPriority = (gcnew System::Windows::Forms::Label());
            this->fcgCBMuxMinimize = (gcnew System::Windows::Forms::CheckBox());
            this->fcgtabPageBat = (gcnew System::Windows::Forms::TabPage());
            this->fcgLBBatAfterString = (gcnew System::Windows::Forms::Label());
            this->fcgLBBatBeforeString = (gcnew System::Windows::Forms::Label());
            this->fcgPNSeparator = (gcnew System::Windows::Forms::Panel());
            this->fcgBTBatBeforePath = (gcnew System::Windows::Forms::Button());
            this->fcgTXBatBeforePath = (gcnew System::Windows::Forms::TextBox());
            this->fcgLBBatBeforePath = (gcnew System::Windows::Forms::Label());
            this->fcgCBWaitForBatBefore = (gcnew System::Windows::Forms::CheckBox());
            this->fcgCBRunBatBefore = (gcnew System::Windows::Forms::CheckBox());
            this->fcgBTBatAfterPath = (gcnew System::Windows::Forms::Button());
            this->fcgTXBatAfterPath = (gcnew System::Windows::Forms::TextBox());
            this->fcgLBBatAfterPath = (gcnew System::Windows::Forms::Label());
            this->fcgCBWaitForBatAfter = (gcnew System::Windows::Forms::CheckBox());
            this->fcgCBRunBatAfter = (gcnew System::Windows::Forms::CheckBox());
            this->fcgTXCmd = (gcnew System::Windows::Forms::TextBox());
            this->fcgBTCancel = (gcnew System::Windows::Forms::Button());
            this->fcgBTOK = (gcnew System::Windows::Forms::Button());
            this->fcgBTDefault = (gcnew System::Windows::Forms::Button());
            this->fcgLBVersionDate = (gcnew System::Windows::Forms::Label());
            this->fcgLBVersion = (gcnew System::Windows::Forms::Label());
            this->fcgfolderBrowserTemp = (gcnew System::Windows::Forms::FolderBrowserDialog());
            this->fcgOpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
            this->fcgTTEx = (gcnew System::Windows::Forms::ToolTip(this->components));
            this->fcgtabControlNVEnc = (gcnew System::Windows::Forms::TabControl());
            this->tabPageVideoEnc = (gcnew System::Windows::Forms::TabPage());
            this->fcgLBLookaheadDisable = (gcnew System::Windows::Forms::Label());
            this->fcgNULookaheadDepth = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgLBAQStrengthAuto = (gcnew System::Windows::Forms::Label());
            this->fcgNUAQStrength = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgLBAQStrength = (gcnew System::Windows::Forms::Label());
            this->fcgCXAQ = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBLookaheadDepth = (gcnew System::Windows::Forms::Label());
            this->fcgLBAQ = (gcnew System::Windows::Forms::Label());
            this->fcgNUVBVBufsize = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgGroupBoxAspectRatio = (gcnew System::Windows::Forms::GroupBox());
            this->fcgLBAspectRatio = (gcnew System::Windows::Forms::Label());
            this->fcgNUAspectRatioY = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUAspectRatioX = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgCXAspectRatio = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBVBVBufsize = (gcnew System::Windows::Forms::Label());
            this->fcgCBAFS = (gcnew System::Windows::Forms::CheckBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->fcgCXEncCodec = (gcnew System::Windows::Forms::ComboBox());
            this->fcgNURefFrames = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgLBRefFrames = (gcnew System::Windows::Forms::Label());
            this->fcgNUBframes = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgLBBframes = (gcnew System::Windows::Forms::Label());
            this->fcgPNBitrate = (gcnew System::Windows::Forms::Panel());
            this->fcgLBBitrate = (gcnew System::Windows::Forms::Label());
            this->fcgNUBitrate = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgLBBitrate2 = (gcnew System::Windows::Forms::Label());
            this->fcgNUMaxkbps = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgLBMaxkbps = (gcnew System::Windows::Forms::Label());
            this->fcgLBMaxBitrate2 = (gcnew System::Windows::Forms::Label());
            this->fcgPNQP = (gcnew System::Windows::Forms::Panel());
            this->fcgLBQPI = (gcnew System::Windows::Forms::Label());
            this->fcgNUQPI = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUQPP = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUQPB = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgLBQPP = (gcnew System::Windows::Forms::Label());
            this->fcgLBQPB = (gcnew System::Windows::Forms::Label());
            this->fcgLBGOPLengthAuto = (gcnew System::Windows::Forms::Label());
            this->fcgNUGopLength = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgLBGOPLength = (gcnew System::Windows::Forms::Label());
            this->fcgLBEncMode = (gcnew System::Windows::Forms::Label());
            this->fcgCXEncMode = (gcnew System::Windows::Forms::ComboBox());
            this->fcgPBNVEncLogoEnabled = (gcnew System::Windows::Forms::PictureBox());
            this->fcgPBNVEncLogoDisabled = (gcnew System::Windows::Forms::PictureBox());
            this->fcgGroupBoxQulaityStg = (gcnew System::Windows::Forms::GroupBox());
            this->fcgBTQualityStg = (gcnew System::Windows::Forms::Button());
            this->fcgCXQualityPreset = (gcnew System::Windows::Forms::ComboBox());
            this->fcgPNH264 = (gcnew System::Windows::Forms::Panel());
            this->fcgLBBluray = (gcnew System::Windows::Forms::Label());
            this->fcgCBBluray = (gcnew System::Windows::Forms::CheckBox());
            this->fcgLBDeblock = (gcnew System::Windows::Forms::Label());
            this->fcgCXAdaptiveTransform = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBAdaptiveTransform = (gcnew System::Windows::Forms::Label());
            this->fcgLBInterlaced = (gcnew System::Windows::Forms::Label());
            this->fcgLBCodecProfile = (gcnew System::Windows::Forms::Label());
            this->fcgCXBDirectMode = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBCodecLevel = (gcnew System::Windows::Forms::Label());
            this->fcgLBBDirectMode = (gcnew System::Windows::Forms::Label());
            this->fcgCXCodecProfile = (gcnew System::Windows::Forms::ComboBox());
            this->fcgCXCodecLevel = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBMVPRecision = (gcnew System::Windows::Forms::Label());
            this->fcgCXMVPrecision = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBFullrangeH264 = (gcnew System::Windows::Forms::Label());
            this->fcgCXInterlaced = (gcnew System::Windows::Forms::ComboBox());
            this->fcgCBFullrangeH264 = (gcnew System::Windows::Forms::CheckBox());
            this->fcgLBSlices = (gcnew System::Windows::Forms::Label());
            this->fcgCXVideoFormatH264 = (gcnew System::Windows::Forms::ComboBox());
            this->fcgCBDeblock = (gcnew System::Windows::Forms::CheckBox());
            this->fcgCBCABAC = (gcnew System::Windows::Forms::CheckBox());
            this->fcgLBVideoFormatH264 = (gcnew System::Windows::Forms::Label());
            this->fcgNUSlices = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcggroupBoxColorH264 = (gcnew System::Windows::Forms::GroupBox());
            this->fcgCXTransferH264 = (gcnew System::Windows::Forms::ComboBox());
            this->fcgCXColorPrimH264 = (gcnew System::Windows::Forms::ComboBox());
            this->fcgCXColorMatrixH264 = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBTransferH264 = (gcnew System::Windows::Forms::Label());
            this->fcgLBColorPrimH264 = (gcnew System::Windows::Forms::Label());
            this->fcgLBColorMatrixH264 = (gcnew System::Windows::Forms::Label());
            this->fcgLBCABAC = (gcnew System::Windows::Forms::Label());
            this->fcgPNHEVC = (gcnew System::Windows::Forms::Panel());
            this->fcgLBHEVCOutBitDepth = (gcnew System::Windows::Forms::Label());
            this->fcgCXHEVCOutBitDepth = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBFullrangeHEVC = (gcnew System::Windows::Forms::Label());
            this->fcgCBFullrangeHEVC = (gcnew System::Windows::Forms::CheckBox());
            this->fcgCXVideoFormatHEVC = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBVideoFormatHEVC = (gcnew System::Windows::Forms::Label());
            this->fcggroupBoxColorHEVC = (gcnew System::Windows::Forms::GroupBox());
            this->fcgCXTransferHEVC = (gcnew System::Windows::Forms::ComboBox());
            this->fcgCXColorPrimHEVC = (gcnew System::Windows::Forms::ComboBox());
            this->fcgCXColorMatrixHEVC = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBTransferHEVC = (gcnew System::Windows::Forms::Label());
            this->fcgLBColorPrimHEVC = (gcnew System::Windows::Forms::Label());
            this->fcgLBColorMatrixHEVC = (gcnew System::Windows::Forms::Label());
            this->fcgLBHEVCMinCUSize = (gcnew System::Windows::Forms::Label());
            this->fcgCXHEVCMinCUSize = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBHEVCMaxCUSize = (gcnew System::Windows::Forms::Label());
            this->fcgCXHEVCMaxCUSize = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBHEVCProfile = (gcnew System::Windows::Forms::Label());
            this->fxgLBHEVCTier = (gcnew System::Windows::Forms::Label());
            this->fcgCXHEVCTier = (gcnew System::Windows::Forms::ComboBox());
            this->fxgCXHEVCLevel = (gcnew System::Windows::Forms::ComboBox());
            this->tabPageExOpt = (gcnew System::Windows::Forms::TabPage());
            this->fcggroupBoxVpp = (gcnew System::Windows::Forms::GroupBox());
            this->fcgCBVppPerfMonitor = (gcnew System::Windows::Forms::CheckBox());
            this->fcggroupBoxVppDenoise = (gcnew System::Windows::Forms::GroupBox());
            this->fcgPNVppDenoiseKnn = (gcnew System::Windows::Forms::Panel());
            this->fcgLBVppDenoiseKnnThreshold = (gcnew System::Windows::Forms::Label());
            this->fcgLBVppDenoiseKnnStrength = (gcnew System::Windows::Forms::Label());
            this->fcgLBVppDenoiseKnnRadius = (gcnew System::Windows::Forms::Label());
            this->fcgNUVppDenoiseKnnThreshold = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppDenoiseKnnStrength = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppDenoiseKnnRadius = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgPNVppDenoisePmd = (gcnew System::Windows::Forms::Panel());
            this->fcgLBVppDenoisePmdThreshold = (gcnew System::Windows::Forms::Label());
            this->fcgLBVppDenoisePmdStrength = (gcnew System::Windows::Forms::Label());
            this->fcgLBVppDenoisePmdApplyCount = (gcnew System::Windows::Forms::Label());
            this->fcgNUVppDenoisePmdThreshold = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppDenoisePmdStrength = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppDenoisePmdApplyCount = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgCXVppDenoiseMethod = (gcnew System::Windows::Forms::ComboBox());
            this->fcgCBVppResize = (gcnew System::Windows::Forms::CheckBox());
            this->fcggroupBoxResize = (gcnew System::Windows::Forms::GroupBox());
            this->fcgCXVppResizeAlg = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBVppResize = (gcnew System::Windows::Forms::Label());
            this->fcgNUVppResizeHeight = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgNUVppResizeWidth = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgCBAuoTcfileout = (gcnew System::Windows::Forms::CheckBox());
            this->fcgLBTempDir = (gcnew System::Windows::Forms::Label());
            this->fcgBTCustomTempDir = (gcnew System::Windows::Forms::Button());
            this->fcgTXCustomTempDir = (gcnew System::Windows::Forms::TextBox());
            this->fcgCXTempDir = (gcnew System::Windows::Forms::ComboBox());
            this->tabPageNVEncFeatures = (gcnew System::Windows::Forms::TabPage());
            this->fcgTabControlFeatures = (gcnew System::Windows::Forms::TabControl());
            this->fcgTabPageH264 = (gcnew System::Windows::Forms::TabPage());
            this->fcgDGVFeaturesH264 = (gcnew System::Windows::Forms::DataGridView());
            this->fcgTabPageHEVC = (gcnew System::Windows::Forms::TabPage());
            this->fcgDGVFeaturesHEVC = (gcnew System::Windows::Forms::DataGridView());
            this->fcgLBOSInfo = (gcnew System::Windows::Forms::Label());
            this->fcgLBOSInfoLabel = (gcnew System::Windows::Forms::Label());
            this->fcgLBCPUInfoOnFeatureTab = (gcnew System::Windows::Forms::Label());
            this->fcgLBCPUInfoLabelOnFeatureTab = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->fcgLBGPUInfoOnFeatureTab = (gcnew System::Windows::Forms::Label());
            this->fcgLBGPUInfoLabelOnFeatureTab = (gcnew System::Windows::Forms::Label());
            this->fcgCSExeFiles = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
            this->fcgTSExeFileshelp = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->fcgLBguiExBlog = (gcnew System::Windows::Forms::LinkLabel());
            this->fcgtabControlAudio = (gcnew System::Windows::Forms::TabControl());
            this->fcgtabPageAudioMain = (gcnew System::Windows::Forms::TabPage());
            this->fcgCXAudioDelayCut = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBAudioDelayCut = (gcnew System::Windows::Forms::Label());
            this->fcgCBAudioEncTiming = (gcnew System::Windows::Forms::Label());
            this->fcgCXAudioEncTiming = (gcnew System::Windows::Forms::ComboBox());
            this->fcgCXAudioTempDir = (gcnew System::Windows::Forms::ComboBox());
            this->fcgTXCustomAudioTempDir = (gcnew System::Windows::Forms::TextBox());
            this->fcgBTCustomAudioTempDir = (gcnew System::Windows::Forms::Button());
            this->fcgCBAudioUsePipe = (gcnew System::Windows::Forms::CheckBox());
            this->fcgLBAudioBitrate = (gcnew System::Windows::Forms::Label());
            this->fcgNUAudioBitrate = (gcnew System::Windows::Forms::NumericUpDown());
            this->fcgCBAudio2pass = (gcnew System::Windows::Forms::CheckBox());
            this->fcgCXAudioEncMode = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBAudioEncMode = (gcnew System::Windows::Forms::Label());
            this->fcgBTAudioEncoderPath = (gcnew System::Windows::Forms::Button());
            this->fcgTXAudioEncoderPath = (gcnew System::Windows::Forms::TextBox());
            this->fcgLBAudioEncoderPath = (gcnew System::Windows::Forms::Label());
            this->fcgCBAudioOnly = (gcnew System::Windows::Forms::CheckBox());
            this->fcgCBFAWCheck = (gcnew System::Windows::Forms::CheckBox());
            this->fcgCXAudioEncoder = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBAudioEncoder = (gcnew System::Windows::Forms::Label());
            this->fcgLBAudioTemp = (gcnew System::Windows::Forms::Label());
            this->fcgtabPageAudioOther = (gcnew System::Windows::Forms::TabPage());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->fcgLBBatAfterAudioString = (gcnew System::Windows::Forms::Label());
            this->fcgLBBatBeforeAudioString = (gcnew System::Windows::Forms::Label());
            this->fcgBTBatAfterAudioPath = (gcnew System::Windows::Forms::Button());
            this->fcgTXBatAfterAudioPath = (gcnew System::Windows::Forms::TextBox());
            this->fcgLBBatAfterAudioPath = (gcnew System::Windows::Forms::Label());
            this->fcgCBRunBatAfterAudio = (gcnew System::Windows::Forms::CheckBox());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->fcgBTBatBeforeAudioPath = (gcnew System::Windows::Forms::Button());
            this->fcgTXBatBeforeAudioPath = (gcnew System::Windows::Forms::TextBox());
            this->fcgLBBatBeforeAudioPath = (gcnew System::Windows::Forms::Label());
            this->fcgCBRunBatBeforeAudio = (gcnew System::Windows::Forms::CheckBox());
            this->fcgCXAudioPriority = (gcnew System::Windows::Forms::ComboBox());
            this->fcgLBAudioPriority = (gcnew System::Windows::Forms::Label());
            this->fcgtoolStripSettings->SuspendLayout();
            this->fcgtabControlMux->SuspendLayout();
            this->fcgtabPageMP4->SuspendLayout();
            this->fcgtabPageMKV->SuspendLayout();
            this->fcgtabPageMPG->SuspendLayout();
            this->fcgtabPageMux->SuspendLayout();
            this->fcgtabPageBat->SuspendLayout();
            this->fcgtabControlNVEnc->SuspendLayout();
            this->tabPageVideoEnc->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNULookaheadDepth))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUAQStrength))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVBVBufsize))->BeginInit();
            this->fcgGroupBoxAspectRatio->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUAspectRatioY))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUAspectRatioX))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNURefFrames))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUBframes))->BeginInit();
            this->fcgPNBitrate->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUBitrate))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUMaxkbps))->BeginInit();
            this->fcgPNQP->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPI))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPP))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPB))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUGopLength))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgPBNVEncLogoEnabled))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgPBNVEncLogoDisabled))->BeginInit();
            this->fcgGroupBoxQulaityStg->SuspendLayout();
            this->fcgPNH264->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUSlices))->BeginInit();
            this->fcggroupBoxColorH264->SuspendLayout();
            this->fcgPNHEVC->SuspendLayout();
            this->fcggroupBoxColorHEVC->SuspendLayout();
            this->tabPageExOpt->SuspendLayout();
            this->fcggroupBoxVpp->SuspendLayout();
            this->fcggroupBoxVppDenoise->SuspendLayout();
            this->fcgPNVppDenoiseKnn->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoiseKnnThreshold))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoiseKnnStrength))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoiseKnnRadius))->BeginInit();
            this->fcgPNVppDenoisePmd->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoisePmdThreshold))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoisePmdStrength))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoisePmdApplyCount))->BeginInit();
            this->fcggroupBoxResize->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppResizeHeight))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppResizeWidth))->BeginInit();
            this->tabPageNVEncFeatures->SuspendLayout();
            this->fcgTabControlFeatures->SuspendLayout();
            this->fcgTabPageH264->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgDGVFeaturesH264))->BeginInit();
            this->fcgTabPageHEVC->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgDGVFeaturesHEVC))->BeginInit();
            this->fcgCSExeFiles->SuspendLayout();
            this->fcgtabControlAudio->SuspendLayout();
            this->fcgtabPageAudioMain->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUAudioBitrate))->BeginInit();
            this->fcgtabPageAudioOther->SuspendLayout();
            this->SuspendLayout();
            // 
            // fcgtoolStripSettings
            // 
            this->fcgtoolStripSettings->ImageScalingSize = System::Drawing::Size(18, 18);
            this->fcgtoolStripSettings->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {
                this->fcgTSBSave,
                    this->fcgTSBSaveNew, this->fcgTSBDelete, this->fcgtoolStripSeparator1, this->fcgTSSettings, this->fcgTSBBitrateCalc, this->toolStripSeparator2,
                    this->fcgTSBOtherSettings, this->fcgTSLSettingsNotes, this->fcgTSTSettingsNotes
            });
            this->fcgtoolStripSettings->Location = System::Drawing::Point(0, 0);
            this->fcgtoolStripSettings->Name = L"fcgtoolStripSettings";
            this->fcgtoolStripSettings->Size = System::Drawing::Size(1008, 25);
            this->fcgtoolStripSettings->TabIndex = 1;
            this->fcgtoolStripSettings->Text = L"toolStrip1";
            // 
            // fcgTSBSave
            // 
            this->fcgTSBSave->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fcgTSBSave.Image")));
            this->fcgTSBSave->ImageTransparentColor = System::Drawing::Color::Magenta;
            this->fcgTSBSave->Name = L"fcgTSBSave";
            this->fcgTSBSave->Size = System::Drawing::Size(86, 22);
            this->fcgTSBSave->Text = L"上書き保存";
            this->fcgTSBSave->Click += gcnew System::EventHandler(this, &frmConfig::fcgTSBSave_Click);
            // 
            // fcgTSBSaveNew
            // 
            this->fcgTSBSaveNew->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fcgTSBSaveNew.Image")));
            this->fcgTSBSaveNew->ImageTransparentColor = System::Drawing::Color::Black;
            this->fcgTSBSaveNew->Name = L"fcgTSBSaveNew";
            this->fcgTSBSaveNew->Size = System::Drawing::Size(77, 22);
            this->fcgTSBSaveNew->Text = L"新規保存";
            this->fcgTSBSaveNew->Click += gcnew System::EventHandler(this, &frmConfig::fcgTSBSaveNew_Click);
            // 
            // fcgTSBDelete
            // 
            this->fcgTSBDelete->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fcgTSBDelete.Image")));
            this->fcgTSBDelete->ImageTransparentColor = System::Drawing::Color::Magenta;
            this->fcgTSBDelete->Name = L"fcgTSBDelete";
            this->fcgTSBDelete->Size = System::Drawing::Size(53, 22);
            this->fcgTSBDelete->Text = L"削除";
            this->fcgTSBDelete->Click += gcnew System::EventHandler(this, &frmConfig::fcgTSBDelete_Click);
            // 
            // fcgtoolStripSeparator1
            // 
            this->fcgtoolStripSeparator1->Name = L"fcgtoolStripSeparator1";
            this->fcgtoolStripSeparator1->Size = System::Drawing::Size(6, 25);
            // 
            // fcgTSSettings
            // 
            this->fcgTSSettings->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fcgTSSettings.Image")));
            this->fcgTSSettings->ImageTransparentColor = System::Drawing::Color::Magenta;
            this->fcgTSSettings->Name = L"fcgTSSettings";
            this->fcgTSSettings->Size = System::Drawing::Size(81, 22);
            this->fcgTSSettings->Text = L"プリセット";
            this->fcgTSSettings->DropDownItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &frmConfig::fcgTSSettings_DropDownItemClicked);
            this->fcgTSSettings->Click += gcnew System::EventHandler(this, &frmConfig::fcgTSSettings_Click);
            // 
            // fcgTSBBitrateCalc
            // 
            this->fcgTSBBitrateCalc->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
            this->fcgTSBBitrateCalc->CheckOnClick = true;
            this->fcgTSBBitrateCalc->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
            this->fcgTSBBitrateCalc->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fcgTSBBitrateCalc.Image")));
            this->fcgTSBBitrateCalc->ImageTransparentColor = System::Drawing::Color::Magenta;
            this->fcgTSBBitrateCalc->Name = L"fcgTSBBitrateCalc";
            this->fcgTSBBitrateCalc->Size = System::Drawing::Size(96, 22);
            this->fcgTSBBitrateCalc->Text = L"ビットレート計算機";
            this->fcgTSBBitrateCalc->CheckedChanged += gcnew System::EventHandler(this, &frmConfig::fcgTSBBitrateCalc_CheckedChanged);
            // 
            // toolStripSeparator2
            // 
            this->toolStripSeparator2->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
            this->toolStripSeparator2->Name = L"toolStripSeparator2";
            this->toolStripSeparator2->Size = System::Drawing::Size(6, 25);
            // 
            // fcgTSBOtherSettings
            // 
            this->fcgTSBOtherSettings->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
            this->fcgTSBOtherSettings->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
            this->fcgTSBOtherSettings->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fcgTSBOtherSettings.Image")));
            this->fcgTSBOtherSettings->ImageTransparentColor = System::Drawing::Color::Magenta;
            this->fcgTSBOtherSettings->Name = L"fcgTSBOtherSettings";
            this->fcgTSBOtherSettings->Size = System::Drawing::Size(76, 22);
            this->fcgTSBOtherSettings->Text = L"その他の設定";
            this->fcgTSBOtherSettings->Click += gcnew System::EventHandler(this, &frmConfig::fcgTSBOtherSettings_Click);
            // 
            // fcgTSLSettingsNotes
            // 
            this->fcgTSLSettingsNotes->DoubleClickEnabled = true;
            this->fcgTSLSettingsNotes->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->fcgTSLSettingsNotes->Margin = System::Windows::Forms::Padding(3, 1, 0, 2);
            this->fcgTSLSettingsNotes->Name = L"fcgTSLSettingsNotes";
            this->fcgTSLSettingsNotes->Overflow = System::Windows::Forms::ToolStripItemOverflow::Never;
            this->fcgTSLSettingsNotes->Size = System::Drawing::Size(45, 22);
            this->fcgTSLSettingsNotes->Text = L"メモ表示";
            this->fcgTSLSettingsNotes->DoubleClick += gcnew System::EventHandler(this, &frmConfig::fcgTSLSettingsNotes_DoubleClick);
            // 
            // fcgTSTSettingsNotes
            // 
            this->fcgTSTSettingsNotes->BackColor = System::Drawing::SystemColors::Window;
            this->fcgTSTSettingsNotes->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->fcgTSTSettingsNotes->Margin = System::Windows::Forms::Padding(3, 0, 1, 0);
            this->fcgTSTSettingsNotes->Name = L"fcgTSTSettingsNotes";
            this->fcgTSTSettingsNotes->Size = System::Drawing::Size(200, 25);
            this->fcgTSTSettingsNotes->Text = L"メモ...";
            this->fcgTSTSettingsNotes->Visible = false;
            this->fcgTSTSettingsNotes->Leave += gcnew System::EventHandler(this, &frmConfig::fcgTSTSettingsNotes_Leave);
            this->fcgTSTSettingsNotes->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &frmConfig::fcgTSTSettingsNotes_KeyDown);
            this->fcgTSTSettingsNotes->TextChanged += gcnew System::EventHandler(this, &frmConfig::fcgTSTSettingsNotes_TextChanged);
            // 
            // fcgtabControlMux
            // 
            this->fcgtabControlMux->Controls->Add(this->fcgtabPageMP4);
            this->fcgtabControlMux->Controls->Add(this->fcgtabPageMKV);
            this->fcgtabControlMux->Controls->Add(this->fcgtabPageMPG);
            this->fcgtabControlMux->Controls->Add(this->fcgtabPageMux);
            this->fcgtabControlMux->Controls->Add(this->fcgtabPageBat);
            this->fcgtabControlMux->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->fcgtabControlMux->Location = System::Drawing::Point(622, 339);
            this->fcgtabControlMux->Name = L"fcgtabControlMux";
            this->fcgtabControlMux->SelectedIndex = 0;
            this->fcgtabControlMux->Size = System::Drawing::Size(384, 201);
            this->fcgtabControlMux->TabIndex = 3;
            // 
            // fcgtabPageMP4
            // 
            this->fcgtabPageMP4->Controls->Add(this->fcgBTMP4RawPath);
            this->fcgtabPageMP4->Controls->Add(this->fcgTXMP4RawPath);
            this->fcgtabPageMP4->Controls->Add(this->fcgLBMP4RawPath);
            this->fcgtabPageMP4->Controls->Add(this->fcgCBMP4MuxApple);
            this->fcgtabPageMP4->Controls->Add(this->fcgBTMP4BoxTempDir);
            this->fcgtabPageMP4->Controls->Add(this->fcgTXMP4BoxTempDir);
            this->fcgtabPageMP4->Controls->Add(this->fcgCXMP4BoxTempDir);
            this->fcgtabPageMP4->Controls->Add(this->fcgLBMP4BoxTempDir);
            this->fcgtabPageMP4->Controls->Add(this->fcgBTTC2MP4Path);
            this->fcgtabPageMP4->Controls->Add(this->fcgTXTC2MP4Path);
            this->fcgtabPageMP4->Controls->Add(this->fcgBTMP4MuxerPath);
            this->fcgtabPageMP4->Controls->Add(this->fcgTXMP4MuxerPath);
            this->fcgtabPageMP4->Controls->Add(this->fcgLBTC2MP4Path);
            this->fcgtabPageMP4->Controls->Add(this->fcgLBMP4MuxerPath);
            this->fcgtabPageMP4->Controls->Add(this->fcgCXMP4CmdEx);
            this->fcgtabPageMP4->Controls->Add(this->fcgLBMP4CmdEx);
            this->fcgtabPageMP4->Controls->Add(this->fcgCBMP4MuxerExt);
            this->fcgtabPageMP4->Location = System::Drawing::Point(4, 23);
            this->fcgtabPageMP4->Name = L"fcgtabPageMP4";
            this->fcgtabPageMP4->Padding = System::Windows::Forms::Padding(3);
            this->fcgtabPageMP4->Size = System::Drawing::Size(376, 174);
            this->fcgtabPageMP4->TabIndex = 0;
            this->fcgtabPageMP4->Text = L"mp4";
            this->fcgtabPageMP4->UseVisualStyleBackColor = true;
            // 
            // fcgBTMP4RawPath
            // 
            this->fcgBTMP4RawPath->Location = System::Drawing::Point(340, 102);
            this->fcgBTMP4RawPath->Name = L"fcgBTMP4RawPath";
            this->fcgBTMP4RawPath->Size = System::Drawing::Size(30, 23);
            this->fcgBTMP4RawPath->TabIndex = 23;
            this->fcgBTMP4RawPath->Text = L"...";
            this->fcgBTMP4RawPath->UseVisualStyleBackColor = true;
            this->fcgBTMP4RawPath->Visible = false;
            this->fcgBTMP4RawPath->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTMP4RawMuxerPath_Click);
            // 
            // fcgTXMP4RawPath
            // 
            this->fcgTXMP4RawPath->AllowDrop = true;
            this->fcgTXMP4RawPath->Location = System::Drawing::Point(136, 103);
            this->fcgTXMP4RawPath->Name = L"fcgTXMP4RawPath";
            this->fcgTXMP4RawPath->Size = System::Drawing::Size(202, 21);
            this->fcgTXMP4RawPath->TabIndex = 22;
            this->fcgTXMP4RawPath->Visible = false;
            this->fcgTXMP4RawPath->TextChanged += gcnew System::EventHandler(this, &frmConfig::fcgTXMP4RawMuxerPath_TextChanged);
            this->fcgTXMP4RawPath->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_DragDrop);
            this->fcgTXMP4RawPath->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_Enter);
            // 
            // fcgLBMP4RawPath
            // 
            this->fcgLBMP4RawPath->AutoSize = true;
            this->fcgLBMP4RawPath->Location = System::Drawing::Point(4, 106);
            this->fcgLBMP4RawPath->Name = L"fcgLBMP4RawPath";
            this->fcgLBMP4RawPath->Size = System::Drawing::Size(49, 14);
            this->fcgLBMP4RawPath->TabIndex = 21;
            this->fcgLBMP4RawPath->Text = L"～の指定";
            this->fcgLBMP4RawPath->Visible = false;
            // 
            // fcgCBMP4MuxApple
            // 
            this->fcgCBMP4MuxApple->AutoSize = true;
            this->fcgCBMP4MuxApple->Location = System::Drawing::Point(254, 34);
            this->fcgCBMP4MuxApple->Name = L"fcgCBMP4MuxApple";
            this->fcgCBMP4MuxApple->Size = System::Drawing::Size(109, 18);
            this->fcgCBMP4MuxApple->TabIndex = 20;
            this->fcgCBMP4MuxApple->Tag = L"chValue";
            this->fcgCBMP4MuxApple->Text = L"Apple形式に対応";
            this->fcgCBMP4MuxApple->UseVisualStyleBackColor = true;
            // 
            // fcgBTMP4BoxTempDir
            // 
            this->fcgBTMP4BoxTempDir->Location = System::Drawing::Point(340, 146);
            this->fcgBTMP4BoxTempDir->Name = L"fcgBTMP4BoxTempDir";
            this->fcgBTMP4BoxTempDir->Size = System::Drawing::Size(30, 23);
            this->fcgBTMP4BoxTempDir->TabIndex = 8;
            this->fcgBTMP4BoxTempDir->Text = L"...";
            this->fcgBTMP4BoxTempDir->UseVisualStyleBackColor = true;
            this->fcgBTMP4BoxTempDir->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTMP4BoxTempDir_Click);
            // 
            // fcgTXMP4BoxTempDir
            // 
            this->fcgTXMP4BoxTempDir->Location = System::Drawing::Point(107, 147);
            this->fcgTXMP4BoxTempDir->Name = L"fcgTXMP4BoxTempDir";
            this->fcgTXMP4BoxTempDir->Size = System::Drawing::Size(227, 21);
            this->fcgTXMP4BoxTempDir->TabIndex = 7;
            this->fcgTXMP4BoxTempDir->TextChanged += gcnew System::EventHandler(this, &frmConfig::fcgTXMP4BoxTempDir_TextChanged);
            // 
            // fcgCXMP4BoxTempDir
            // 
            this->fcgCXMP4BoxTempDir->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXMP4BoxTempDir->FormattingEnabled = true;
            this->fcgCXMP4BoxTempDir->Location = System::Drawing::Point(145, 119);
            this->fcgCXMP4BoxTempDir->Name = L"fcgCXMP4BoxTempDir";
            this->fcgCXMP4BoxTempDir->Size = System::Drawing::Size(206, 22);
            this->fcgCXMP4BoxTempDir->TabIndex = 6;
            this->fcgCXMP4BoxTempDir->Tag = L"chValue";
            // 
            // fcgLBMP4BoxTempDir
            // 
            this->fcgLBMP4BoxTempDir->AutoSize = true;
            this->fcgLBMP4BoxTempDir->Location = System::Drawing::Point(25, 122);
            this->fcgLBMP4BoxTempDir->Name = L"fcgLBMP4BoxTempDir";
            this->fcgLBMP4BoxTempDir->Size = System::Drawing::Size(105, 14);
            this->fcgLBMP4BoxTempDir->TabIndex = 18;
            this->fcgLBMP4BoxTempDir->Text = L"mp4box一時フォルダ";
            // 
            // fcgBTTC2MP4Path
            // 
            this->fcgBTTC2MP4Path->Location = System::Drawing::Point(340, 80);
            this->fcgBTTC2MP4Path->Name = L"fcgBTTC2MP4Path";
            this->fcgBTTC2MP4Path->Size = System::Drawing::Size(30, 23);
            this->fcgBTTC2MP4Path->TabIndex = 5;
            this->fcgBTTC2MP4Path->Text = L"...";
            this->fcgBTTC2MP4Path->UseVisualStyleBackColor = true;
            this->fcgBTTC2MP4Path->Visible = false;
            this->fcgBTTC2MP4Path->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTTC2MP4Path_Click);
            // 
            // fcgTXTC2MP4Path
            // 
            this->fcgTXTC2MP4Path->AllowDrop = true;
            this->fcgTXTC2MP4Path->Location = System::Drawing::Point(136, 81);
            this->fcgTXTC2MP4Path->Name = L"fcgTXTC2MP4Path";
            this->fcgTXTC2MP4Path->Size = System::Drawing::Size(202, 21);
            this->fcgTXTC2MP4Path->TabIndex = 4;
            this->fcgTXTC2MP4Path->Visible = false;
            this->fcgTXTC2MP4Path->TextChanged += gcnew System::EventHandler(this, &frmConfig::fcgTXTC2MP4Path_TextChanged);
            this->fcgTXTC2MP4Path->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_DragDrop);
            this->fcgTXTC2MP4Path->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_Enter);
            // 
            // fcgBTMP4MuxerPath
            // 
            this->fcgBTMP4MuxerPath->Location = System::Drawing::Point(340, 58);
            this->fcgBTMP4MuxerPath->Name = L"fcgBTMP4MuxerPath";
            this->fcgBTMP4MuxerPath->Size = System::Drawing::Size(30, 23);
            this->fcgBTMP4MuxerPath->TabIndex = 3;
            this->fcgBTMP4MuxerPath->Text = L"...";
            this->fcgBTMP4MuxerPath->UseVisualStyleBackColor = true;
            this->fcgBTMP4MuxerPath->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTMP4MuxerPath_Click);
            // 
            // fcgTXMP4MuxerPath
            // 
            this->fcgTXMP4MuxerPath->AllowDrop = true;
            this->fcgTXMP4MuxerPath->Location = System::Drawing::Point(136, 59);
            this->fcgTXMP4MuxerPath->Name = L"fcgTXMP4MuxerPath";
            this->fcgTXMP4MuxerPath->Size = System::Drawing::Size(202, 21);
            this->fcgTXMP4MuxerPath->TabIndex = 2;
            this->fcgTXMP4MuxerPath->Tag = L"";
            this->fcgTXMP4MuxerPath->TextChanged += gcnew System::EventHandler(this, &frmConfig::fcgTXMP4MuxerPath_TextChanged);
            this->fcgTXMP4MuxerPath->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_DragDrop);
            this->fcgTXMP4MuxerPath->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_Enter);
            // 
            // fcgLBTC2MP4Path
            // 
            this->fcgLBTC2MP4Path->AutoSize = true;
            this->fcgLBTC2MP4Path->Location = System::Drawing::Point(4, 84);
            this->fcgLBTC2MP4Path->Name = L"fcgLBTC2MP4Path";
            this->fcgLBTC2MP4Path->Size = System::Drawing::Size(49, 14);
            this->fcgLBTC2MP4Path->TabIndex = 4;
            this->fcgLBTC2MP4Path->Text = L"～の指定";
            this->fcgLBTC2MP4Path->Visible = false;
            // 
            // fcgLBMP4MuxerPath
            // 
            this->fcgLBMP4MuxerPath->AutoSize = true;
            this->fcgLBMP4MuxerPath->Location = System::Drawing::Point(4, 62);
            this->fcgLBMP4MuxerPath->Name = L"fcgLBMP4MuxerPath";
            this->fcgLBMP4MuxerPath->Size = System::Drawing::Size(49, 14);
            this->fcgLBMP4MuxerPath->TabIndex = 3;
            this->fcgLBMP4MuxerPath->Text = L"～の指定";
            // 
            // fcgCXMP4CmdEx
            // 
            this->fcgCXMP4CmdEx->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXMP4CmdEx->FormattingEnabled = true;
            this->fcgCXMP4CmdEx->Location = System::Drawing::Point(213, 7);
            this->fcgCXMP4CmdEx->Name = L"fcgCXMP4CmdEx";
            this->fcgCXMP4CmdEx->Size = System::Drawing::Size(157, 22);
            this->fcgCXMP4CmdEx->TabIndex = 1;
            this->fcgCXMP4CmdEx->Tag = L"chValue";
            // 
            // fcgLBMP4CmdEx
            // 
            this->fcgLBMP4CmdEx->AutoSize = true;
            this->fcgLBMP4CmdEx->Location = System::Drawing::Point(139, 10);
            this->fcgLBMP4CmdEx->Name = L"fcgLBMP4CmdEx";
            this->fcgLBMP4CmdEx->Size = System::Drawing::Size(68, 14);
            this->fcgLBMP4CmdEx->TabIndex = 1;
            this->fcgLBMP4CmdEx->Text = L"拡張オプション";
            // 
            // fcgCBMP4MuxerExt
            // 
            this->fcgCBMP4MuxerExt->AutoSize = true;
            this->fcgCBMP4MuxerExt->Location = System::Drawing::Point(10, 9);
            this->fcgCBMP4MuxerExt->Name = L"fcgCBMP4MuxerExt";
            this->fcgCBMP4MuxerExt->Size = System::Drawing::Size(113, 18);
            this->fcgCBMP4MuxerExt->TabIndex = 0;
            this->fcgCBMP4MuxerExt->Tag = L"chValue";
            this->fcgCBMP4MuxerExt->Text = L"外部muxerを使用";
            this->fcgCBMP4MuxerExt->UseVisualStyleBackColor = true;
            // 
            // fcgtabPageMKV
            // 
            this->fcgtabPageMKV->Controls->Add(this->fcgBTMKVMuxerPath);
            this->fcgtabPageMKV->Controls->Add(this->fcgTXMKVMuxerPath);
            this->fcgtabPageMKV->Controls->Add(this->fcgLBMKVMuxerPath);
            this->fcgtabPageMKV->Controls->Add(this->fcgCXMKVCmdEx);
            this->fcgtabPageMKV->Controls->Add(this->fcgLBMKVMuxerCmdEx);
            this->fcgtabPageMKV->Controls->Add(this->fcgCBMKVMuxerExt);
            this->fcgtabPageMKV->Location = System::Drawing::Point(4, 23);
            this->fcgtabPageMKV->Name = L"fcgtabPageMKV";
            this->fcgtabPageMKV->Padding = System::Windows::Forms::Padding(3);
            this->fcgtabPageMKV->Size = System::Drawing::Size(376, 174);
            this->fcgtabPageMKV->TabIndex = 1;
            this->fcgtabPageMKV->Text = L"mkv";
            this->fcgtabPageMKV->UseVisualStyleBackColor = true;
            // 
            // fcgBTMKVMuxerPath
            // 
            this->fcgBTMKVMuxerPath->Location = System::Drawing::Point(340, 76);
            this->fcgBTMKVMuxerPath->Name = L"fcgBTMKVMuxerPath";
            this->fcgBTMKVMuxerPath->Size = System::Drawing::Size(30, 23);
            this->fcgBTMKVMuxerPath->TabIndex = 3;
            this->fcgBTMKVMuxerPath->Text = L"...";
            this->fcgBTMKVMuxerPath->UseVisualStyleBackColor = true;
            this->fcgBTMKVMuxerPath->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTMKVMuxerPath_Click);
            // 
            // fcgTXMKVMuxerPath
            // 
            this->fcgTXMKVMuxerPath->Location = System::Drawing::Point(131, 77);
            this->fcgTXMKVMuxerPath->Name = L"fcgTXMKVMuxerPath";
            this->fcgTXMKVMuxerPath->Size = System::Drawing::Size(207, 21);
            this->fcgTXMKVMuxerPath->TabIndex = 2;
            this->fcgTXMKVMuxerPath->TextChanged += gcnew System::EventHandler(this, &frmConfig::fcgTXMKVMuxerPath_TextChanged);
            this->fcgTXMKVMuxerPath->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_DragDrop);
            this->fcgTXMKVMuxerPath->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_Enter);
            // 
            // fcgLBMKVMuxerPath
            // 
            this->fcgLBMKVMuxerPath->AutoSize = true;
            this->fcgLBMKVMuxerPath->Location = System::Drawing::Point(4, 80);
            this->fcgLBMKVMuxerPath->Name = L"fcgLBMKVMuxerPath";
            this->fcgLBMKVMuxerPath->Size = System::Drawing::Size(49, 14);
            this->fcgLBMKVMuxerPath->TabIndex = 19;
            this->fcgLBMKVMuxerPath->Text = L"～の指定";
            // 
            // fcgCXMKVCmdEx
            // 
            this->fcgCXMKVCmdEx->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXMKVCmdEx->FormattingEnabled = true;
            this->fcgCXMKVCmdEx->Location = System::Drawing::Point(213, 43);
            this->fcgCXMKVCmdEx->Name = L"fcgCXMKVCmdEx";
            this->fcgCXMKVCmdEx->Size = System::Drawing::Size(157, 22);
            this->fcgCXMKVCmdEx->TabIndex = 1;
            this->fcgCXMKVCmdEx->Tag = L"chValue";
            // 
            // fcgLBMKVMuxerCmdEx
            // 
            this->fcgLBMKVMuxerCmdEx->AutoSize = true;
            this->fcgLBMKVMuxerCmdEx->Location = System::Drawing::Point(139, 46);
            this->fcgLBMKVMuxerCmdEx->Name = L"fcgLBMKVMuxerCmdEx";
            this->fcgLBMKVMuxerCmdEx->Size = System::Drawing::Size(68, 14);
            this->fcgLBMKVMuxerCmdEx->TabIndex = 17;
            this->fcgLBMKVMuxerCmdEx->Text = L"拡張オプション";
            // 
            // fcgCBMKVMuxerExt
            // 
            this->fcgCBMKVMuxerExt->AutoSize = true;
            this->fcgCBMKVMuxerExt->Location = System::Drawing::Point(10, 45);
            this->fcgCBMKVMuxerExt->Name = L"fcgCBMKVMuxerExt";
            this->fcgCBMKVMuxerExt->Size = System::Drawing::Size(113, 18);
            this->fcgCBMKVMuxerExt->TabIndex = 0;
            this->fcgCBMKVMuxerExt->Tag = L"chValue";
            this->fcgCBMKVMuxerExt->Text = L"外部muxerを使用";
            this->fcgCBMKVMuxerExt->UseVisualStyleBackColor = true;
            // 
            // fcgtabPageMPG
            // 
            this->fcgtabPageMPG->Controls->Add(this->fcgBTMPGMuxerPath);
            this->fcgtabPageMPG->Controls->Add(this->fcgTXMPGMuxerPath);
            this->fcgtabPageMPG->Controls->Add(this->fcgLBMPGMuxerPath);
            this->fcgtabPageMPG->Controls->Add(this->fcgCXMPGCmdEx);
            this->fcgtabPageMPG->Controls->Add(this->fcgLBMPGMuxerCmdEx);
            this->fcgtabPageMPG->Controls->Add(this->fcgCBMPGMuxerExt);
            this->fcgtabPageMPG->Location = System::Drawing::Point(4, 23);
            this->fcgtabPageMPG->Name = L"fcgtabPageMPG";
            this->fcgtabPageMPG->Size = System::Drawing::Size(376, 174);
            this->fcgtabPageMPG->TabIndex = 4;
            this->fcgtabPageMPG->Text = L"mpg";
            this->fcgtabPageMPG->UseVisualStyleBackColor = true;
            // 
            // fcgBTMPGMuxerPath
            // 
            this->fcgBTMPGMuxerPath->Location = System::Drawing::Point(341, 92);
            this->fcgBTMPGMuxerPath->Name = L"fcgBTMPGMuxerPath";
            this->fcgBTMPGMuxerPath->Size = System::Drawing::Size(30, 23);
            this->fcgBTMPGMuxerPath->TabIndex = 23;
            this->fcgBTMPGMuxerPath->Text = L"...";
            this->fcgBTMPGMuxerPath->UseVisualStyleBackColor = true;
            this->fcgBTMPGMuxerPath->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTMPGMuxerPath_Click);
            // 
            // fcgTXMPGMuxerPath
            // 
            this->fcgTXMPGMuxerPath->Location = System::Drawing::Point(132, 93);
            this->fcgTXMPGMuxerPath->Name = L"fcgTXMPGMuxerPath";
            this->fcgTXMPGMuxerPath->Size = System::Drawing::Size(207, 21);
            this->fcgTXMPGMuxerPath->TabIndex = 22;
            this->fcgTXMPGMuxerPath->TextChanged += gcnew System::EventHandler(this, &frmConfig::fcgTXMPGMuxerPath_TextChanged);
            this->fcgTXMPGMuxerPath->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_DragDrop);
            this->fcgTXMPGMuxerPath->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_Enter);
            // 
            // fcgLBMPGMuxerPath
            // 
            this->fcgLBMPGMuxerPath->AutoSize = true;
            this->fcgLBMPGMuxerPath->Location = System::Drawing::Point(5, 96);
            this->fcgLBMPGMuxerPath->Name = L"fcgLBMPGMuxerPath";
            this->fcgLBMPGMuxerPath->Size = System::Drawing::Size(49, 14);
            this->fcgLBMPGMuxerPath->TabIndex = 25;
            this->fcgLBMPGMuxerPath->Text = L"～の指定";
            // 
            // fcgCXMPGCmdEx
            // 
            this->fcgCXMPGCmdEx->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXMPGCmdEx->FormattingEnabled = true;
            this->fcgCXMPGCmdEx->Location = System::Drawing::Point(214, 59);
            this->fcgCXMPGCmdEx->Name = L"fcgCXMPGCmdEx";
            this->fcgCXMPGCmdEx->Size = System::Drawing::Size(157, 22);
            this->fcgCXMPGCmdEx->TabIndex = 21;
            this->fcgCXMPGCmdEx->Tag = L"chValue";
            // 
            // fcgLBMPGMuxerCmdEx
            // 
            this->fcgLBMPGMuxerCmdEx->AutoSize = true;
            this->fcgLBMPGMuxerCmdEx->Location = System::Drawing::Point(140, 62);
            this->fcgLBMPGMuxerCmdEx->Name = L"fcgLBMPGMuxerCmdEx";
            this->fcgLBMPGMuxerCmdEx->Size = System::Drawing::Size(68, 14);
            this->fcgLBMPGMuxerCmdEx->TabIndex = 24;
            this->fcgLBMPGMuxerCmdEx->Text = L"拡張オプション";
            // 
            // fcgCBMPGMuxerExt
            // 
            this->fcgCBMPGMuxerExt->AutoSize = true;
            this->fcgCBMPGMuxerExt->Location = System::Drawing::Point(11, 61);
            this->fcgCBMPGMuxerExt->Name = L"fcgCBMPGMuxerExt";
            this->fcgCBMPGMuxerExt->Size = System::Drawing::Size(113, 18);
            this->fcgCBMPGMuxerExt->TabIndex = 20;
            this->fcgCBMPGMuxerExt->Tag = L"chValue";
            this->fcgCBMPGMuxerExt->Text = L"外部muxerを使用";
            this->fcgCBMPGMuxerExt->UseVisualStyleBackColor = true;
            // 
            // fcgtabPageMux
            // 
            this->fcgtabPageMux->Controls->Add(this->fcgCXMuxPriority);
            this->fcgtabPageMux->Controls->Add(this->fcgLBMuxPriority);
            this->fcgtabPageMux->Controls->Add(this->fcgCBMuxMinimize);
            this->fcgtabPageMux->Location = System::Drawing::Point(4, 23);
            this->fcgtabPageMux->Name = L"fcgtabPageMux";
            this->fcgtabPageMux->Size = System::Drawing::Size(376, 174);
            this->fcgtabPageMux->TabIndex = 2;
            this->fcgtabPageMux->Text = L"Mux共通設定";
            this->fcgtabPageMux->UseVisualStyleBackColor = true;
            // 
            // fcgCXMuxPriority
            // 
            this->fcgCXMuxPriority->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXMuxPriority->FormattingEnabled = true;
            this->fcgCXMuxPriority->Location = System::Drawing::Point(102, 64);
            this->fcgCXMuxPriority->Name = L"fcgCXMuxPriority";
            this->fcgCXMuxPriority->Size = System::Drawing::Size(198, 22);
            this->fcgCXMuxPriority->TabIndex = 1;
            this->fcgCXMuxPriority->Tag = L"chValue";
            // 
            // fcgLBMuxPriority
            // 
            this->fcgLBMuxPriority->AutoSize = true;
            this->fcgLBMuxPriority->Location = System::Drawing::Point(15, 67);
            this->fcgLBMuxPriority->Name = L"fcgLBMuxPriority";
            this->fcgLBMuxPriority->Size = System::Drawing::Size(62, 14);
            this->fcgLBMuxPriority->TabIndex = 1;
            this->fcgLBMuxPriority->Text = L"Mux優先度";
            // 
            // fcgCBMuxMinimize
            // 
            this->fcgCBMuxMinimize->AutoSize = true;
            this->fcgCBMuxMinimize->Location = System::Drawing::Point(18, 26);
            this->fcgCBMuxMinimize->Name = L"fcgCBMuxMinimize";
            this->fcgCBMuxMinimize->Size = System::Drawing::Size(59, 18);
            this->fcgCBMuxMinimize->TabIndex = 0;
            this->fcgCBMuxMinimize->Tag = L"chValue";
            this->fcgCBMuxMinimize->Text = L"最小化";
            this->fcgCBMuxMinimize->UseVisualStyleBackColor = true;
            // 
            // fcgtabPageBat
            // 
            this->fcgtabPageBat->Controls->Add(this->fcgLBBatAfterString);
            this->fcgtabPageBat->Controls->Add(this->fcgLBBatBeforeString);
            this->fcgtabPageBat->Controls->Add(this->fcgPNSeparator);
            this->fcgtabPageBat->Controls->Add(this->fcgBTBatBeforePath);
            this->fcgtabPageBat->Controls->Add(this->fcgTXBatBeforePath);
            this->fcgtabPageBat->Controls->Add(this->fcgLBBatBeforePath);
            this->fcgtabPageBat->Controls->Add(this->fcgCBWaitForBatBefore);
            this->fcgtabPageBat->Controls->Add(this->fcgCBRunBatBefore);
            this->fcgtabPageBat->Controls->Add(this->fcgBTBatAfterPath);
            this->fcgtabPageBat->Controls->Add(this->fcgTXBatAfterPath);
            this->fcgtabPageBat->Controls->Add(this->fcgLBBatAfterPath);
            this->fcgtabPageBat->Controls->Add(this->fcgCBWaitForBatAfter);
            this->fcgtabPageBat->Controls->Add(this->fcgCBRunBatAfter);
            this->fcgtabPageBat->Location = System::Drawing::Point(4, 23);
            this->fcgtabPageBat->Name = L"fcgtabPageBat";
            this->fcgtabPageBat->Size = System::Drawing::Size(376, 174);
            this->fcgtabPageBat->TabIndex = 3;
            this->fcgtabPageBat->Text = L"エンコ前後バッチ処理";
            this->fcgtabPageBat->UseVisualStyleBackColor = true;
            // 
            // fcgLBBatAfterString
            // 
            this->fcgLBBatAfterString->AutoSize = true;
            this->fcgLBBatAfterString->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
            this->fcgLBBatAfterString->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->fcgLBBatAfterString->Location = System::Drawing::Point(304, 112);
            this->fcgLBBatAfterString->Name = L"fcgLBBatAfterString";
            this->fcgLBBatAfterString->Size = System::Drawing::Size(27, 15);
            this->fcgLBBatAfterString->TabIndex = 20;
            this->fcgLBBatAfterString->Text = L" 後& ";
            this->fcgLBBatAfterString->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            // 
            // fcgLBBatBeforeString
            // 
            this->fcgLBBatBeforeString->AutoSize = true;
            this->fcgLBBatBeforeString->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
            this->fcgLBBatBeforeString->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->fcgLBBatBeforeString->Location = System::Drawing::Point(304, 14);
            this->fcgLBBatBeforeString->Name = L"fcgLBBatBeforeString";
            this->fcgLBBatBeforeString->Size = System::Drawing::Size(27, 15);
            this->fcgLBBatBeforeString->TabIndex = 19;
            this->fcgLBBatBeforeString->Text = L" 前& ";
            this->fcgLBBatBeforeString->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            // 
            // fcgPNSeparator
            // 
            this->fcgPNSeparator->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->fcgPNSeparator->Location = System::Drawing::Point(18, 88);
            this->fcgPNSeparator->Name = L"fcgPNSeparator";
            this->fcgPNSeparator->Size = System::Drawing::Size(342, 1);
            this->fcgPNSeparator->TabIndex = 18;
            // 
            // fcgBTBatBeforePath
            // 
            this->fcgBTBatBeforePath->Location = System::Drawing::Point(330, 55);
            this->fcgBTBatBeforePath->Name = L"fcgBTBatBeforePath";
            this->fcgBTBatBeforePath->Size = System::Drawing::Size(30, 23);
            this->fcgBTBatBeforePath->TabIndex = 17;
            this->fcgBTBatBeforePath->Tag = L"chValue";
            this->fcgBTBatBeforePath->Text = L"...";
            this->fcgBTBatBeforePath->UseVisualStyleBackColor = true;
            this->fcgBTBatBeforePath->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTBatBeforePath_Click);
            // 
            // fcgTXBatBeforePath
            // 
            this->fcgTXBatBeforePath->AllowDrop = true;
            this->fcgTXBatBeforePath->Location = System::Drawing::Point(126, 56);
            this->fcgTXBatBeforePath->Name = L"fcgTXBatBeforePath";
            this->fcgTXBatBeforePath->Size = System::Drawing::Size(202, 21);
            this->fcgTXBatBeforePath->TabIndex = 16;
            this->fcgTXBatBeforePath->Tag = L"chValue";
            this->fcgTXBatBeforePath->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_DragDrop);
            this->fcgTXBatBeforePath->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_Enter);
            // 
            // fcgLBBatBeforePath
            // 
            this->fcgLBBatBeforePath->AutoSize = true;
            this->fcgLBBatBeforePath->Location = System::Drawing::Point(40, 59);
            this->fcgLBBatBeforePath->Name = L"fcgLBBatBeforePath";
            this->fcgLBBatBeforePath->Size = System::Drawing::Size(61, 14);
            this->fcgLBBatBeforePath->TabIndex = 15;
            this->fcgLBBatBeforePath->Text = L"バッチファイル";
            // 
            // fcgCBWaitForBatBefore
            // 
            this->fcgCBWaitForBatBefore->AutoSize = true;
            this->fcgCBWaitForBatBefore->Location = System::Drawing::Point(40, 30);
            this->fcgCBWaitForBatBefore->Name = L"fcgCBWaitForBatBefore";
            this->fcgCBWaitForBatBefore->Size = System::Drawing::Size(150, 18);
            this->fcgCBWaitForBatBefore->TabIndex = 14;
            this->fcgCBWaitForBatBefore->Tag = L"chValue";
            this->fcgCBWaitForBatBefore->Text = L"バッチ処理の終了を待機する";
            this->fcgCBWaitForBatBefore->UseVisualStyleBackColor = true;
            // 
            // fcgCBRunBatBefore
            // 
            this->fcgCBRunBatBefore->AutoSize = true;
            this->fcgCBRunBatBefore->Location = System::Drawing::Point(18, 6);
            this->fcgCBRunBatBefore->Name = L"fcgCBRunBatBefore";
            this->fcgCBRunBatBefore->Size = System::Drawing::Size(179, 18);
            this->fcgCBRunBatBefore->TabIndex = 13;
            this->fcgCBRunBatBefore->Tag = L"chValue";
            this->fcgCBRunBatBefore->Text = L"エンコード開始前、バッチ処理を行う";
            this->fcgCBRunBatBefore->UseVisualStyleBackColor = true;
            // 
            // fcgBTBatAfterPath
            // 
            this->fcgBTBatAfterPath->Location = System::Drawing::Point(330, 146);
            this->fcgBTBatAfterPath->Name = L"fcgBTBatAfterPath";
            this->fcgBTBatAfterPath->Size = System::Drawing::Size(30, 23);
            this->fcgBTBatAfterPath->TabIndex = 10;
            this->fcgBTBatAfterPath->Tag = L"chValue";
            this->fcgBTBatAfterPath->Text = L"...";
            this->fcgBTBatAfterPath->UseVisualStyleBackColor = true;
            this->fcgBTBatAfterPath->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTBatAfterPath_Click);
            // 
            // fcgTXBatAfterPath
            // 
            this->fcgTXBatAfterPath->AllowDrop = true;
            this->fcgTXBatAfterPath->Location = System::Drawing::Point(126, 147);
            this->fcgTXBatAfterPath->Name = L"fcgTXBatAfterPath";
            this->fcgTXBatAfterPath->Size = System::Drawing::Size(202, 21);
            this->fcgTXBatAfterPath->TabIndex = 9;
            this->fcgTXBatAfterPath->Tag = L"chValue";
            this->fcgTXBatAfterPath->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_DragDrop);
            this->fcgTXBatAfterPath->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_Enter);
            // 
            // fcgLBBatAfterPath
            // 
            this->fcgLBBatAfterPath->AutoSize = true;
            this->fcgLBBatAfterPath->Location = System::Drawing::Point(40, 150);
            this->fcgLBBatAfterPath->Name = L"fcgLBBatAfterPath";
            this->fcgLBBatAfterPath->Size = System::Drawing::Size(61, 14);
            this->fcgLBBatAfterPath->TabIndex = 8;
            this->fcgLBBatAfterPath->Text = L"バッチファイル";
            // 
            // fcgCBWaitForBatAfter
            // 
            this->fcgCBWaitForBatAfter->AutoSize = true;
            this->fcgCBWaitForBatAfter->Location = System::Drawing::Point(40, 122);
            this->fcgCBWaitForBatAfter->Name = L"fcgCBWaitForBatAfter";
            this->fcgCBWaitForBatAfter->Size = System::Drawing::Size(150, 18);
            this->fcgCBWaitForBatAfter->TabIndex = 7;
            this->fcgCBWaitForBatAfter->Tag = L"chValue";
            this->fcgCBWaitForBatAfter->Text = L"バッチ処理の終了を待機する";
            this->fcgCBWaitForBatAfter->UseVisualStyleBackColor = true;
            // 
            // fcgCBRunBatAfter
            // 
            this->fcgCBRunBatAfter->AutoSize = true;
            this->fcgCBRunBatAfter->Location = System::Drawing::Point(18, 98);
            this->fcgCBRunBatAfter->Name = L"fcgCBRunBatAfter";
            this->fcgCBRunBatAfter->Size = System::Drawing::Size(179, 18);
            this->fcgCBRunBatAfter->TabIndex = 6;
            this->fcgCBRunBatAfter->Tag = L"chValue";
            this->fcgCBRunBatAfter->Text = L"エンコード終了後、バッチ処理を行う";
            this->fcgCBRunBatAfter->UseVisualStyleBackColor = true;
            // 
            // fcgTXCmd
            // 
            this->fcgTXCmd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->fcgTXCmd->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->fcgTXCmd->Location = System::Drawing::Point(9, 512);
            this->fcgTXCmd->Name = L"fcgTXCmd";
            this->fcgTXCmd->ReadOnly = true;
            this->fcgTXCmd->Size = System::Drawing::Size(992, 21);
            this->fcgTXCmd->TabIndex = 4;
            this->fcgTXCmd->Visible = false;
            this->fcgTXCmd->DoubleClick += gcnew System::EventHandler(this, &frmConfig::fcgTXCmd_DoubleClick);
            // 
            // fcgBTCancel
            // 
            this->fcgBTCancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->fcgBTCancel->Location = System::Drawing::Point(771, 546);
            this->fcgBTCancel->Name = L"fcgBTCancel";
            this->fcgBTCancel->Size = System::Drawing::Size(84, 28);
            this->fcgBTCancel->TabIndex = 5;
            this->fcgBTCancel->Text = L"キャンセル";
            this->fcgBTCancel->UseVisualStyleBackColor = true;
            this->fcgBTCancel->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTCancel_Click);
            // 
            // fcgBTOK
            // 
            this->fcgBTOK->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->fcgBTOK->Location = System::Drawing::Point(893, 546);
            this->fcgBTOK->Name = L"fcgBTOK";
            this->fcgBTOK->Size = System::Drawing::Size(84, 28);
            this->fcgBTOK->TabIndex = 6;
            this->fcgBTOK->Text = L"OK";
            this->fcgBTOK->UseVisualStyleBackColor = true;
            this->fcgBTOK->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTOK_Click);
            // 
            // fcgBTDefault
            // 
            this->fcgBTDefault->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->fcgBTDefault->Location = System::Drawing::Point(9, 548);
            this->fcgBTDefault->Name = L"fcgBTDefault";
            this->fcgBTDefault->Size = System::Drawing::Size(112, 28);
            this->fcgBTDefault->TabIndex = 7;
            this->fcgBTDefault->Text = L"デフォルト";
            this->fcgBTDefault->UseVisualStyleBackColor = true;
            this->fcgBTDefault->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTDefault_Click);
            // 
            // fcgLBVersionDate
            // 
            this->fcgLBVersionDate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->fcgLBVersionDate->AutoSize = true;
            this->fcgLBVersionDate->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->fcgLBVersionDate->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->fcgLBVersionDate->Location = System::Drawing::Point(445, 555);
            this->fcgLBVersionDate->Name = L"fcgLBVersionDate";
            this->fcgLBVersionDate->Size = System::Drawing::Size(47, 14);
            this->fcgLBVersionDate->TabIndex = 8;
            this->fcgLBVersionDate->Text = L"Version";
            // 
            // fcgLBVersion
            // 
            this->fcgLBVersion->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->fcgLBVersion->AutoSize = true;
            this->fcgLBVersion->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->fcgLBVersion->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->fcgLBVersion->Location = System::Drawing::Point(136, 555);
            this->fcgLBVersion->Name = L"fcgLBVersion";
            this->fcgLBVersion->Size = System::Drawing::Size(47, 14);
            this->fcgLBVersion->TabIndex = 9;
            this->fcgLBVersion->Text = L"Version";
            // 
            // fcgOpenFileDialog
            // 
            this->fcgOpenFileDialog->FileName = L"openFileDialog1";
            // 
            // fcgTTEx
            // 
            this->fcgTTEx->AutomaticDelay = 200;
            this->fcgTTEx->AutoPopDelay = 9999;
            this->fcgTTEx->InitialDelay = 200;
            this->fcgTTEx->IsBalloon = true;
            this->fcgTTEx->ReshowDelay = 50;
            this->fcgTTEx->ShowAlways = true;
            this->fcgTTEx->UseAnimation = false;
            this->fcgTTEx->UseFading = false;
            // 
            // fcgtabControlNVEnc
            // 
            this->fcgtabControlNVEnc->Controls->Add(this->tabPageVideoEnc);
            this->fcgtabControlNVEnc->Controls->Add(this->tabPageExOpt);
            this->fcgtabControlNVEnc->Controls->Add(this->tabPageNVEncFeatures);
            this->fcgtabControlNVEnc->Location = System::Drawing::Point(4, 31);
            this->fcgtabControlNVEnc->Name = L"fcgtabControlNVEnc";
            this->fcgtabControlNVEnc->SelectedIndex = 0;
            this->fcgtabControlNVEnc->Size = System::Drawing::Size(616, 509);
            this->fcgtabControlNVEnc->TabIndex = 49;
            // 
            // tabPageVideoEnc
            // 
            this->tabPageVideoEnc->Controls->Add(this->fcgLBLookaheadDisable);
            this->tabPageVideoEnc->Controls->Add(this->fcgNULookaheadDepth);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBAQStrengthAuto);
            this->tabPageVideoEnc->Controls->Add(this->fcgNUAQStrength);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBAQStrength);
            this->tabPageVideoEnc->Controls->Add(this->fcgCXAQ);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBLookaheadDepth);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBAQ);
            this->tabPageVideoEnc->Controls->Add(this->fcgNUVBVBufsize);
            this->tabPageVideoEnc->Controls->Add(this->fcgGroupBoxAspectRatio);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBVBVBufsize);
            this->tabPageVideoEnc->Controls->Add(this->fcgCBAFS);
            this->tabPageVideoEnc->Controls->Add(this->label1);
            this->tabPageVideoEnc->Controls->Add(this->fcgCXEncCodec);
            this->tabPageVideoEnc->Controls->Add(this->fcgNURefFrames);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBRefFrames);
            this->tabPageVideoEnc->Controls->Add(this->fcgNUBframes);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBBframes);
            this->tabPageVideoEnc->Controls->Add(this->fcgPNBitrate);
            this->tabPageVideoEnc->Controls->Add(this->fcgPNQP);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBGOPLengthAuto);
            this->tabPageVideoEnc->Controls->Add(this->fcgNUGopLength);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBGOPLength);
            this->tabPageVideoEnc->Controls->Add(this->fcgLBEncMode);
            this->tabPageVideoEnc->Controls->Add(this->fcgCXEncMode);
            this->tabPageVideoEnc->Controls->Add(this->fcgPBNVEncLogoEnabled);
            this->tabPageVideoEnc->Controls->Add(this->fcgPBNVEncLogoDisabled);
            this->tabPageVideoEnc->Controls->Add(this->fcgGroupBoxQulaityStg);
            this->tabPageVideoEnc->Controls->Add(this->fcgPNH264);
            this->tabPageVideoEnc->Controls->Add(this->fcgPNHEVC);
            this->tabPageVideoEnc->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->tabPageVideoEnc->Location = System::Drawing::Point(4, 24);
            this->tabPageVideoEnc->Name = L"tabPageVideoEnc";
            this->tabPageVideoEnc->Padding = System::Windows::Forms::Padding(3);
            this->tabPageVideoEnc->Size = System::Drawing::Size(608, 481);
            this->tabPageVideoEnc->TabIndex = 0;
            this->tabPageVideoEnc->Text = L"動画エンコード";
            this->tabPageVideoEnc->UseVisualStyleBackColor = true;
            // 
            // fcgLBLookaheadDisable
            // 
            this->fcgLBLookaheadDisable->AutoSize = true;
            this->fcgLBLookaheadDisable->Location = System::Drawing::Point(215, 326);
            this->fcgLBLookaheadDisable->Name = L"fcgLBLookaheadDisable";
            this->fcgLBLookaheadDisable->Size = System::Drawing::Size(66, 14);
            this->fcgLBLookaheadDisable->TabIndex = 165;
            this->fcgLBLookaheadDisable->Text = L"※\"0\"で無効";
            // 
            // fcgNULookaheadDepth
            // 
            this->fcgNULookaheadDepth->Location = System::Drawing::Point(132, 324);
            this->fcgNULookaheadDepth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 32, 0, 0, 0 });
            this->fcgNULookaheadDepth->Name = L"fcgNULookaheadDepth";
            this->fcgNULookaheadDepth->Size = System::Drawing::Size(77, 21);
            this->fcgNULookaheadDepth->TabIndex = 164;
            this->fcgNULookaheadDepth->Tag = L"chValue";
            this->fcgNULookaheadDepth->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgLBAQStrengthAuto
            // 
            this->fcgLBAQStrengthAuto->AutoSize = true;
            this->fcgLBAQStrengthAuto->Location = System::Drawing::Point(215, 381);
            this->fcgLBAQStrengthAuto->Name = L"fcgLBAQStrengthAuto";
            this->fcgLBAQStrengthAuto->Size = System::Drawing::Size(66, 14);
            this->fcgLBAQStrengthAuto->TabIndex = 163;
            this->fcgLBAQStrengthAuto->Text = L"※\"0\"で自動";
            // 
            // fcgNUAQStrength
            // 
            this->fcgNUAQStrength->Location = System::Drawing::Point(132, 379);
            this->fcgNUAQStrength->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
            this->fcgNUAQStrength->Name = L"fcgNUAQStrength";
            this->fcgNUAQStrength->Size = System::Drawing::Size(77, 21);
            this->fcgNUAQStrength->TabIndex = 161;
            this->fcgNUAQStrength->Tag = L"chValue";
            this->fcgNUAQStrength->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgLBAQStrength
            // 
            this->fcgLBAQStrength->AutoSize = true;
            this->fcgLBAQStrength->Location = System::Drawing::Point(14, 381);
            this->fcgLBAQStrength->Name = L"fcgLBAQStrength";
            this->fcgLBAQStrength->Size = System::Drawing::Size(71, 14);
            this->fcgLBAQStrength->TabIndex = 162;
            this->fcgLBAQStrength->Text = L"AQ strength";
            // 
            // fcgCXAQ
            // 
            this->fcgCXAQ->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXAQ->FormattingEnabled = true;
            this->fcgCXAQ->Location = System::Drawing::Point(132, 350);
            this->fcgCXAQ->Name = L"fcgCXAQ";
            this->fcgCXAQ->Size = System::Drawing::Size(122, 22);
            this->fcgCXAQ->TabIndex = 4;
            this->fcgCXAQ->Tag = L"chValue";
            // 
            // fcgLBLookaheadDepth
            // 
            this->fcgLBLookaheadDepth->AutoSize = true;
            this->fcgLBLookaheadDepth->Location = System::Drawing::Point(14, 326);
            this->fcgLBLookaheadDepth->Name = L"fcgLBLookaheadDepth";
            this->fcgLBLookaheadDepth->Size = System::Drawing::Size(100, 14);
            this->fcgLBLookaheadDepth->TabIndex = 160;
            this->fcgLBLookaheadDepth->Text = L"Lookahead depth";
            // 
            // fcgLBAQ
            // 
            this->fcgLBAQ->AutoSize = true;
            this->fcgLBAQ->Location = System::Drawing::Point(14, 353);
            this->fcgLBAQ->Name = L"fcgLBAQ";
            this->fcgLBAQ->Size = System::Drawing::Size(102, 14);
            this->fcgLBAQ->TabIndex = 158;
            this->fcgLBAQ->Text = L"適応的量子化 (AQ)";
            // 
            // fcgNUVBVBufsize
            // 
            this->fcgNUVBVBufsize->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
            this->fcgNUVBVBufsize->Location = System::Drawing::Point(132, 298);
            this->fcgNUVBVBufsize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128000, 0, 0, 0 });
            this->fcgNUVBVBufsize->Name = L"fcgNUVBVBufsize";
            this->fcgNUVBVBufsize->Size = System::Drawing::Size(77, 21);
            this->fcgNUVBVBufsize->TabIndex = 155;
            this->fcgNUVBVBufsize->Tag = L"chValue";
            this->fcgNUVBVBufsize->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgGroupBoxAspectRatio
            // 
            this->fcgGroupBoxAspectRatio->Controls->Add(this->fcgLBAspectRatio);
            this->fcgGroupBoxAspectRatio->Controls->Add(this->fcgNUAspectRatioY);
            this->fcgGroupBoxAspectRatio->Controls->Add(this->fcgNUAspectRatioX);
            this->fcgGroupBoxAspectRatio->Controls->Add(this->fcgCXAspectRatio);
            this->fcgGroupBoxAspectRatio->Location = System::Drawing::Point(12, 400);
            this->fcgGroupBoxAspectRatio->Name = L"fcgGroupBoxAspectRatio";
            this->fcgGroupBoxAspectRatio->Size = System::Drawing::Size(241, 76);
            this->fcgGroupBoxAspectRatio->TabIndex = 27;
            this->fcgGroupBoxAspectRatio->TabStop = false;
            this->fcgGroupBoxAspectRatio->Text = L"アスペクト比";
            // 
            // fcgLBAspectRatio
            // 
            this->fcgLBAspectRatio->AutoSize = true;
            this->fcgLBAspectRatio->Location = System::Drawing::Point(131, 47);
            this->fcgLBAspectRatio->Name = L"fcgLBAspectRatio";
            this->fcgLBAspectRatio->Size = System::Drawing::Size(12, 14);
            this->fcgLBAspectRatio->TabIndex = 3;
            this->fcgLBAspectRatio->Text = L":";
            // 
            // fcgNUAspectRatioY
            // 
            this->fcgNUAspectRatioY->Location = System::Drawing::Point(149, 45);
            this->fcgNUAspectRatioY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65535, 0, 0, 0 });
            this->fcgNUAspectRatioY->Name = L"fcgNUAspectRatioY";
            this->fcgNUAspectRatioY->Size = System::Drawing::Size(60, 21);
            this->fcgNUAspectRatioY->TabIndex = 2;
            this->fcgNUAspectRatioY->Tag = L"chValue";
            this->fcgNUAspectRatioY->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgNUAspectRatioX
            // 
            this->fcgNUAspectRatioX->Location = System::Drawing::Point(65, 45);
            this->fcgNUAspectRatioX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65535, 0, 0, 0 });
            this->fcgNUAspectRatioX->Name = L"fcgNUAspectRatioX";
            this->fcgNUAspectRatioX->Size = System::Drawing::Size(60, 21);
            this->fcgNUAspectRatioX->TabIndex = 1;
            this->fcgNUAspectRatioX->Tag = L"chValue";
            this->fcgNUAspectRatioX->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgCXAspectRatio
            // 
            this->fcgCXAspectRatio->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXAspectRatio->FormattingEnabled = true;
            this->fcgCXAspectRatio->Location = System::Drawing::Point(26, 18);
            this->fcgCXAspectRatio->Name = L"fcgCXAspectRatio";
            this->fcgCXAspectRatio->Size = System::Drawing::Size(197, 22);
            this->fcgCXAspectRatio->TabIndex = 0;
            this->fcgCXAspectRatio->Tag = L"chValue";
            // 
            // fcgLBVBVBufsize
            // 
            this->fcgLBVBVBufsize->AutoSize = true;
            this->fcgLBVBVBufsize->Location = System::Drawing::Point(14, 299);
            this->fcgLBVBVBufsize->Name = L"fcgLBVBVBufsize";
            this->fcgLBVBVBufsize->Size = System::Drawing::Size(84, 14);
            this->fcgLBVBVBufsize->TabIndex = 156;
            this->fcgLBVBVBufsize->Text = L"VBVバッファサイズ";
            // 
            // fcgCBAFS
            // 
            this->fcgCBAFS->AutoSize = true;
            this->fcgCBAFS->Location = System::Drawing::Point(362, 8);
            this->fcgCBAFS->Name = L"fcgCBAFS";
            this->fcgCBAFS->Size = System::Drawing::Size(183, 18);
            this->fcgCBAFS->TabIndex = 154;
            this->fcgCBAFS->Tag = L"chValue";
            this->fcgCBAFS->Text = L"自動フィールドシフト(afs)を使用する";
            this->fcgCBAFS->UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(13, 88);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(51, 14);
            this->label1->TabIndex = 151;
            this->label1->Text = L"出力形式";
            // 
            // fcgCXEncCodec
            // 
            this->fcgCXEncCodec->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXEncCodec->FormattingEnabled = true;
            this->fcgCXEncCodec->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"高品質", L"標準", L"高速" });
            this->fcgCXEncCodec->Location = System::Drawing::Point(81, 85);
            this->fcgCXEncCodec->Name = L"fcgCXEncCodec";
            this->fcgCXEncCodec->Size = System::Drawing::Size(185, 22);
            this->fcgCXEncCodec->TabIndex = 150;
            this->fcgCXEncCodec->Tag = L"chValue";
            this->fcgCXEncCodec->SelectedIndexChanged += gcnew System::EventHandler(this, &frmConfig::fcgChangeEnabled);
            // 
            // fcgNURefFrames
            // 
            this->fcgNURefFrames->Location = System::Drawing::Point(132, 273);
            this->fcgNURefFrames->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 16, 0, 0, 0 });
            this->fcgNURefFrames->Name = L"fcgNURefFrames";
            this->fcgNURefFrames->Size = System::Drawing::Size(77, 21);
            this->fcgNURefFrames->TabIndex = 139;
            this->fcgNURefFrames->Tag = L"chValue";
            this->fcgNURefFrames->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgLBRefFrames
            // 
            this->fcgLBRefFrames->AutoSize = true;
            this->fcgLBRefFrames->Location = System::Drawing::Point(13, 275);
            this->fcgLBRefFrames->Name = L"fcgLBRefFrames";
            this->fcgLBRefFrames->Size = System::Drawing::Size(51, 14);
            this->fcgLBRefFrames->TabIndex = 140;
            this->fcgLBRefFrames->Text = L"参照距離";
            // 
            // fcgNUBframes
            // 
            this->fcgNUBframes->Location = System::Drawing::Point(132, 248);
            this->fcgNUBframes->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 16, 0, 0, 0 });
            this->fcgNUBframes->Name = L"fcgNUBframes";
            this->fcgNUBframes->Size = System::Drawing::Size(77, 21);
            this->fcgNUBframes->TabIndex = 132;
            this->fcgNUBframes->Tag = L"chValue";
            this->fcgNUBframes->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgLBBframes
            // 
            this->fcgLBBframes->AutoSize = true;
            this->fcgLBBframes->Location = System::Drawing::Point(14, 251);
            this->fcgLBBframes->Name = L"fcgLBBframes";
            this->fcgLBBframes->Size = System::Drawing::Size(58, 14);
            this->fcgLBBframes->TabIndex = 133;
            this->fcgLBBframes->Text = L"Bフレーム数";
            // 
            // fcgPNBitrate
            // 
            this->fcgPNBitrate->Controls->Add(this->fcgLBBitrate);
            this->fcgPNBitrate->Controls->Add(this->fcgNUBitrate);
            this->fcgPNBitrate->Controls->Add(this->fcgLBBitrate2);
            this->fcgPNBitrate->Controls->Add(this->fcgNUMaxkbps);
            this->fcgPNBitrate->Controls->Add(this->fcgLBMaxkbps);
            this->fcgPNBitrate->Controls->Add(this->fcgLBMaxBitrate2);
            this->fcgPNBitrate->Location = System::Drawing::Point(8, 140);
            this->fcgPNBitrate->Name = L"fcgPNBitrate";
            this->fcgPNBitrate->Size = System::Drawing::Size(289, 54);
            this->fcgPNBitrate->TabIndex = 114;
            // 
            // fcgLBBitrate
            // 
            this->fcgLBBitrate->AutoSize = true;
            this->fcgLBBitrate->Location = System::Drawing::Point(5, 4);
            this->fcgLBBitrate->Name = L"fcgLBBitrate";
            this->fcgLBBitrate->Size = System::Drawing::Size(54, 14);
            this->fcgLBBitrate->TabIndex = 66;
            this->fcgLBBitrate->Text = L"ビットレート";
            // 
            // fcgNUBitrate
            // 
            this->fcgNUBitrate->Location = System::Drawing::Point(124, 2);
            this->fcgNUBitrate->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65535, 0, 0, 0 });
            this->fcgNUBitrate->Name = L"fcgNUBitrate";
            this->fcgNUBitrate->Size = System::Drawing::Size(77, 21);
            this->fcgNUBitrate->TabIndex = 5;
            this->fcgNUBitrate->Tag = L"chValue";
            this->fcgNUBitrate->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgLBBitrate2
            // 
            this->fcgLBBitrate2->AutoSize = true;
            this->fcgLBBitrate2->Location = System::Drawing::Point(207, 4);
            this->fcgLBBitrate2->Name = L"fcgLBBitrate2";
            this->fcgLBBitrate2->Size = System::Drawing::Size(32, 14);
            this->fcgLBBitrate2->TabIndex = 69;
            this->fcgLBBitrate2->Text = L"kbps";
            // 
            // fcgNUMaxkbps
            // 
            this->fcgNUMaxkbps->Location = System::Drawing::Point(124, 29);
            this->fcgNUMaxkbps->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65535, 0, 0, 0 });
            this->fcgNUMaxkbps->Name = L"fcgNUMaxkbps";
            this->fcgNUMaxkbps->Size = System::Drawing::Size(77, 21);
            this->fcgNUMaxkbps->TabIndex = 6;
            this->fcgNUMaxkbps->Tag = L"chValue";
            this->fcgNUMaxkbps->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgLBMaxkbps
            // 
            this->fcgLBMaxkbps->AutoSize = true;
            this->fcgLBMaxkbps->Location = System::Drawing::Point(5, 33);
            this->fcgLBMaxkbps->Name = L"fcgLBMaxkbps";
            this->fcgLBMaxkbps->Size = System::Drawing::Size(76, 14);
            this->fcgLBMaxkbps->TabIndex = 78;
            this->fcgLBMaxkbps->Text = L"最大ビットレート";
            // 
            // fcgLBMaxBitrate2
            // 
            this->fcgLBMaxBitrate2->AutoSize = true;
            this->fcgLBMaxBitrate2->Location = System::Drawing::Point(207, 31);
            this->fcgLBMaxBitrate2->Name = L"fcgLBMaxBitrate2";
            this->fcgLBMaxBitrate2->Size = System::Drawing::Size(32, 14);
            this->fcgLBMaxBitrate2->TabIndex = 80;
            this->fcgLBMaxBitrate2->Text = L"kbps";
            // 
            // fcgPNQP
            // 
            this->fcgPNQP->Controls->Add(this->fcgLBQPI);
            this->fcgPNQP->Controls->Add(this->fcgNUQPI);
            this->fcgPNQP->Controls->Add(this->fcgNUQPP);
            this->fcgPNQP->Controls->Add(this->fcgNUQPB);
            this->fcgPNQP->Controls->Add(this->fcgLBQPP);
            this->fcgPNQP->Controls->Add(this->fcgLBQPB);
            this->fcgPNQP->Location = System::Drawing::Point(8, 140);
            this->fcgPNQP->Name = L"fcgPNQP";
            this->fcgPNQP->Size = System::Drawing::Size(289, 79);
            this->fcgPNQP->TabIndex = 113;
            // 
            // fcgLBQPI
            // 
            this->fcgLBQPI->AutoSize = true;
            this->fcgLBQPI->Location = System::Drawing::Point(10, 4);
            this->fcgLBQPI->Name = L"fcgLBQPI";
            this->fcgLBQPI->Size = System::Drawing::Size(66, 14);
            this->fcgLBQPI->TabIndex = 75;
            this->fcgLBQPI->Text = L"QP I frame";
            // 
            // fcgNUQPI
            // 
            this->fcgNUQPI->Location = System::Drawing::Point(124, 2);
            this->fcgNUQPI->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 51, 0, 0, 0 });
            this->fcgNUQPI->Name = L"fcgNUQPI";
            this->fcgNUQPI->Size = System::Drawing::Size(77, 21);
            this->fcgNUQPI->TabIndex = 7;
            this->fcgNUQPI->Tag = L"chValue";
            this->fcgNUQPI->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgNUQPP
            // 
            this->fcgNUQPP->Location = System::Drawing::Point(124, 29);
            this->fcgNUQPP->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 51, 0, 0, 0 });
            this->fcgNUQPP->Name = L"fcgNUQPP";
            this->fcgNUQPP->Size = System::Drawing::Size(77, 21);
            this->fcgNUQPP->TabIndex = 8;
            this->fcgNUQPP->Tag = L"chValue";
            this->fcgNUQPP->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgNUQPB
            // 
            this->fcgNUQPB->Location = System::Drawing::Point(124, 55);
            this->fcgNUQPB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 51, 0, 0, 0 });
            this->fcgNUQPB->Name = L"fcgNUQPB";
            this->fcgNUQPB->Size = System::Drawing::Size(77, 21);
            this->fcgNUQPB->TabIndex = 9;
            this->fcgNUQPB->Tag = L"chValue";
            this->fcgNUQPB->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgLBQPP
            // 
            this->fcgLBQPP->AutoSize = true;
            this->fcgLBQPP->Location = System::Drawing::Point(10, 31);
            this->fcgLBQPP->Name = L"fcgLBQPP";
            this->fcgLBQPP->Size = System::Drawing::Size(69, 14);
            this->fcgLBQPP->TabIndex = 76;
            this->fcgLBQPP->Text = L"QP P frame";
            // 
            // fcgLBQPB
            // 
            this->fcgLBQPB->AutoSize = true;
            this->fcgLBQPB->Location = System::Drawing::Point(6, 57);
            this->fcgLBQPB->Name = L"fcgLBQPB";
            this->fcgLBQPB->Size = System::Drawing::Size(69, 14);
            this->fcgLBQPB->TabIndex = 77;
            this->fcgLBQPB->Text = L"QP B frame";
            // 
            // fcgLBGOPLengthAuto
            // 
            this->fcgLBGOPLengthAuto->AutoSize = true;
            this->fcgLBGOPLengthAuto->Location = System::Drawing::Point(214, 226);
            this->fcgLBGOPLengthAuto->Name = L"fcgLBGOPLengthAuto";
            this->fcgLBGOPLengthAuto->Size = System::Drawing::Size(66, 14);
            this->fcgLBGOPLengthAuto->TabIndex = 101;
            this->fcgLBGOPLengthAuto->Text = L"※\"0\"で自動";
            // 
            // fcgNUGopLength
            // 
            this->fcgNUGopLength->Location = System::Drawing::Point(132, 223);
            this->fcgNUGopLength->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 120000, 0, 0, 0 });
            this->fcgNUGopLength->Name = L"fcgNUGopLength";
            this->fcgNUGopLength->Size = System::Drawing::Size(77, 21);
            this->fcgNUGopLength->TabIndex = 10;
            this->fcgNUGopLength->Tag = L"chValue";
            this->fcgNUGopLength->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgLBGOPLength
            // 
            this->fcgLBGOPLength->AutoSize = true;
            this->fcgLBGOPLength->Location = System::Drawing::Point(14, 226);
            this->fcgLBGOPLength->Name = L"fcgLBGOPLength";
            this->fcgLBGOPLength->Size = System::Drawing::Size(41, 14);
            this->fcgLBGOPLength->TabIndex = 85;
            this->fcgLBGOPLength->Text = L"GOP長";
            // 
            // fcgLBEncMode
            // 
            this->fcgLBEncMode->AutoSize = true;
            this->fcgLBEncMode->Location = System::Drawing::Point(13, 116);
            this->fcgLBEncMode->Name = L"fcgLBEncMode";
            this->fcgLBEncMode->Size = System::Drawing::Size(32, 14);
            this->fcgLBEncMode->TabIndex = 79;
            this->fcgLBEncMode->Text = L"モード";
            // 
            // fcgCXEncMode
            // 
            this->fcgCXEncMode->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXEncMode->FormattingEnabled = true;
            this->fcgCXEncMode->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"高品質", L"標準", L"高速" });
            this->fcgCXEncMode->Location = System::Drawing::Point(81, 113);
            this->fcgCXEncMode->Name = L"fcgCXEncMode";
            this->fcgCXEncMode->Size = System::Drawing::Size(185, 22);
            this->fcgCXEncMode->TabIndex = 4;
            this->fcgCXEncMode->Tag = L"chValue";
            this->fcgCXEncMode->SelectedIndexChanged += gcnew System::EventHandler(this, &frmConfig::fcgChangeEnabled);
            // 
            // fcgPBNVEncLogoEnabled
            // 
            this->fcgPBNVEncLogoEnabled->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fcgPBNVEncLogoEnabled.Image")));
            this->fcgPBNVEncLogoEnabled->Location = System::Drawing::Point(6, 3);
            this->fcgPBNVEncLogoEnabled->Name = L"fcgPBNVEncLogoEnabled";
            this->fcgPBNVEncLogoEnabled->Size = System::Drawing::Size(219, 75);
            this->fcgPBNVEncLogoEnabled->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->fcgPBNVEncLogoEnabled->TabIndex = 148;
            this->fcgPBNVEncLogoEnabled->TabStop = false;
            // 
            // fcgPBNVEncLogoDisabled
            // 
            this->fcgPBNVEncLogoDisabled->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fcgPBNVEncLogoDisabled.Image")));
            this->fcgPBNVEncLogoDisabled->Location = System::Drawing::Point(6, 3);
            this->fcgPBNVEncLogoDisabled->Name = L"fcgPBNVEncLogoDisabled";
            this->fcgPBNVEncLogoDisabled->Size = System::Drawing::Size(219, 75);
            this->fcgPBNVEncLogoDisabled->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->fcgPBNVEncLogoDisabled->TabIndex = 149;
            this->fcgPBNVEncLogoDisabled->TabStop = false;
            // 
            // fcgGroupBoxQulaityStg
            // 
            this->fcgGroupBoxQulaityStg->Controls->Add(this->fcgBTQualityStg);
            this->fcgGroupBoxQulaityStg->Controls->Add(this->fcgCXQualityPreset);
            this->fcgGroupBoxQulaityStg->Location = System::Drawing::Point(66, 398);
            this->fcgGroupBoxQulaityStg->Name = L"fcgGroupBoxQulaityStg";
            this->fcgGroupBoxQulaityStg->Size = System::Drawing::Size(219, 77);
            this->fcgGroupBoxQulaityStg->TabIndex = 28;
            this->fcgGroupBoxQulaityStg->TabStop = false;
            this->fcgGroupBoxQulaityStg->Text = L"品質設定";
            this->fcgGroupBoxQulaityStg->Visible = false;
            // 
            // fcgBTQualityStg
            // 
            this->fcgBTQualityStg->Location = System::Drawing::Point(106, 45);
            this->fcgBTQualityStg->Name = L"fcgBTQualityStg";
            this->fcgBTQualityStg->Size = System::Drawing::Size(97, 28);
            this->fcgBTQualityStg->TabIndex = 7;
            this->fcgBTQualityStg->Text = L"ロードして反映";
            this->fcgBTQualityStg->UseVisualStyleBackColor = true;
            this->fcgBTQualityStg->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTQualityStg_Click);
            // 
            // fcgCXQualityPreset
            // 
            this->fcgCXQualityPreset->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXQualityPreset->FormattingEnabled = true;
            this->fcgCXQualityPreset->Location = System::Drawing::Point(26, 17);
            this->fcgCXQualityPreset->Name = L"fcgCXQualityPreset";
            this->fcgCXQualityPreset->Size = System::Drawing::Size(174, 22);
            this->fcgCXQualityPreset->TabIndex = 0;
            this->fcgCXQualityPreset->Tag = L"chValue";
            // 
            // fcgPNH264
            // 
            this->fcgPNH264->Controls->Add(this->fcgLBBluray);
            this->fcgPNH264->Controls->Add(this->fcgCBBluray);
            this->fcgPNH264->Controls->Add(this->fcgLBDeblock);
            this->fcgPNH264->Controls->Add(this->fcgCXAdaptiveTransform);
            this->fcgPNH264->Controls->Add(this->fcgLBAdaptiveTransform);
            this->fcgPNH264->Controls->Add(this->fcgLBInterlaced);
            this->fcgPNH264->Controls->Add(this->fcgLBCodecProfile);
            this->fcgPNH264->Controls->Add(this->fcgCXBDirectMode);
            this->fcgPNH264->Controls->Add(this->fcgLBCodecLevel);
            this->fcgPNH264->Controls->Add(this->fcgLBBDirectMode);
            this->fcgPNH264->Controls->Add(this->fcgCXCodecProfile);
            this->fcgPNH264->Controls->Add(this->fcgCXCodecLevel);
            this->fcgPNH264->Controls->Add(this->fcgLBMVPRecision);
            this->fcgPNH264->Controls->Add(this->fcgCXMVPrecision);
            this->fcgPNH264->Controls->Add(this->fcgLBFullrangeH264);
            this->fcgPNH264->Controls->Add(this->fcgCXInterlaced);
            this->fcgPNH264->Controls->Add(this->fcgCBFullrangeH264);
            this->fcgPNH264->Controls->Add(this->fcgLBSlices);
            this->fcgPNH264->Controls->Add(this->fcgCXVideoFormatH264);
            this->fcgPNH264->Controls->Add(this->fcgCBDeblock);
            this->fcgPNH264->Controls->Add(this->fcgCBCABAC);
            this->fcgPNH264->Controls->Add(this->fcgLBVideoFormatH264);
            this->fcgPNH264->Controls->Add(this->fcgNUSlices);
            this->fcgPNH264->Controls->Add(this->fcggroupBoxColorH264);
            this->fcgPNH264->Controls->Add(this->fcgLBCABAC);
            this->fcgPNH264->Location = System::Drawing::Point(341, 31);
            this->fcgPNH264->Name = L"fcgPNH264";
            this->fcgPNH264->Size = System::Drawing::Size(264, 448);
            this->fcgPNH264->TabIndex = 152;
            // 
            // fcgLBBluray
            // 
            this->fcgLBBluray->AutoSize = true;
            this->fcgLBBluray->Location = System::Drawing::Point(15, 164);
            this->fcgLBBluray->Name = L"fcgLBBluray";
            this->fcgLBBluray->Size = System::Drawing::Size(74, 14);
            this->fcgLBBluray->TabIndex = 156;
            this->fcgLBBluray->Text = L"Bluray用出力";
            // 
            // fcgCBBluray
            // 
            this->fcgCBBluray->AutoSize = true;
            this->fcgCBBluray->Location = System::Drawing::Point(127, 165);
            this->fcgCBBluray->Name = L"fcgCBBluray";
            this->fcgCBBluray->Size = System::Drawing::Size(15, 14);
            this->fcgCBBluray->TabIndex = 155;
            this->fcgCBBluray->Tag = L"chValue";
            this->fcgCBBluray->UseVisualStyleBackColor = true;
            // 
            // fcgLBDeblock
            // 
            this->fcgLBDeblock->AutoSize = true;
            this->fcgLBDeblock->Location = System::Drawing::Point(15, 140);
            this->fcgLBDeblock->Name = L"fcgLBDeblock";
            this->fcgLBDeblock->Size = System::Drawing::Size(76, 14);
            this->fcgLBDeblock->TabIndex = 154;
            this->fcgLBDeblock->Text = L"デブロックフィルタ";
            // 
            // fcgCXAdaptiveTransform
            // 
            this->fcgCXAdaptiveTransform->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXAdaptiveTransform->FormattingEnabled = true;
            this->fcgCXAdaptiveTransform->Location = System::Drawing::Point(125, 191);
            this->fcgCXAdaptiveTransform->Name = L"fcgCXAdaptiveTransform";
            this->fcgCXAdaptiveTransform->Size = System::Drawing::Size(122, 22);
            this->fcgCXAdaptiveTransform->TabIndex = 149;
            this->fcgCXAdaptiveTransform->Tag = L"chValue";
            // 
            // fcgLBAdaptiveTransform
            // 
            this->fcgLBAdaptiveTransform->AutoSize = true;
            this->fcgLBAdaptiveTransform->Location = System::Drawing::Point(15, 194);
            this->fcgLBAdaptiveTransform->Name = L"fcgLBAdaptiveTransform";
            this->fcgLBAdaptiveTransform->Size = System::Drawing::Size(102, 14);
            this->fcgLBAdaptiveTransform->TabIndex = 148;
            this->fcgLBAdaptiveTransform->Text = L"Adapt. Transform";
            // 
            // fcgLBInterlaced
            // 
            this->fcgLBInterlaced->AutoSize = true;
            this->fcgLBInterlaced->Location = System::Drawing::Point(15, 8);
            this->fcgLBInterlaced->Name = L"fcgLBInterlaced";
            this->fcgLBInterlaced->Size = System::Drawing::Size(64, 14);
            this->fcgLBInterlaced->TabIndex = 86;
            this->fcgLBInterlaced->Text = L"フレームタイプ";
            // 
            // fcgLBCodecProfile
            // 
            this->fcgLBCodecProfile->AutoSize = true;
            this->fcgLBCodecProfile->Location = System::Drawing::Point(15, 36);
            this->fcgLBCodecProfile->Name = L"fcgLBCodecProfile";
            this->fcgLBCodecProfile->Size = System::Drawing::Size(53, 14);
            this->fcgLBCodecProfile->TabIndex = 83;
            this->fcgLBCodecProfile->Text = L"プロファイル";
            // 
            // fcgCXBDirectMode
            // 
            this->fcgCXBDirectMode->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXBDirectMode->FormattingEnabled = true;
            this->fcgCXBDirectMode->Location = System::Drawing::Point(123, 252);
            this->fcgCXBDirectMode->Name = L"fcgCXBDirectMode";
            this->fcgCXBDirectMode->Size = System::Drawing::Size(124, 22);
            this->fcgCXBDirectMode->TabIndex = 138;
            this->fcgCXBDirectMode->Tag = L"chValue";
            // 
            // fcgLBCodecLevel
            // 
            this->fcgLBCodecLevel->AutoSize = true;
            this->fcgLBCodecLevel->Location = System::Drawing::Point(15, 64);
            this->fcgLBCodecLevel->Name = L"fcgLBCodecLevel";
            this->fcgLBCodecLevel->Size = System::Drawing::Size(33, 14);
            this->fcgLBCodecLevel->TabIndex = 84;
            this->fcgLBCodecLevel->Text = L"レベル";
            // 
            // fcgLBBDirectMode
            // 
            this->fcgLBBDirectMode->AutoSize = true;
            this->fcgLBBDirectMode->Location = System::Drawing::Point(17, 255);
            this->fcgLBBDirectMode->Name = L"fcgLBBDirectMode";
            this->fcgLBBDirectMode->Size = System::Drawing::Size(70, 14);
            this->fcgLBBDirectMode->TabIndex = 137;
            this->fcgLBBDirectMode->Text = L"動き予測方式";
            // 
            // fcgCXCodecProfile
            // 
            this->fcgCXCodecProfile->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXCodecProfile->FormattingEnabled = true;
            this->fcgCXCodecProfile->Location = System::Drawing::Point(126, 33);
            this->fcgCXCodecProfile->Name = L"fcgCXCodecProfile";
            this->fcgCXCodecProfile->Size = System::Drawing::Size(121, 22);
            this->fcgCXCodecProfile->TabIndex = 21;
            this->fcgCXCodecProfile->Tag = L"chValue";
            // 
            // fcgCXCodecLevel
            // 
            this->fcgCXCodecLevel->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXCodecLevel->FormattingEnabled = true;
            this->fcgCXCodecLevel->Location = System::Drawing::Point(126, 61);
            this->fcgCXCodecLevel->Name = L"fcgCXCodecLevel";
            this->fcgCXCodecLevel->Size = System::Drawing::Size(121, 22);
            this->fcgCXCodecLevel->TabIndex = 22;
            this->fcgCXCodecLevel->Tag = L"chValue";
            // 
            // fcgLBMVPRecision
            // 
            this->fcgLBMVPRecision->AutoSize = true;
            this->fcgLBMVPRecision->Location = System::Drawing::Point(15, 224);
            this->fcgLBMVPRecision->Name = L"fcgLBMVPRecision";
            this->fcgLBMVPRecision->Size = System::Drawing::Size(70, 14);
            this->fcgLBMVPRecision->TabIndex = 135;
            this->fcgLBMVPRecision->Text = L"動き探索精度";
            // 
            // fcgCXMVPrecision
            // 
            this->fcgCXMVPrecision->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXMVPrecision->FormattingEnabled = true;
            this->fcgCXMVPrecision->Location = System::Drawing::Point(125, 220);
            this->fcgCXMVPrecision->Name = L"fcgCXMVPrecision";
            this->fcgCXMVPrecision->Size = System::Drawing::Size(122, 22);
            this->fcgCXMVPrecision->TabIndex = 134;
            this->fcgCXMVPrecision->Tag = L"chValue";
            // 
            // fcgLBFullrangeH264
            // 
            this->fcgLBFullrangeH264->AutoSize = true;
            this->fcgLBFullrangeH264->Location = System::Drawing::Point(18, 317);
            this->fcgLBFullrangeH264->Name = L"fcgLBFullrangeH264";
            this->fcgLBFullrangeH264->Size = System::Drawing::Size(55, 14);
            this->fcgLBFullrangeH264->TabIndex = 145;
            this->fcgLBFullrangeH264->Text = L"fullrange";
            // 
            // fcgCXInterlaced
            // 
            this->fcgCXInterlaced->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXInterlaced->FormattingEnabled = true;
            this->fcgCXInterlaced->Location = System::Drawing::Point(126, 5);
            this->fcgCXInterlaced->Name = L"fcgCXInterlaced";
            this->fcgCXInterlaced->Size = System::Drawing::Size(121, 22);
            this->fcgCXInterlaced->TabIndex = 20;
            this->fcgCXInterlaced->Tag = L"chValue";
            // 
            // fcgCBFullrangeH264
            // 
            this->fcgCBFullrangeH264->AutoSize = true;
            this->fcgCBFullrangeH264->Location = System::Drawing::Point(125, 320);
            this->fcgCBFullrangeH264->Name = L"fcgCBFullrangeH264";
            this->fcgCBFullrangeH264->Size = System::Drawing::Size(15, 14);
            this->fcgCBFullrangeH264->TabIndex = 142;
            this->fcgCBFullrangeH264->Tag = L"chValue";
            this->fcgCBFullrangeH264->UseVisualStyleBackColor = true;
            // 
            // fcgLBSlices
            // 
            this->fcgLBSlices->AutoSize = true;
            this->fcgLBSlices->Location = System::Drawing::Point(15, 91);
            this->fcgLBSlices->Name = L"fcgLBSlices";
            this->fcgLBSlices->Size = System::Drawing::Size(50, 14);
            this->fcgLBSlices->TabIndex = 103;
            this->fcgLBSlices->Text = L"スライス数";
            // 
            // fcgCXVideoFormatH264
            // 
            this->fcgCXVideoFormatH264->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXVideoFormatH264->FormattingEnabled = true;
            this->fcgCXVideoFormatH264->Location = System::Drawing::Point(125, 290);
            this->fcgCXVideoFormatH264->Name = L"fcgCXVideoFormatH264";
            this->fcgCXVideoFormatH264->Size = System::Drawing::Size(121, 22);
            this->fcgCXVideoFormatH264->TabIndex = 141;
            this->fcgCXVideoFormatH264->Tag = L"chValue";
            // 
            // fcgCBDeblock
            // 
            this->fcgCBDeblock->AutoSize = true;
            this->fcgCBDeblock->Location = System::Drawing::Point(127, 141);
            this->fcgCBDeblock->Name = L"fcgCBDeblock";
            this->fcgCBDeblock->Size = System::Drawing::Size(15, 14);
            this->fcgCBDeblock->TabIndex = 25;
            this->fcgCBDeblock->Tag = L"chValue";
            this->fcgCBDeblock->UseVisualStyleBackColor = true;
            // 
            // fcgCBCABAC
            // 
            this->fcgCBCABAC->AutoSize = true;
            this->fcgCBCABAC->Location = System::Drawing::Point(127, 118);
            this->fcgCBCABAC->Name = L"fcgCBCABAC";
            this->fcgCBCABAC->Size = System::Drawing::Size(15, 14);
            this->fcgCBCABAC->TabIndex = 24;
            this->fcgCBCABAC->Tag = L"chValue";
            this->fcgCBCABAC->UseVisualStyleBackColor = true;
            // 
            // fcgLBVideoFormatH264
            // 
            this->fcgLBVideoFormatH264->AutoSize = true;
            this->fcgLBVideoFormatH264->Location = System::Drawing::Point(18, 291);
            this->fcgLBVideoFormatH264->Name = L"fcgLBVideoFormatH264";
            this->fcgLBVideoFormatH264->Size = System::Drawing::Size(73, 14);
            this->fcgLBVideoFormatH264->TabIndex = 144;
            this->fcgLBVideoFormatH264->Text = L"videoformat";
            // 
            // fcgNUSlices
            // 
            this->fcgNUSlices->Location = System::Drawing::Point(127, 89);
            this->fcgNUSlices->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->fcgNUSlices->Name = L"fcgNUSlices";
            this->fcgNUSlices->Size = System::Drawing::Size(70, 21);
            this->fcgNUSlices->TabIndex = 23;
            this->fcgNUSlices->Tag = L"chValue";
            this->fcgNUSlices->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUSlices->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            // 
            // fcggroupBoxColorH264
            // 
            this->fcggroupBoxColorH264->Controls->Add(this->fcgCXTransferH264);
            this->fcggroupBoxColorH264->Controls->Add(this->fcgCXColorPrimH264);
            this->fcggroupBoxColorH264->Controls->Add(this->fcgCXColorMatrixH264);
            this->fcggroupBoxColorH264->Controls->Add(this->fcgLBTransferH264);
            this->fcggroupBoxColorH264->Controls->Add(this->fcgLBColorPrimH264);
            this->fcggroupBoxColorH264->Controls->Add(this->fcgLBColorMatrixH264);
            this->fcggroupBoxColorH264->Location = System::Drawing::Point(14, 337);
            this->fcggroupBoxColorH264->Name = L"fcggroupBoxColorH264";
            this->fcggroupBoxColorH264->Size = System::Drawing::Size(241, 103);
            this->fcggroupBoxColorH264->TabIndex = 143;
            this->fcggroupBoxColorH264->TabStop = false;
            this->fcggroupBoxColorH264->Text = L"色設定";
            // 
            // fcgCXTransferH264
            // 
            this->fcgCXTransferH264->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXTransferH264->FormattingEnabled = true;
            this->fcgCXTransferH264->Location = System::Drawing::Point(111, 72);
            this->fcgCXTransferH264->Name = L"fcgCXTransferH264";
            this->fcgCXTransferH264->Size = System::Drawing::Size(121, 22);
            this->fcgCXTransferH264->TabIndex = 2;
            this->fcgCXTransferH264->Tag = L"chValue";
            // 
            // fcgCXColorPrimH264
            // 
            this->fcgCXColorPrimH264->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXColorPrimH264->FormattingEnabled = true;
            this->fcgCXColorPrimH264->Location = System::Drawing::Point(111, 44);
            this->fcgCXColorPrimH264->Name = L"fcgCXColorPrimH264";
            this->fcgCXColorPrimH264->Size = System::Drawing::Size(121, 22);
            this->fcgCXColorPrimH264->TabIndex = 1;
            this->fcgCXColorPrimH264->Tag = L"chValue";
            // 
            // fcgCXColorMatrixH264
            // 
            this->fcgCXColorMatrixH264->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXColorMatrixH264->FormattingEnabled = true;
            this->fcgCXColorMatrixH264->Location = System::Drawing::Point(111, 16);
            this->fcgCXColorMatrixH264->Name = L"fcgCXColorMatrixH264";
            this->fcgCXColorMatrixH264->Size = System::Drawing::Size(121, 22);
            this->fcgCXColorMatrixH264->TabIndex = 0;
            this->fcgCXColorMatrixH264->Tag = L"chValue";
            // 
            // fcgLBTransferH264
            // 
            this->fcgLBTransferH264->AutoSize = true;
            this->fcgLBTransferH264->Location = System::Drawing::Point(18, 75);
            this->fcgLBTransferH264->Name = L"fcgLBTransferH264";
            this->fcgLBTransferH264->Size = System::Drawing::Size(49, 14);
            this->fcgLBTransferH264->TabIndex = 2;
            this->fcgLBTransferH264->Text = L"transfer";
            // 
            // fcgLBColorPrimH264
            // 
            this->fcgLBColorPrimH264->AutoSize = true;
            this->fcgLBColorPrimH264->Location = System::Drawing::Point(18, 47);
            this->fcgLBColorPrimH264->Name = L"fcgLBColorPrimH264";
            this->fcgLBColorPrimH264->Size = System::Drawing::Size(61, 14);
            this->fcgLBColorPrimH264->TabIndex = 1;
            this->fcgLBColorPrimH264->Text = L"colorprim";
            // 
            // fcgLBColorMatrixH264
            // 
            this->fcgLBColorMatrixH264->AutoSize = true;
            this->fcgLBColorMatrixH264->Location = System::Drawing::Point(18, 19);
            this->fcgLBColorMatrixH264->Name = L"fcgLBColorMatrixH264";
            this->fcgLBColorMatrixH264->Size = System::Drawing::Size(70, 14);
            this->fcgLBColorMatrixH264->TabIndex = 0;
            this->fcgLBColorMatrixH264->Text = L"colormatrix";
            // 
            // fcgLBCABAC
            // 
            this->fcgLBCABAC->AutoSize = true;
            this->fcgLBCABAC->Location = System::Drawing::Point(15, 117);
            this->fcgLBCABAC->Name = L"fcgLBCABAC";
            this->fcgLBCABAC->Size = System::Drawing::Size(42, 14);
            this->fcgLBCABAC->TabIndex = 131;
            this->fcgLBCABAC->Text = L"CABAC";
            // 
            // fcgPNHEVC
            // 
            this->fcgPNHEVC->Controls->Add(this->fcgLBHEVCOutBitDepth);
            this->fcgPNHEVC->Controls->Add(this->fcgCXHEVCOutBitDepth);
            this->fcgPNHEVC->Controls->Add(this->fcgLBFullrangeHEVC);
            this->fcgPNHEVC->Controls->Add(this->fcgCBFullrangeHEVC);
            this->fcgPNHEVC->Controls->Add(this->fcgCXVideoFormatHEVC);
            this->fcgPNHEVC->Controls->Add(this->fcgLBVideoFormatHEVC);
            this->fcgPNHEVC->Controls->Add(this->fcggroupBoxColorHEVC);
            this->fcgPNHEVC->Controls->Add(this->fcgLBHEVCMinCUSize);
            this->fcgPNHEVC->Controls->Add(this->fcgCXHEVCMinCUSize);
            this->fcgPNHEVC->Controls->Add(this->fcgLBHEVCMaxCUSize);
            this->fcgPNHEVC->Controls->Add(this->fcgCXHEVCMaxCUSize);
            this->fcgPNHEVC->Controls->Add(this->fcgLBHEVCProfile);
            this->fcgPNHEVC->Controls->Add(this->fxgLBHEVCTier);
            this->fcgPNHEVC->Controls->Add(this->fcgCXHEVCTier);
            this->fcgPNHEVC->Controls->Add(this->fxgCXHEVCLevel);
            this->fcgPNHEVC->Location = System::Drawing::Point(341, 90);
            this->fcgPNHEVC->Name = L"fcgPNHEVC";
            this->fcgPNHEVC->Size = System::Drawing::Size(264, 388);
            this->fcgPNHEVC->TabIndex = 153;
            // 
            // fcgLBHEVCOutBitDepth
            // 
            this->fcgLBHEVCOutBitDepth->AutoSize = true;
            this->fcgLBHEVCOutBitDepth->Location = System::Drawing::Point(17, 10);
            this->fcgLBHEVCOutBitDepth->Name = L"fcgLBHEVCOutBitDepth";
            this->fcgLBHEVCOutBitDepth->Size = System::Drawing::Size(73, 14);
            this->fcgLBHEVCOutBitDepth->TabIndex = 156;
            this->fcgLBHEVCOutBitDepth->Text = L"出力ビット深度";
            // 
            // fcgCXHEVCOutBitDepth
            // 
            this->fcgCXHEVCOutBitDepth->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXHEVCOutBitDepth->FormattingEnabled = true;
            this->fcgCXHEVCOutBitDepth->Location = System::Drawing::Point(126, 7);
            this->fcgCXHEVCOutBitDepth->Name = L"fcgCXHEVCOutBitDepth";
            this->fcgCXHEVCOutBitDepth->Size = System::Drawing::Size(121, 22);
            this->fcgCXHEVCOutBitDepth->TabIndex = 155;
            this->fcgCXHEVCOutBitDepth->Tag = L"chValue";
            // 
            // fcgLBFullrangeHEVC
            // 
            this->fcgLBFullrangeHEVC->AutoSize = true;
            this->fcgLBFullrangeHEVC->Location = System::Drawing::Point(18, 258);
            this->fcgLBFullrangeHEVC->Name = L"fcgLBFullrangeHEVC";
            this->fcgLBFullrangeHEVC->Size = System::Drawing::Size(55, 14);
            this->fcgLBFullrangeHEVC->TabIndex = 154;
            this->fcgLBFullrangeHEVC->Text = L"fullrange";
            // 
            // fcgCBFullrangeHEVC
            // 
            this->fcgCBFullrangeHEVC->AutoSize = true;
            this->fcgCBFullrangeHEVC->Location = System::Drawing::Point(125, 261);
            this->fcgCBFullrangeHEVC->Name = L"fcgCBFullrangeHEVC";
            this->fcgCBFullrangeHEVC->Size = System::Drawing::Size(15, 14);
            this->fcgCBFullrangeHEVC->TabIndex = 151;
            this->fcgCBFullrangeHEVC->Tag = L"chValue";
            this->fcgCBFullrangeHEVC->UseVisualStyleBackColor = true;
            // 
            // fcgCXVideoFormatHEVC
            // 
            this->fcgCXVideoFormatHEVC->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXVideoFormatHEVC->FormattingEnabled = true;
            this->fcgCXVideoFormatHEVC->Location = System::Drawing::Point(125, 231);
            this->fcgCXVideoFormatHEVC->Name = L"fcgCXVideoFormatHEVC";
            this->fcgCXVideoFormatHEVC->Size = System::Drawing::Size(121, 22);
            this->fcgCXVideoFormatHEVC->TabIndex = 150;
            this->fcgCXVideoFormatHEVC->Tag = L"chValue";
            // 
            // fcgLBVideoFormatHEVC
            // 
            this->fcgLBVideoFormatHEVC->AutoSize = true;
            this->fcgLBVideoFormatHEVC->Location = System::Drawing::Point(18, 232);
            this->fcgLBVideoFormatHEVC->Name = L"fcgLBVideoFormatHEVC";
            this->fcgLBVideoFormatHEVC->Size = System::Drawing::Size(73, 14);
            this->fcgLBVideoFormatHEVC->TabIndex = 153;
            this->fcgLBVideoFormatHEVC->Text = L"videoformat";
            // 
            // fcggroupBoxColorHEVC
            // 
            this->fcggroupBoxColorHEVC->Controls->Add(this->fcgCXTransferHEVC);
            this->fcggroupBoxColorHEVC->Controls->Add(this->fcgCXColorPrimHEVC);
            this->fcggroupBoxColorHEVC->Controls->Add(this->fcgCXColorMatrixHEVC);
            this->fcggroupBoxColorHEVC->Controls->Add(this->fcgLBTransferHEVC);
            this->fcggroupBoxColorHEVC->Controls->Add(this->fcgLBColorPrimHEVC);
            this->fcggroupBoxColorHEVC->Controls->Add(this->fcgLBColorMatrixHEVC);
            this->fcggroupBoxColorHEVC->Location = System::Drawing::Point(14, 278);
            this->fcggroupBoxColorHEVC->Name = L"fcggroupBoxColorHEVC";
            this->fcggroupBoxColorHEVC->Size = System::Drawing::Size(241, 103);
            this->fcggroupBoxColorHEVC->TabIndex = 152;
            this->fcggroupBoxColorHEVC->TabStop = false;
            this->fcggroupBoxColorHEVC->Text = L"色設定";
            // 
            // fcgCXTransferHEVC
            // 
            this->fcgCXTransferHEVC->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXTransferHEVC->FormattingEnabled = true;
            this->fcgCXTransferHEVC->Location = System::Drawing::Point(111, 72);
            this->fcgCXTransferHEVC->Name = L"fcgCXTransferHEVC";
            this->fcgCXTransferHEVC->Size = System::Drawing::Size(121, 22);
            this->fcgCXTransferHEVC->TabIndex = 2;
            this->fcgCXTransferHEVC->Tag = L"chValue";
            // 
            // fcgCXColorPrimHEVC
            // 
            this->fcgCXColorPrimHEVC->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXColorPrimHEVC->FormattingEnabled = true;
            this->fcgCXColorPrimHEVC->Location = System::Drawing::Point(111, 44);
            this->fcgCXColorPrimHEVC->Name = L"fcgCXColorPrimHEVC";
            this->fcgCXColorPrimHEVC->Size = System::Drawing::Size(121, 22);
            this->fcgCXColorPrimHEVC->TabIndex = 1;
            this->fcgCXColorPrimHEVC->Tag = L"chValue";
            // 
            // fcgCXColorMatrixHEVC
            // 
            this->fcgCXColorMatrixHEVC->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXColorMatrixHEVC->FormattingEnabled = true;
            this->fcgCXColorMatrixHEVC->Location = System::Drawing::Point(111, 16);
            this->fcgCXColorMatrixHEVC->Name = L"fcgCXColorMatrixHEVC";
            this->fcgCXColorMatrixHEVC->Size = System::Drawing::Size(121, 22);
            this->fcgCXColorMatrixHEVC->TabIndex = 0;
            this->fcgCXColorMatrixHEVC->Tag = L"chValue";
            // 
            // fcgLBTransferHEVC
            // 
            this->fcgLBTransferHEVC->AutoSize = true;
            this->fcgLBTransferHEVC->Location = System::Drawing::Point(18, 75);
            this->fcgLBTransferHEVC->Name = L"fcgLBTransferHEVC";
            this->fcgLBTransferHEVC->Size = System::Drawing::Size(49, 14);
            this->fcgLBTransferHEVC->TabIndex = 2;
            this->fcgLBTransferHEVC->Text = L"transfer";
            // 
            // fcgLBColorPrimHEVC
            // 
            this->fcgLBColorPrimHEVC->AutoSize = true;
            this->fcgLBColorPrimHEVC->Location = System::Drawing::Point(18, 47);
            this->fcgLBColorPrimHEVC->Name = L"fcgLBColorPrimHEVC";
            this->fcgLBColorPrimHEVC->Size = System::Drawing::Size(61, 14);
            this->fcgLBColorPrimHEVC->TabIndex = 1;
            this->fcgLBColorPrimHEVC->Text = L"colorprim";
            // 
            // fcgLBColorMatrixHEVC
            // 
            this->fcgLBColorMatrixHEVC->AutoSize = true;
            this->fcgLBColorMatrixHEVC->Location = System::Drawing::Point(18, 19);
            this->fcgLBColorMatrixHEVC->Name = L"fcgLBColorMatrixHEVC";
            this->fcgLBColorMatrixHEVC->Size = System::Drawing::Size(70, 14);
            this->fcgLBColorMatrixHEVC->TabIndex = 0;
            this->fcgLBColorMatrixHEVC->Text = L"colormatrix";
            // 
            // fcgLBHEVCMinCUSize
            // 
            this->fcgLBHEVCMinCUSize->AutoSize = true;
            this->fcgLBHEVCMinCUSize->Location = System::Drawing::Point(17, 125);
            this->fcgLBHEVCMinCUSize->Name = L"fcgLBHEVCMinCUSize";
            this->fcgLBHEVCMinCUSize->Size = System::Drawing::Size(70, 14);
            this->fcgLBHEVCMinCUSize->TabIndex = 149;
            this->fcgLBHEVCMinCUSize->Text = L"最小CUサイズ";
            // 
            // fcgCXHEVCMinCUSize
            // 
            this->fcgCXHEVCMinCUSize->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXHEVCMinCUSize->FormattingEnabled = true;
            this->fcgCXHEVCMinCUSize->Location = System::Drawing::Point(126, 122);
            this->fcgCXHEVCMinCUSize->Name = L"fcgCXHEVCMinCUSize";
            this->fcgCXHEVCMinCUSize->Size = System::Drawing::Size(121, 22);
            this->fcgCXHEVCMinCUSize->TabIndex = 148;
            this->fcgCXHEVCMinCUSize->Tag = L"chValue";
            // 
            // fcgLBHEVCMaxCUSize
            // 
            this->fcgLBHEVCMaxCUSize->AutoSize = true;
            this->fcgLBHEVCMaxCUSize->Location = System::Drawing::Point(17, 95);
            this->fcgLBHEVCMaxCUSize->Name = L"fcgLBHEVCMaxCUSize";
            this->fcgLBHEVCMaxCUSize->Size = System::Drawing::Size(70, 14);
            this->fcgLBHEVCMaxCUSize->TabIndex = 147;
            this->fcgLBHEVCMaxCUSize->Text = L"最大CUサイズ";
            // 
            // fcgCXHEVCMaxCUSize
            // 
            this->fcgCXHEVCMaxCUSize->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXHEVCMaxCUSize->FormattingEnabled = true;
            this->fcgCXHEVCMaxCUSize->Location = System::Drawing::Point(126, 92);
            this->fcgCXHEVCMaxCUSize->Name = L"fcgCXHEVCMaxCUSize";
            this->fcgCXHEVCMaxCUSize->Size = System::Drawing::Size(121, 22);
            this->fcgCXHEVCMaxCUSize->TabIndex = 146;
            this->fcgCXHEVCMaxCUSize->Tag = L"chValue";
            // 
            // fcgLBHEVCProfile
            // 
            this->fcgLBHEVCProfile->AutoSize = true;
            this->fcgLBHEVCProfile->Location = System::Drawing::Point(17, 37);
            this->fcgLBHEVCProfile->Name = L"fcgLBHEVCProfile";
            this->fcgLBHEVCProfile->Size = System::Drawing::Size(53, 14);
            this->fcgLBHEVCProfile->TabIndex = 83;
            this->fcgLBHEVCProfile->Text = L"プロファイル";
            // 
            // fxgLBHEVCTier
            // 
            this->fxgLBHEVCTier->AutoSize = true;
            this->fxgLBHEVCTier->Location = System::Drawing::Point(17, 66);
            this->fxgLBHEVCTier->Name = L"fxgLBHEVCTier";
            this->fxgLBHEVCTier->Size = System::Drawing::Size(33, 14);
            this->fxgLBHEVCTier->TabIndex = 84;
            this->fxgLBHEVCTier->Text = L"レベル";
            // 
            // fcgCXHEVCTier
            // 
            this->fcgCXHEVCTier->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXHEVCTier->FormattingEnabled = true;
            this->fcgCXHEVCTier->Location = System::Drawing::Point(126, 34);
            this->fcgCXHEVCTier->Name = L"fcgCXHEVCTier";
            this->fcgCXHEVCTier->Size = System::Drawing::Size(121, 22);
            this->fcgCXHEVCTier->TabIndex = 21;
            this->fcgCXHEVCTier->Tag = L"chValue";
            // 
            // fxgCXHEVCLevel
            // 
            this->fxgCXHEVCLevel->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fxgCXHEVCLevel->FormattingEnabled = true;
            this->fxgCXHEVCLevel->Location = System::Drawing::Point(126, 63);
            this->fxgCXHEVCLevel->Name = L"fxgCXHEVCLevel";
            this->fxgCXHEVCLevel->Size = System::Drawing::Size(121, 22);
            this->fxgCXHEVCLevel->TabIndex = 22;
            this->fxgCXHEVCLevel->Tag = L"chValue";
            // 
            // tabPageExOpt
            // 
            this->tabPageExOpt->Controls->Add(this->fcggroupBoxVpp);
            this->tabPageExOpt->Controls->Add(this->fcgCBAuoTcfileout);
            this->tabPageExOpt->Controls->Add(this->fcgLBTempDir);
            this->tabPageExOpt->Controls->Add(this->fcgBTCustomTempDir);
            this->tabPageExOpt->Controls->Add(this->fcgTXCustomTempDir);
            this->tabPageExOpt->Controls->Add(this->fcgCXTempDir);
            this->tabPageExOpt->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->tabPageExOpt->Location = System::Drawing::Point(4, 24);
            this->tabPageExOpt->Name = L"tabPageExOpt";
            this->tabPageExOpt->Size = System::Drawing::Size(608, 481);
            this->tabPageExOpt->TabIndex = 1;
            this->tabPageExOpt->Text = L"その他";
            this->tabPageExOpt->UseVisualStyleBackColor = true;
            // 
            // fcggroupBoxVpp
            // 
            this->fcggroupBoxVpp->Controls->Add(this->fcgCBVppPerfMonitor);
            this->fcggroupBoxVpp->Controls->Add(this->fcggroupBoxVppDenoise);
            this->fcggroupBoxVpp->Controls->Add(this->fcgCBVppResize);
            this->fcggroupBoxVpp->Controls->Add(this->fcggroupBoxResize);
            this->fcggroupBoxVpp->Location = System::Drawing::Point(9, 106);
            this->fcggroupBoxVpp->Name = L"fcggroupBoxVpp";
            this->fcggroupBoxVpp->Size = System::Drawing::Size(592, 369);
            this->fcggroupBoxVpp->TabIndex = 74;
            this->fcggroupBoxVpp->TabStop = false;
            this->fcggroupBoxVpp->Text = L"ビデオフィルタ";
            // 
            // fcgCBVppPerfMonitor
            // 
            this->fcgCBVppPerfMonitor->AutoSize = true;
            this->fcgCBVppPerfMonitor->Location = System::Drawing::Point(18, 336);
            this->fcgCBVppPerfMonitor->Name = L"fcgCBVppPerfMonitor";
            this->fcgCBVppPerfMonitor->Size = System::Drawing::Size(112, 18);
            this->fcgCBVppPerfMonitor->TabIndex = 3;
            this->fcgCBVppPerfMonitor->Tag = L"chValue";
            this->fcgCBVppPerfMonitor->Text = L"パフォーマンスチェック";
            this->fcgCBVppPerfMonitor->UseVisualStyleBackColor = true;
            // 
            // fcggroupBoxVppDenoise
            // 
            this->fcggroupBoxVppDenoise->Controls->Add(this->fcgPNVppDenoiseKnn);
            this->fcggroupBoxVppDenoise->Controls->Add(this->fcgPNVppDenoisePmd);
            this->fcggroupBoxVppDenoise->Controls->Add(this->fcgCXVppDenoiseMethod);
            this->fcggroupBoxVppDenoise->Location = System::Drawing::Point(18, 136);
            this->fcggroupBoxVppDenoise->Name = L"fcggroupBoxVppDenoise";
            this->fcggroupBoxVppDenoise->Size = System::Drawing::Size(235, 141);
            this->fcggroupBoxVppDenoise->TabIndex = 2;
            this->fcggroupBoxVppDenoise->TabStop = false;
            this->fcggroupBoxVppDenoise->Text = L"ノイズ除去";
            // 
            // fcgPNVppDenoiseKnn
            // 
            this->fcgPNVppDenoiseKnn->Controls->Add(this->fcgLBVppDenoiseKnnThreshold);
            this->fcgPNVppDenoiseKnn->Controls->Add(this->fcgLBVppDenoiseKnnStrength);
            this->fcgPNVppDenoiseKnn->Controls->Add(this->fcgLBVppDenoiseKnnRadius);
            this->fcgPNVppDenoiseKnn->Controls->Add(this->fcgNUVppDenoiseKnnThreshold);
            this->fcgPNVppDenoiseKnn->Controls->Add(this->fcgNUVppDenoiseKnnStrength);
            this->fcgPNVppDenoiseKnn->Controls->Add(this->fcgNUVppDenoiseKnnRadius);
            this->fcgPNVppDenoiseKnn->Location = System::Drawing::Point(3, 43);
            this->fcgPNVppDenoiseKnn->Name = L"fcgPNVppDenoiseKnn";
            this->fcgPNVppDenoiseKnn->Size = System::Drawing::Size(226, 92);
            this->fcgPNVppDenoiseKnn->TabIndex = 65;
            // 
            // fcgLBVppDenoiseKnnThreshold
            // 
            this->fcgLBVppDenoiseKnnThreshold->AutoSize = true;
            this->fcgLBVppDenoiseKnnThreshold->Location = System::Drawing::Point(69, 66);
            this->fcgLBVppDenoiseKnnThreshold->Name = L"fcgLBVppDenoiseKnnThreshold";
            this->fcgLBVppDenoiseKnnThreshold->Size = System::Drawing::Size(29, 14);
            this->fcgLBVppDenoiseKnnThreshold->TabIndex = 11;
            this->fcgLBVppDenoiseKnnThreshold->Text = L"閾値";
            // 
            // fcgLBVppDenoiseKnnStrength
            // 
            this->fcgLBVppDenoiseKnnStrength->AutoSize = true;
            this->fcgLBVppDenoiseKnnStrength->Location = System::Drawing::Point(69, 39);
            this->fcgLBVppDenoiseKnnStrength->Name = L"fcgLBVppDenoiseKnnStrength";
            this->fcgLBVppDenoiseKnnStrength->Size = System::Drawing::Size(26, 14);
            this->fcgLBVppDenoiseKnnStrength->TabIndex = 10;
            this->fcgLBVppDenoiseKnnStrength->Text = L"強さ";
            // 
            // fcgLBVppDenoiseKnnRadius
            // 
            this->fcgLBVppDenoiseKnnRadius->AutoSize = true;
            this->fcgLBVppDenoiseKnnRadius->Location = System::Drawing::Point(69, 12);
            this->fcgLBVppDenoiseKnnRadius->Name = L"fcgLBVppDenoiseKnnRadius";
            this->fcgLBVppDenoiseKnnRadius->Size = System::Drawing::Size(29, 14);
            this->fcgLBVppDenoiseKnnRadius->TabIndex = 9;
            this->fcgLBVppDenoiseKnnRadius->Text = L"半径";
            // 
            // fcgNUVppDenoiseKnnThreshold
            // 
            this->fcgNUVppDenoiseKnnThreshold->DecimalPlaces = 2;
            this->fcgNUVppDenoiseKnnThreshold->Location = System::Drawing::Point(129, 64);
            this->fcgNUVppDenoiseKnnThreshold->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->fcgNUVppDenoiseKnnThreshold->Name = L"fcgNUVppDenoiseKnnThreshold";
            this->fcgNUVppDenoiseKnnThreshold->Size = System::Drawing::Size(60, 21);
            this->fcgNUVppDenoiseKnnThreshold->TabIndex = 8;
            this->fcgNUVppDenoiseKnnThreshold->Tag = L"chValue";
            this->fcgNUVppDenoiseKnnThreshold->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppDenoiseKnnThreshold->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            // 
            // fcgNUVppDenoiseKnnStrength
            // 
            this->fcgNUVppDenoiseKnnStrength->DecimalPlaces = 2;
            this->fcgNUVppDenoiseKnnStrength->Location = System::Drawing::Point(129, 37);
            this->fcgNUVppDenoiseKnnStrength->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->fcgNUVppDenoiseKnnStrength->Name = L"fcgNUVppDenoiseKnnStrength";
            this->fcgNUVppDenoiseKnnStrength->Size = System::Drawing::Size(60, 21);
            this->fcgNUVppDenoiseKnnStrength->TabIndex = 7;
            this->fcgNUVppDenoiseKnnStrength->Tag = L"chValue";
            this->fcgNUVppDenoiseKnnStrength->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppDenoiseKnnStrength->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            // 
            // fcgNUVppDenoiseKnnRadius
            // 
            this->fcgNUVppDenoiseKnnRadius->Location = System::Drawing::Point(129, 10);
            this->fcgNUVppDenoiseKnnRadius->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
            this->fcgNUVppDenoiseKnnRadius->Name = L"fcgNUVppDenoiseKnnRadius";
            this->fcgNUVppDenoiseKnnRadius->Size = System::Drawing::Size(60, 21);
            this->fcgNUVppDenoiseKnnRadius->TabIndex = 6;
            this->fcgNUVppDenoiseKnnRadius->Tag = L"chValue";
            this->fcgNUVppDenoiseKnnRadius->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppDenoiseKnnRadius->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
            // 
            // fcgPNVppDenoisePmd
            // 
            this->fcgPNVppDenoisePmd->Controls->Add(this->fcgLBVppDenoisePmdThreshold);
            this->fcgPNVppDenoisePmd->Controls->Add(this->fcgLBVppDenoisePmdStrength);
            this->fcgPNVppDenoisePmd->Controls->Add(this->fcgLBVppDenoisePmdApplyCount);
            this->fcgPNVppDenoisePmd->Controls->Add(this->fcgNUVppDenoisePmdThreshold);
            this->fcgPNVppDenoisePmd->Controls->Add(this->fcgNUVppDenoisePmdStrength);
            this->fcgPNVppDenoisePmd->Controls->Add(this->fcgNUVppDenoisePmdApplyCount);
            this->fcgPNVppDenoisePmd->Location = System::Drawing::Point(3, 43);
            this->fcgPNVppDenoisePmd->Name = L"fcgPNVppDenoisePmd";
            this->fcgPNVppDenoisePmd->Size = System::Drawing::Size(226, 92);
            this->fcgPNVppDenoisePmd->TabIndex = 64;
            // 
            // fcgLBVppDenoisePmdThreshold
            // 
            this->fcgLBVppDenoisePmdThreshold->AutoSize = true;
            this->fcgLBVppDenoisePmdThreshold->Location = System::Drawing::Point(69, 66);
            this->fcgLBVppDenoisePmdThreshold->Name = L"fcgLBVppDenoisePmdThreshold";
            this->fcgLBVppDenoisePmdThreshold->Size = System::Drawing::Size(29, 14);
            this->fcgLBVppDenoisePmdThreshold->TabIndex = 11;
            this->fcgLBVppDenoisePmdThreshold->Text = L"閾値";
            // 
            // fcgLBVppDenoisePmdStrength
            // 
            this->fcgLBVppDenoisePmdStrength->AutoSize = true;
            this->fcgLBVppDenoisePmdStrength->Location = System::Drawing::Point(69, 39);
            this->fcgLBVppDenoisePmdStrength->Name = L"fcgLBVppDenoisePmdStrength";
            this->fcgLBVppDenoisePmdStrength->Size = System::Drawing::Size(26, 14);
            this->fcgLBVppDenoisePmdStrength->TabIndex = 10;
            this->fcgLBVppDenoisePmdStrength->Text = L"強さ";
            // 
            // fcgLBVppDenoisePmdApplyCount
            // 
            this->fcgLBVppDenoisePmdApplyCount->AutoSize = true;
            this->fcgLBVppDenoisePmdApplyCount->Location = System::Drawing::Point(69, 12);
            this->fcgLBVppDenoisePmdApplyCount->Name = L"fcgLBVppDenoisePmdApplyCount";
            this->fcgLBVppDenoisePmdApplyCount->Size = System::Drawing::Size(29, 14);
            this->fcgLBVppDenoisePmdApplyCount->TabIndex = 9;
            this->fcgLBVppDenoisePmdApplyCount->Text = L"回数";
            // 
            // fcgNUVppDenoisePmdThreshold
            // 
            this->fcgNUVppDenoisePmdThreshold->Location = System::Drawing::Point(129, 64);
            this->fcgNUVppDenoisePmdThreshold->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
            this->fcgNUVppDenoisePmdThreshold->Name = L"fcgNUVppDenoisePmdThreshold";
            this->fcgNUVppDenoisePmdThreshold->Size = System::Drawing::Size(60, 21);
            this->fcgNUVppDenoisePmdThreshold->TabIndex = 8;
            this->fcgNUVppDenoisePmdThreshold->Tag = L"chValue";
            this->fcgNUVppDenoisePmdThreshold->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppDenoisePmdThreshold->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
            // 
            // fcgNUVppDenoisePmdStrength
            // 
            this->fcgNUVppDenoisePmdStrength->Location = System::Drawing::Point(129, 37);
            this->fcgNUVppDenoisePmdStrength->Name = L"fcgNUVppDenoisePmdStrength";
            this->fcgNUVppDenoisePmdStrength->Size = System::Drawing::Size(60, 21);
            this->fcgNUVppDenoisePmdStrength->TabIndex = 7;
            this->fcgNUVppDenoisePmdStrength->Tag = L"chValue";
            this->fcgNUVppDenoisePmdStrength->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppDenoisePmdStrength->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
            // 
            // fcgNUVppDenoisePmdApplyCount
            // 
            this->fcgNUVppDenoisePmdApplyCount->Location = System::Drawing::Point(129, 10);
            this->fcgNUVppDenoisePmdApplyCount->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
            this->fcgNUVppDenoisePmdApplyCount->Name = L"fcgNUVppDenoisePmdApplyCount";
            this->fcgNUVppDenoisePmdApplyCount->Size = System::Drawing::Size(60, 21);
            this->fcgNUVppDenoisePmdApplyCount->TabIndex = 6;
            this->fcgNUVppDenoisePmdApplyCount->Tag = L"chValue";
            this->fcgNUVppDenoisePmdApplyCount->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->fcgNUVppDenoisePmdApplyCount->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
            // 
            // fcgCXVppDenoiseMethod
            // 
            this->fcgCXVppDenoiseMethod->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXVppDenoiseMethod->FormattingEnabled = true;
            this->fcgCXVppDenoiseMethod->Location = System::Drawing::Point(26, 20);
            this->fcgCXVppDenoiseMethod->Name = L"fcgCXVppDenoiseMethod";
            this->fcgCXVppDenoiseMethod->Size = System::Drawing::Size(191, 22);
            this->fcgCXVppDenoiseMethod->TabIndex = 63;
            this->fcgCXVppDenoiseMethod->Tag = L"chValue";
            this->fcgCXVppDenoiseMethod->SelectedIndexChanged += gcnew System::EventHandler(this, &frmConfig::fcgChangeEnabled);
            // 
            // fcgCBVppResize
            // 
            this->fcgCBVppResize->AutoSize = true;
            this->fcgCBVppResize->Location = System::Drawing::Point(27, 29);
            this->fcgCBVppResize->Name = L"fcgCBVppResize";
            this->fcgCBVppResize->Size = System::Drawing::Size(58, 18);
            this->fcgCBVppResize->TabIndex = 0;
            this->fcgCBVppResize->Tag = L"chValue";
            this->fcgCBVppResize->Text = L"リサイズ";
            this->fcgCBVppResize->UseVisualStyleBackColor = true;
            this->fcgCBVppResize->CheckedChanged += gcnew System::EventHandler(this, &frmConfig::fcgChangeEnabled);
            // 
            // fcggroupBoxResize
            // 
            this->fcggroupBoxResize->Controls->Add(this->fcgCXVppResizeAlg);
            this->fcggroupBoxResize->Controls->Add(this->fcgLBVppResize);
            this->fcggroupBoxResize->Controls->Add(this->fcgNUVppResizeHeight);
            this->fcggroupBoxResize->Controls->Add(this->fcgNUVppResizeWidth);
            this->fcggroupBoxResize->Location = System::Drawing::Point(18, 29);
            this->fcggroupBoxResize->Name = L"fcggroupBoxResize";
            this->fcggroupBoxResize->Size = System::Drawing::Size(235, 89);
            this->fcggroupBoxResize->TabIndex = 0;
            this->fcggroupBoxResize->TabStop = false;
            // 
            // fcgCXVppResizeAlg
            // 
            this->fcgCXVppResizeAlg->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXVppResizeAlg->FormattingEnabled = true;
            this->fcgCXVppResizeAlg->Location = System::Drawing::Point(48, 52);
            this->fcgCXVppResizeAlg->Name = L"fcgCXVppResizeAlg";
            this->fcgCXVppResizeAlg->Size = System::Drawing::Size(144, 22);
            this->fcgCXVppResizeAlg->TabIndex = 63;
            this->fcgCXVppResizeAlg->Tag = L"chValue";
            // 
            // fcgLBVppResize
            // 
            this->fcgLBVppResize->AutoSize = true;
            this->fcgLBVppResize->Location = System::Drawing::Point(114, 25);
            this->fcgLBVppResize->Name = L"fcgLBVppResize";
            this->fcgLBVppResize->Size = System::Drawing::Size(13, 14);
            this->fcgLBVppResize->TabIndex = 6;
            this->fcgLBVppResize->Text = L"x";
            // 
            // fcgNUVppResizeHeight
            // 
            this->fcgNUVppResizeHeight->Location = System::Drawing::Point(132, 23);
            this->fcgNUVppResizeHeight->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65535, 0, 0, 0 });
            this->fcgNUVppResizeHeight->Name = L"fcgNUVppResizeHeight";
            this->fcgNUVppResizeHeight->Size = System::Drawing::Size(60, 21);
            this->fcgNUVppResizeHeight->TabIndex = 5;
            this->fcgNUVppResizeHeight->Tag = L"chValue";
            this->fcgNUVppResizeHeight->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgNUVppResizeWidth
            // 
            this->fcgNUVppResizeWidth->Location = System::Drawing::Point(48, 23);
            this->fcgNUVppResizeWidth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65535, 0, 0, 0 });
            this->fcgNUVppResizeWidth->Name = L"fcgNUVppResizeWidth";
            this->fcgNUVppResizeWidth->Size = System::Drawing::Size(60, 21);
            this->fcgNUVppResizeWidth->TabIndex = 4;
            this->fcgNUVppResizeWidth->Tag = L"chValue";
            this->fcgNUVppResizeWidth->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgCBAuoTcfileout
            // 
            this->fcgCBAuoTcfileout->AutoSize = true;
            this->fcgCBAuoTcfileout->Location = System::Drawing::Point(346, 49);
            this->fcgCBAuoTcfileout->Name = L"fcgCBAuoTcfileout";
            this->fcgCBAuoTcfileout->Size = System::Drawing::Size(98, 18);
            this->fcgCBAuoTcfileout->TabIndex = 73;
            this->fcgCBAuoTcfileout->Tag = L"chValue";
            this->fcgCBAuoTcfileout->Text = L"タイムコード出力";
            this->fcgCBAuoTcfileout->UseVisualStyleBackColor = true;
            // 
            // fcgLBTempDir
            // 
            this->fcgLBTempDir->AutoSize = true;
            this->fcgLBTempDir->Location = System::Drawing::Point(15, 9);
            this->fcgLBTempDir->Name = L"fcgLBTempDir";
            this->fcgLBTempDir->Size = System::Drawing::Size(60, 14);
            this->fcgLBTempDir->TabIndex = 67;
            this->fcgLBTempDir->Text = L"一時フォルダ";
            // 
            // fcgBTCustomTempDir
            // 
            this->fcgBTCustomTempDir->Location = System::Drawing::Point(215, 62);
            this->fcgBTCustomTempDir->Name = L"fcgBTCustomTempDir";
            this->fcgBTCustomTempDir->Size = System::Drawing::Size(29, 23);
            this->fcgBTCustomTempDir->TabIndex = 64;
            this->fcgBTCustomTempDir->Text = L"...";
            this->fcgBTCustomTempDir->UseVisualStyleBackColor = true;
            this->fcgBTCustomTempDir->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTCustomTempDir_Click);
            // 
            // fcgTXCustomTempDir
            // 
            this->fcgTXCustomTempDir->Location = System::Drawing::Point(30, 63);
            this->fcgTXCustomTempDir->Name = L"fcgTXCustomTempDir";
            this->fcgTXCustomTempDir->Size = System::Drawing::Size(182, 21);
            this->fcgTXCustomTempDir->TabIndex = 63;
            this->fcgTXCustomTempDir->Tag = L"";
            this->fcgTXCustomTempDir->TextChanged += gcnew System::EventHandler(this, &frmConfig::fcgTXCustomTempDir_TextChanged);
            // 
            // fcgCXTempDir
            // 
            this->fcgCXTempDir->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXTempDir->FormattingEnabled = true;
            this->fcgCXTempDir->Location = System::Drawing::Point(18, 35);
            this->fcgCXTempDir->Name = L"fcgCXTempDir";
            this->fcgCXTempDir->Size = System::Drawing::Size(209, 22);
            this->fcgCXTempDir->TabIndex = 62;
            this->fcgCXTempDir->Tag = L"chValue";
            // 
            // tabPageNVEncFeatures
            // 
            this->tabPageNVEncFeatures->Controls->Add(this->fcgTabControlFeatures);
            this->tabPageNVEncFeatures->Controls->Add(this->fcgLBOSInfo);
            this->tabPageNVEncFeatures->Controls->Add(this->fcgLBOSInfoLabel);
            this->tabPageNVEncFeatures->Controls->Add(this->fcgLBCPUInfoOnFeatureTab);
            this->tabPageNVEncFeatures->Controls->Add(this->fcgLBCPUInfoLabelOnFeatureTab);
            this->tabPageNVEncFeatures->Controls->Add(this->label2);
            this->tabPageNVEncFeatures->Controls->Add(this->fcgLBGPUInfoOnFeatureTab);
            this->tabPageNVEncFeatures->Controls->Add(this->fcgLBGPUInfoLabelOnFeatureTab);
            this->tabPageNVEncFeatures->Location = System::Drawing::Point(4, 24);
            this->tabPageNVEncFeatures->Name = L"tabPageNVEncFeatures";
            this->tabPageNVEncFeatures->Size = System::Drawing::Size(608, 481);
            this->tabPageNVEncFeatures->TabIndex = 2;
            this->tabPageNVEncFeatures->Text = L"情報";
            this->tabPageNVEncFeatures->UseVisualStyleBackColor = true;
            // 
            // fcgTabControlFeatures
            // 
            this->fcgTabControlFeatures->Controls->Add(this->fcgTabPageH264);
            this->fcgTabControlFeatures->Controls->Add(this->fcgTabPageHEVC);
            this->fcgTabControlFeatures->Location = System::Drawing::Point(3, 134);
            this->fcgTabControlFeatures->Name = L"fcgTabControlFeatures";
            this->fcgTabControlFeatures->SelectedIndex = 0;
            this->fcgTabControlFeatures->Size = System::Drawing::Size(602, 344);
            this->fcgTabControlFeatures->TabIndex = 122;
            // 
            // fcgTabPageH264
            // 
            this->fcgTabPageH264->Controls->Add(this->fcgDGVFeaturesH264);
            this->fcgTabPageH264->Location = System::Drawing::Point(4, 24);
            this->fcgTabPageH264->Name = L"fcgTabPageH264";
            this->fcgTabPageH264->Padding = System::Windows::Forms::Padding(3);
            this->fcgTabPageH264->Size = System::Drawing::Size(594, 316);
            this->fcgTabPageH264->TabIndex = 0;
            this->fcgTabPageH264->Text = L"H.264/AVC";
            this->fcgTabPageH264->UseVisualStyleBackColor = true;
            // 
            // fcgDGVFeaturesH264
            // 
            this->fcgDGVFeaturesH264->BackgroundColor = System::Drawing::SystemColors::Window;
            this->fcgDGVFeaturesH264->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->fcgDGVFeaturesH264->Location = System::Drawing::Point(3, 3);
            this->fcgDGVFeaturesH264->Name = L"fcgDGVFeaturesH264";
            this->fcgDGVFeaturesH264->RowTemplate->Height = 21;
            this->fcgDGVFeaturesH264->Size = System::Drawing::Size(588, 310);
            this->fcgDGVFeaturesH264->TabIndex = 0;
            // 
            // fcgTabPageHEVC
            // 
            this->fcgTabPageHEVC->Controls->Add(this->fcgDGVFeaturesHEVC);
            this->fcgTabPageHEVC->Location = System::Drawing::Point(4, 24);
            this->fcgTabPageHEVC->Name = L"fcgTabPageHEVC";
            this->fcgTabPageHEVC->Padding = System::Windows::Forms::Padding(3);
            this->fcgTabPageHEVC->Size = System::Drawing::Size(594, 316);
            this->fcgTabPageHEVC->TabIndex = 1;
            this->fcgTabPageHEVC->Text = L"H.265/HEVC";
            this->fcgTabPageHEVC->UseVisualStyleBackColor = true;
            // 
            // fcgDGVFeaturesHEVC
            // 
            this->fcgDGVFeaturesHEVC->BackgroundColor = System::Drawing::SystemColors::Window;
            this->fcgDGVFeaturesHEVC->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->fcgDGVFeaturesHEVC->Location = System::Drawing::Point(3, 3);
            this->fcgDGVFeaturesHEVC->Name = L"fcgDGVFeaturesHEVC";
            this->fcgDGVFeaturesHEVC->RowTemplate->Height = 21;
            this->fcgDGVFeaturesHEVC->Size = System::Drawing::Size(588, 310);
            this->fcgDGVFeaturesHEVC->TabIndex = 1;
            // 
            // fcgLBOSInfo
            // 
            this->fcgLBOSInfo->AutoSize = true;
            this->fcgLBOSInfo->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->fcgLBOSInfo->ForeColor = System::Drawing::Color::DarkViolet;
            this->fcgLBOSInfo->Location = System::Drawing::Point(96, 51);
            this->fcgLBOSInfo->Name = L"fcgLBOSInfo";
            this->fcgLBOSInfo->Size = System::Drawing::Size(26, 17);
            this->fcgLBOSInfo->TabIndex = 121;
            this->fcgLBOSInfo->Text = L"OS";
            // 
            // fcgLBOSInfoLabel
            // 
            this->fcgLBOSInfoLabel->AutoSize = true;
            this->fcgLBOSInfoLabel->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->fcgLBOSInfoLabel->ForeColor = System::Drawing::Color::Blue;
            this->fcgLBOSInfoLabel->Location = System::Drawing::Point(33, 49);
            this->fcgLBOSInfoLabel->Name = L"fcgLBOSInfoLabel";
            this->fcgLBOSInfoLabel->Size = System::Drawing::Size(30, 19);
            this->fcgLBOSInfoLabel->TabIndex = 120;
            this->fcgLBOSInfoLabel->Text = L"OS";
            // 
            // fcgLBCPUInfoOnFeatureTab
            // 
            this->fcgLBCPUInfoOnFeatureTab->AutoSize = true;
            this->fcgLBCPUInfoOnFeatureTab->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->fcgLBCPUInfoOnFeatureTab->ForeColor = System::Drawing::Color::DarkViolet;
            this->fcgLBCPUInfoOnFeatureTab->Location = System::Drawing::Point(96, 78);
            this->fcgLBCPUInfoOnFeatureTab->Name = L"fcgLBCPUInfoOnFeatureTab";
            this->fcgLBCPUInfoOnFeatureTab->Size = System::Drawing::Size(34, 17);
            this->fcgLBCPUInfoOnFeatureTab->TabIndex = 119;
            this->fcgLBCPUInfoOnFeatureTab->Text = L"CPU";
            // 
            // fcgLBCPUInfoLabelOnFeatureTab
            // 
            this->fcgLBCPUInfoLabelOnFeatureTab->AutoSize = true;
            this->fcgLBCPUInfoLabelOnFeatureTab->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 11.25F, System::Drawing::FontStyle::Italic,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
            this->fcgLBCPUInfoLabelOnFeatureTab->ForeColor = System::Drawing::Color::Blue;
            this->fcgLBCPUInfoLabelOnFeatureTab->Location = System::Drawing::Point(32, 76);
            this->fcgLBCPUInfoLabelOnFeatureTab->Name = L"fcgLBCPUInfoLabelOnFeatureTab";
            this->fcgLBCPUInfoLabelOnFeatureTab->Size = System::Drawing::Size(39, 19);
            this->fcgLBCPUInfoLabelOnFeatureTab->TabIndex = 118;
            this->fcgLBCPUInfoLabelOnFeatureTab->Text = L"CPU";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->label2->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->label2->Location = System::Drawing::Point(14, 15);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(314, 19);
            this->label2->TabIndex = 117;
            this->label2->Text = L"現在の環境でサポートされる機能を表示しています。";
            // 
            // fcgLBGPUInfoOnFeatureTab
            // 
            this->fcgLBGPUInfoOnFeatureTab->AutoSize = true;
            this->fcgLBGPUInfoOnFeatureTab->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->fcgLBGPUInfoOnFeatureTab->ForeColor = System::Drawing::Color::DarkViolet;
            this->fcgLBGPUInfoOnFeatureTab->Location = System::Drawing::Point(96, 105);
            this->fcgLBGPUInfoOnFeatureTab->Name = L"fcgLBGPUInfoOnFeatureTab";
            this->fcgLBGPUInfoOnFeatureTab->Size = System::Drawing::Size(35, 17);
            this->fcgLBGPUInfoOnFeatureTab->TabIndex = 116;
            this->fcgLBGPUInfoOnFeatureTab->Text = L"GPU";
            // 
            // fcgLBGPUInfoLabelOnFeatureTab
            // 
            this->fcgLBGPUInfoLabelOnFeatureTab->AutoSize = true;
            this->fcgLBGPUInfoLabelOnFeatureTab->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 11.25F, System::Drawing::FontStyle::Italic,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
            this->fcgLBGPUInfoLabelOnFeatureTab->ForeColor = System::Drawing::Color::Blue;
            this->fcgLBGPUInfoLabelOnFeatureTab->Location = System::Drawing::Point(32, 103);
            this->fcgLBGPUInfoLabelOnFeatureTab->Name = L"fcgLBGPUInfoLabelOnFeatureTab";
            this->fcgLBGPUInfoLabelOnFeatureTab->Size = System::Drawing::Size(40, 19);
            this->fcgLBGPUInfoLabelOnFeatureTab->TabIndex = 115;
            this->fcgLBGPUInfoLabelOnFeatureTab->Text = L"GPU";
            // 
            // fcgCSExeFiles
            // 
            this->fcgCSExeFiles->ImageScalingSize = System::Drawing::Size(18, 18);
            this->fcgCSExeFiles->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fcgTSExeFileshelp });
            this->fcgCSExeFiles->Name = L"fcgCSx264";
            this->fcgCSExeFiles->Size = System::Drawing::Size(131, 26);
            // 
            // fcgTSExeFileshelp
            // 
            this->fcgTSExeFileshelp->Name = L"fcgTSExeFileshelp";
            this->fcgTSExeFileshelp->Size = System::Drawing::Size(130, 22);
            this->fcgTSExeFileshelp->Text = L"helpを表示";
            this->fcgTSExeFileshelp->Click += gcnew System::EventHandler(this, &frmConfig::fcgTSExeFileshelp_Click);
            // 
            // fcgLBguiExBlog
            // 
            this->fcgLBguiExBlog->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->fcgLBguiExBlog->AutoSize = true;
            this->fcgLBguiExBlog->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->fcgLBguiExBlog->LinkColor = System::Drawing::Color::Gray;
            this->fcgLBguiExBlog->Location = System::Drawing::Point(639, 555);
            this->fcgLBguiExBlog->Name = L"fcgLBguiExBlog";
            this->fcgLBguiExBlog->Size = System::Drawing::Size(79, 14);
            this->fcgLBguiExBlog->TabIndex = 50;
            this->fcgLBguiExBlog->TabStop = true;
            this->fcgLBguiExBlog->Text = L"NVEncについて";
            this->fcgLBguiExBlog->VisitedLinkColor = System::Drawing::Color::Gray;
            this->fcgLBguiExBlog->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &frmConfig::fcgLBguiExBlog_LinkClicked);
            // 
            // fcgtabControlAudio
            // 
            this->fcgtabControlAudio->Controls->Add(this->fcgtabPageAudioMain);
            this->fcgtabControlAudio->Controls->Add(this->fcgtabPageAudioOther);
            this->fcgtabControlAudio->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 8.25F));
            this->fcgtabControlAudio->Location = System::Drawing::Point(621, 31);
            this->fcgtabControlAudio->Name = L"fcgtabControlAudio";
            this->fcgtabControlAudio->SelectedIndex = 0;
            this->fcgtabControlAudio->Size = System::Drawing::Size(384, 296);
            this->fcgtabControlAudio->TabIndex = 51;
            // 
            // fcgtabPageAudioMain
            // 
            this->fcgtabPageAudioMain->Controls->Add(this->fcgCXAudioDelayCut);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgLBAudioDelayCut);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgCBAudioEncTiming);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgCXAudioEncTiming);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgCXAudioTempDir);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgTXCustomAudioTempDir);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgBTCustomAudioTempDir);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgCBAudioUsePipe);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgLBAudioBitrate);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgNUAudioBitrate);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgCBAudio2pass);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgCXAudioEncMode);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgLBAudioEncMode);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgBTAudioEncoderPath);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgTXAudioEncoderPath);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgLBAudioEncoderPath);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgCBAudioOnly);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgCBFAWCheck);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgCXAudioEncoder);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgLBAudioEncoder);
            this->fcgtabPageAudioMain->Controls->Add(this->fcgLBAudioTemp);
            this->fcgtabPageAudioMain->Location = System::Drawing::Point(4, 23);
            this->fcgtabPageAudioMain->Name = L"fcgtabPageAudioMain";
            this->fcgtabPageAudioMain->Padding = System::Windows::Forms::Padding(3);
            this->fcgtabPageAudioMain->Size = System::Drawing::Size(376, 269);
            this->fcgtabPageAudioMain->TabIndex = 0;
            this->fcgtabPageAudioMain->Text = L"音声";
            this->fcgtabPageAudioMain->UseVisualStyleBackColor = true;
            // 
            // fcgCXAudioDelayCut
            // 
            this->fcgCXAudioDelayCut->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXAudioDelayCut->FormattingEnabled = true;
            this->fcgCXAudioDelayCut->Location = System::Drawing::Point(291, 133);
            this->fcgCXAudioDelayCut->Name = L"fcgCXAudioDelayCut";
            this->fcgCXAudioDelayCut->Size = System::Drawing::Size(70, 22);
            this->fcgCXAudioDelayCut->TabIndex = 43;
            this->fcgCXAudioDelayCut->Tag = L"chValue";
            // 
            // fcgLBAudioDelayCut
            // 
            this->fcgLBAudioDelayCut->AutoSize = true;
            this->fcgLBAudioDelayCut->Location = System::Drawing::Point(224, 136);
            this->fcgLBAudioDelayCut->Name = L"fcgLBAudioDelayCut";
            this->fcgLBAudioDelayCut->Size = System::Drawing::Size(60, 14);
            this->fcgLBAudioDelayCut->TabIndex = 54;
            this->fcgLBAudioDelayCut->Text = L"ディレイカット";
            // 
            // fcgCBAudioEncTiming
            // 
            this->fcgCBAudioEncTiming->AutoSize = true;
            this->fcgCBAudioEncTiming->Location = System::Drawing::Point(242, 54);
            this->fcgCBAudioEncTiming->Name = L"fcgCBAudioEncTiming";
            this->fcgCBAudioEncTiming->Size = System::Drawing::Size(40, 14);
            this->fcgCBAudioEncTiming->TabIndex = 53;
            this->fcgCBAudioEncTiming->Text = L"処理順";
            // 
            // fcgCXAudioEncTiming
            // 
            this->fcgCXAudioEncTiming->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXAudioEncTiming->FormattingEnabled = true;
            this->fcgCXAudioEncTiming->Location = System::Drawing::Point(286, 51);
            this->fcgCXAudioEncTiming->Name = L"fcgCXAudioEncTiming";
            this->fcgCXAudioEncTiming->Size = System::Drawing::Size(68, 22);
            this->fcgCXAudioEncTiming->TabIndex = 52;
            this->fcgCXAudioEncTiming->Tag = L"chValue";
            // 
            // fcgCXAudioTempDir
            // 
            this->fcgCXAudioTempDir->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXAudioTempDir->FormattingEnabled = true;
            this->fcgCXAudioTempDir->Location = System::Drawing::Point(135, 208);
            this->fcgCXAudioTempDir->Name = L"fcgCXAudioTempDir";
            this->fcgCXAudioTempDir->Size = System::Drawing::Size(150, 22);
            this->fcgCXAudioTempDir->TabIndex = 46;
            this->fcgCXAudioTempDir->Tag = L"chValue";
            // 
            // fcgTXCustomAudioTempDir
            // 
            this->fcgTXCustomAudioTempDir->Location = System::Drawing::Point(64, 236);
            this->fcgTXCustomAudioTempDir->Name = L"fcgTXCustomAudioTempDir";
            this->fcgTXCustomAudioTempDir->Size = System::Drawing::Size(245, 21);
            this->fcgTXCustomAudioTempDir->TabIndex = 47;
            this->fcgTXCustomAudioTempDir->TextChanged += gcnew System::EventHandler(this, &frmConfig::fcgTXCustomAudioTempDir_TextChanged);
            // 
            // fcgBTCustomAudioTempDir
            // 
            this->fcgBTCustomAudioTempDir->Location = System::Drawing::Point(316, 234);
            this->fcgBTCustomAudioTempDir->Name = L"fcgBTCustomAudioTempDir";
            this->fcgBTCustomAudioTempDir->Size = System::Drawing::Size(29, 23);
            this->fcgBTCustomAudioTempDir->TabIndex = 49;
            this->fcgBTCustomAudioTempDir->Text = L"...";
            this->fcgBTCustomAudioTempDir->UseVisualStyleBackColor = true;
            this->fcgBTCustomAudioTempDir->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTCustomAudioTempDir_Click);
            // 
            // fcgCBAudioUsePipe
            // 
            this->fcgCBAudioUsePipe->AutoSize = true;
            this->fcgCBAudioUsePipe->Location = System::Drawing::Point(130, 134);
            this->fcgCBAudioUsePipe->Name = L"fcgCBAudioUsePipe";
            this->fcgCBAudioUsePipe->Size = System::Drawing::Size(73, 18);
            this->fcgCBAudioUsePipe->TabIndex = 42;
            this->fcgCBAudioUsePipe->Tag = L"chValue";
            this->fcgCBAudioUsePipe->Text = L"パイプ処理";
            this->fcgCBAudioUsePipe->UseVisualStyleBackColor = true;
            // 
            // fcgLBAudioBitrate
            // 
            this->fcgLBAudioBitrate->AutoSize = true;
            this->fcgLBAudioBitrate->Location = System::Drawing::Point(284, 161);
            this->fcgLBAudioBitrate->Name = L"fcgLBAudioBitrate";
            this->fcgLBAudioBitrate->Size = System::Drawing::Size(32, 14);
            this->fcgLBAudioBitrate->TabIndex = 50;
            this->fcgLBAudioBitrate->Text = L"kbps";
            // 
            // fcgNUAudioBitrate
            // 
            this->fcgNUAudioBitrate->Location = System::Drawing::Point(212, 157);
            this->fcgNUAudioBitrate->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1536, 0, 0, 0 });
            this->fcgNUAudioBitrate->Name = L"fcgNUAudioBitrate";
            this->fcgNUAudioBitrate->Size = System::Drawing::Size(65, 21);
            this->fcgNUAudioBitrate->TabIndex = 40;
            this->fcgNUAudioBitrate->Tag = L"chValue";
            this->fcgNUAudioBitrate->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            // 
            // fcgCBAudio2pass
            // 
            this->fcgCBAudio2pass->AutoSize = true;
            this->fcgCBAudio2pass->Location = System::Drawing::Point(59, 134);
            this->fcgCBAudio2pass->Name = L"fcgCBAudio2pass";
            this->fcgCBAudio2pass->Size = System::Drawing::Size(56, 18);
            this->fcgCBAudio2pass->TabIndex = 41;
            this->fcgCBAudio2pass->Tag = L"chValue";
            this->fcgCBAudio2pass->Text = L"2pass";
            this->fcgCBAudio2pass->UseVisualStyleBackColor = true;
            this->fcgCBAudio2pass->CheckedChanged += gcnew System::EventHandler(this, &frmConfig::fcgCBAudio2pass_CheckedChanged);
            // 
            // fcgCXAudioEncMode
            // 
            this->fcgCXAudioEncMode->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXAudioEncMode->FormattingEnabled = true;
            this->fcgCXAudioEncMode->Location = System::Drawing::Point(16, 156);
            this->fcgCXAudioEncMode->Name = L"fcgCXAudioEncMode";
            this->fcgCXAudioEncMode->Size = System::Drawing::Size(189, 22);
            this->fcgCXAudioEncMode->TabIndex = 39;
            this->fcgCXAudioEncMode->Tag = L"chValue";
            this->fcgCXAudioEncMode->SelectedIndexChanged += gcnew System::EventHandler(this, &frmConfig::fcgCXAudioEncMode_SelectedIndexChanged);
            // 
            // fcgLBAudioEncMode
            // 
            this->fcgLBAudioEncMode->AutoSize = true;
            this->fcgLBAudioEncMode->Location = System::Drawing::Point(4, 136);
            this->fcgLBAudioEncMode->Name = L"fcgLBAudioEncMode";
            this->fcgLBAudioEncMode->Size = System::Drawing::Size(32, 14);
            this->fcgLBAudioEncMode->TabIndex = 48;
            this->fcgLBAudioEncMode->Text = L"モード";
            // 
            // fcgBTAudioEncoderPath
            // 
            this->fcgBTAudioEncoderPath->Location = System::Drawing::Point(324, 90);
            this->fcgBTAudioEncoderPath->Name = L"fcgBTAudioEncoderPath";
            this->fcgBTAudioEncoderPath->Size = System::Drawing::Size(30, 23);
            this->fcgBTAudioEncoderPath->TabIndex = 38;
            this->fcgBTAudioEncoderPath->Text = L"...";
            this->fcgBTAudioEncoderPath->UseVisualStyleBackColor = true;
            this->fcgBTAudioEncoderPath->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTAudioEncoderPath_Click);
            // 
            // fcgTXAudioEncoderPath
            // 
            this->fcgTXAudioEncoderPath->AllowDrop = true;
            this->fcgTXAudioEncoderPath->Location = System::Drawing::Point(16, 92);
            this->fcgTXAudioEncoderPath->Name = L"fcgTXAudioEncoderPath";
            this->fcgTXAudioEncoderPath->Size = System::Drawing::Size(303, 21);
            this->fcgTXAudioEncoderPath->TabIndex = 37;
            this->fcgTXAudioEncoderPath->TextChanged += gcnew System::EventHandler(this, &frmConfig::fcgTXAudioEncoderPath_TextChanged);
            this->fcgTXAudioEncoderPath->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_DragDrop);
            this->fcgTXAudioEncoderPath->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_Enter);
            // 
            // fcgLBAudioEncoderPath
            // 
            this->fcgLBAudioEncoderPath->AutoSize = true;
            this->fcgLBAudioEncoderPath->Location = System::Drawing::Point(12, 75);
            this->fcgLBAudioEncoderPath->Name = L"fcgLBAudioEncoderPath";
            this->fcgLBAudioEncoderPath->Size = System::Drawing::Size(49, 14);
            this->fcgLBAudioEncoderPath->TabIndex = 44;
            this->fcgLBAudioEncoderPath->Text = L"～の指定";
            // 
            // fcgCBAudioOnly
            // 
            this->fcgCBAudioOnly->AutoSize = true;
            this->fcgCBAudioOnly->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->fcgCBAudioOnly->Location = System::Drawing::Point(252, 5);
            this->fcgCBAudioOnly->Name = L"fcgCBAudioOnly";
            this->fcgCBAudioOnly->Size = System::Drawing::Size(89, 18);
            this->fcgCBAudioOnly->TabIndex = 34;
            this->fcgCBAudioOnly->Tag = L"chValue";
            this->fcgCBAudioOnly->Text = L"音声のみ出力";
            this->fcgCBAudioOnly->UseVisualStyleBackColor = true;
            // 
            // fcgCBFAWCheck
            // 
            this->fcgCBFAWCheck->AutoSize = true;
            this->fcgCBFAWCheck->Location = System::Drawing::Point(252, 28);
            this->fcgCBFAWCheck->Name = L"fcgCBFAWCheck";
            this->fcgCBFAWCheck->Size = System::Drawing::Size(81, 18);
            this->fcgCBFAWCheck->TabIndex = 36;
            this->fcgCBFAWCheck->Tag = L"chValue";
            this->fcgCBFAWCheck->Text = L"FAWCheck";
            this->fcgCBFAWCheck->UseVisualStyleBackColor = true;
            // 
            // fcgCXAudioEncoder
            // 
            this->fcgCXAudioEncoder->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXAudioEncoder->FormattingEnabled = true;
            this->fcgCXAudioEncoder->Location = System::Drawing::Point(17, 34);
            this->fcgCXAudioEncoder->Name = L"fcgCXAudioEncoder";
            this->fcgCXAudioEncoder->Size = System::Drawing::Size(172, 22);
            this->fcgCXAudioEncoder->TabIndex = 32;
            this->fcgCXAudioEncoder->Tag = L"chValue";
            this->fcgCXAudioEncoder->SelectedIndexChanged += gcnew System::EventHandler(this, &frmConfig::fcgCXAudioEncoder_SelectedIndexChanged);
            // 
            // fcgLBAudioEncoder
            // 
            this->fcgLBAudioEncoder->AutoSize = true;
            this->fcgLBAudioEncoder->Location = System::Drawing::Point(5, 14);
            this->fcgLBAudioEncoder->Name = L"fcgLBAudioEncoder";
            this->fcgLBAudioEncoder->Size = System::Drawing::Size(48, 14);
            this->fcgLBAudioEncoder->TabIndex = 33;
            this->fcgLBAudioEncoder->Text = L"エンコーダ";
            // 
            // fcgLBAudioTemp
            // 
            this->fcgLBAudioTemp->AutoSize = true;
            this->fcgLBAudioTemp->Location = System::Drawing::Point(7, 211);
            this->fcgLBAudioTemp->Name = L"fcgLBAudioTemp";
            this->fcgLBAudioTemp->Size = System::Drawing::Size(114, 14);
            this->fcgLBAudioTemp->TabIndex = 51;
            this->fcgLBAudioTemp->Text = L"音声一時ファイル出力先";
            // 
            // fcgtabPageAudioOther
            // 
            this->fcgtabPageAudioOther->Controls->Add(this->panel2);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgLBBatAfterAudioString);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgLBBatBeforeAudioString);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgBTBatAfterAudioPath);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgTXBatAfterAudioPath);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgLBBatAfterAudioPath);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgCBRunBatAfterAudio);
            this->fcgtabPageAudioOther->Controls->Add(this->panel1);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgBTBatBeforeAudioPath);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgTXBatBeforeAudioPath);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgLBBatBeforeAudioPath);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgCBRunBatBeforeAudio);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgCXAudioPriority);
            this->fcgtabPageAudioOther->Controls->Add(this->fcgLBAudioPriority);
            this->fcgtabPageAudioOther->Location = System::Drawing::Point(4, 23);
            this->fcgtabPageAudioOther->Name = L"fcgtabPageAudioOther";
            this->fcgtabPageAudioOther->Padding = System::Windows::Forms::Padding(3);
            this->fcgtabPageAudioOther->Size = System::Drawing::Size(376, 269);
            this->fcgtabPageAudioOther->TabIndex = 1;
            this->fcgtabPageAudioOther->Text = L"その他";
            this->fcgtabPageAudioOther->UseVisualStyleBackColor = true;
            // 
            // panel2
            // 
            this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel2->Location = System::Drawing::Point(18, 126);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(342, 1);
            this->panel2->TabIndex = 61;
            // 
            // fcgLBBatAfterAudioString
            // 
            this->fcgLBBatAfterAudioString->AutoSize = true;
            this->fcgLBBatAfterAudioString->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
            this->fcgLBBatAfterAudioString->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->fcgLBBatAfterAudioString->Location = System::Drawing::Point(304, 208);
            this->fcgLBBatAfterAudioString->Name = L"fcgLBBatAfterAudioString";
            this->fcgLBBatAfterAudioString->Size = System::Drawing::Size(27, 15);
            this->fcgLBBatAfterAudioString->TabIndex = 60;
            this->fcgLBBatAfterAudioString->Text = L" 後& ";
            this->fcgLBBatAfterAudioString->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            // 
            // fcgLBBatBeforeAudioString
            // 
            this->fcgLBBatBeforeAudioString->AutoSize = true;
            this->fcgLBBatBeforeAudioString->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(128)));
            this->fcgLBBatBeforeAudioString->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->fcgLBBatBeforeAudioString->Location = System::Drawing::Point(304, 139);
            this->fcgLBBatBeforeAudioString->Name = L"fcgLBBatBeforeAudioString";
            this->fcgLBBatBeforeAudioString->Size = System::Drawing::Size(27, 15);
            this->fcgLBBatBeforeAudioString->TabIndex = 51;
            this->fcgLBBatBeforeAudioString->Text = L" 前& ";
            this->fcgLBBatBeforeAudioString->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            // 
            // fcgBTBatAfterAudioPath
            // 
            this->fcgBTBatAfterAudioPath->Location = System::Drawing::Point(330, 231);
            this->fcgBTBatAfterAudioPath->Name = L"fcgBTBatAfterAudioPath";
            this->fcgBTBatAfterAudioPath->Size = System::Drawing::Size(30, 23);
            this->fcgBTBatAfterAudioPath->TabIndex = 59;
            this->fcgBTBatAfterAudioPath->Tag = L"chValue";
            this->fcgBTBatAfterAudioPath->Text = L"...";
            this->fcgBTBatAfterAudioPath->UseVisualStyleBackColor = true;
            this->fcgBTBatAfterAudioPath->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTBatAfterAudioPath_Click);
            // 
            // fcgTXBatAfterAudioPath
            // 
            this->fcgTXBatAfterAudioPath->AllowDrop = true;
            this->fcgTXBatAfterAudioPath->Location = System::Drawing::Point(126, 232);
            this->fcgTXBatAfterAudioPath->Name = L"fcgTXBatAfterAudioPath";
            this->fcgTXBatAfterAudioPath->Size = System::Drawing::Size(202, 21);
            this->fcgTXBatAfterAudioPath->TabIndex = 58;
            this->fcgTXBatAfterAudioPath->Tag = L"chValue";
            this->fcgTXBatAfterAudioPath->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_DragDrop);
            this->fcgTXBatAfterAudioPath->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_Enter);
            // 
            // fcgLBBatAfterAudioPath
            // 
            this->fcgLBBatAfterAudioPath->AutoSize = true;
            this->fcgLBBatAfterAudioPath->Location = System::Drawing::Point(40, 236);
            this->fcgLBBatAfterAudioPath->Name = L"fcgLBBatAfterAudioPath";
            this->fcgLBBatAfterAudioPath->Size = System::Drawing::Size(61, 14);
            this->fcgLBBatAfterAudioPath->TabIndex = 57;
            this->fcgLBBatAfterAudioPath->Text = L"バッチファイル";
            // 
            // fcgCBRunBatAfterAudio
            // 
            this->fcgCBRunBatAfterAudio->AutoSize = true;
            this->fcgCBRunBatAfterAudio->Location = System::Drawing::Point(18, 207);
            this->fcgCBRunBatAfterAudio->Name = L"fcgCBRunBatAfterAudio";
            this->fcgCBRunBatAfterAudio->Size = System::Drawing::Size(201, 18);
            this->fcgCBRunBatAfterAudio->TabIndex = 55;
            this->fcgCBRunBatAfterAudio->Tag = L"chValue";
            this->fcgCBRunBatAfterAudio->Text = L"音声エンコード終了後、バッチ処理を行う";
            this->fcgCBRunBatAfterAudio->UseVisualStyleBackColor = true;
            // 
            // panel1
            // 
            this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel1->Location = System::Drawing::Point(18, 196);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(342, 1);
            this->panel1->TabIndex = 54;
            // 
            // fcgBTBatBeforeAudioPath
            // 
            this->fcgBTBatBeforeAudioPath->Location = System::Drawing::Point(330, 164);
            this->fcgBTBatBeforeAudioPath->Name = L"fcgBTBatBeforeAudioPath";
            this->fcgBTBatBeforeAudioPath->Size = System::Drawing::Size(30, 23);
            this->fcgBTBatBeforeAudioPath->TabIndex = 53;
            this->fcgBTBatBeforeAudioPath->Tag = L"chValue";
            this->fcgBTBatBeforeAudioPath->Text = L"...";
            this->fcgBTBatBeforeAudioPath->UseVisualStyleBackColor = true;
            this->fcgBTBatBeforeAudioPath->Click += gcnew System::EventHandler(this, &frmConfig::fcgBTBatBeforeAudioPath_Click);
            // 
            // fcgTXBatBeforeAudioPath
            // 
            this->fcgTXBatBeforeAudioPath->AllowDrop = true;
            this->fcgTXBatBeforeAudioPath->Location = System::Drawing::Point(126, 164);
            this->fcgTXBatBeforeAudioPath->Name = L"fcgTXBatBeforeAudioPath";
            this->fcgTXBatBeforeAudioPath->Size = System::Drawing::Size(202, 21);
            this->fcgTXBatBeforeAudioPath->TabIndex = 52;
            this->fcgTXBatBeforeAudioPath->Tag = L"chValue";
            this->fcgTXBatBeforeAudioPath->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_DragDrop);
            this->fcgTXBatBeforeAudioPath->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &frmConfig::fcgSetDragDropFilename_Enter);
            // 
            // fcgLBBatBeforeAudioPath
            // 
            this->fcgLBBatBeforeAudioPath->AutoSize = true;
            this->fcgLBBatBeforeAudioPath->Location = System::Drawing::Point(40, 167);
            this->fcgLBBatBeforeAudioPath->Name = L"fcgLBBatBeforeAudioPath";
            this->fcgLBBatBeforeAudioPath->Size = System::Drawing::Size(61, 14);
            this->fcgLBBatBeforeAudioPath->TabIndex = 50;
            this->fcgLBBatBeforeAudioPath->Text = L"バッチファイル";
            // 
            // fcgCBRunBatBeforeAudio
            // 
            this->fcgCBRunBatBeforeAudio->AutoSize = true;
            this->fcgCBRunBatBeforeAudio->Location = System::Drawing::Point(18, 139);
            this->fcgCBRunBatBeforeAudio->Name = L"fcgCBRunBatBeforeAudio";
            this->fcgCBRunBatBeforeAudio->Size = System::Drawing::Size(201, 18);
            this->fcgCBRunBatBeforeAudio->TabIndex = 48;
            this->fcgCBRunBatBeforeAudio->Tag = L"chValue";
            this->fcgCBRunBatBeforeAudio->Text = L"音声エンコード開始前、バッチ処理を行う";
            this->fcgCBRunBatBeforeAudio->UseVisualStyleBackColor = true;
            // 
            // fcgCXAudioPriority
            // 
            this->fcgCXAudioPriority->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->fcgCXAudioPriority->FormattingEnabled = true;
            this->fcgCXAudioPriority->Location = System::Drawing::Point(156, 20);
            this->fcgCXAudioPriority->Name = L"fcgCXAudioPriority";
            this->fcgCXAudioPriority->Size = System::Drawing::Size(136, 22);
            this->fcgCXAudioPriority->TabIndex = 47;
            this->fcgCXAudioPriority->Tag = L"chValue";
            // 
            // fcgLBAudioPriority
            // 
            this->fcgLBAudioPriority->AutoSize = true;
            this->fcgLBAudioPriority->Location = System::Drawing::Point(29, 23);
            this->fcgLBAudioPriority->Name = L"fcgLBAudioPriority";
            this->fcgLBAudioPriority->Size = System::Drawing::Size(62, 14);
            this->fcgLBAudioPriority->TabIndex = 46;
            this->fcgLBAudioPriority->Text = L"音声優先度";
            // 
            // frmConfig
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
            this->ClientSize = System::Drawing::Size(1008, 577);
            this->Controls->Add(this->fcgtabControlAudio);
            this->Controls->Add(this->fcgLBguiExBlog);
            this->Controls->Add(this->fcgtabControlMux);
            this->Controls->Add(this->fcgtabControlNVEnc);
            this->Controls->Add(this->fcgLBVersion);
            this->Controls->Add(this->fcgLBVersionDate);
            this->Controls->Add(this->fcgBTDefault);
            this->Controls->Add(this->fcgBTOK);
            this->Controls->Add(this->fcgBTCancel);
            this->Controls->Add(this->fcgTXCmd);
            this->Controls->Add(this->fcgtoolStripSettings);
            this->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(128)));
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->Name = L"frmConfig";
            this->ShowIcon = false;
            this->Text = L"Aviutl 出力 プラグイン";
            this->Load += gcnew System::EventHandler(this, &frmConfig::frmConfig_Load);
            this->fcgtoolStripSettings->ResumeLayout(false);
            this->fcgtoolStripSettings->PerformLayout();
            this->fcgtabControlMux->ResumeLayout(false);
            this->fcgtabPageMP4->ResumeLayout(false);
            this->fcgtabPageMP4->PerformLayout();
            this->fcgtabPageMKV->ResumeLayout(false);
            this->fcgtabPageMKV->PerformLayout();
            this->fcgtabPageMPG->ResumeLayout(false);
            this->fcgtabPageMPG->PerformLayout();
            this->fcgtabPageMux->ResumeLayout(false);
            this->fcgtabPageMux->PerformLayout();
            this->fcgtabPageBat->ResumeLayout(false);
            this->fcgtabPageBat->PerformLayout();
            this->fcgtabControlNVEnc->ResumeLayout(false);
            this->tabPageVideoEnc->ResumeLayout(false);
            this->tabPageVideoEnc->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNULookaheadDepth))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUAQStrength))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVBVBufsize))->EndInit();
            this->fcgGroupBoxAspectRatio->ResumeLayout(false);
            this->fcgGroupBoxAspectRatio->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUAspectRatioY))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUAspectRatioX))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNURefFrames))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUBframes))->EndInit();
            this->fcgPNBitrate->ResumeLayout(false);
            this->fcgPNBitrate->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUBitrate))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUMaxkbps))->EndInit();
            this->fcgPNQP->ResumeLayout(false);
            this->fcgPNQP->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPI))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPP))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUQPB))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUGopLength))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgPBNVEncLogoEnabled))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgPBNVEncLogoDisabled))->EndInit();
            this->fcgGroupBoxQulaityStg->ResumeLayout(false);
            this->fcgPNH264->ResumeLayout(false);
            this->fcgPNH264->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUSlices))->EndInit();
            this->fcggroupBoxColorH264->ResumeLayout(false);
            this->fcggroupBoxColorH264->PerformLayout();
            this->fcgPNHEVC->ResumeLayout(false);
            this->fcgPNHEVC->PerformLayout();
            this->fcggroupBoxColorHEVC->ResumeLayout(false);
            this->fcggroupBoxColorHEVC->PerformLayout();
            this->tabPageExOpt->ResumeLayout(false);
            this->tabPageExOpt->PerformLayout();
            this->fcggroupBoxVpp->ResumeLayout(false);
            this->fcggroupBoxVpp->PerformLayout();
            this->fcggroupBoxVppDenoise->ResumeLayout(false);
            this->fcgPNVppDenoiseKnn->ResumeLayout(false);
            this->fcgPNVppDenoiseKnn->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoiseKnnThreshold))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoiseKnnStrength))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoiseKnnRadius))->EndInit();
            this->fcgPNVppDenoisePmd->ResumeLayout(false);
            this->fcgPNVppDenoisePmd->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoisePmdThreshold))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoisePmdStrength))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppDenoisePmdApplyCount))->EndInit();
            this->fcggroupBoxResize->ResumeLayout(false);
            this->fcggroupBoxResize->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppResizeHeight))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUVppResizeWidth))->EndInit();
            this->tabPageNVEncFeatures->ResumeLayout(false);
            this->tabPageNVEncFeatures->PerformLayout();
            this->fcgTabControlFeatures->ResumeLayout(false);
            this->fcgTabPageH264->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgDGVFeaturesH264))->EndInit();
            this->fcgTabPageHEVC->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgDGVFeaturesHEVC))->EndInit();
            this->fcgCSExeFiles->ResumeLayout(false);
            this->fcgtabControlAudio->ResumeLayout(false);
            this->fcgtabPageAudioMain->ResumeLayout(false);
            this->fcgtabPageAudioMain->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fcgNUAudioBitrate))->EndInit();
            this->fcgtabPageAudioOther->ResumeLayout(false);
            this->fcgtabPageAudioOther->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private:
        delegate void SetEnvironmentInfoDelegate();
        String^ StrCPUInfo;
        String^ StrGPUInfo;
        SetEnvironmentInfoDelegate ^getEnvironmentInfoDelegate;

        nvfeature_t featureCache;
        DataTable^ dataTableNVEncFeaturesH264;
        DataTable^ dataTableNVEncFeaturesHEVC;
        
        
        const SYSTEM_DATA *sys_dat;
        CONF_GUIEX *conf;
        LocalSettings LocalStg;
        bool CurrentPipeEnabled;
        bool stgChanged;
        String^ CurrentStgDir;
        ToolStripMenuItem^ CheckedStgMenuItem;
        CONF_GUIEX *cnf_stgSelected;
        String^ lastQualityStr;
#ifdef HIDE_MPEG2
        TabPage^ tabPageMpgMux;
#endif
    private:
        System::Int32 GetCurrentAudioDefaultBitrate();
        delegate System::Void qualityTimerChangeDelegate();
        System::Void InitComboBox();
        System::Void setAudioDisplay();
        System::Void AudioEncodeModeChanged();
        System::Void InitStgFileList();
        System::Void RebuildStgFileDropDown(String^ stgDir);
        System::Void RebuildStgFileDropDown(ToolStripDropDownItem^ TS, String^ dir);
        System::Void SetLocalStg();
        System::Void LoadLocalStg();
        System::Void SaveLocalStg();
        System::Boolean CheckLocalStg();
        System::Void SetTXMaxLen(TextBox^ TX, int max_len);
        System::Void SetTXMaxLenAll();
        System::Void InitForm();
        System::Void ConfToFrm(CONF_GUIEX *cnf);
        System::Void FrmToConf(CONF_GUIEX *cnf);
        System::Void SetChangedEvent(Control^ control, System::EventHandler^ _event);
        System::Void SetAllCheckChangedEvents(Control ^top);
        System::Void SaveToStgFile(String^ stgName);
        System::Void DeleteStgFile(ToolStripMenuItem^ mItem);
        System::Boolean EnableSettingsNoteChange(bool Enable);
        System::Void fcgTSLSettingsNotes_DoubleClick(System::Object^  sender, System::EventArgs^  e);
        System::Void fcgTSTSettingsNotes_Leave(System::Object^  sender, System::EventArgs^  e);
        System::Void fcgTSTSettingsNotes_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
        System::Void fcgTSTSettingsNotes_TextChanged(System::Object^  sender, System::EventArgs^  e);
        System::Void GetfcgTSLSettingsNotes(char *notes, int nSize);
        System::Void SetfcgTSLSettingsNotes(const char *notes);
        System::Void SetfcgTSLSettingsNotes(String^ notes);
        System::Void fcgTSBSave_Click(System::Object^  sender, System::EventArgs^  e);
        System::Void fcgTSBSaveNew_Click(System::Object^  sender, System::EventArgs^  e);
        System::Void fcgTSBDelete_Click(System::Object^  sender, System::EventArgs^  e);
        System::Void fcgTSSettings_DropDownItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e);
        System::Void UncheckAllDropDownItem(ToolStripItem^ mItem);
        ToolStripMenuItem^ fcgTSSettingsSearchItem(String^ stgPath, ToolStripItem^ mItem);
        ToolStripMenuItem^ fcgTSSettingsSearchItem(String^ stgPath);
        System::Void CheckTSSettingsDropDownItem(ToolStripMenuItem^ mItem);
        System::Void CheckTSItemsEnabled(CONF_GUIEX *current_conf);
        System::Void fcgChangeMuxerVisible(System::Object^  sender, System::EventArgs^  e);
        System::Void SetHelpToolTips();
        System::Void ShowExehelp(String^ ExePath, String^ args);
        System::Void fcgTSBOtherSettings_Click(System::Object^  sender, System::EventArgs^  e);
        System::Void fcgChangeEnabled(System::Object^  sender, System::EventArgs^  e);
        System::Void fcgTSBBitrateCalc_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
        System::Void CloseBitrateCalc();
        System::Void SetfbcBTABEnable(bool enable, int max);
        System::Void SetfbcBTVBEnable(bool enable);
        System::Void fcgCBAudio2pass_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
        System::Void fcgCXAudioEncoder_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
        System::Void fcgCXAudioEncMode_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
        System::Void AdjustLocation();
        System::Void ActivateToolTip(bool Enable);
        System::Void SetStgEscKey(bool Enable);
        System::Void SetToolStripEvents(ToolStrip^ TS, System::Windows::Forms::MouseEventHandler^ _event);
        System::Void SetEnvironmentInfo();
        System::Void SetupFeatureTable();
        System::Void fcgCodecChanged(System::Object^  sender, System::EventArgs^  e);
    public:
        System::Void InitData(CONF_GUIEX *set_config, const SYSTEM_DATA *system_data);
        System::Void SetVideoBitrate(int bitrate);
        System::Void SetAudioBitrate(int bitrate);
        System::Void InformfbcClosed();
    private:
        System::Void fcgTSItem_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
            EnableSettingsNoteChange(false);
        }
    private:
        System::Void frmConfig_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
            if (e->KeyCode == Keys::Escape)
                this->Close();
        }
    private:
        System::Void NUSelectAll(System::Object^  sender, System::EventArgs^  e) {
             NumericUpDown^ NU = dynamic_cast<NumericUpDown^>(sender);
             NU->Select(0, NU->Text->Length);
         }
    private:
        System::Void setComboBox(ComboBox^ CX, const X264_OPTION_STR * list) {
            CX->BeginUpdate();
            CX->Items->Clear();
            for (int i = 0; list[i].desc; i++)
                CX->Items->Add(String(list[i].desc).ToString());
            CX->EndUpdate();
        }
    private:
        System::Void setComboBox(ComboBox^ CX, const CX_DESC * list) {
            CX->BeginUpdate();
            CX->Items->Clear();
            for (int i = 0; list[i].desc; i++)
                CX->Items->Add(String(list[i].desc).ToString());
            CX->EndUpdate();
        }
    private:
        template<size_t size>
        System::Void setComboBox(ComboBox^ CX, const guid_desc (&list)[size]) {
            CX->BeginUpdate();
            CX->Items->Clear();
            for (int i = 0; i < size; i++)
                CX->Items->Add(String(list[i].desc).ToString());
            CX->EndUpdate();
        }
    private:
        System::Void setComboBox(ComboBox^ CX, const char * const * list) {
            CX->BeginUpdate();
            CX->Items->Clear();
            for (int i = 0; list[i]; i++)
                CX->Items->Add(String(list[i]).ToString());
            CX->EndUpdate();
        }
    private:
        System::Void setComboBox(ComboBox^ CX, const WCHAR * const * list) {
            CX->BeginUpdate();
            CX->Items->Clear();
            for (int i = 0; list[i]; i++)
                CX->Items->Add(String(list[i]).ToString());
            CX->EndUpdate();
        }
    private:
        System::Void setPriorityList(ComboBox^ CX) {
            CX->BeginUpdate();
            CX->Items->Clear();
            for (int i = 0; priority_table[i].text; i++)
                CX->Items->Add(String(priority_table[i].text).ToString());
            CX->EndUpdate();
        }
    private:
        System::Void setMuxerCmdExNames(ComboBox^ CX, int muxer_index) {
            CX->BeginUpdate();
            CX->Items->Clear();
            MUXER_SETTINGS *mstg = &sys_dat->exstg->s_mux[muxer_index];
            for (int i = 0; i < mstg->ex_count; i++)
                CX->Items->Add(String(mstg->ex_cmd[i].name).ToString());
            CX->EndUpdate();
        }
    private:
        System::Void setAudioEncoderNames() {
            fcgCXAudioEncoder->BeginUpdate();
            fcgCXAudioEncoder->Items->Clear();
            //fcgCXAudioEncoder->Items->AddRange(reinterpret_cast<array<String^>^>(LocalStg.audEncName->ToArray(String::typeid)));
            fcgCXAudioEncoder->Items->AddRange(LocalStg.audEncName->ToArray());
            fcgCXAudioEncoder->EndUpdate();
        }
    private:
        System::Void TX_LimitbyBytes(System::Object^  sender, System::ComponentModel::CancelEventArgs^ e) {
            int maxLength = 0;
            int stringBytes = 0;
            TextBox^ TX = nullptr;
            if ((TX = dynamic_cast<TextBox^>(sender)) == nullptr)
                return;
            stringBytes = CountStringBytes(TX->Text);
            maxLength = TX->MaxLength;
            if (stringBytes > maxLength - 1) {
                e->Cancel = true;
                MessageBox::Show(this, L"入力された文字数が多すぎます。減らしてください。", L"エラー", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
    private:
        System::Boolean openExeFile(TextBox^ TX, String^ ExeName) {
            //WinXPにおいて、OpenFileDialogはCurrentDirctoryを勝手に変更しやがるので、
            //一度保存し、あとから再適用する
            String^ CurrentDir = Directory::GetCurrentDirectory();
            OpenFileDialog ofd;
            ofd.Multiselect = false;
            ofd.FileName = ExeName;
            ofd.Filter = MakeExeFilter(ExeName);
            if (Directory::Exists(LocalStg.LastAppDir))
                ofd.InitialDirectory = Path::GetFullPath(LocalStg.LastAppDir);
            else if (File::Exists(TX->Text))
                ofd.InitialDirectory = Path::GetFullPath(Path::GetDirectoryName(TX->Text));
            else
                ofd.InitialDirectory = String(sys_dat->aviutl_dir).ToString();
            bool ret = (ofd.ShowDialog() == System::Windows::Forms::DialogResult::OK);
            if (ret) {
                if (sys_dat->exstg->s_local.get_relative_path)
                    ofd.FileName = GetRelativePath(ofd.FileName, CurrentDir);
                LocalStg.LastAppDir = Path::GetDirectoryName(Path::GetFullPath(ofd.FileName));
                TX->Text = ofd.FileName;
                TX->SelectionStart = TX->Text->Length;
            }
            Directory::SetCurrentDirectory(CurrentDir);
            return ret;
        }
    private: 
        System::Void fcgBTMP4MuxerPath_Click(System::Object^  sender, System::EventArgs^  e) {
            openExeFile(fcgTXMP4MuxerPath, LocalStg.MP4MuxerExeName);
        }
    private: 
        System::Void fcgBTTC2MP4Path_Click(System::Object^  sender, System::EventArgs^  e) {
            openExeFile(fcgTXTC2MP4Path, LocalStg.TC2MP4ExeName);
        }
    private:
        System::Void fcgBTMP4RawMuxerPath_Click(System::Object^  sender, System::EventArgs^  e) {
            openExeFile(fcgTXMP4RawPath, LocalStg.MP4RawExeName);
        }
    private: 
        System::Void fcgBTAudioEncoderPath_Click(System::Object^  sender, System::EventArgs^  e) {
            int index = fcgCXAudioEncoder->SelectedIndex;
            openExeFile(fcgTXAudioEncoderPath, LocalStg.audEncExeName[index]);
        }
    private: 
        System::Void fcgBTMKVMuxerPath_Click(System::Object^  sender, System::EventArgs^  e) {
            openExeFile(fcgTXMKVMuxerPath, LocalStg.MKVMuxerExeName);
        }
    private:
        System::Void fcgBTMPGMuxerPath_Click(System::Object^  sender, System::EventArgs^  e) {
            openExeFile(fcgTXMPGMuxerPath, LocalStg.MPGMuxerExeName);
        }
    private:
        System::Void openTempFolder(TextBox^ TX) {
            FolderBrowserDialog^ fbd = fcgfolderBrowserTemp;
            if (Directory::Exists(TX->Text))
                fbd->SelectedPath = TX->Text;
            if (fbd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                if (sys_dat->exstg->s_local.get_relative_path)
                    fbd->SelectedPath = GetRelativePath(fbd->SelectedPath);
                TX->Text = fbd->SelectedPath;
                TX->SelectionStart = TX->Text->Length;
            }
        }
    private: 
        System::Void fcgBTCustomAudioTempDir_Click(System::Object^  sender, System::EventArgs^  e) {
            openTempFolder(fcgTXCustomAudioTempDir);
        }
    private: 
        System::Void fcgBTMP4BoxTempDir_Click(System::Object^  sender, System::EventArgs^  e) {
            openTempFolder(fcgTXMP4BoxTempDir);
        }
    private: 
        System::Void fcgBTCustomTempDir_Click(System::Object^  sender, System::EventArgs^  e) {
            openTempFolder(fcgTXCustomTempDir);
        }
    private:
        System::Boolean openAndSetFilePath(TextBox^ TX, String^ fileTypeName) {
            return openAndSetFilePath(TX, fileTypeName, nullptr, nullptr);
        }
    private:
        System::Boolean openAndSetFilePath(TextBox^ TX, String^ fileTypeName, String^ ext) {
            return openAndSetFilePath(TX, fileTypeName, ext, nullptr);
        }
    private:
        System::Boolean openAndSetFilePath(TextBox^ TX, String^ fileTypeName, String^ ext, String^ dir) {
            //WinXPにおいて、OpenFileDialogはCurrentDirctoryを勝手に変更しやがるので、
            //一度保存し、あとから再適用する
            String^ CurrentDir = Directory::GetCurrentDirectory();
            //設定
            if (ext == nullptr)
                ext = L".*";
            OpenFileDialog^ ofd = fcgOpenFileDialog;
            ofd->FileName = L"";
            if (dir != nullptr && Directory::Exists(dir))
                ofd->InitialDirectory = dir;
            if (TX->Text->Length) {
                String^ fileName = nullptr;
                try {
                    fileName = Path::GetFileName(TX->Text);
                } catch (...) {
                    //invalid charによる例外は破棄
                }
                if (fileName != nullptr)
                    ofd->FileName = fileName;
            }
            ofd->Multiselect = false;
            ofd->Filter = fileTypeName + L"(*" + ext + L")|*" + ext;
            bool ret = (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK);
            if (ret) {
                if (sys_dat->exstg->s_local.get_relative_path)
                    ofd->FileName = GetRelativePath(ofd->FileName, CurrentDir);
                TX->Text = ofd->FileName;
                TX->SelectionStart = TX->Text->Length;
            }
            Directory::SetCurrentDirectory(CurrentDir);
            return ret;
        }
    private:
        System::Void fcgBTBatAfterPath_Click(System::Object^  sender, System::EventArgs^  e) {
            if (openAndSetFilePath(fcgTXBatAfterPath, L"バッチファイル", ".bat", LocalStg.LastBatDir))
                LocalStg.LastBatDir = Path::GetDirectoryName(fcgTXBatAfterPath->Text);
        }
    private:
        System::Void fcgBTBatBeforePath_Click(System::Object^  sender, System::EventArgs^  e) {
            if (openAndSetFilePath(fcgTXBatBeforePath, L"バッチファイル", ".bat", LocalStg.LastBatDir))
                LocalStg.LastBatDir = Path::GetDirectoryName(fcgTXBatBeforePath->Text);
        }
    private:
        System::Void fcgBTBatBeforeAudioPath_Click(System::Object^  sender, System::EventArgs^  e) {
            if (openAndSetFilePath(fcgTXBatBeforeAudioPath, L"バッチファイル", ".bat", LocalStg.LastBatDir))
                LocalStg.LastBatDir = Path::GetDirectoryName(fcgTXBatBeforeAudioPath->Text);
        }
    private:
        System::Void fcgBTBatAfterAudioPath_Click(System::Object^  sender, System::EventArgs^  e) {
            if (openAndSetFilePath(fcgTXBatAfterAudioPath, L"バッチファイル", ".bat", LocalStg.LastBatDir))
                LocalStg.LastBatDir = Path::GetDirectoryName(fcgTXBatAfterAudioPath->Text);
        }
    private:
        System::Void SetCXIndex(ComboBox^ CX, int index) {
            CX->SelectedIndex = clamp(index, 0, CX->Items->Count - 1);
        }
    private:
        System::Void SetNUValue(NumericUpDown^ NU, Decimal d) {
            NU->Value = clamp(d, NU->Minimum, NU->Maximum);
        }
    private:
        System::Void SetNUValue(NumericUpDown^ NU, int i) {
            NU->Value = clamp(Convert::ToDecimal(i), NU->Minimum, NU->Maximum);
        }
    private:
        System::Void SetNUValue(NumericUpDown^ NU, unsigned int i) {
            NU->Value = clamp(Convert::ToDecimal(i), NU->Minimum, NU->Maximum);
        }
    private:
        System::Void SetNUValue(NumericUpDown^ NU, float f) {
            NU->Value = clamp(Convert::ToDecimal(f), NU->Minimum, NU->Maximum);
        }
    private: 
        System::Void frmConfig_Load(System::Object^  sender, System::EventArgs^  e) {
            InitForm();
        }
    private: 
        System::Void fcgBTOK_Click(System::Object^  sender, System::EventArgs^  e) {
            if (CheckLocalStg())
                return;
            init_CONF_GUIEX(conf, false);
            FrmToConf(conf);
            SaveLocalStg();
            ZeroMemory(conf->oth.notes, sizeof(conf->oth.notes));
            this->Close();
        }
    private: 
        System::Void fcgBTCancel_Click(System::Object^  sender, System::EventArgs^  e) {
            this->Close();
        }
    private: 
        System::Void fcgBTDefault_Click(System::Object^  sender, System::EventArgs^  e) {
            init_CONF_GUIEX(conf, FALSE);
            ConfToFrm(conf);
        }
    private:
        System::Void ChangePresetNameDisplay(bool changed) {
            if (CheckedStgMenuItem != nullptr) {
                fcgTSSettings->Text = (changed) ? L"[" + CheckedStgMenuItem->Text + L"]*" : CheckedStgMenuItem->Text;
                fcgTSBSave->Enabled = changed;
            }
        }
    private:
        System::Void CheckOtherChanges(System::Object^  sender, System::EventArgs^  e) {
            if (CheckedStgMenuItem == nullptr)
                return;
            CONF_GUIEX check_change;
            init_CONF_GUIEX(&check_change, FALSE);
            FrmToConf(&check_change);
            ChangePresetNameDisplay(memcmp(&check_change, cnf_stgSelected, sizeof(CONF_GUIEX)) != 0);
        }
    private: 
        System::Void fcgTXCmd_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
            int offset = (fcgTXCmd->Multiline) ? -fcgTXCmdfulloffset : fcgTXCmdfulloffset;
            fcgTXCmd->Height += offset;
            this->Height += offset;
            fcgTXCmd->Multiline = !fcgTXCmd->Multiline;
        }
    private: 
        System::Void fcgTSSettings_Click(System::Object^  sender, System::EventArgs^  e) {
            if (EnableSettingsNoteChange(false))
                fcgTSSettings->ShowDropDown();
        }
    private: 
        System::Void fcgTXAudioEncoderPath_TextChanged(System::Object^  sender, System::EventArgs^  e) {
            LocalStg.audEncPath[fcgCXAudioEncoder->SelectedIndex] = fcgTXAudioEncoderPath->Text;
            fcgBTAudioEncoderPath->ContextMenuStrip = (File::Exists(fcgTXAudioEncoderPath->Text)) ? fcgCSExeFiles : nullptr;
        }
    private: 
        System::Void fcgTXMP4MuxerPath_TextChanged(System::Object^  sender, System::EventArgs^  e) {
            LocalStg.MP4MuxerPath = fcgTXMP4MuxerPath->Text;
            fcgBTMP4MuxerPath->ContextMenuStrip = (File::Exists(fcgTXMP4MuxerPath->Text)) ? fcgCSExeFiles : nullptr;
        }
    private: 
        System::Void fcgTXTC2MP4Path_TextChanged(System::Object^  sender, System::EventArgs^  e) {
            LocalStg.TC2MP4Path = fcgTXTC2MP4Path->Text;
            fcgBTTC2MP4Path->ContextMenuStrip = (File::Exists(fcgTXTC2MP4Path->Text)) ? fcgCSExeFiles : nullptr;
        }
    private:
        System::Void fcgTXMP4RawMuxerPath_TextChanged(System::Object^  sender, System::EventArgs^  e) {
            LocalStg.MP4RawPath = fcgTXMP4RawPath->Text;
            fcgBTMP4RawPath->ContextMenuStrip = (File::Exists(fcgTXMP4RawPath->Text)) ? fcgCSExeFiles : nullptr;
        }
    private: 
        System::Void fcgTXMKVMuxerPath_TextChanged(System::Object^  sender, System::EventArgs^  e) {
            LocalStg.MKVMuxerPath = fcgTXMKVMuxerPath->Text;
            fcgBTMKVMuxerPath->ContextMenuStrip = (File::Exists(fcgTXMKVMuxerPath->Text)) ? fcgCSExeFiles : nullptr;
        }
    private:
        System::Void fcgTXMPGMuxerPath_TextChanged(System::Object^  sender, System::EventArgs^  e) {
            LocalStg.MPGMuxerPath = fcgTXMPGMuxerPath->Text;
            fcgBTMPGMuxerPath->ContextMenuStrip = (File::Exists(fcgTXMPGMuxerPath->Text)) ? fcgCSExeFiles : nullptr;
        }
    private: 
        System::Void fcgTXMP4BoxTempDir_TextChanged(System::Object^  sender, System::EventArgs^  e) {
            LocalStg.CustomMP4TmpDir = fcgTXMP4BoxTempDir->Text;
        }
    private: 
        System::Void fcgTXCustomAudioTempDir_TextChanged(System::Object^  sender, System::EventArgs^  e) {
            LocalStg.CustomAudTmpDir = fcgTXCustomAudioTempDir->Text;
        }
    private: 
        System::Void fcgTXCustomTempDir_TextChanged(System::Object^  sender, System::EventArgs^  e) {
            LocalStg.CustomTmpDir = fcgTXCustomTempDir->Text;
        }
    private:
        System::Void fcgSetDragDropFilename_Enter(System::Object^  sender, DragEventArgs^  e) {
            e->Effect = (e->Data->GetDataPresent(DataFormats::FileDrop)) ? DragDropEffects::Copy : DragDropEffects::None;
        }
    private:
        System::Void fcgSetDragDropFilename_DragDrop(System::Object^  sender, DragEventArgs^  e) {
            TextBox^ TX = dynamic_cast<TextBox^>(sender);
            array<System::String ^>^ filelist = dynamic_cast<array<System::String ^>^>(e->Data->GetData(DataFormats::FileDrop, false));
            if (filelist == nullptr || TX == nullptr)
                return;
            String^ filePath = filelist[0]; //複数だった場合は先頭のものを使用
            if (sys_dat->exstg->s_local.get_relative_path)
                filePath = GetRelativePath(filePath);
            TX->Text = filePath;
        }
    private:
        System::Void fcgTSExeFileshelp_Click(System::Object^  sender, System::EventArgs^  e) {
            System::Windows::Forms::ToolStripMenuItem^ TS = dynamic_cast<System::Windows::Forms::ToolStripMenuItem^>(sender);
            if (TS == nullptr) return;
            System::Windows::Forms::ContextMenuStrip^ CS = dynamic_cast<System::Windows::Forms::ContextMenuStrip^>(TS->Owner);
            if (CS == nullptr) return;

            //Name, args, Path の順番
            array<ExeControls>^ ControlList = {
                { fcgBTAudioEncoderPath->Name,   fcgTXAudioEncoderPath->Text,   sys_dat->exstg->s_aud[fcgCXAudioEncoder->SelectedIndex].cmd_help },
                { fcgBTMP4MuxerPath->Name,       fcgTXMP4MuxerPath->Text,       sys_dat->exstg->s_mux[MUXER_MP4].help_cmd },
                { fcgBTTC2MP4Path->Name,         fcgTXTC2MP4Path->Text,         sys_dat->exstg->s_mux[MUXER_TC2MP4].help_cmd },
                { fcgBTMP4RawPath->Name,         fcgTXMP4RawPath->Text,         sys_dat->exstg->s_mux[MUXER_MP4_RAW].help_cmd },
                { fcgBTMKVMuxerPath->Name,       fcgTXMKVMuxerPath->Text,       sys_dat->exstg->s_mux[MUXER_MKV].help_cmd },
                { fcgBTMPGMuxerPath->Name,       fcgTXMPGMuxerPath->Text,       sys_dat->exstg->s_mux[MUXER_MPG].help_cmd }
            };
            for (int i = 0; i < ControlList->Length; i++) {
                if (NULL == String::Compare(CS->SourceControl->Name, ControlList[i].Name)) {
                    ShowExehelp(ControlList[i].Path, String(ControlList[i].args).ToString());
                    return;
                }
            }
            MessageBox::Show(L"ヘルプ表示用のコマンドが設定されていません。", L"エラー", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    private:
        System::Void fcgLBguiExBlog_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
            fcgLBguiExBlog->LinkVisited = true;
            try {
                System::Diagnostics::Process::Start(String(sys_dat->exstg->blog_url).ToString());
            } catch (...) {
                //いちいちメッセージとか出さない
            };
        }
    private:
        System::Void fcgBTQualityStg_Click(System::Object^  sender, System::EventArgs^  e) {
            if (NULL == featureCache)
                return;
            CONF_GUIEX cnf;
            FrmToConf(&cnf);
            auto presetList = nvfeature_GetCachedNVEncCapability(featureCache);
            memcpy(&cnf.nvenc.enc_config, &presetList[fcgCXEncCodec->SelectedIndex].presetConfigs[fcgCXQualityPreset->SelectedIndex].presetCfg, sizeof(cnf.nvenc.enc_config));
            if (cnf.nvenc.enc_config.gopLength == UINT32_MAX) {
                cnf.nvenc.enc_config.gopLength = 0;
                cnf.nvenc.enc_config.encodeCodecConfig.h264Config.idrPeriod = 0;
                cnf.nvenc.enc_config.encodeCodecConfig.hevcConfig.idrPeriod = 0;
            }
            cnf.nvenc.codecConfig[fcgCXEncCodec->SelectedIndex] = cnf.nvenc.enc_config.encodeCodecConfig;
            //cnf.nvenc.enc_config.encodeCodecConfig.h264Config.sliceModeData = 1;
            //cnf.nvenc.enc_config.encodeCodecConfig.hevcConfig.sliceMode     = 0;
            //cnf.nvenc.enc_config.encodeCodecConfig.hevcConfig.sliceModeData = 0;
            ConfToFrm(&cnf);
        }
    };
}
