/*******************************************************************************
*
*  (C) COPYRIGHT AUTHORS, 2022 - 2024
*
*  TITLE:       KDUBASE.H
*
*  VERSION:     1.41
*
*  DATE:        30 Mar 2024
*
*  Base KDU definitions.
*
* THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
* ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
* TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
* PARTICULAR PURPOSE.
*
*******************************************************************************/

#pragma once

#pragma warning(disable: 4201)

typedef enum _KDU_SOURCEBASE {
    SourceBaseNone = 0,
    SourceBaseWinIo,
    SourceBaseWinRing0,
    SourceBasePhyMem,
    SourceBaseMapMem,
    SourceBaseRWEverything,
    SourceBaseMax
} KDU_SOURCEBASE;

typedef struct _KDU_DB_ENTRY {
    ULONG MinNtBuildNumberSupport;
    ULONG MaxNtBuildNumberSupport;
    ULONG ResourceId;
    ULONG ProviderId;
    ULONG VictimId;
    KDU_SOURCEBASE DrvSourceBase;
    union {
        ULONG Flags;
        struct {
            ULONG SupportHVCI : 1;
            ULONG SignatureWHQL : 1;
            ULONG IgnoreChecksum : 1;
            ULONG NoForcedSD : 1;
            ULONG NoUnloadSupported : 1;
            ULONG PML4FromLowStub : 1;
            ULONG NoVictim : 1;
            ULONG PhysMemoryBruteForce : 1;
            ULONG PreferPhysical : 1;
            ULONG PreferVirtual : 1;
            ULONG CompanionRequired : 1;
            ULONG UseSymbols : 1;
            ULONG OpenProcessSupported : 1;
            ULONG Reserved : 19;
        };
    };
    ULONG SupportedShellFlags;
    LPWSTR Desciption;
    LPWSTR DriverName; //only file name, e.g. PROCEXP
    LPWSTR DeviceName; //device name, e.g. PROCEXP152
    LPWSTR SignerName;
} KDU_DB_ENTRY, * PKDU_DB_ENTRY;

typedef struct _KDU_DB {
    ULONG NumberOfEntries;
    KDU_DB_ENTRY* Entries;
} KDU_DB, * PKDU_DB;

typedef struct _KDU_DB_VERSION {
    WORD MajorVersion;
    WORD MinorVersion;
    WORD Revision;
    WORD Build;
} KDU_DB_VERSION, * PKDU_DB_VERSION;

typedef struct _KDU_DB_RES_ENTRY {
    ULONG ResourceId;
    const void* Data;
    ULONG Size;
} KDU_DB_RES_ENTRY, * PKDU_DB_RES_ENTRY;

typedef struct _KDU_DB_RES {
    ULONG NumberOfEntries;
    KDU_DB_RES_ENTRY* Entries;
} KDU_DB_RES, * PKDU_DB_RES;