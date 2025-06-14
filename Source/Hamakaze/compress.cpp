/*******************************************************************************
*
*  (C) COPYRIGHT AUTHORS, 2015 - 2023
*
*  TITLE:       COMPRESS.CPP
*
*  VERSION:     1.31
*
*  DATE:        08 Apr 2023
*
*  Compression support routines.
*
* THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
* ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
* TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
* PARTICULAR PURPOSE.
*
*******************************************************************************/

#include "global.h"
#include <msdelta.h>

#pragma comment(lib, "msdelta.lib")

/*
* EncodeBuffer
*
* Purpose:
*
* Decrypt/Encrypt given buffer.
*
*/
VOID EncodeBuffer(
    _In_ PVOID Buffer,
    _In_ ULONG BufferSize,
    _In_ ULONG Key
)
{
    ULONG k, c;
    PUCHAR ptr;

    if ((Buffer == NULL) || (BufferSize == 0))
        return;

    k = Key;
    c = BufferSize;
    ptr = (PUCHAR)Buffer;

    do {
        *ptr ^= k;
        k = _rotl(k, 1);
        ptr++;
        --c;
    } while (c != 0);
}

/*
* KDULoadResource
*
* Purpose:
*
* Access and decompress resource.
*
* N.B. Use supHeapFree to release memory allocated for the decompressed buffer.
*
*/
PVOID KDULoadResource(
    _In_ ULONG_PTR ResourceId,
    _In_ PVOID DllHandle,
    _In_ PULONG DataSize,
    _In_ ULONG DecryptKey,
    _In_ BOOLEAN VerifyChecksum
)
{
    PBYTE dataPtr;
    ULONG dataSize = 0;
    SIZE_T decompressedSize = 0;

    if (DataSize)
        *DataSize = 0;

#ifdef _LIB
    PKDU_DB_RES_ENTRY pResEntry{};

    for (ULONG i = 0; i < gResTable.NumberOfEntries; ++i) {
        if (gResTable.Entries[i].ResourceId == ResourceId) {
            pResEntry = &gResTable.Entries[i];
            break;
        }
    }

    if (!pResEntry) {
#endif

    dataPtr = supQueryResourceData(ResourceId,
        DllHandle,
        &dataSize);

#ifdef _LIB
    } else {
        dataPtr = (PBYTE)pResEntry->Data;
        dataSize = pResEntry->Size;
    }
#endif

    if (dataPtr && dataSize) {

        dataPtr = (PBYTE)KDUDecompressResource(dataPtr,
            dataSize,
            &decompressedSize,
            DecryptKey,
            VerifyChecksum);

        if (DataSize)
            *DataSize = (ULONG)decompressedSize;

        return dataPtr;

    }

    return NULL;
}

/*
* KDUDecompressResource
*
* Purpose:
*
* Decompress resource and return pointer to decompressed data.
*
* N.B. Use supHeapFree to release memory allocated for the decompressed buffer.
*
*/
PVOID KDUDecompressResource(
    _In_ PVOID ResourcePtr,
    _In_ SIZE_T ResourceSize,
    _Out_ PSIZE_T DecompressedSize,
    _In_ ULONG DecryptKey,
    _In_ BOOLEAN VerifyChecksum
)
{
    BOOLEAN bValidData;
    DELTA_INPUT diDelta, diSource;
    DELTA_OUTPUT doOutput;
    PVOID resultPtr = NULL, dataBlob;

    *DecompressedSize = 0;

    RtlSecureZeroMemory(&diSource, sizeof(DELTA_INPUT));
    RtlSecureZeroMemory(&diDelta, sizeof(DELTA_INPUT));
    RtlSecureZeroMemory(&doOutput, sizeof(DELTA_OUTPUT));

    dataBlob = supHeapAlloc(ResourceSize);
    if (dataBlob) {
        RtlCopyMemory(dataBlob, ResourcePtr, ResourceSize);
        EncodeBuffer(dataBlob, (ULONG)ResourceSize, DecryptKey);

        diDelta.Editable = FALSE;
        diDelta.lpcStart = dataBlob;
        diDelta.uSize = ResourceSize;

        if (ApplyDeltaB(DELTA_FILE_TYPE_RAW, diSource, diDelta, &doOutput)) {
            
            SIZE_T newSize = doOutput.uSize;
            PVOID decomPtr = doOutput.lpStart;

            bValidData = TRUE;

            if (VerifyChecksum) {

                ULONG headerSum = 0, calcSum = 0;

                bValidData = supVerifyMappedImageMatchesChecksum(decomPtr,
                    (ULONG)newSize,
                    &headerSum,
                    &calcSum);

                if (bValidData == FALSE) {
                    
                    supPrintfEvent(kduEventError, 
                        "[!] Error data checksum mismatch! Header sum 0x%lx, calculated sum 0x%lx\r\n",
                        headerSum, 
                        calcSum);

                }
            }
            else {
                printf_s("[+] Checksum verification skipped\r\n");
            }

            if (bValidData) {
                resultPtr = (PVOID)supHeapAlloc(newSize);
                if (resultPtr) {
                    RtlCopyMemory(resultPtr, decomPtr, newSize);
                    *DecompressedSize = newSize;
                }
            }

            DeltaFree(doOutput.lpStart);

        }
        else {
            
            supShowWin32Error("[!] Error while decompressing resource", GetLastError());

        }

        supHeapFree(dataBlob);
    }

    return resultPtr;
}
