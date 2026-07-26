#pragma once

#include <string>

#include <android/hardware/wifi/supplicant/1.0/ISupplicantStaIface.h>
#include <android/hardware/wifi/supplicant/1.0/ISupplicantStaIfaceCallback.h>
#include <hidl/Status.h>
#include <utils/StrongPointer.h>

#include "SupplicantIface.h"

using ::android::hardware::Return;

namespace android::hardware::wifi::supplicant::V1_0::implementation {

class SupplicantStaIface : public SupplicantIface, public ISupplicantStaIface {
public:
    using SupplicantIface::SupplicantIface;

    Return<void> getName(getName_cb _hidl_cb) override;
    Return<void> getType(getType_cb _hidl_cb) override;

    // Network Management
    Return<void> addNetwork(addNetwork_cb _hidl_cb) override;
    Return<void> removeNetwork(SupplicantNetworkId id, removeNetwork_cb _hidl_cb) override;
    Return<void> getNetwork(SupplicantNetworkId id, getNetwork_cb _hidl_cb) override;
    Return<void> listNetworks(listNetworks_cb _hidl_cb) override;

    // WPS Operations
    Return<void> setWpsDeviceName(const hidl_string& name, setWpsDeviceName_cb _hidl_cb) override;
    Return<void> setWpsDeviceType(const hidl_array<uint8_t, 8>& type, setWpsDeviceType_cb _hidl_cb) override;
    Return<void> setWpsManufacturer(const hidl_string& manufacturer, setWpsManufacturer_cb _hidl_cb) override;
    Return<void> setWpsModelName(const hidl_string& modelName, setWpsModelName_cb _hidl_cb) override;
    Return<void> setWpsModelNumber(const hidl_string& modelNumber, setWpsModelNumber_cb _hidl_cb) override;
    Return<void> setWpsSerialNumber(const hidl_string& serialNumber, setWpsSerialNumber_cb _hidl_cb) override;
    Return<void> setWpsConfigMethods(hidl_bitfield<WpsConfigMethods> configMethods, setWpsConfigMethods_cb _hidl_cb) override;

    Return<void> registerCallback(const android::sp<ISupplicantStaIfaceCallback>& callback, registerCallback_cb _hidl_cb) override;
    Return<void> reassociate(reassociate_cb _hidl_cb) override;
    Return<void> reconnect(reconnect_cb _hidl_cb) override;
    Return<void> disconnect(disconnect_cb _hidl_cb) override;
    Return<void> setPowerSave(bool enable, setPowerSave_cb _hidl_cb) override;
    Return<void> initiateTdlsDiscover(const hidl_array<uint8_t, 6>& macAddress, initiateTdlsDiscover_cb _hidl_cb) override;
    Return<void> initiateTdlsSetup(const hidl_array<uint8_t, 6>& macAddress, initiateTdlsSetup_cb _hidl_cb) override;
    Return<void> initiateTdlsTeardown(const hidl_array<uint8_t, 6>& macAddress, initiateTdlsTeardown_cb _hidl_cb) override;
    Return<void> initiateAnqpQuery(const hidl_array<uint8_t, 6>& macAddress, const hidl_vec<ISupplicantStaIface::AnqpInfoId>& infoElements, const hidl_vec<ISupplicantStaIface::Hs20AnqpSubtypes>& subTypes, initiateAnqpQuery_cb _hidl_cb) override;
    Return<void> initiateHs20IconQuery(const hidl_array<uint8_t, 6>& macAddress, const hidl_string& fileName, initiateHs20IconQuery_cb _hidl_cb) override;
    Return<void> getMacAddress(getMacAddress_cb _hidl_cb) override;
    Return<void> startRxFilter(startRxFilter_cb _hidl_cb) override;
    Return<void> stopRxFilter(stopRxFilter_cb _hidl_cb) override;
    Return<void> addRxFilter(ISupplicantStaIface::RxFilterType type, addRxFilter_cb _hidl_cb) override;
    Return<void> removeRxFilter(ISupplicantStaIface::RxFilterType type, removeRxFilter_cb _hidl_cb) override;
    Return<void> setBtCoexistenceMode(ISupplicantStaIface::BtCoexistenceMode mode, setBtCoexistenceMode_cb _hidl_cb) override;
    Return<void> setBtCoexistenceScanModeEnabled(bool enable, setBtCoexistenceScanModeEnabled_cb _hidl_cb) override;
    Return<void> setSuspendModeEnabled(bool enable, setSuspendModeEnabled_cb _hidl_cb) override;
    Return<void> setCountryCode(const android::hardware::hidl_array<int8_t, 2>& code, setCountryCode_cb _hidl_cb) override;
    Return<void> startWpsRegistrar(const android::hardware::hidl_array<uint8_t, 6>& bssid, const android::hardware::hidl_string& pin, startWpsRegistrar_cb _hidl_cb) override;
    Return<void> startWpsPbc(const android::hardware::hidl_array<uint8_t, 6>& bssid, startWpsPbc_cb _hidl_cb) override;
    Return<void> startWpsPinKeypad(const android::hardware::hidl_string& pin, startWpsPinKeypad_cb _hidl_cb) override;
    Return<void> startWpsPinDisplay(const android::hardware::hidl_array<uint8_t, 6>& bssid, startWpsPinDisplay_cb _hidl_cb) override;
    Return<void> cancelWps(cancelWps_cb _hidl_cb) override;
    Return<void> setExternalSim(bool useExternalSim, setExternalSim_cb _hidl_cb) override;
    Return<void> addExtRadioWork(const hidl_string& name, uint32_t freqInMhz, uint32_t timeoutInSec, addExtRadioWork_cb _hidl_cb) override;
    Return<void> removeExtRadioWork(uint32_t id, removeExtRadioWork_cb _hidl_cb) override;
    Return<void> enableAutoReconnect(bool enable, enableAutoReconnect_cb _hidl_cb) override;

private:
    android::sp<ISupplicantStaIfaceCallback> mCallback;

};

}  // namespace android::hardware::wifi::supplicant::V1_0::implementation
