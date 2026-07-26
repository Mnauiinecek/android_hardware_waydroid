#include <string>
#include "SupplicantNetwork.h"

using android::sp;
using ::android::hardware::Return;
using ::android::hardware::Void;

namespace android::hardware::wifi::supplicant::V1_0::implementation {

SupplicantNetwork::SupplicantNetwork(SupplicantNetworkId id, const std::string &interfaceName, IfaceType type)
    : mNetworkId(id),
      mInterfaceName(interfaceName),
      mNetworkType(type) {}

Return<void> SupplicantNetwork::getId(getId_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status, mNetworkId);
    return Void();
}

Return<void> SupplicantNetwork::getInterfaceName(getInterfaceName_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status, mInterfaceName);
    return Void();
}

Return<void> SupplicantNetwork::getType(getType_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status, mNetworkType);
    return Void();
}

}
