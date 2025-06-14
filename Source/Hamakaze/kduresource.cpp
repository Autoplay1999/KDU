#include "global.h"
#include "kduresource.h"

// Tanikaze
// Driver
#include "../Tanikaze/drv/ALSysIO64_bin_bin.h"
#include "../Tanikaze/drv/AMDRyzenMasterDriver_bin_bin.h"
#include "../Tanikaze/drv/amsdk_bin_bin.h"
#include "../Tanikaze/drv/AODDriver215_bin_bin.h"
#include "../Tanikaze/drv/AppShopDrv103_bin_bin.h"
#include "../Tanikaze/drv/asio2_bin_bin.h"
#include "../Tanikaze/drv/AsIO3_bin_bin.h"
#include "../Tanikaze/drv/AsrDrv106_bin_bin.h"
#include "../Tanikaze/drv/AsrDrv107_bin_bin.h"
#include "../Tanikaze/drv/AsrDrv107n_bin_bin.h"
#include "../Tanikaze/drv/ATSZIO64_bin_bin.h"
#include "../Tanikaze/drv/AxtuDrv_bin_bin.h"
#include "../Tanikaze/drv/dbk64_bin_bin.h"
#include "../Tanikaze/drv/DbUtil2_3_bin_bin.h"
#include "../Tanikaze/drv/dbutildrv2_bin_bin.h"
#include "../Tanikaze/drv/DirectIo64_2_bin_bin.h"
#include "../Tanikaze/drv/DirectIo64_bin_bin.h"
#include "../Tanikaze/drv/echo_driver_bin_bin.h"
#include "../Tanikaze/drv/eleetx1_bin_bin.h"
#include "../Tanikaze/drv/ene2_bin_bin.h"
#include "../Tanikaze/drv/EneIo64_bin_bin.h"
#include "../Tanikaze/drv/EneTechIo64_bin_bin.h"
#include "../Tanikaze/drv/etdsupp_bin_bin.h"
#include "../Tanikaze/drv/gdrv_bin_bin.h"
#include "../Tanikaze/drv/GLCKIO2_bin_bin.h"
#include "../Tanikaze/drv/gmerdrv_bin_bin.h"
#include "../Tanikaze/drv/heavenluo_bin_bin.h"
#include "../Tanikaze/drv/HW64_bin_bin.h"
#include "../Tanikaze/drv/HwRwDrv_x64_bin_bin.h"
#include "../Tanikaze/drv/inpoutx64_bin_bin.h"
#include "../Tanikaze/drv/iQVM64_bin_bin.h"
#include "../Tanikaze/drv/irec_bin_bin.h"
#include "../Tanikaze/drv/KExplore_bin_bin.h"
#include "../Tanikaze/drv/KObjExp_bin_bin.h"
#include "../Tanikaze/drv/kprocesshacker_bin_bin.h"
#include "../Tanikaze/drv/KRegExp_bin_bin.h"
#include "../Tanikaze/drv/LDD_bin_bin.h"
#include "../Tanikaze/drv/lha_bin_bin.h"
#include "../Tanikaze/drv/mimidrv_bin_bin.h"
#include "../Tanikaze/drv/MsIo64_bin_bin.h"
#include "../Tanikaze/drv/nvoclock_bin_bin.h"
#include "../Tanikaze/drv/pcdsrvc_x64_bin_bin.h"
#include "../Tanikaze/drv/PdFwKrnl_bin_bin.h"
#include "../Tanikaze/drv/PhyDMACC_bin_bin.h"
#include "../Tanikaze/drv/Phymemx64_bin_bin.h"
#include "../Tanikaze/drv/physmem_bin_bin.h"
#include "../Tanikaze/drv/pmxdrv64_bin_bin.h"
#include "../Tanikaze/drv/procexp1627_bin_bin.h"
#include "../Tanikaze/drv/procexp1702_bin_bin.h"
#include "../Tanikaze/drv/RTCore64_bin_bin.h"
#include "../Tanikaze/drv/rtkio64_bin_bin.h"
#include "../Tanikaze/drv/rzpnk_bin_bin.h"
#include "../Tanikaze/drv/SysDrv3S_bin_bin.h"
#include "../Tanikaze/drv/WinRing0x64_bin_bin.h"
#include "../Tanikaze/drv/wnBios64_bin_bin.h"
// Data
#include "../Tanikaze/data/dbutilcat_bin_bin.h"
#include "../Tanikaze/data/dbutilinf_bin_bin.h"
#include "../Tanikaze/data/KMUEXE_bin_bin.h"
#include "../Tanikaze/data/KMUSIG_bin_bin.h"
#include "../Tanikaze/data/AsusCertService_bin_bin.h"

