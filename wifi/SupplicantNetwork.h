#pragma once

#include <string>

#include <android/hardware/wifi/supplicant/1.0/ISupplicantNetwork.h>
#include <hidl/Status.h>

using ::android::hardware::Return;

namespace android::hardware::wifi::supplicant::V1_0::implementation {

class SupplicantNetwork : public ISupplicantNetwork {
public:
    SupplicantNetworkId mNetworkId;
    std::string mInterfaceName;
    IfaceType mNetworkType;

    SupplicantNetwork(SupplicantNetworkId id, const std::string &interfaceName, IfaceType type);

    Return<void> getId(getId_cb _hidl_cb) override;
    Return<void> getInterfaceName(getInterfaceName_cb _hidl_cb) override;
    Return<void> getType(getType_cb _hidl_cb) override;
};

}  // namespace android::hardware::wifi::supplicant::V1_0::implementation
