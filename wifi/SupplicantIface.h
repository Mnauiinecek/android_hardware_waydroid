#pragma once

#include <string>
#include <vector>

#include <android/hardware/wifi/supplicant/1.0/ISupplicantIface.h>
#include <android/hardware/wifi/supplicant/1.0/ISupplicantStaIfaceCallback.h>
#include <hidl/Status.h>
#include <utils/StrongPointer.h>

#include "SupplicantStaNetwork.h"

using ::android::hardware::Return;

namespace android::hardware::wifi::supplicant::V1_0::implementation {

class SupplicantIface : public ISupplicantIface {
public:
    SupplicantIface(const std::string& interfaceName);

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

protected:
    std::string mInterfaceName;
    std::string mNetworkName;

    IfaceType mNetworkType = IfaceType::STA;

    std::vector<android::sp<SupplicantStaNetwork>> mNetworks;
};

}  // namespace android::hardware::wifi::supplicant::V1_0::implementation