// Hamakaze
#include "../Hamakaze/res/SB_SMBUS_SDK_bin_bin.h"
#include "../Hamakaze/res/Taigei32_bin_bin.h"

KDU_DB_RES_ENTRY gResEntry[] = {
    // Tanikaze/Driver
    {
        IDR_INTEL_NAL,
        IQVM64_BIN_DATA,
        IQVM64_BIN_SIZE
    },
    {
        IDR_PROCEXP1627,
        PROCEXP1627_BIN_DATA,
        PROCEXP1627_BIN_SIZE
    },
    {
        IDR_RTCORE64,
        RTCORE64_BIN_DATA,
        RTCORE64_BIN_SIZE
    },
    {
        IDR_GDRV,
        GDRV_BIN_DATA,
        GDRV_BIN_SIZE
    },
    {
        IDR_ATSZIO64,
        ATSZIO64_BIN_DATA,
        ATSZIO64_BIN_SIZE
    },
    {
        IDR_MSIO64,
        MSIO64_BIN_DATA,
        MSIO64_BIN_SIZE
    },
    {
        IDR_GLCKIO2,
        GLCKIO2_BIN_DATA,
        GLCKIO2_BIN_SIZE
    },
    {
        IDR_ENEIO64,
        ENEIO64_BIN_DATA,
        ENEIO64_BIN_SIZE
    },
    {
        IDR_WINRING0,
        WINRING0X64_BIN_DATA,
        WINRING0X64_BIN_SIZE
    },
    {
        IDR_ENETECHIO64,
        ENETECHIO64_BIN_DATA,
        ENETECHIO64_BIN_SIZE
    },
    {
        IDR_PHYMEMX64,
        PHYMEMX64_BIN_DATA,
        PHYMEMX64_BIN_SIZE
    },
    {
        IDR_RTKIO64,
        RTKIO64_BIN_DATA,
        RTKIO64_BIN_SIZE
    },
    {
        IDR_ENETECHIO64B,
        ENE2_BIN_DATA,
        ENE2_BIN_SIZE
    },
    {
        IDR_LHA,
        LHA_BIN_DATA,
        LHA_BIN_SIZE
    },
    {
        IDR_ASUSIO2,
        ASIO2_BIN_DATA,
        ASIO2_BIN_SIZE
    },
    {
        IDR_DIRECTIO64,
        DIRECTIO64_BIN_DATA,
        DIRECTIO64_BIN_SIZE
    },
    {
        IDR_GMERDRV,
        GMERDRV_BIN_DATA,
        GMERDRV_BIN_SIZE
    },
    {
        IDR_DBUTIL23,
        DBUTIL2_3_BIN_DATA,
        DBUTIL2_3_BIN_SIZE
    },
    {
        IDR_MIMIDRV,
        MIMIDRV_BIN_DATA,
        MIMIDRV_BIN_SIZE
    },
    {
        IDR_KPH,
        KPROCESSHACKER_BIN_DATA,
        KPROCESSHACKER_BIN_SIZE
    },
    {
        IDR_DBUTILDRV2,
        DBUTILDRV2_BIN_DATA,
        DBUTILDRV2_BIN_SIZE
    },
    {
        IDR_DBK64,
        DBK64_BIN_DATA,
        DBK64_BIN_SIZE
    },
    {
        IDR_ASUSIO3,
        ASIO3_BIN_DATA,
        ASIO3_BIN_SIZE
    },
    {
        IDR_HW64,
        HW64_BIN_DATA,
        HW64_BIN_SIZE
    },
    {
        IDR_SYSDRV3S,
        SYSDRV3S_BIN_DATA,
        SYSDRV3S_BIN_SIZE
    },
    {
        IDR_ZEMANA,
        AMSDK_BIN_DATA,
        AMSDK_BIN_SIZE
    },
    {
        IDR_INPOUTX64,
        INPOUTX64_BIN_DATA,
        INPOUTX64_BIN_SIZE
    },
    {
        IDR_PASSMARK_OSF,
        DIRECTIO64_2_BIN_DATA,
        DIRECTIO64_2_BIN_SIZE
    },
    {
        IDR_ASROCKDRV,
        ASRDRV106_BIN_DATA,
        ASRDRV106_BIN_SIZE
    },
    {
        IDR_ALSYSIO64,
        ALSYSIO64_BIN_DATA,
        ALSYSIO64_BIN_SIZE
    },
    {
        IDR_AMD_RYZENMASTER,
        AMDRYZENMASTERDRIVER_BIN_DATA,
        AMDRYZENMASTERDRIVER_BIN_SIZE
    },
    {
        IDR_PHYSMEM,
        PHYSMEM_BIN_DATA,
        PHYSMEM_BIN_SIZE
    },
    {
        IDR_PROCEXP1702,
        PROCEXP1702_BIN_DATA,
        PROCEXP1702_BIN_SIZE
    },
    {
        IDR_LDD,
        LDD_BIN_DATA,
        LDD_BIN_SIZE
    },
    {
        IDR_PCDSRVC,
        PCDSRVC_X64_BIN_DATA,
        PCDSRVC_X64_BIN_SIZE
    },
    {
        IDR_MSI_WINIO,
        HEAVENLUO_BIN_DATA,
        HEAVENLUO_BIN_SIZE
    },
    {
        IDR_HP_ETDSUPP,
        ETDSUPP_BIN_DATA,
        ETDSUPP_BIN_SIZE
    },
    {
        IDR_KEXPLORE,
        KEXPLORE_BIN_DATA,
        KEXPLORE_BIN_SIZE
    },
    {
        IDR_KOBJEXP,
        KOBJEXP_BIN_DATA,
        KOBJEXP_BIN_SIZE
    },
    {
        IDR_KREGEXP,
        KREGEXP_BIN_DATA,
        KREGEXP_BIN_SIZE
    },
    {
        IDR_ECHODRV,
        ECHO_DRIVER_BIN_DATA,
        ECHO_DRIVER_BIN_SIZE
    },
    {
        IDR_NVOCLOCK,
        NVOCLOCK_BIN_DATA,
        NVOCLOCK_BIN_SIZE
    },
    {
        IDR_IREC,
        IREC_BIN_DATA,
        IREC_BIN_SIZE
    },
    {
        IDR_PHYDMACC,
        PHYDMACC_BIN_DATA,
        PHYDMACC_BIN_SIZE
    },
    {
        IDR_RZPNK,
        RZPNK_BIN_DATA,
        RZPNK_BIN_SIZE
    },
    {
        IDR_AMD_PDFWKRNL,
        PDFWKRNL_BIN_DATA,
        PDFWKRNL_BIN_SIZE
    },
    {
        IDR_AMD_AOD215,
        AODDRIVER215_BIN_DATA,
        AODDRIVER215_BIN_SIZE
    },
    {
        IDR_WNBIOS64,
        WNBIOS64_BIN_DATA,
        WNBIOS64_BIN_SIZE
    },
    {
        IDR_EVGA_ELEETX1,
        ELEETX1_BIN_DATA,
        ELEETX1_BIN_SIZE
    },
    {
        IDR_ASROCKDRV2,
        AXTUDRV_BIN_DATA,
        AXTUDRV_BIN_SIZE
    },
    {
        IDR_ASROCKAPPSHOP103,
        APPSHOPDRV103_BIN_DATA,
        APPSHOPDRV103_BIN_SIZE
    },
    {
        IDR_ASROCKDRV3,
        ASRDRV107N_BIN_DATA,
        ASRDRV107N_BIN_SIZE
    },
    {
        IDR_ASROCKDRV4,
        ASRDRV107_BIN_DATA,
        ASRDRV107_BIN_SIZE
    },
    {
        IDR_PMXDRV64,
        PMXDRV64_BIN_DATA,
        PMXDRV64_BIN_SIZE
    },
    {
        IDR_HWRWDRVX64,
        HWRWDRV_X64_BIN_DATA,
        HWRWDRV_X64_BIN_SIZE
    },
    // Tanikaze/Data
    {
        IDR_DATA_DBUTILCAT,
        DBUTILCAT_BIN_DATA,
        DBUTILCAT_BIN_SIZE
    },
    {
        IDR_DATA_DBUTILINF,
        DBUTILINF_BIN_DATA,
        DBUTILINF_BIN_SIZE
    },
    {
        IDR_DATA_KMUEXE,
        KMUEXE_BIN_DATA,
        KMUEXE_BIN_SIZE
    },
    {
        IDR_DATA_KMUSIG,
        KMUSIG_BIN_DATA,
        KMUSIG_BIN_SIZE
    },
    {
        IDR_DATA_ASUSCERTSERVICE,
        ASUSCERTSERVICE_BIN_DATA,
        ASUSCERTSERVICE_BIN_SIZE
    },
    // Hamakaze
    {
        IDR_TAIGEI32,
		TAIGEI32_BIN_DATA,
		TAIGEI32_BIN_SIZE
    },
    {
        IDR_TAIGEI64,
        SB_SMBUS_SDK_BIN_DATA,
        SB_SMBUS_SDK_BIN_SIZE
    }
};

KDU_DB_RES gResTable = {
    RTL_NUMBER_OF(gResEntry),
    gResEntry
};